#include <stdio.h>

#define CM_PER_INCH 2.54f
#define INCHES_PER_FOOT 12.0f

int main(void)
{
    float height_cm;
    float total_inches;
    int feet;
    float inches;

    printf("Height (cm): ");
    while (scanf("%f", &height_cm) == 1 && height_cm > 0)
    {
        // 先换算为总英寸，再拆分为英尺和小数英寸
        total_inches = height_cm / CM_PER_INCH;
        feet = (int)(total_inches / INCHES_PER_FOOT);
        inches = total_inches - feet * INCHES_PER_FOOT;
        printf("%.1f cm = %d ft %.1f in\n",
               height_cm, feet, inches);
        printf("Height (cm, <=0 to quit): ");
    }
    printf("Bye\n");

    return 0;
}
