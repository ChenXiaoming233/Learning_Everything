#include <stdio.h>


int main(){
    int cnt=1;
    int n=0;
    double sum=0;
    printf("请输入数字的数量");
    scanf("%d",&n);
    int numbers[n];
    if(cnt>2){
    int x=0;
            printf("请输入第%d个数字",cnt);
            scanf("%d",x);
        while(cnt<n){
            
            numbers[cnt]=x;
            cnt++;
        }
    }
    else{
        printf("请输入第1个数字");
        scanf("%d",&);
        numbers[0]=x;
    }
        
    
    return 0;
}WXQCEFZ2