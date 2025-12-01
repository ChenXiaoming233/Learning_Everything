// #*思维 #细节
#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> list1(100000, 0);
vector<int> hascout(100000, 0);

int main()
{
    cin >> n; // 已知朋友圈个数
    for (int i = 0; i < n; i++)
    {
        int k; // 该朋友圈中的人数
        cin >> k;
        if (k == 1)
        {
            int x;
            cin >> x; // 不计入 list1
        }
        else
        {
            for (int j = 0; j < k; j++)
            {
                int x;
                cin >> x;
                list1[x]++; // 只有 k>=2 才算“有朋友”
            }
        }
    }
    cin >> m;
    int count = 0;
    for (int i = 0; i < m; i++)
    {
        int forcheck;
        cin >> forcheck;
        if (list1[forcheck] == 0 && hascout[forcheck] == 0)
        {
            cout << (count == 0 ? "" : " ");
            printf("%05d", forcheck); 
            // ! 注意 %5d != %05d 
            count++;
            // list1[forcheck]++; 
            // ! 注意 不可以直接利用 list1 去重，因为同一 id 有可能重复出现
            hascout[forcheck] = 1;
        }
    }
    if (count == 0)
    {
        cout << "No one is handsome";
    }
    cout << endl;
}