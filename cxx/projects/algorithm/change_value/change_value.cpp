#include <cstdio>

void pass(void)
{
    int count = 0;
    char* ptr = (char*)&count;

    while(count++ < 100)
    {
        if(*(++ptr) == 123)
        {
            ptr++;
            short int* handle = (short int*)ptr;
            *(handle) = 456;
        }
    }
}

int main()
{
    int x;
    x = 123;
    printf("%d\n", x);
    pass();
    printf("%d\n", x);
    return 0;
}