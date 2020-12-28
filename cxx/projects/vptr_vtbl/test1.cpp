class Base
{
public:
    Base(int i){}
    virtual ~Base(){}
    virtual void func(){}
};

class Derived : public Base
{
public:
    Derived() : Base(1){}
    virtual ~Derived(){}
    virtual void func(){}
};

int main()
{
    Base a(1);
    Derived b;
    return 0;
}