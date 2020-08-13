# C++关键字 -- virtual（动多态）

函数重载（function overloading）是静多态，在编译时就通过名字重整（name mangling）实现了。

而函数重写（function overriding）是动多态，使用`virtual`关键字来实现。

## 1. 动多态形成的条件

1. 父类中有虚函数
2. 子类中重写了父类的虚函数
3. 将子类对象地址赋给父类指针，并发生虚函数的调用

ps: 子类中override函数的访问权限（public, protected, private）可以与父类不同.

## 2. 原理

在类的起始有虚表指针。所以sizeof(空类)＝１，sizeof(含虚函数的空类)＝８。其中８即为虚表指针的大小。



## 3. 应用场景

### 3.1 虚函数
### 3.2 纯虚函数
### 3.3 虚继承


## 4. sizeof


## 5. 几个疑问

### 析构函数前的virtual有什么用？一定需要吗？

不一定需要，但如果该类作为基类，则析构函数前加上virtual。
这时为了一个基类的指针删除一个派生类的对象时，派生类的析构函数会被调用。否则派生类的析构不会被调用，造成内存泄露。

参考：[C++中虚析构函数的作用及其原理分析](https://blog.csdn.net/weicao1990/article/details/81911341)

### 子类中override基类中虚函数的行为叫什么？


### 子类中函数名可以和基类中非虚函数名相同吗？


## 6. Reference

1. [名字修饰](https://zh.wikipedia.org/wiki/%E5%90%8D%E5%AD%97%E4%BF%AE%E9%A5%B0)