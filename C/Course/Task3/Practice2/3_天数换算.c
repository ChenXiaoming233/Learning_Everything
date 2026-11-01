#include <stdio.h>

#define DAYS_PER_WEEK 7

int main(void)
{
    int days;
    int weeks;
    int remaining;

    printf("Days: ");
    while (scanf("%d", &days) == 1 && days > 0)
    {
        // 商为周数，余数为不足一周的天数
        weeks = days / DAYS_PER_WEEK;
        remaining = days % DAYS_PER_WEEK;
        printf("%d days = %d weeks %d days\n",
               days, weeks, remaining);
        printf("Days: ");
    }

    return 0;
}
