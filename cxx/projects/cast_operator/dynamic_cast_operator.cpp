#include <iostream>
class Base
{
public:
    virtual ~Base(){};
};

class Derived : public Base
{

};

class Derived1 : public Derived
{
    // void func();
};

int main()
{
    Base* base_ptr = new Derived();
    if(dynamic_cast<Derived1*>(base_ptr) == nullptr)
    {
        std::cout << "failure";
    }
    // Derived1* derived_ptr = ;
    delete base_ptr;
    return 0;
}