class Base
{
public:
    virtual ~Base(){};
};

class Derived : public Base
{

};

int main()
{
    Base* base_ptr = new Base();
    Derived* derived_ptr = dynamic_cast<Derived*>(base_ptr);
    delete base_ptr;
    return 0;
}