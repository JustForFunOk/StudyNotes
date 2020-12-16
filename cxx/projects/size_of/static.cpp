#include <iostream>
using namespace std;

class A
{
    static int s_a;
};

int main()
{
    A a;
    cout << sizeof(a) << endl;

    static int b;
    cout << sizeof(b) << endl;

    return 0;
}