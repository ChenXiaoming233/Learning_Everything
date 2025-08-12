//烂了 如烂 换用while尝试实践
#include <stdio.h>

int main() {
    int number = 0;
    printf("需要求平均数的数的数\n");
    scanf("%d",&number);
    double total = 0.0;

    for(int i=0; i<number; i++){
        double temp = 0.0;
        printf("请输入第 %d 个数\n",i+1);
        scanf("%lf",&temp);
        printf("%lf",temp);
        total = temp + total;
        printf("%lf",total);//ATTENTION: 格式说明符与变量类型的匹配很重要！！
    }

    double avrg = total/number;
    printf("平均数是%lf\n",avrg);
}