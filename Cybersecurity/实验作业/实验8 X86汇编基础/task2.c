#include <stdio.h>

int main() {
    unsigned short stock = 65535; // 16位无符号整数的最大值
    int purchase_count;
    
    printf("当前商品库存: %u\n", stock);
    printf("请输入你要买的数量（请输入 1）: ");
    scanf("%d", &purchase_count);
    
    stock = stock + purchase_count; 
    
    printf("购买后的新库存为: %u\n", stock);
    
    if (stock == 0) {
        printf("警告：库存清零！由于系统漏洞，你触发了免费赠送机制！\n");
    }
    
    return 0;
}
