#include <iostream>

using namespace std;

class EmptyClass
{

};

int main()
{
    EmptyClass empty_class1, empty_class2;
    cout << "the size of Empty Class = " << sizeof(EmptyClass) << endl;
    cout << "the size of empty class1 = " << sizeof(empty_class1) << endl;
    cout << "the size of empty class2 = " << sizeof(empty_class2) << endl;

    cout << "the address of empty_class1 = " << &empty_class1 << endl;
    cout << "the address of empty_class2 = " << &empty_class2 << endl;

}