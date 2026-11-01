#include <stdio.h>

int main(void)
{
    char name[40];
    float height_inches;
    float height_feet;

    printf("Name: ");
    scanf("%39s", name);
    printf("Height (inch): ");
    scanf("%f", &height_inches);

    height_feet = height_inches / 12.0f; // 12 英寸 = 1 英尺

    printf("%s, you are %.3f feet tall\n", name, height_feet);

    return 0;
}
