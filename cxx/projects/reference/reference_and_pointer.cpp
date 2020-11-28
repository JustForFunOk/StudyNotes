#include <iostream>

using namespace std;

class Test
{
    int a;
    int* ptr_a;
    int& ref_a;
};

int main()
{
    int a = 66;
    int& ref_a = a;
    int* ptr_a = &a;
    cout << &ref_a << endl;
    cout << ptr_a << endl;
    cout << sizeof(Test) << endl;  // why 24

    int& ref_ref_a = ref_a;
    int** ptr_ptr_a = &ptr_a;
    cout << &ref_ref_a << endl;
    cout << ptr_ptr_a << endl;
    return 0;
}