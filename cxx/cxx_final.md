# 关键字final


## 用法

### 修饰类
``` C++
struct A final { };
struct B : A { }; // 错误！不能继承被final修饰的
```

### 修饰函数
``` C++
struct C
{
    virtual void f() final {} // final 函数
};

struct D : C
{
    virtual void f() {} // 错误，不能override被final修饰的函数
};
```