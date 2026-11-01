#include <stdio.h>
#include <string.h>

int main(void)
{
    char first[20];
    char last[20];

    printf("名: ");
    scanf("%19s", first);
    printf("姓: ");
    scanf("%19s", last);

    printf("\"%s,%s\"\n", first, last);
    printf("\"%20s,%20s\"\n", first, last);
    printf("\"%-20s,%-20s\"\n", first, last);

    // 字段宽度分别比自身字符数多 3
    printf("%*s%*s\n",
           (int)strlen(first) + 3, first,
           (int)strlen(last) + 3, last);

    return 0;
}
