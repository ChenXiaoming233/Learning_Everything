#include <stdio.h>

#define LPG 3.785 // 升 / 加仑 = 3.785
#define KPM 1.609 // 公里 / 英里 = 1.609

int main(void)
{
    double ms; // 路程
    double gs; // 油耗
    double mpg; // 英里/加仑
    double kms; // 路程 (km)
    double ls; // 油耗 (L)
    double lp100; // 百公里油耗

    printf("Miles traveled (mile): ");
    scanf("%lf", &ms);
    printf("Gas used (gallon): ");
    scanf("%lf", &gs);

    mpg = ms / gs;

    // 换算总耗油与里程，再计算百公里油耗
    ls = gs * LPG;
    kms = ms * KPM;
    lp100 = ls / kms * 100.0;

    printf("ms per gallon: %.1f\n", mpg);
    printf("ls per 100 km: %.1f\n", lp100);

    return 0;
}
