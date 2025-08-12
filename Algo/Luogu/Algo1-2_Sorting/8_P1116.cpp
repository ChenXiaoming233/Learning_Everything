#include <iostream>
#include <vector>
#include <algorithm>  

using namespace std;

// 列车排序过程类似冒泡排序
int main() {
    int num;
    cin >> num;
    vector<int> train(num);
    for(int i = 0; i < num; i++){
        cin >> train[i];
    }
    int count = 0;
    for(int i = 0; i < num - 1; i++){
        for(int j = 0; j < num - i - 1; j++){
            if(train[j + 1] < train[j]){
                swap(train[j + 1], train[j]); // 注意要实际进行互换，否则统计的只是所有的逆序对数量，而非需要交换的次数；例如 3 1 4 2，逆序对是 (3,1), (3,2), (4,2)，共 3 个，但实际交换次数是 4（交换 3 和 1，交换 3 和 4，交换 4 和 2，交换 3 和 2），代码会输出 3，但正确答案是 4
                count++;
            }
        }
    }
    cout << count;
    return 0;
}