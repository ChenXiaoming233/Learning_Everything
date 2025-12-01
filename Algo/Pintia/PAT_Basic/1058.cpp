#include <bits/stdc++.h>

using namespace std;

struct Question
{
    int no;
    int full;           // 满分值
    int num;            // 选项个数
    int truth;          // 正选个数
    vector<char> trues; // 答案
    int count = 0;      // 错误计数
    bool operator<(const Question &other) const
    {
        if (count != other.count)
            return (count > other.count);
        else
            return (no < other.no);
    }
};
vector<Question> Ques;

vector<vector<string>> ans;

int main()
{
    int n, m; // 学生人数 多选题个数
    cin >> n >> m;
    cin.ignore();
    for (int i = 0; i < m; i++) // 该层为一道题目，i 代表第几题
    {
        Question Que_temp;
        Que_temp.no = i + 1;
        cin >> Que_temp.full >> Que_temp.num >> Que_temp.truth;
        for (int j = 0; j < Que_temp.truth; j++) // 该层为一个选项，j 代表第几个选项
        {
            char true_temp;
            cin >> true_temp;
            Que_temp.trues.push_back(true_temp);
        }
        Ques.push_back(Que_temp);
    }

    for(int i = 0; i < n; i++){
        string s;
        getline(cin, s);
        int sta = 0;
        for(int j = 0; j < m; j++){
            int num = 0, t = 0;
            
        }
    }




    for (int i = 0; i < n; i++) // 该层为一个同学，i 代表第几个同学
    {
        string ans_temp;
        getline(cin, ans_temp);
        int pos_front = 0;
        int pos_back = 0;
        while (1)
        {
            pos_front = ans_temp.find('(', pos_front);
            pos_back = ans_temp.find(')', pos_back);
            if (pos_front == string::npos or pos_back == string::npos)
                break;
            if (pos_back <= pos_front)
                break;
            ans[i].push_back(ans_temp.substr(pos_front + 1, pos_back - pos_front - 1));
            pos_front++;
            pos_back++;
        }

        int count = 0;
        for (int j = 0; j < m; j++) // 该层为一个题目，j 代表第几题
        {
            stringstream ss(ans[i][j]);
            int num_stu;
            ss >> num_stu;
            if (num_stu != Ques[j].num)
            {
                continue;
            }
            vector<char> ans_stu(num_stu);
            bool isTrue = true;
            for (int k = 0; k < num_stu; k++) // 该层为一个选项，k 代表第几个选项
            {
                ss >> ans_stu[k];
                if (ans_stu[k] != Ques[j].trues[k])
                {
                    isTrue = false;
                    Ques[j].count++;
                    break;
                }
            }
            if (isTrue == true)
            {
                count += Ques[j].full;
            }
        }
        cout << count << endl;
    }
    sort(Ques.begin(), Ques.end());
    cout << Ques[0].count;
    for (int i = 0; i < m; i++)
    {
        if (Ques[0].count == Ques[i].count)
        {
            cout << " " << Ques[i].no;
        }
    }
}