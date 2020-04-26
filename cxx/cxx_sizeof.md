# size_of

## 类

### 空类

``` c++
class EmptyClass
{};

EmptyClass empty_class1, empty_class2;

cout << "the size of Empty Class = " << sizeof(EmptyClass) << endl;

cout << "the address of empty_class1 = " << &empty_class1 << endl;
cout << "the address of empty_class2 = " << &empty_class2 << endl;

---Output---
the size of Empty Class = 1
the address of empty_class1 = 0x7fff49b1aa86
the address of empty_class2 = 0x7fff49b1aa87
```

这里说的空类，指类里无非静态成员变量，只有成员函数。

空类的大小为1， 因为标准规定完整对象的大小为正数，不同的对象需要不同的地址来表示。