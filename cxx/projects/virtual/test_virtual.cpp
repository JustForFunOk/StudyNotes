#include <iostream>

using namespace std;

class NoVirtualBase
{
  public:
    void print()
    {
        cout << "NoVirtualBase" << endl;
    }

    void printNumber(int a)
    {
        cout << "NoVirtualBase" << a << endl;
    }
};

class Base
{
    virtual void print()
    {
        cout << "Base" << endl;
    }
};

class Derive : public Base
{
    virtual void print() override
    {
        cout << "Derive" << endl;
    }
};

class NoVirtualDerive : public NoVirtualBase
{
  public:
    void print()
    {
        cout << "NoVirtualDerive" << endl;
    }

    void printNumber(int a, int b)
    {
        cout << "NoVirtualDerive " << a << "," << b << endl;
    }
};

int main()
{
    // test sizeof
    NoVirtualBase no_virtual_base;
    cout << "the sizeof NoVirtualBase class : "<< sizeof(no_virtual_base) << endl;

    Base base;
    cout << "the sizeof Base class : "<< sizeof(base) << endl;

    Derive derive;
    cout << "the sizeof Derive class : "<< sizeof(derive) << endl;

    // test same function in no virtual base class
    no_virtual_base.print();

    NoVirtualDerive no_virtual_derive;
    no_virtual_derive.print();

    NoVirtualBase* no_virtual_base_pointer = new NoVirtualDerive;
    no_virtual_base_pointer->print();
    delete no_virtual_base_pointer;

    // test overload across base and derived class
    // no_virtual_derive.printNumber(2);  // no matching function for call to ‘NoVirtualDerive::printNumber(int)’
    no_virtual_derive.NoVirtualBase::printNumber(2);  // name hiding
    no_virtual_derive.printNumber(2, 3);
    no_virtual_derive.NoVirtualDerive::printNumber(2, 3);


    return 0;
}