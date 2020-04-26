#include <iostream>

using namespace std;

class NoVirtualBase
{
    void print()
    {
        cout << "NoVirtualBase" << endl;
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

int main()
{
    NoVirtualBase no_virtual_base;
    cout << "the sizeof NoVirtualBase class : "<< sizeof(no_virtual_base) << endl;

    Base base;
    cout << "the sizeof Base class : "<< sizeof(base) << endl;

    Derive derive;
    cout << "the sizeof Derive class : "<< sizeof(derive) << endl;

    return 0;
}