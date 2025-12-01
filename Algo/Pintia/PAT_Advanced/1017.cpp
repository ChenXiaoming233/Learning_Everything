#include <bits/stdc++.h>

using namespace std;

struct Cos
{
    int h, m, s;
    int p; // 处理时间 单位为分钟
    int id;
    int totalTime;
    int entryTime;
    long long arrivalTime; // 以秒为单位
    bool operator< (const Cos& other)const{
        return arrivalTime < other.arrivalTime;
    }
};

int globalTime = 0;
int n, k; // 顾客总数 <= 10^4  窗口数量 <= 100

int main()
{
    cin >> n >> k;
    queue<Cos> line[k];
    vector<Cos> coss;
    // 录入信息
    for (int i = 0; i < n; i++)
    {
        Cos cos_temp;
        char colon;
        cos_temp.id = i + 1;
        cos_temp.totalTime = 0;
        cin >> cos_temp.h >> colon >> cos_temp.m >> colon >> cos_temp.s >> cos_temp.p;
        cos_temp.arrivalTime = cos_temp.h * 60 * 60 + cos_temp.m * 60 + cos_temp.s;
        if(cos_temp.arrivalTime > 61200){
            n--;
        }
        else{
            coss.push_back(cos_temp);
        }    
    }

    sort(coss.begin(), coss.end());
    
    int next = min(k, n);

    // 初始装填
    for (int i = 0; i < next; i++)
    {
        line[i].push(coss[i]);
        coss[i].entryTime = globalTime;
    }

    int empty = 0;
    while (1)
    {
        globalTime++;
        for (int i = 0; i < k; i++)
        {
            Cos &cos = line[i].front();
            cos.p--;
            if (cos.p == 0)
            {
                cos.totalTime = globalTime - cos.entryTime;
                line[i].pop();
                if (next != n - 1)
                {
                    line[i].push(coss[next]);
                    next++;
                }
                else{
                    empty++;
                }
            }
        }
        if(empty == k){
            break;
        }
    }

    float sum = 0.0;
    for(int i = 0; i < n; i++){
        sum += coss[i].totalTime;
    }

    float avg = sum / n;
    printf("%.1f", avg);
}