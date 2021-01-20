#include <iostream>

class A
{
    char a;
    char& ref_a = a;
};

int main()
{
    std::cout << sizeof(A) << std::endl;
    return 0;
}