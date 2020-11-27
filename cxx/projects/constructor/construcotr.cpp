#include <iostream>
using namespace std;
class A
{
public:
    A()
    {
        cout << "constr" << endl;
    }
    A(const A&)
    {
        cout << "copy const" << endl;
    }
    A& operator=(const A&)
    {
        cout << "copy oper" << endl;
    }
};

int main()
{
    A a[3];
    for(int i =0; i < 3; ++i)
        a[i] = A();
    return 0;
}

/* Output
constr
constr
constr
constr
copy oper
constr
copy oper
constr
copy oper
*/