#include <iostream>

using namespace std;

namespace test_name_mangling
{
void print_hello_world()
{
    std::cout << "Hello World!" << std::endl;
}

int cal_sum(int a, int b)
{
    return (a+b);
}
}

int main()
{
    test_name_mangling::print_hello_world();
    test_name_mangling::cal_sum(1, 2);
}