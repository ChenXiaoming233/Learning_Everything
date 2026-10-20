#include <stdio.h>

int main(void)
{
    char ch;
    int i;
    float f;
    double d;

    printf("%zu %zu %zu %zu\n", sizeof(ch), sizeof(i), sizeof(f), sizeof(d));
    printf("%zu %zu %zu\n", sizeof(ch/i), sizeof(f*d), sizeof(f+i));
    printf("%zu\n", sizeof(ch/i + f*d - (f+i)));

    return 0;
}
