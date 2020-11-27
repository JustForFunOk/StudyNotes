#include <iostream>

using namespace std;

class Base
{
public:
    virtual ~Base()
    {
        cout << "Base::~Base()" << endl;
    }
    virtual void func1()
    {
        cout << "Base::func1()" << endl;
    }
    void func2()
    {
        cout << "Base::func2()" << endl;
    }
    void func3()
    {
        cout << "Base::func3()" << endl;
    }

};

class Derived : public Base
{
public:
    ~Derived()
    {
        cout << "Derived::~Derived()" << endl;
    }
    virtual void func1()
    {
        cout << "Derived::func1()" << endl;
    }
    void func2() // 条款36:绝不重新定义继承而来的非虚函数,会导致不同的运行结果
    {
        cout << "Derived::fun2()" << endl;
    }
    void func4()
    {
        cout << "Derived::fun4()" << endl;
    }
};

int main()
{
    Base* base_ptr = new Derived();
    // Derived::func1()
    base_ptr->func1();
    // Base::func2()
    base_ptr->func2(); // base_ptr只知道自己func2()函数的地址, derived中func2的地址其无法索引,所以这里调用的是Base::func2
    // 但是实例化的不是Derived吗,Base只是一个指针,怎么调用Base中的东西? Derived继承了Base,所以包含Base中的所有的元素.
    // Base::func3()
    base_ptr->func3();
//  base_ptr->func4(); func4是Derived特有的,对Base不可见.

    delete base_ptr;
    return 0;
}