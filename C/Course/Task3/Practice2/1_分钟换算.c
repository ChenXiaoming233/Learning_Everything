#include <stdio.h>

#define MINUTES_PER_HOUR 60

int main(void)
{
    int minutes;
    int hours;
    int remaining;

    printf("Minutes: ");
    while (scanf("%d", &minutes) == 1 && minutes > 0)
    {
        // 商为小时数，余数为剩余分钟数
        hours = minutes / MINUTES_PER_HOUR;
        remaining = minutes % MINUTES_PER_HOUR;
        printf("%d minutes = %d hours %d minutes\n",
               minutes, hours, remaining);
        printf("Minutes: ");
    }

    return 0;
}
