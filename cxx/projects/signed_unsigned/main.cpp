#include "stdio.h"

int main()
{
    char a = -1;
    printf("char a = -1 --> a = %x\n", a);

    unsigned short b = a;
    printf("unsigned short b = a --> b = %x\n", b);
    return 0;
}