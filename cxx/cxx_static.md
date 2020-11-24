# static

C语言中

* 修饰全局变量

  未被static修饰的全局变量本身具有外链性/外延性 external link

  被static修饰的全局变量，作用域仅限于本文件

* 修饰局部变量

  生命周期 和整个进程的生命周期一样

  储存位置

* 修饰函数

  ``` c
  static void MX_TIM2_Init(void)
  {
      //...
  }
  ```
  普通函数默认情况下是extern的，但静态函数只在本文件中可见。因此定义静态函数有以下好处：
  * 其他文件中可以定义相同名字的函数，不会发生冲突。
  * 静态函数不能被其他文件所用。

C++类中

1. 类的静态成员(变量和方法)属于类本身
   在类加载的时候就会分配内存，当对象不存在时可以通过类来访问
2. 类的非静态成员（变量和方法）属于类的对象
   所以只有在类的对象产生（创建类的实例）时才会分配内存，然后通过类的对象（实例）去访问。

* static修饰数据成员

  用来实现同簇类对象间的数据共享。

  在生成对象的时候，普通数据成员才有空间。而static成员在类声明的时候就已经开辟了空间，储存在data区rw段。

  static 成员类外储存，求类大小时并不包含在内。

  初始化：类内定义，类外初始化。type 类名:: 变量名 = 初始值；必须初始化，且只能在类外初始化。

* static修饰成员函数

  static修饰成员函数，作用就是管理静态成员，以对外提供接口。

  static修饰的成员函数属于类本身。

  static成员函数只能访问static数据成员以及成员函数。因为非static成员函数在调用时this指针被当作参数传入，而static成员函数属于类，不属于对象，没有this指针。

``` c++
class A
{
public:
    int x, y;
    static int share;
    static int& getPrivateShare()
    {
//      x = 222; //static成员函数不能访问非static数据成员以及成员函数
        return privateShare;
    }
private:
    static int privateShare; // 私有成员只能通过公有成员函数来访问，static也不例外
}；
//static数据成员初始化
int A::share = 100; // 类内定义，类外初始化
int A::privateShare = 1000;

int main
{
	cout << A::share << endl; // 当对象不存在时可以通过类来访问static数据成员
//	cout << A::x << endl; //而非static的就会报错 invalid use of non-static data member 'A::x'
	cout << A::getPrivateShare() << endl;
	A::getPrivateShare() = 2000; // 因为是引用，所以可以被赋值

	A a1, a2;
	cout << sizeof(A) << endl;  // 8 // static成员类外储存，求类大小时不包含在内
    cout << sizeof(a1) << endl; // 8
    cout << sizeof(a2) << endl; // 8

	// static数据成员在族类对象间数据共享
	a1.share = 200;
	cout << a2.share << endl; // 200



}
```


### 参考
1. https://blog.csdn.net/yesyes120/article/details/79519753
