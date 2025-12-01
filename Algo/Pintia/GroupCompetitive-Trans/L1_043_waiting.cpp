// #模拟

#include <bits/stdc++.h>

using namespace std;

int ds; // 总计天数
struct record
{
    int no;
    char statue;
    long long t; // 从当天 0 点开始的时间，以分钟为单位
    bool operator<(const record &other) const
    {
        if (no != other.no)
        {
            return no < other.no;
        }
        return statue > other.statue;
    }
};
vector<record> records;

int main()
{
    cin >> ds;
    string record_o;
    string temp;
    getline(cin, temp);
    for (int i = 0; i < ds; i++)
    {
        records.clear();
        while (getline(cin, record_o))
        {
            stringstream ss(record_o);
            record r;
            string time;
            ss >> r.no ;
            ss >> r.statue;
            ss >> time;
            stringstream ss2(time);
            char temp;
            int h, m;
            ss2 >> h >> temp >> m;
            r.t = h * 60 + m;
            if (r.no == 0)
            {
                break;
            }
            records.push_back(r);
        }
        sort(records.begin(), records.end());
        int reader = 0;
        int totalt = 0;
        for (size_t i = 0; i + 1 < records.size(); i++)
        {
            if ((records[i].statue == 'S' and records[i + 1].statue == 'E') and (records[i].no == records[i + 1].no))
            {
                totalt += records[i + 1].t - records[i].t;
                reader++;
            }
        }
        if (reader == 0)
        {
            cout << "0 0" << endl;
        }
        else
        {
            int avg = round(static_cast<float>(totalt) / reader);
            cout << reader << " " << avg << endl;
        }
    }
}