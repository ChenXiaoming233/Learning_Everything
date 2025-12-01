#include <bits/stdc++.h>

using namespace std;

struct race
{
    char a, b;
};

int main()
{
    int n = 0;
    cin >> n;
    vector<race> ra, rb, rc;
    int ac = 0;
    int aj = 0;
    int ab = 0;
    int bc = 0;
    int bj = 0;
    int bb = 0;
    for (int i = 0; i < n; i++)
    {
        race r;
        cin >> r.a >> r.b;
        if ((r.a == 'J' and r.b == 'C') or (r.a == 'C' and r.b == 'B') or (r.a == 'B' and r.b == 'J'))
        {
            ra.push_back(r);
            if (r.a == 'C')
                ac++;
            if (r.a == 'J')
                aj++;
            if (r.a == 'B')
                ab++;
        }
        else if ((r.b == 'J' and r.a == 'C') or (r.b == 'C' and r.a == 'B') or (r.b == 'B' and r.a == 'J'))
        {
            rb.push_back(r);
            if (r.b == 'C')
                bc++;
            if (r.b == 'J')
                bj++;
            if (r.b == 'B')
                bb++;
        }
        else
            rc.push_back(r);
    }
    cout << rb.size() << " " << rc.size() << " " << ra.size() << endl;
    cout << ra.size() << " " << rc.size() << " " << rb.size() << endl;
    if (max({ac, aj, ab}) == ac) cout << "C";
    if (max({ac, aj, ab}) == aj) cout << "J";
    if (max({ac, aj, ab}) == ab) cout << "B";
    cout << " ";
    if (max({bc, bj, bb}) == bc) cout << "C";
    if (max({bc, bj, bb}) == bj) cout << "J";
    if (max({bc, bj, bb}) == bb) cout << "B";
    return 0;
}