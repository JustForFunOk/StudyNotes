# 函数重载function overloading

## 形成函数重载的条件

函数名相同，参数列表不同。

（不严谨的说法）函数名相同，形参数量不同，形参类型不同，形参顺序不同。

返回值不同不能构成函数重载。

## 原理

名字重整（name mangling）


## 几个问题

### 函数重载可以发生在子类和父类之间吗？

不能。通过子类对象调用父类函数时会提示函数未定义。

这个应该不叫函数重载。可以通过显式的指定类名来调用父类函数。

name hiding.

``` c++
class NoVirtualBase
{
  public:
    void printNumber(int a)
    {
        cout << "NoVirtualBase" << a << endl;
    }
};

class NoVirtualDerive : public NoVirtualBase
{
  public:
    void printNumber(int a, int b)
    {
        cout << "NoVirtualDerive " << a << "," << b << endl;
    }
};

// no matching function for call to ‘NoVirtualDerive::printNumber(int)’
// no_virtual_derive.printNumber(2);  // error

no_virtual_derive.NoVirtualBase::printNumber(2);

no_virtual_derive.printNumber(2, 3);  // name hiding
no_virtual_derive.NoVirtualDerive::printNumber(2, 3);
```


### 子类和父类中可以有相同的函数（非virtual）吗？调用时会调用哪个？

可以。不会冲突。子类对象就调用子类中的函数，父类对象就会调用父类中的函数。