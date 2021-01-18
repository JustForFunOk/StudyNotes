#include <stdio.h>
int my_max(int x, int y)
{
    return x > y ? x : y;
}

int main()
{
    // declare function pointer
    int (*fn)(int, int); 

    // initialize
    fn = &my_max;  // method1 
    fn = my_max;   // method2 

    // declare and initialize together
//  int (*fn)(int, int) = &my_max;

    // use
    printf("my_max(2,4)=%d\n", my_max(2, 4));
    printf("(*fn)(2, 4)=%d\n",  (*fn)(2, 4));
    printf("fn(2, 4)=%d\n",        fn(2, 4));
    
    return 0;
}