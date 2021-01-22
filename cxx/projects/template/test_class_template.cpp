#include <iostream>

template <typename T1, typename T2>
class Test
{
public:
    Test(){std::cout << "template" << std::endl;}
};

template <typename T1>
class Test<T1, float>
{
public:
    Test(){std::cout << "template part specialization" << std::endl;}
};

template <>
class Test<double, double>
{
public:
    Test(){std::cout << "template specialization" << std::endl;}
};

int main()
{
    Test<int, int> test1;  // template
    Test<int, float> test2;  // template part specialization
    Test<double, double> test3;  // template specialization
    return 0;
}