#include<stdio.h>
int main(){
    int s,v,t,T;
    scanf("%d%d",&s,&v);
    t=s/v + 11;
    T=60 - t;
    printf("7:%d",T);
    
    return 0;
}