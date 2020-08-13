#include <iostream>

using namespace std;

class Base
{
  public:
    Base() = default;
    virtual ~Base() = default;
    virtual void doSth(int a = 1)
    {
        cout << "Base" << a << endl;
    }
};

class Derived: public Base
{
  public:
    Derived() = default;
    ~Derived() = default;
    void doSth(int a = 2)
    {
        cout << "Derived" << a << endl;
    }
};

int main()
{
    Base* b = new Derived;
    b->doSth();
    delete b;
    return 0;
}