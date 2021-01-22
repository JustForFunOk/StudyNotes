#include <iostream>


template <typename T1, typename T2>
void test(T1 input1, T2 input2)
{
    std::cout << "template" << std::endl;
}

template <>
void test(float input1, float input2)
{
    std::cout << "template specialization" << std::endl;
}

void test(float input1, float input2)
{
    std::cout << "function" << std::endl;
}


int main()
{
    test(2, 2);  // template
    test(3.3f, 4.4f);  // function
    return 0;
}