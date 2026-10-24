#include <stdio.h>
#include <limits.h>

int main(void) {
    unsigned int stock = 65535; // 16位无符号整数的最大值
    int purchase_count;

    printf("当前商品库存: %u\n", stock);
    printf("请输入你要买的数量（请输入 1）: ");
    scanf("%d", &purchase_count);

    if (purchase_count != 1 || purchase_count < 0) {
        puts("输入无效。");
        return 1;
    }

    if ((unsigned int)purchase_count > UINT_MAX - stock) {
        puts("购买数量过大，操作已取消。");
        return 1;
    }

    stock = (unsigned int)stock + purchase_count; 
    
    printf("购买后的新库存为: %u\n", stock);
    
    if (stock == 0) {
        printf("警告：库存清零！由于系统漏洞，你触发了免费赠送机制！\n");
    }
    
    return 0;
}
