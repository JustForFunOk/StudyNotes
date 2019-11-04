---
title: Cplusplus Study Notes
date: 2018-06-12 09:10:05
tags:
---



## C知识温习

### 题目

#### 经典指针题目

* 一个整型数（An integer） 

  `int a;`

* 一个指向整型数的指针（ A pointer to an integer）

  `int* a;`

* 一个指向指针的的指针，它指向的指针是指向一个整型数（ A pointer to a pointer to an intege）

  `int** a;`

* 一个有10个整型数的数组（ An array of 10 integers） 

  `int a[10];`

* 一个有10个指针的数组，该指针是指向一个整型数的。（An array of 10 pointers to integers） 

  `int* a[10];`等效于`int* (a[10]);`

* 一个指向有10个整型数数组的指针（ A pointer to an array of 10 integers）

  `int (*a)[10];`

* 一个指向函数的指针，该函数有一个整型参数并返回一个整型数（A pointer to a function that takes an integer as an argument and returns an integer)

  `int (*a)(int);` 

* 一个有10个指针的数组，该指针指向一个函数，该函数有一个整型参数并返回一个整型数（ An array of ten pointers to functions that take an integer argument and return an integer ）

  `int (*a[10])(int);`

#### sizeof

``` c
// 1
// sizeof的实质
// sizeof是关键词，不是函数。而且其优先级要高于算术运算符。知道就行，一般sizeof都配合着()使用。
int a = 1;
float b = 2.0;
int length = sizeof a+b; //sizeof a+b 等价于 (sizeof a)+b 所以length = 6

// 2
// 常量/常量表达式
// 字符、整数默认为int类型，小数默认为double类型。字符串别忘了加上最后的'\0'。
sizeof('a'); //int类型    4  注意：虽然是字符，但是是常量，所以还是占用4byte
sizeof(6);   //int类型    4
sizeof(6.6f); //float类型  4
sizeof(6.6);  //double类型 8
sizeof(2+6.6);//double类型 8
sizeof("china"); //5+1 = 6

// 3
//常用数据类型
sizeof(char); //char 1，short 2，int 4，long 4， long long 8，float 4，double 8

// 4
//引用类型
sizeof(int&); //同int类型 4byte    

// 5
//共同体 占用内存最大的变量所占用的内存
union union_test
{
   int a;
   float b;
};
sizeof(union_test); //float类型 4byte

// 6
//结构体 注意内存对齐
//字节对齐主要是为了提高内存的访问效率
//通过预编译命令#pragma pack(n)来设置对齐系数
//32位编译系统4byte对齐，64位编译系统8byte对齐
//注意：1、结构体中若有数组，数组空间一定连续 2、若结构体为空则为1
struct struct_test
{
    
}
sizeof(struct_test) //

// 7
// 函数 等价于函数返回值的长度
int func_test()
{
    return 0;
}
sizeof(func_test()); //等价于sizeof(int);

//8
// 指针 均是指针自身所占用的空间（32位编译系统指针4byte，64位编译系统指针8byte）
// 字符串指针
char* pc = "china";
sizeof(pc);
// 函数指针
void (*pf)();
sizeof(pf);
// 数组指针
int (*p)[2]; //注意区分数组指针和指针数组
sizeof(p);

// 9
// 数组 返回整个数组占用内存
// 普通数组
char a[10];
sizeof(a); //1x10=10byte
// 指针数组
char *b[10]; //等价于char *(b[10]);
sizeof(b); //32位编译系统，4x10=40
// 特例：形参中的数组 数组作为函数的形参时会自动退化为指针
void test(char c[10])
{
    sizeof(c); //32位编译系统4byte
}
// 特例：对数组名进行运算时，会退化为指针
int d[2][3]={0};
sizeof(d);   //2x3x4=24byte
sizeof(d+1); //32位编译系统为4byte

// 10
// 类 类中的函数不占用空间
// 空类的sizeof为1
// static数据成员所占空间不包含在类内。
```
参考：[盘点SIZEOF操作符考点](https://blog.csdn.net/yijudingyiwanju/article/details/77145438)

### 从源文件到可执行文件经历了什么？

参考自：[【摘录】汇编文件后缀 .s 与 .S](https://www.cnblogs.com/IamEasy_Man/archive/2011/08/10/2134212.html)

预处理（Pre-Processing）-->编译（Compiling）-->汇编（Assembling）-->链接（Linking）

``` bash
$ gcc -E main.c -o main.i
$ gcc -S main.i -o main.s
$ gcc -c main.s -o main.o
$ gcc    main.o -o main
```

main.c（源文件） --> main.i（C文件） --> main.s（汇编文件） --> main.o（二进制文件） --> main（可执行二进制文件）

1. 预处理（Pre-Processing）

   根据以字符#开头的命令（directives），修改原始的C程序。并去除程序中的注释部分。

   这个阶段并**不会去检查代码的错误**，只会把#的语句转成C代码。

2. 编译（Compiling）

   Gcc首先要检查代码的规范性、是否有语法错误等，以确定代码的实际要做的工作，在检查无误后，Gcc把代码翻译成汇编语言

3. 汇编（Assembling）

   汇编阶段是把编译阶段生成的”.s”文件转成”.o”的二进制目标代码。

4. 链接（Linking）

   将库函数（头文件中用到的）等链接到目标文件中。如"stdio.h"中也只有该函数的声明，而没有定义函数的实现，链接就是链接到所用到的库。用编辑器打开main就会发现比main.o多了很多内容。

   完成了链接之后，gcc就可以生成可执行文件。

#### C语言对应的汇编语言

C语言

``` c
#include <stdio.h>
int main(int argc, char *argv[])
{
    int a = 1;
    int b = 2;
    int c = a + b;
    return 0;
}
```

GNU汇编

``` assembly
        3 [1]	{
0x401630                   55                       push   %ebp
0x401631  <+0x0001>        89 e5                    mov    %esp,%ebp
0x401633  <+0x0003>        83 e4 f0                 and    $0xfffffff0,%esp
0x401636  <+0x0006>        83 ec 10                 sub    $0x10,%esp
0x401639  <+0x0009>        e8 92 01 00 00           call   0x4017d0 <__main>
        4 [1]	    int a = 1;
0x40163e  <+0x000e>        c7 44 24 0c 01 00 00 00  movl   $0x1,0xc(%esp)
        5 [1]	    int b = 2;
0x401646  <+0x0016>        c7 44 24 08 02 00 00 00  movl   $0x2,0x8(%esp)
        6 [1]	    int c = a + b;
0x40164e  <+0x001e>        8b 54 24 0c              mov    0xc(%esp),%edx
0x401652  <+0x0022>        8b 44 24 08              mov    0x8(%esp),%eax
0x401656  <+0x0026>        01 d0                    add    %edx,%eax
0x401658  <+0x0028>        89 44 24 04              mov    %eax,0x4(%esp)
        7 [1]	    return 0;
0x40165c  <+0x002c>        b8 00 00 00 00           mov    $0x0,%eax
        8 [1]	}
0x401661  <+0x0031>        c9                       leave
0x401662  <+0x0032>        c3                       ret
```

其中，movx把?位的EAX寄存器值传送?位的EBX寄存器值，x为l时为32位，为w时为16位，为b时为8位。

[汇编语言里 eax, ebx, ecx, edx, esi, edi, ebp, esp这些都是什么意思啊?](https://blog.csdn.net/liquanhai/article/details/5479141)

### 商和余数

``` C
 7 /  3 =  2    7 %  3 =  1
-7 /  3 = -2   -7 %  3 = -1
 7 / -3 = -2    7 % -3 =  1
```

### 命名

字母、数字、下划线，不以数字开头，避讳关键字

#### 关键字

C语言中32个关键字

* 数据类型（11个）

  `char` `short` `int` `long` `float` `double` `auto` `void` `struct` `union` `enum`

* 修饰变量类型（7个）

  `unsigned` `signed` `extern` `static` `const` `volatile` `register`

* 语序（12个）

  `if` `else` `switch` `case` `default` `break` `continue` `do` `while` `for` `return` `goto`

* 计算长度（1个）

  `sizeof`

* 取别名（1个）

  `typedef`

注意：

* `main`不是关键词，可以定义变量`int main;`，但是不推荐这么做。
* `union`有什么实际用途？实现伪多态。[Why do we need C Unions?](https://stackoverflow.com/questions/252552/why-do-we-need-c-unions)
* `volatile`（不稳定的）的作用？[C语言中volatile关键字的作用](https://blog.csdn.net/tigerjibo/article/details/7427366)

### 计算机内存地址

硬件和系统的关系：64位操作系统只能安装在64位电脑上(CPU必须是64位的)。32位操作系统则可以安装在32位(32位CPU)或64位(64位CPU)电脑上。

一般说的32位总线指的是地址总线。

CPU和内存之间：地址线、数据线、控制线（读/写）



#### 疑问

* 32位系统能使用4G以上的内存条吗？
* 64位处理器装32位系统会影响什么？
* 内存条的上限是和处理器位数相关还是和系统位数相关？

### 将10进制数字转换成2进制输出



### 补码

0的补码还是0.

求补码的方法：取反，+1

* 为什么char类型的取值范围是-128-127？

  这是补码的编码规则决定的。



### ASCII

American Standard Code for Information Interchange

需要记住的常用的：

Esc 27

空格32

‘0’ 48

‘A’ 65

‘a’ 97



### 优先级

#### 易错优先级

|          |             | 正确结果                             | 错误结果                                     |
| -------- | ----------- | ------------------------------------ | -------------------------------------------- |
| [ ]高于* | int *a[10]; | int *(a[10]);a是int指针的数组        | int (*a)[10];a是个指向数组的指针             |
| ()高于*  | int *f()    | int*(f()) f是个函数，返回值为int指针 | int(*f)() f是个函数指针，所指函数返回int类型 |
|          |             |                                      |                                              |
|          |             |                                      |                                              |



### 排序

#### 选择排序法

拿第一个的数依次和后面所有的数据进行比较。

``` c
for(i=0;i<n-1;i++)
{
    for(j=i+1;j<n;j++)
    {
        
    }
}    
```

#### 冒泡排序法

### 二维数组

``` c
// 假设有二维数组如下
int arr[3][4];
// 将二维数组理解为 int[4] arr[3] 3个长度为4个int类型的一维数组更好理解
// 起始地址：四个地址的值相同
arr    <--> &arr[0]     这两个等价
arr[0] <--> &arr[0][0]  这两个等价
而这四个地址的值又相等
// 步长：步长不同
// arr[0]理解为3个一维数组中的第1个数组
arr   +1 和 &arr[0]   +1   移动了16个字节
arr[0]+1 和 &arr[0][0]+1   移动了 4个字节
```

一维数组的数组名，是一级指针；二维数组的数组名，是数组指针。

### 指针

指针的本质：**有类型**的地址。类型决定了指针的寻址能力。

``` c
int a = 1;
printf("&a = %p", &a);
// 若上述输出为0x0022ff00，那么&a与0x0022ff00等价吗？不等价！
//&a <--> (int*)0x0022ff00
```



#### void *

无类型指针，为了实现泛型编程，其能接受任意类型的指针变量。如memcpy函数。



### 大端和小端

大小端平时不怎么用的到，在网络编程中需要用到。

``` c
int a = 0x12345678;  //0x12为高字节 0x78为低字节
//	高地址		  小端	大端
//0x00ff0003	0x12	0x78
//0x00ff0002	0x34	0x56
//0x00ff0001	0x56	0x34
//0x00ff0000	0x78	0x12
//	低地址 
int* p = &a; //均是低地址
```

对变量取地址，返回的都是低地址。

小端：**低地址**存放**低字节**数据。小端低低

x86，linux：小端

c51，网络传输：大端

### `#`和`##`

`#`解决了双引号中无法替换问题， `##`解决了非双引号中粘连无法替换的问题。

`##`预处理的粘合剂

``` c
#include <stdio.h>
#define XNAME(n) x##n
#define PRINT_XN(n) printf("x"#n" = %d\n", x##n)
int main()
{
    int XNAME(1) = 14;
    int XNAME(2) = 20;
    printf("x1 = %d,x2 = %d\n",x1,x2);
    PRINT_XN(1); //隐藏了变量的声明和使用 点赞
    PRINT_XN(2);
    return 0;
}
```



### 几个预定义宏

这些预定义宏在早期打印日志的时候很有用，现在被IDE的Debug功能取代了。

`__DATE__` 进行预处理的日期（"MMmm dd yyyy"形式的字符串文字）
`__FILE__` 代表当前源代码文件名的字符串文字
`__LINE__` 代表当前源代码中的行号的整数常量
`__TIME__` 源文件编译时间，格式"hh：mm：ss"
`__func__` 当前所在函数名

``` c
printf( "The file is %s.\n",__FILE__);
printf( "The date is %s.\n",__DATE__);
printf( "The time is %s.\n",__TIME__);
printf( "This is line %d.\n",__LINE__);
printf( "This function is %s.\n",__func__);
```



### 宏定义实现比较大小

``` C++
#define Max(a,b) a>b?a:b
// 比较大小不使用 > < if
#define Min(c,d) (long long)(c-d)&0x8000000000000000?c:d
```







## C++对C的扩展

### 类型增强

C++更严谨了。

#### 类型检查更严格

比如，把一个 const 类型的指针赋给非 const 类型的指针。c 语言中可以通的过，但是
在 c++中则编不过去。

#### 新的类型

**string**

并不算的上是数据类型，其实是个类。

**bool**

在C里可以用枚举来实现。

其大小为1个字节。

#### 真正的枚举

c 语言中枚举本质就是整型，枚举变量可以用任意整型赋值。而C++中只能用被枚举出来的元素初始化。

枚举还可以当作当作宏定义使用。

#### 表达式的值可被赋值

c 语言中表达式通常不能作为左值的，即不可被赋值，c++中某些表达式是可以赋值的。

``` C++
int a,b = 5;
// 以下语句在C中不能编译通过，表达式不可以被赋值
(a = b) = 10; //首先将b的值赋给a，然后再将10赋值给a。最后a=10,b=5
(a < b? a:b) = 200; //三目运算符构成条件表达式。a不小于b，所以将200赋值给b。最后a=10,b=200
// 
a = b = 100; //从右向左，100赋值给了b，整个表达式的值赋值给了a。最后a=100,b=100
int c = (a = 10) + (b = 10); // c最后等于20
// 个例
a++++; //错误
```

上述操作有什么实际应用价值不太明白？

学了运算符重载会懂。

### 输入/输出

cin/cout是类对象，而scanf/sprintf是函数。

scanf使用中输出长度超过了预定义的长度后，程序会崩溃。

`>>`既可表示流输入运算符又可表示移位运算符这就是运算符的重载，具体使用哪种跟语境有关。和cin一起就是表示流输入运算符。

cin>>name; cin相当于键盘，从键盘流到变量name中去

cout<<"name = "<<name<<endl; cout相当于屏幕，先是“name =”流入cout中，然后...

endl 是end line的缩写。

C++中尽量不要用指针、字符数组、强制转换。

``` C++
// 这里无论使用任何输入函数，只要实际输入长度超过了数组长度都不安全
char name[30];
scanf("%s",name);// 这里最多能输入29个字符，最后一个是'/0'
cin>>name;
// C++中用string代替之前在C中使用的字符数组
string s;
cin >> s; //string只能配合cin而不是scanf来用，这样使用接近无限制输入长度
cout << s.max_size() << endl; //可通过成员函数查看最多可输入的长度，电脑中实测可输入2147473647个字符
```

#### 改进

scanf中%d和%c不好一起用

``` C++
//scanf("%d%c",a,b);//这样使用时ab之间不能输入其他东西
//只能这样分开用
scanf("%d",a);
getchar();
scanf("%c",b);
```

#### 格式化输入输出

`#include <iomanip>`

设置宽度`setw()` 只对紧挨着的后面的输出有效

左对齐`setiosflags(ios::left)`

设置小数精度`setprecision()`和`setiosflags(ios::fixed)`

设置输出格式：十六进制`hex`、二进制`oct`、十进制`dec`

设置填充零`setfill('0')` 

例子：

 ``` c
// 用 cout 的格式控制，显示一个时钟，格式 00：00：00
#include <iostream>
#include <iomanip> // setw() setfill()

using namespace std;

typedef unsigned short ushort;
// 储存时间的结构体
struct _time{
    ushort hours;                // 小时 0-23
    ushort minutes;              // 分钟 0-59
    ushort seconds;              // 秒钟 0-59
    long long totalSeconds;     // 从开始经过的秒钟数
}timer;

int main()
{
    timer.totalSeconds = 0;
    while(1)
    {
        // 将总秒数换算成小时：分钟：秒钟格式
        timer.hours = timer.totalSeconds / 3600 % 24;
        timer.minutes = timer.totalSeconds % 3600 / 60;
        timer.seconds = timer.totalSeconds % 3600 % 60;

        system("cls"); // 清除控制台的内容，这样才能做到一直只显示一个时间的效果

        // 按照指定格式显示
        cout << setfill('0') << setw(2) << timer.hours << ":" << setw(2) << timer.minutes << ":" << setw(2) << timer.seconds << endl;

        _sleep(1000); // 延时1s

        timer.totalSeconds++; // 经过的时间加1s
    }
    return 0;
}

 ```

* 如何清除控制台的内容？

  [How can I clear console](https://stackoverflow.com/questions/6486289/how-can-i-clear-console)

  其中提到system()不安全。[Why system() is evil](http://www.cplusplus.com/articles/j3wTURfi/)



### string

string不是关键字，是一个类。

``` c++
string str;
cout << str << endl; //什么也不输出，不是输出空格。
cout << sizeof(str) << endl; //输出为4（不一定），其实是一个char*
// 初始化1
string str1("Hello World!");
// 初始化2
string str2 = "Hello World!";
// 初始化3    
string str3;
str3 = str2; // 赋值运算符重载 
// 初始化4
string str4(str2); //拷贝构造
string str5 = str2; // 拷贝构造
// 等等
```

[string构造器](http://www.cplusplus.com/reference/string/string/string/)有很多种。

string数据结构上的实现原理应该和vector一样，是一个长度可变的一维数组。申请的空间要大于字符串实际长度。

* string中字符串长度，这个长度不包括'\0'：`.size()`

* 实现字符串和字符数之间的拷贝，返回指向string内容的char*：`.c_str()`

  ``` C++
  string s("Hello");
  char buf[1024];
  strcpy(buf, s.c_str()); // 将字符串s的内容拷贝到字符数组buf
  ```

* 两字符串之间内容的交换：`.swap(string)`

* 查找某个字符：`.find( , )`

string类中重载了很多基本运算符，可以当成一个数据类型很方便的操作。如：`+`字符串拼接 `==`字符串比较 `[]`定位字符串中的某位字符 

#### 赋值运算符重载

和拷贝构造器一样，编译器提供默认的。但是是浅赋值，会导致自身内存泄漏，内存自身发生重析构，不能解决自赋值的问题。

注意：这里所说的浅拷贝不能拿已经有的类如string，vector去试，因为其已经做了赋值运算符重载，实现了深拷贝。若要看浅拷贝，要自己写一个新类，然后使用赋值运算符，这时就是浅拷贝。

#### 小疑问

* C++中的string末尾有没有'\0'?

  和C中的字符数组不一样，C++中的字符串没有'\0'

  参考：[Why are strings in C++ usually terminated with '\0'?](https://stackoverflow.com/questions/10943033/why-are-strings-in-c-usually-terminated-with-0)

  补充：`\0`的ASCII是0，相当于NULL

* sizeof(string)到底是多少？

  这个返回的是`char*`类型的长度，这个值跟string中实际放了多少东西无关，存放字符串的地方是从堆中动态申请的。sizeof返回值和编译器有关系，经典结果是4，我在MinGW上测的是24.

**字符串的赋值是什么原理？**

```c++
string sc = "aaa", sd = "bbbbb";
cout << sizeof(sc) << " " << sc << endl;
sc = sd;
cout << sizeof(sc) << " " << sc << endl;
// 输出为：
24 aaa
24 bbbbb
```

疑问1：sc的长度是固定不变的，怎么做到可以储存比自身大的字符串的？

解答：参见《C++ Primer Plus》的p665-p666

C++为字符串分配的内存块比实际字符串的大。

当字符串不断增大超过了内存块的大小，程序将分配一个大小为原来两倍的新内存块。

capacity()返回当前分配给字符串的内存块的大小。

size()返回字符串的长度。

疑问2：string占用的字节长度是固定的？无论string1中存放了什么sizeof(string1)都等于24？如：

```c++
string sd = "bbbbb", se = "ccccccccccccccccccccccccccccccccc";
cout << "sd:" << "capacity->" << sd.capacity() << " address->" << &sd << endl;
cout << "se:" << "capacity->" << se.capacity() << " address->" << &se << endl;
// 输出为：
sd:capacity->15 address->0x61fe48
se:capacity->33 address->0x61fe30
```

0x61fe30到0x61fe48只有24个字节，怎么实现储存大于24个字节的数据的？

解答：不能把C++中的string当作C中的字符数组理解。C++中的string是一个类，sizeof(string)是string实例化后的大小，而string数据并不储存到对象中，而是储存在内存中的另外一个地方并占用capacity()大小的内存，string中有一个指针指向储存数据的地址。所以，使用一个string1所占用的内存大小总共为sizeof(string1)+string1.capacity()字节。可参考：[C++ string类型占几个字节](https://blog.csdn.net/dlutbrucezhang/article/details/9822235)。所以，上面字符串的赋值应该只是对指针赋值了新的地址。



- 不要自己定义swap()这个函数名，系统已经有这个函数了，可以使用Swap()
- 



### this指针





### 函数重载

函数重载（静多态，编译阶段就决定了）：函数名相同，函数参数列表（类型，个数，顺序）不同。返回值类型不能构成重载条件。

* 匹配原则：

  1. 严格匹配，找到则调用

  2. 匹配不到，则通过隐式转换寻求一个匹配。

     隐式转换，如char类型、double类型到int类型的转换。

     注意：C++ 允许，int 到 long 和 double，double 到 int 和 float 隐式类型转换。函数重载时遇到这种情型，如输入的是int但是却有long和double两种参数类型的重载，计算机不知道使用哪一个，则会引起ambiguous二义性，不能编译通过。

知识点：C++中的小数默认为double类型，如1.2，若要float类型则指定为1.2f。

* 重载实现原理

  C++利用 name mangling(倾轧)技术，来改名函数名，区分参数不同的同名函数。
  实现原理：用 v-c-i-f-l-d 表示 void char int float long double 及其引用。

  ``` C++
  void func(char a, int b, double c); //func_cid(char a, int b, double c);
  ```

  name mangling 发生在两个阶段，.cpp 编译阶段，和.h 的声明阶段。 只有两个阶段同时进行，才能匹配调用。    

  若要在C++中不倾轧则使用`extern "C" {}`

  所以，在C++中调用标准C库，不能使用倾轧。但是在C++工程中包含C语言的头文件进行调用时会进行倾轧。一般都是在.c文件中定义函数，在.h文件中调用函数。如标准C库stdio.h中加入了如下片段，这样就能在C++中使用标准C库了。

  ``` C++
  #ifdef __cplusplus
  extern "C" {
  #endif
      
  #ifdef __cplusplus
  }
  #endif 
  ```


### 运算符重载

C++中认为操作符都是函数，而函数是可以重载的（并不是所有的运算符都是可以重载的）。

关键字：`operator`

如重载`+`号运算符，

``` C++
返回值类型 operator+(形参列表)
{
    重载实体；
}
```

#### 不可以重载的运算符

* `.` 成员访问运算符
* `.*`成员指针访问运算符
* `::`域运算符
* `?:`条件运算符，唯一一个三目运算符
* `sizeof`长度运算符，sizeof为关键字

#### 重载方式

分为成员函数重载和友元函数重载

* 所有一元运算符                                                   建议使用成员函数重载
  * 其中 `=` `[]` `()` `->` `->*`                           只能使用成员函数重载
* `+=` `-=` `*=` `/=` `^=` `&=` `!=` `%=` `>>=` `<<=`   建议使用成员函数重载
* 其他二元运算符                                                   建议使用友员函数重载

#### 注意

* 注意返回值是否要`const`或者`引用&`

* 如何重载`&`这样在前面的运算符？

  用于类对象的运算符一般必须重载，但有两个例外，运算符”=“和运算符”&“不
  必用户重载。
  复制运算符”=“可以用于每一个类对象，可以用它在同类对象之间相互赋值。因为系
  统已为每一个新声明的类重载了一个赋值运算符，它的作用是逐个复制类中的数据成员。

  地址运算符&也不必重载，它能返回类对象在内存中的起始地址。

其他总结：参看CSDN上的C++课程。



### 默认参数

规定：形参中，从右向左默认，且中间不能跳跃

调用的时候，实参个数+默认形参参数个数>=形参个数

注意：声明和定义分开时，如在类中默认参数最好只在声明中制定，即只在.h中指定，因为这样用户可以看到。

#### 和函数重载的关系

1个参数或是2个参数的形式，重载和默认参数都是可以实现的，但是不能同时存在。否则编译不通过，存在二义性。

``` C++
void func(int a)
{
    cout << "func(int a)" << endl;
}
void func(int a, int b = 10)
{
    cout << "func(int a, int b = 10)" << endl;
}
// 调用的时候
func(1); //存在二义性，编译不能通过
```

### 引用

先讨论`int a = 500;`中a存放在什么位置？a在哪？

a生成空间，在栈上。a经过编译器编译后变成一段地址，比如

*(int *)0xb0002345 = 500;

a本身是不存在的，编译器把变量编译成机器能看的懂得，a就是一段内存空间的别名，操作a就是操作这段内存空间。

`int& ra = a;`ra就是a的引用

1. 引用是一种声明关系，声明的时候必须要初始化。引用不开辟空间，即ra不占用空间。
2. 此种声明关系，一经声明，不可变更。
3. 可以对引用再次引用。多次引用的结果，多个引用指向同一个变量。
4. 引用要与原类型保持一致

引用的本质，是对指针的再次包装，引用的目的是消除指针。指针可以有引用，不应该有引用的指针。

``` C++
// 可以建立对指针的引用
int *p; // int **pp = &p;
int * & rp = p;
// 但不能建立对引用的引用
int a;
int &ra = a;
int & & rra = ra; // error // 目的是消除指针
// 可以定义指针的指针
int **pp = &p;
// 不能定义引用的指针
int& * p = &ra; // error // 引用就是对指针的包装，不允许再打开它
// 可以定义指针数组
int x, y, z;
int * p[] = {&x, &y, &z}; // 指针数组
// 但不能定义引用数组
int & rp[] = {x, y, z}; //
// 可以定义数组引用
int arr[] = {1, 2, 3, 4, 5};
int (&rarr)[5] = arr;
```

* 常引用

  ``` C++
  const int a = 100;
  const int &ra = a;
  
  
  ```


### new/delete

* new和delete是关键字

* new/delete以及new[]/delete[]要配对使用，不明白原理的情况下不要错乱使用，配对使用准没错。

* 更多详细内容参考：[浅谈 C++ 中的 new/delete 和 new[]/delete[]](https://blog.csdn.net/hazir/article/details/21413833)

   new [] 一个对象数组时，需要保存数组的维度，C++ 的做法是在分配数组空间时**多分配了 4 个字节的大小**，专门保存数组的大小，在 delete [] 时就可以取出这个保存的数，就知道了需要调用析构函数多少次了。



## 指针











### const

``` c++
class A
{
public:
    A(int _constVal2 = 0)
        :constVal2(_constVal2) //可以在参数列表中进行初始化
    {
        
    }
    void dis() const       
    {
        cout << constVal2 << endl; // 可以访问
        cout << x << endl; // 可以访问
        x = 1;   // 错误 const不能修改数据成员
        func1(); // 错误 
        func2(); // 正确 只能访问const成员函数
    }
    void dis()  // 可以构成重载
    {}
    void func1()
    {}
    void func2() const
    {}    
private:
    int x, y;
    const int constVal2;
}；

int main()
{  
    const int constVal1 = 1; // 必须在定义时初始化
//  constVal1 = 2；// 且不能被修改
    
    int a = 1;
    const int * pa = &a; // 指针所指向的地址里存放的值不能修改
    int const * pa = &a; // 同上
    int * const pa = &a; // 指针只能指向该地址
    const int * const pa = &a; // 全部都不能修改
    
    //类对象
    const A a1(1);
    a1.dis(); // 调用的是void dis() const
    A a2(2);
    a2.dis(); // 调用的是void dis()，若其不存在则调用void dis() const    
}
```

#### 形参

一般形参为指针或引用时，配合使用const，以避免子函数内对原值进行了修改。

而正常的形参，不需要加const，因为是对实参的拷贝，加与不加都没有影响。

若形参或实参定义为const，那实参或形参也要定义为const吗？


#### 数据成员

* 数据成员不是类成员变量时，必须在定义时进行初始化。数据成员是累成员变量时还可以在参数列表中进行初始化。
* 被const修饰的数据成员不能被修改。

#### 成员函数

位置：放在函数声明之后，实现体之前。要求在声明和定义处都要有const

意义：const函数保证不会修改数据成员。能访问，但不能修改。函数里也只能调用其它const成员函数。

const修饰成员函数时可以构成重载。

#### 类对象

意义：const修饰对象保证不会修改数据成员。只能调用const成员函数。非const成员对象，优先调用非const成员函数，若无，则可调用const成员函数。



### static

C语言中

* 全局变量

  本身具有外链性/外延性 external link

  被static修饰的全局变量，作用域仅限于本文件

* 局部变量

  生命周期 和整个进程的生命周期一样

  储存位置

C++中

* static修饰数据成员

  用来实现同簇类对象间的数据共享。

  在生成对象的时候，普通数据成员才有空间。而static成员在类声明的时候就已经开辟了空间，储存在data区rw段。

  static 成员类外储存，求类大小时并不包含在内。

  static数据成员，即属于类，也属于对象，但终归属于类。（当对象不存在时可以通过类来访问）

  初始化：类内定义，类外初始化。type 类名:: 变量名 = 初始值；必须初始化，且只能在类外初始化。

* static修饰成员函数

  static修饰成员函数，作用就是管理静态成员，以对外提供接口。

  statci修饰的成员函数，即属于类也属于对象，但终归属于类。

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









## 封装（encapsulation）

* 从C语言中的struct到C++中的类

  C++认为C封装不彻底。

  1. 没有权限控制。比如我们用 struct 封装的类，即知其接口，又可以直接访问其内部数据，这样却没有达到信息隐蔽的功效。而 class 则提供了这样的功能，屏蔽内部数据，对外开放接口。
  2. 数据和行为都是分开的。C中封装数据和行为分开了，数据放到一起打包struct，然后把数据以引用或指针的方式传给行为。

* struct 中所有行为和属性都是 public 的(默认)。C++中的 class 可以指定行为和属性的访问方式，**默认为 pirvate**。若要访问类中的私有变量只能通过函数返回值的形式。bug：可以通过返回私有成员的引用在外部修改私有变量。

### 构造器（constructor）

也就是平时所说的构造函数。

1. 与类名相同，无返回，被系统生成对象自动调用，用于初始化。
2. 可以有参数，所以会涉及构造器的重载，默认参数。重载和默认不能同时存在，但是要包含标配，为了对象的无参创建。
3. 若未提供任何构造器，系统默认生成一个无参空构造器。若提供，则不再生成默认构造器。

``` c++
class Stack{
    // constructor
    Stack(){
        
    }
    // 重载
    Stack(int size){
        
    }
    // 默认参数
    Stack(int size = 1024){
        
    }
    // destructor
    ~Stack(){
        
    }
}
// 无参
Stack st; //Stack st();会与C语言中的函数声明冲突，所以没有()
```

#### 参数初始化表

：

#### 拷贝构造器

``` c++
class A
{
    A() //构造器
    {}
    A(const A & another) // 拷贝构造器
    {
        // 申请空间
        // 赋值操作
    }
}

class B
{
    B() // 构造器
    {}
}

A a1;
A a2(a1); // 深拷贝
B b1;
B b2(b1); // 不会报错，使用系统实现的浅拷贝
```

注意：

1. 系统提供了默认的拷贝构造器，但是是浅拷贝。
2. 若要实现深拷贝就要自己定义。
3. 因为const A & another中const，所以只能访问another中const成员函数。

总结：如果类中使用了在堆中申请动态内存，那么使用浅拷贝就会导致重复析构，在某些平台上会报错，所以这时一定要自定义拷贝构造器。



### 析构器（destructor）

与类名相同，无参，无返回，对象消失的时候自动被调用



### string的构造器



## 继承

``` c++
class A : public B
{

};
```

A称为B的基类或父类

B称为A的派生类或子类

A继承自B，B派生出了A

### 访问权限

public:可以被任意实体访问

protected:只允许子类及本类的成员函数访问

private:只允许本类的成员函数访问

| 继承方式      | 基类-->派生类        | 基类-->派生类           | 基类-->派生类            |
| ------------- | -------------------- | ----------------------- | ------------------------ |
| public继承    | public --> public    | protected --> protected | private --> 子类不可访问 |
| protected继承 | public --> protected | protected --> protected | private --> 子类不可访问 |
| private继承   | public --> private   | protected --> private   | private --> 子类不可访问 |



### 注意点

* 与C中的struct不一样，C++中struct中可以包含函数，也可以和class一样可以继承。唯一不同的是，默认的继承访问权限。（实例：stl中的stl_vector.h中就用到了类继承结构体）（参考：[C++ Struct 也可以继承](https://blog.csdn.net/u012422855/article/details/58148133)）

## 模板

定义：模板是一种使用**无类型参数**来产生一系列函数或类的机制，是C++的一个重要特征。

实质：参数化类型。

概念：泛型，允许程序员在强类型程序设计语言中编写代码时定义一些可变部分，那些部分在使用前必须作出指明。函数重载和模板都实现了泛型。

类似：函数重载

举例：

1. 最常用的vector即为模板类，`vector<int>`为储存int类型的向量，`vector<double>`为储存double类型的向量。

2. OpenCV中的点的坐标Point2d, Point2f, Point2i就是使用了模板类。定义如下：

   ```c++
   typedef Point_<double> cv::Point2d
   typedef Point_<float> cv::Point2f
   typedef Point_<int> cv::Point2i
   ```

函数模板形式：

``` C++
template <模板参数表>
<返回值类型> <函数名> (模板函数形参表)
{
	// 函数体
}

```

类模板形式：

``` C++
template <模板参数表>
class <类名>
{
	// 类的实现
}
```

其中，模板参数表为`typename T`或`class T`，两者使用起来可以认为没有区别，T为虚拟的类型，可随意替换。若要深究[关于C++中模板中的typename和class的区别比较](https://blog.csdn.net/dick_china/article/details/4522253)。

注意：

1. 函数模板不是函数，其在使用过程中发生了：函数模板->模板实例化->函数；类模板是类的抽象，其在使用过程中发生了：类模板->实例化->类->实例化->对象

2. 函数模板只适用函数的参数个数相同而类型不同，函数体相同的情况。即只是传入参数类型不同，内部实现的所有逻辑都一致的情况。与重载不同，如果参数个数不同则不能使用函数模板，如OpenCV中的三维坐标就使用了另一个函数模板：

   ```c++
   typedef Point_<int> cv::Point2i
   typedef Point3_<int> cv::Point3i
   // 其中
   template<typename _Tp> cv::Point_<_Tp>::Point_(_Tp _x, _Tp _y)	
   template<typename _Tp> cv::Point3_<_Tp>::Point3_(_Tp _x, _Tp _y, _Tp _z)	
   ```

3. 当函数模板和函数重载同时存在时，优先匹配函数重载，若不匹配时再匹配函数模板。函数模板+函数重载的方式可以实现函数抽象过程中的特例。

   

实例：

1. 实现两个数字相互交换的函数模板，

   ```c++
   // 模板函数的定义
   template <typename T>
   void Swap(T &a, T &b) //这里需要引用
   {
       T tmp = a;
       a = b;
       b = tmp;
   }
   // 同时存在函数重载 当输入数为double类型时不仅交换而且要变成int类型
   void Swap(double &a, double &b)
   {
       int tmp = (int)a;
       a = (int)b;
       b = tmp;
   }
   // 模板函数的调用
   // int类型
   int ia = 3, ib = 4;
   Swap(ia, ib); // 这里进行了隐式调用，等价于Swap<int>(ia, ib);
   cout << ia << " " << ib << endl;
   // string类型 
   string sa = "World!", sb = "Hello";
   Swap(sa, sb); // 【这里不同长度的字符之间可以相互替换，没明白】//已解决，参见“字符串的赋值是什么原理？”这部分
   cout << sa << " " << sb << endl;
   // double类型 会调用重载函数
   double da = 3.1413435434341, db = 5.343545454523;
   Swap(da, db);
   cout << da << " " << db << endl;
   // 输出为：
   4 3
   Hello World!
   5 3
   ```

2. 实现Stack功能的类模板，[栈和队列的实际应用](https://blog.csdn.net/lanchunhui/article/details/51670904)

   注意格式：

   1. 类模板的声明和实现必须都要放到.hpp文件中，不能将其分开到.h和cpp中！！！
   2. 成员函数的实现时，每个成员函数前都要加上`template <typename T>`，并且类名后要加上`<T>`

   ``` C++
   // MyStack.h
   template <typename T>
   class Stack
   {
   public:
       Stack(int size=512) {
           space = new T[size];
           top = 0;
           _size = size;
       }
       ~Stack(){}
       void push(T ch);
       T pop();
       bool isEmpty();
       bool isFull();
   private:
       T *space;
       int top;
       int _size;
   };
   
   // 入栈
   template <typename T> //加这个是为了区分类模板成员与类成员
   void Stack<T>::push(T ch){ //Stack后加<T>也是为了表示该函数为类模板中的成员函数
       space[top++] = ch;
   }
   // 出栈
   template <typename T>
   T Stack<T>::pop(){
       return space[--top];
   }
   // 判空
   template <typename T>
   bool Stack<T>::isEmpty(){
       return top == 0;
   }
   // 判满
   template <typename T> 
   bool Stack<T>::isFull(){
       return top == _size;
   }
   
   /******************************************************/
   // main.cpp
   Stack<string> s(1024); //实例化一个长度为1024的储存string类型的Stack对象
   if(!s.isFull()){
       s.push("World!");
   }
   if(!s.isFull()){
       s.push("Hello");
   }
   while(!s.isEmpty()){
       cout << s.pop() << endl;
   }
   // 输出为：
   Hello
   World!
   ```



## 内存分配

栈区 堆区 全局区 文字常量区 程序代码区