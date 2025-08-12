#include<iostream>
#include<cstdint> // 添加此行以包含 定宽整数 的定义
#include<cstdio> // 添加此行以包含 printf 函数的定义
#include<algorithm>
#include<vector>
 
using namespace std;
 
int main() {
    std::string word, s;
    getline(cin,word);
    getline(cin,s);
    int pos;
    for(int i=0; i<word.length(); i++){
        if ('A'<=word[i] && word[i]<='Z'){
            word[i] += 'a' - 'A';
        }
    }
    for(int i=0; i<s.length(); i++){
        if ('A'<=s[i] && s[i]<='Z'){
            s[i] += 'a' - 'A';
        }
    }

    word = " " + word + " ";
    s = " " + s + " ";

    pos = s.find(word);
    int count = 0;
    if(pos == -1){
        cout << "-1" << endl;
    }
    else{
        int firstpos = pos;
        int pos = s.find(word);
        while (pos != -1){
            count++;
            pos = s.find(word,pos+1);
        }
        cout << count << " " << firstpos << endl; 
    }
    return 0;
}
