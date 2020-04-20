# C++关键字 -- virtual（动多态）

函数重载（function overloading）是静多态，在编译时就通过名字重整（name mangling）实现了。

而函数重写（function overriding）是动多态，使用`virtual`关键字来实现。

## 1. 动多态形成的条件

1. 父类中有虚函数
2. 子类中重写了父类的虚函数
3. 将子类对象地址赋给父类指针，并发生虚函数的调用

ps: 子类中override函数的访问权限（public, protected, private）可以与父类不同.

## 2. 原理

在类的起始有虚表指针。


## 3. 应用场景

### 3.1 虚函数
### 3.2 纯虚函数
### 3.3 虚继承


## 4. sizeof


## 5. 几个疑问

### 析构函数前的virtual有什么用？一定需要吗？


### 子类中override基类中虚函数的行为叫什么？


### 子类中函数名可以和基类中非虚函数名相同吗？


## 6. Reference

1. [名字修饰](https://zh.wikipedia.org/wiki/%E5%90%8D%E5%AD%97%E4%BF%AE%E9%A5%B0)