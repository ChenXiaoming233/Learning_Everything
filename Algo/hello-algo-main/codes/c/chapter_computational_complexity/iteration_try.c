#include <stdio.h>

int forLoopII(int n){
    int res = 0;
    int i = 1; // 初始化条件变量
    // 循环求和 1, 4, 10, ...
    for (i = 1; i <= n; i++) {
        res += i;
        // 更新条件变量
        i++;
        i *= 2;
    }
    return res;
}

int main(){
    int n;
    printf("请输入一个n值:\n");
    scanf("%d", &n);
    printf("一个结果是%d\n",forLoopII(n));
    return 0;
}