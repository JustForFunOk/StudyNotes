# override

override 确保该函数为虚函数并覆盖某个基类中的虚函数。

* C++11新增关键字
* override并不是必要的，使用它只是让编译器帮我们检查错误
  * 通过添加override关键字，可以检查想要override却没有override的错误
  * ？不能检查不想override，却override的错误，这时候没有使用override

## 使用方法

``` c++
struct A
{
    virtual void foo();
    void bar();
};
 
struct B : A
{
    void foo() const override; // 错误。本意是overrideA中的foo，但是却声明为const，与A中不同，编译失败
    void foo() override; // 正确
    void bar() override; // 错误。本意是overrideA中的bar，但是A中的bar不是虚函数不能被override
};

```


## 几个问题

### override和virtual有什么关系？


### 子类override父类中的虚函数，那么子类中该函数也叫虚函数吗？

如果是，那意思是虚函数无论怎么被override，都一直会是虚函数？用final来结束？


### 解决不了这种情况吧？

``` C++
struct A1
{
    virtual void f() {}
};

struct B1 : A1
{
    void f() {}  // 本意是想写个新函数f，但是却与A1中的虚函数重名了，导致其override了A1中的f函数。这时本来就不会使用override关键字，编译器也不会报错
};
```

## Reference

1. [cppreference.com -- override 说明符](https://zh.cppreference.com/mwiki/index.php?title=cpp/language/override&variant=zh)