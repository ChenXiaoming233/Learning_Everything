#include <stdio.h>

void Temperatures(double fahrenheit);

int main(void)
{
    double fahrenheit;

    printf("Fahrenheit (q to quit): ");
    while (scanf("%lf", &fahrenheit) == 1)
    {
        Temperatures(fahrenheit);
        printf("Fahrenheit (q to quit): ");
    }
    printf("Bye\n");

    return 0;
}

void Temperatures(double fahrenheit)
{
    const double FIVE_NINE = 5.0 / 9.0;
    double celsius = FIVE_NINE * (fahrenheit - 32.0);
    // 摄氏温度加 273.16 得到开尔文温度
    double kelvin = celsius + 273.16;

    printf("Fahrenheit: %.2f\n", fahrenheit);
    printf("Celsius: %.2f\n", celsius);
    printf("Kelvin: %.2f\n", kelvin);
}
