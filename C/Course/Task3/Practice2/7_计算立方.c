#include <stdio.h>

void show_cube(double value);

int main(void)
{
    double value;

    printf("Number: ");
    scanf("%lf", &value);
    show_cube(value);

    return 0;
}

void show_cube(double value)
{
    printf("%.2f cubed: %.2f\n", value, value * value * value);
}
