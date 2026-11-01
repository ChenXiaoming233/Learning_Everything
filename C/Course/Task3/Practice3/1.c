#include <stdio.h>
#include <string.h>

#define PRAISE "What a super marvelous name!"

int main(void)
{
    char name[40];

    printf("What's your name?\n");
    scanf("%39s", name);

    printf("Hello, %s. %s\n", name, PRAISE);
    // 修改：长度值转换为 int 后使用 %d，避免 size_t 格式不匹配
    printf("Your name of %d letters occupies %d memory cells.\n",
           (int)strlen(name), (int)sizeof name);
    printf("The phrase of praise has %d letters ", (int)strlen(PRAISE));
    printf("and occupies %d memory cells.\n", (int)sizeof PRAISE);

    return 0;
}
