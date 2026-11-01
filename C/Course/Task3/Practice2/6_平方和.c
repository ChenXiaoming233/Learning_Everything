#include <stdio.h>

int main(void)
{
    int days;
    int count = 0;
    int sum = 0;

    printf("Days: ");
    scanf("%d", &days);

    while (count < days)
    {
        count++;
        sum += count * count;
    }
    printf("Square sum for 1..%d: %d\n",
           days, sum);

    return 0;
}
