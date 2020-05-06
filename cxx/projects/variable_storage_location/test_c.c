#include <stdio.h>
#include <stdlib.h>

int global_1;
int global_2;

char* global_init_1 = "Hello";
char* global_init_2 = "Hello";

const int const_1 = 6;

int main()
{
    static int static_1;
    static int static_2;

    int local_1;
    int local_init_1 = 0;
    int local_2;
    int local_init_2 = 0;

    int* heap_1 = (int*)malloc(32);
    int* heap_2 = (int*)malloc(32);

    const int const_2 = 9;

    printf("&heap_2       :0x%08X\n", &heap_2);
    printf("&heap_1       :0x%08X\n", &heap_1);
    printf("const_2       :0x%08X\n", &const_2);
    printf("local_init_2  :0x%08X\n", &local_init_2);
    printf("local_2       :0x%08X\n", &local_2);
    printf("local_init_1  :0x%08X\n", &local_init_1);
    printf("local_1       :0x%08X\n", &local_1);
    printf("--------^stack^---------\n");
    printf("heap_2        :0x%08X\n", heap_2);
    printf("heap_1        :0x%08X\n", heap_1);
    printf("---------^heap^---------\n");
    printf("global_2      :0x%08X\n", &global_2);
    printf("global_1      :0x%08X\n", &global_1);
    printf("static_2      :0x%08X\n", &static_2);
    printf("static_1      :0x%08X\n", &static_1);
    printf("----------^bss^---------\n");
    printf("&global_init_2:0x%08X\n", &global_init_2);
    printf("&global_init_1:0x%08X\n", &global_init_1);
    printf("---------^data^---------\n");
    printf("const_1       :0x%08X\n", &const_1);
    printf(" global_init_1:0x%08X\n", global_init_1);
    printf(" global_init_2:0x%08X\n", global_init_2);
    printf("---------^text^---------\n");

    // cout << "global_1:" << &global_1 << endl;
    // cout << "global_2:" << &global_2 << endl;
    // cout << "static_1:" << &static_1 << endl;
    // cout << "static_2:" << &static_2 << endl;
    // cout << "global_init_1:" << &global_init_1 << endl;
    // cout << "global_init_2:" << &global_init_2 << endl;
    // cout << "local_1:" << &local_1 << endl;
    // cout << "local_2:" << &local_2 << endl;


    return 0;
}


// class FUck
// {

//     public:
//     FUck()
//     {}
// };

// FUck fck;
// class Fuck2
// {
// Fuck2()
// {
//     fck;
// }
// }

// Fuck2 fck2;