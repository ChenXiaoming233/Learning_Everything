#include <stdio.h>
#include <string.h>

int main(void)
{
    char first_name[20];
    char last_name[20];
    int firstL;
    int lastL;

    printf("First name: ");
    scanf("%19s", first_name);
    printf("Last name: ");
    scanf("%19s", last_name);

    firstL = (int)strlen(first_name);
    lastL = (int)strlen(last_name);

    printf("%s %s\n", first_name, last_name);

    // 字母数分别与名和姓的结尾对齐
    printf("%*d %*d\n",
           firstL, firstL,
           lastL, lastL);

    // 字母数分别与名和姓的开头对齐
    printf("%-*d %-*d\n",
           firstL, firstL,
           lastL, lastL);

    return 0;
}
