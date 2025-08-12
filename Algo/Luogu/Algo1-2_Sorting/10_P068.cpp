#include <iostream>
#include <vector>
#include <algorithm>  
#include <cmath>

using namespace std;


// 使用 floor 函数向下取整，使用 ceil 函数向上取整，均向正 / 负无穷方向
struct Person{
    int no;
    int score;
};

bool cmp(Person a, Person b){
    if(a.score != b.score){
        return a.score > b.score;
    }
    else{
        return a.no < b.no;
    }
}

int main() {
    int n, m, line, last;
    cin >> n >> m;
    vector<Person> people(n);
    for(int i = 0; i < n; i++){
        cin >> people[i].no >> people[i].score;
    }
    sort(people.begin(), people.end(), cmp);
    last = floor(m * 1.5); // 使用 floor 函数向下取整
    line = people[last - 1].score; // ATTENTION：数组是从 0 开始索引的，所以 people[last] 实际上是第 last+1 个人的分数。
    last = 0;
    for(int i = 0; i < n; i++){
        if(people[i].score >= line){
            last++;
        }
    }
    cout << line << " " << last << endl;
    for(int i = 0; i < last; i++){
        cout << people[i].no << " " << people[i].score << endl;
    }
    return 0;
}

