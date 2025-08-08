#include <iostream>
#include <vector>
#include <algorithm>  

using namespace std;

// 使用 vector 代替数组创建结构体，利用 string 容纳与比较超长数字并进行对比
struct Person{
    int no;
    string count;
};

bool cmp(const Person& a, const Person& b){
    if (a.count.length() != b.count.length()){
        return a.count.length() > b.count.length(); 
        // 如果直接 return a.count > b.count，由于 string 的比较运算符 > 是按字典序而非数值来比较大小，例如："99" > "100" → true（因为 '9' > '1'），但实际上 99 < 100
    }
    return a.count > b.count; // 位数相同，直接比较字符串（字典序降序）
}

int main() {
    int num = 0;
    cin >> num;
    vector<Person> person(num+1);  // 使用 vector 代替数组创建结构体
    for(int i = 1; i <= num; i++){
        cin >> person[i].count;
        person[i].no = i;
    }
    sort(person.begin()+1,person.end(),cmp);
    cout << person[1].no << endl;
    cout << person[1].count;
    return 0;
}