#include <stdio.h>
class A
{
public:
    void func()
    {
        printf("func\n");
    }
    void func() const 
    {
        printf("const func\n");
    }

    void foo(int& i)
    {
        printf("foo %d", i);
    }

    void foo(const int& i)
    {
        printf("foo const %d", i);
    }

    void fooo(int* i)
    {
        printf("fooo %d", *i);
    }

    void fooo(const int* i)
    {
        printf("fooo const %d", *i);
    }
};

int main()
{
    A a;
    const A const_a;
    a.func();
    const_a.func();

    int ii = 66;
    a.foo(ii);
    a.fooo(&ii);
    const int jj = 88;
    a.foo(jj);
    a.fooo(&jj);
    return 0;
}