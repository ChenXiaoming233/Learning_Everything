#!/usr/bin/env python3
import collections
import socket
import struct
import sys


def iter_epb(path):
    data = open(path, "rb").read()
    off = 0
    endian = "<"
    while off + 12 <= len(data):
        block_type = struct.unpack_from(endian + "I", data, off)[0]
        if block_type == 0x0A0D0D0A:
            bom = data[off + 8:off + 12]
            if bom == b"\x4d\x3c\x2b\x1a":
                endian = "<"
            elif bom == b"\x1a\x2b\x3c\x4d":
                endian = ">"
            block_type = struct.unpack_from(endian + "I", data, off)[0]
        block_len = struct.unpack_from(endian + "I", data, off + 4)[0]
        if block_len < 12 or off + block_len > len(data):
            raise ValueError(f"bad pcapng block at {off:#x}: len={block_len}")
        if block_type == 6:
            iface, ts_hi, ts_lo, caplen, origlen = struct.unpack_from(
                endian + "IIIII", data, off + 8
            )
            packet = data[off + 28:off + 28 + caplen]
            yield iface, (ts_hi << 32) | ts_lo, packet, origlen
        off += block_len


def udp_payload(frame):
    if len(frame) < 14:
        return None
    ethertype = struct.unpack_from("!H", frame, 12)[0]
    pos = 14
    if ethertype == 0x8100 and len(frame) >= 18:
        ethertype = struct.unpack_from("!H", frame, 16)[0]
        pos = 18
    if ethertype != 0x0800 or len(frame) < pos + 20:
        return None
    ip = frame[pos:]
    ihl = (ip[0] & 0x0F) * 4
    if (ip[0] >> 4) != 4 or ihl < 20 or len(ip) < ihl + 8 or ip[9] != 17:
        return None
    src = socket.inet_ntoa(ip[12:16])
    dst = socket.inet_ntoa(ip[16:20])
    sport, dport, ulen = struct.unpack_from("!HHH", ip, ihl)
    payload = ip[ihl + 8:ihl + min(ulen, len(ip) - ihl)]
    return src, dst, sport, dport, payload


def parse_rtp(data):
    if len(data) < 12 or data[0] >> 6 != 2:
        return None
    cc = data[0] & 0x0F
    extension = bool(data[0] & 0x10)
    padding = bool(data[0] & 0x20)
    pos = 12 + cc * 4
    if len(data) < pos:
        return None
    if extension:
        if len(data) < pos + 4:
            return None
        ext_words = struct.unpack_from("!H", data, pos + 2)[0]
        pos += 4 + ext_words * 4
    end = len(data)
    if padding:
        pad = data[-1]
        if not pad or pad > end - pos:
            return None
        end -= pad
    marker = bool(data[1] & 0x80)
    pt = data[1] & 0x7F
    seq, timestamp, ssrc = struct.unpack_from("!HII", data, 2)
    return pt, marker, seq, timestamp, ssrc, data[pos:end]


def main():
    if len(sys.argv) != 3:
        raise SystemExit(f"usage: {sys.argv[0]} INPUT.pcapng OUTPUT.h264")
    inp, outp = sys.argv[1:]
    packets = []
    all_udp = collections.Counter()
    for _, ts, frame, _ in iter_epb(inp):
        udp = udp_payload(frame)
        if not udp:
            continue
        src, dst, sport, dport, payload = udp
        all_udp[(src, sport, dst, dport)] += 1
        if dport != 1234:
            continue
        rtp = parse_rtp(payload)
        if rtp:
            packets.append((ts, *rtp))

    nal_counts = collections.Counter()
    rtp_pts = collections.Counter()
    seqs = []
    timestamps = []
    written = 0
    fu_open = False
    with open(outp, "wb") as out:
        def emit(nal):
            nonlocal written
            if not nal:
                return
            out.write(b"\x00\x00\x00\x01" + nal)
            written += 4 + len(nal)
            nal_counts[nal[0] & 0x1F] += 1

        for _, pt, marker, seq, timestamp, ssrc, payload in packets:
            rtp_pts[pt] += 1
            seqs.append(seq)
            timestamps.append(timestamp)
            if not payload:
                continue
            typ = payload[0] & 0x1F
            if 1 <= typ <= 23:
                emit(payload)
                fu_open = False
            elif typ == 24:  # STAP-A
                pos = 1
                while pos + 2 <= len(payload):
                    size = struct.unpack_from("!H", payload, pos)[0]
                    pos += 2
                    if size == 0 or pos + size > len(payload):
                        raise ValueError(f"invalid STAP-A seq={seq} size={size}")
                    emit(payload[pos:pos + size])
                    pos += size
                fu_open = False
            elif typ == 28:  # FU-A
                if len(payload) < 2:
                    continue
                fu_header = payload[1]
                start = bool(fu_header & 0x80)
                end = bool(fu_header & 0x40)
                frag = payload[2:]
                if start:
                    nal_header = bytes([(payload[0] & 0xE0) | (fu_header & 0x1F)])
                    out.write(b"\x00\x00\x00\x01" + nal_header + frag)
                    written += 5 + len(frag)
                    nal_counts[fu_header & 0x1F] += 1
                    fu_open = True
                elif fu_open:
                    out.write(frag)
                    written += len(frag)
                else:
                    print(f"warning: orphan FU-A continuation seq={seq}", file=sys.stderr)
                if end:
                    fu_open = False
            else:
                print(f"warning: unsupported H264 aggregation type={typ} seq={seq}", file=sys.stderr)

    gaps = []
    for a, b in zip(seqs, seqs[1:]):
        if b != ((a + 1) & 0xFFFF):
            gaps.append((a, b))
    print(f"UDP conversations: {dict(all_udp)}")
    print(f"RTP packets: {len(packets)} payload types: {dict(rtp_pts)}")
    print(f"RTP seq: {seqs[0] if seqs else None}..{seqs[-1] if seqs else None}; gaps={gaps}")
    print(f"RTP timestamps: unique={len(set(timestamps))} first={timestamps[0] if timestamps else None} last={timestamps[-1] if timestamps else None}")
    print(f"H264 NAL counts: {dict(sorted(nal_counts.items()))}")
    print(f"wrote {written} bytes to {outp}; FU still open={fu_open}")


if __name__ == "__main__":
    main()
