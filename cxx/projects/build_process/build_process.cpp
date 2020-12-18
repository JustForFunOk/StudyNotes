#include <cstdio>

#define PI 3.1415
#define NAME(n) hello##n

int main()
{
    double NAME(1) = PI;
    printf("%lf", NAME(1));
    return 0;
}