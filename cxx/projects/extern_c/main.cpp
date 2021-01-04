#include "c_lib.h"  // 
#include <stdio.h>

// same function name, the symbol name is sumTwoInt, and use this function not the function in .so
int sumTwoInt(int a, int b)
{
    return a-b;
}

float sumTwoFloat(float a, float b)
{
    return a+b;
}

int main()
{
    int sum = sumTwoInt(1, 2);
    printf("sum = %d\n", sum);
    float sum_float = sumTwoFloat(1.0, 2.0);
    printf("sum_float = %f\n", sum_float);
    return 0;
}