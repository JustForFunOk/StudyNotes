---
title: C++汇总
date: 2018-03-26 09:36:14
categories: 编程语言
author: SunJian
tags:
   - C++
   - 汇总
cover_picture: http://p4j4n6s3q.bkt.clouddn.com/image/C++%E6%B1%87%E6%80%BB/Cplusplus.jpg

---

## 资源汇总

### 官方文档

[官方文档1](http://www.cplusplus.com/)

[官方文档2](http://en.cppreference.com/w/)  [中文版](https://zh.cppreference.com/w/%E9%A6%96%E9%A1%B5)

[中文文档](http://www.runoob.com/cplusplus/cpp-tutorial.html)

### 参考书目

1. Visual C++ 面向对象程序设计教程与实现（第3版）温秀梅

## 命名习惯

## 工程习惯

在调试工程时将所有用到的动态静态链接库，头文件等放到工程目录下，设置里用相对路径。这样以后移植工程会方便的很多，而且直接就能运行。虽然会有占用磁盘空间的弊端。

## 积跬步至千里

### const

const  n.常量，常数

#### vs "#define"

C++语言建议使用const取代#define定义常量。

``` C++
#define PI 3.1415926
const float PI = 3.1415926
```

注意：

* 定义常量时必须初始化
* 一旦定义，则不能修改

* const更加灵活、安全

const可以指定常量的数据类型，C++在编译程序时可以进行更加严格的类型检查，编译时具有良好的检测性。

* 修饰函数形参，用于保证实参在函数内部不被改动
* 大多数C++编译器对具有const参数的函数进行更好的代码优化

#### 结合指针

``` C++
// 常量 “Hello”中的内容不能修改
const char *pc = "Hello";
char const *pc = "Hello";
// 常指针 指针所指向的地址不能修改
char* const pc = "Hello";
// 指向常量的常指针 均不能修改
const char* const pc = "Hello"; 
```



### vector

``` C++
// 可以在运行阶段设置vector对象的长度
int len;
cin >> len;
vector<int> vec_int(len); // 长度可以是变量
// 建立指定尺寸的二维vector
vector<vector<int> > vec_double_int(M, vector<int>(N)); // MxN的二维向量
```



vector<int> v1;

### static

### explicit

显式的



#### cin

cin如何吸收回车键:`cin.get();`

就是需要输入多行数据，其中要用到回车，但是正常情况下使用回车会结束输入。



## 小知识

* 如果在类的定义中包含有对象成员，则在创建类对象时先调用对象成员的构造函数，再调用类本身的构造函数。析构函数的构造函数的调用顺序正好相反。（参考自：参考书目1）

* 程序运行搜寻dll的顺序：（参考自：[Unable to load DLL (Module could not be found HRESULT: 0x8007007E)](https://stackoverflow.com/questions/9003072/unable-to-load-dll-module-could-not-be-found-hresult-0x8007007e)

  1. 当前目录
  2. 系统文件，C:\windows\system32 or c:\windows\SysWOW64 
  3. 环境变量中Path的路径 

* 各个数据类型占用空间

|类型            |位数|
|:----------------:|:---:|
|char|8-bit |
|short|16-bit |
|int|32位和64位系统都是32-bit，16位（嵌入式）系统16-bit |
|long|32-bit |
|float|32-bit |
|long long|64-bit |
|double|64-bit |
|指针|32位系统32-bit，64位系统64-bit |

1. 可以使用`int16_t`,`int32_t`,`int64_t`来指定特定长度的int类型。
2. 使用sizeof()输出变量或数据类型所占用得空间
3. 注意1：这些知识经常结合结构体和空间对齐的知识成为笔试题目。
4. 注意2：储存方式不同则指针不能进行强制转换，如`char*`和`uchar*`之间可以强制转换，这个在图像进行网络传输中会用到。

* 内存空间对齐

* 


## 名词解释

对象成员：是指类的定义中数据成员可以为其他的类的对象，类对象作为另一个类的数据成员。

## 头文件

string

cstdio



## 疑问

### 条件编译

``` C++
#ifdef win64
	/**********/
#endif
```

这个是怎么个工作原理，`win64`是在哪定义的？



### 静态成员变量

.h文件中类成员变量钱加static有什么用？



### 将方法封装成dll库调用比直接生成的exe使用快了10倍



## 小功能

### 解决黑窗一闪而过

``` c++
#include <iostream> // 均需要此头文件
// 方法一
std::system("pause"); // 加在程序末尾，return之前
// 方法二
std::getchar();
```



### 数字到字符串的转换

[to_string](http://www.cplusplus.com/reference/string/to_string/?kw=to_string)

核心代码:

``` c++
#include <string> //std::string, std::to_string
int length=888, width=666;
std::string s = "Size:" + std::to_string(length) + "x" + std::to_string(width);
```
注意：只有此方法不适用于浮点型，如float length=888.88时，输出的是888.880005。

参考: [*StackOverflow*](https://stackoverflow.com/questions/5590381/easiest-way-to-convert-int-to-string-in-c)

---

[stringstream](http://www.cplusplus.com/reference/sstream/stringstream/)

核心代码:

``` c++
#include <string> //std::string
#include <sstream> //std::stringstream
int length=888, width=666;
stringstream ss;
ss.str(""); // 若要多次使用ss,则需要先清空ss
ss << "Size:" << length << "x" << width;
std::string s = ss.str();
```

注意: 若要多次使用*ss*则`ss.str("");`必不可少!

参考: [*StackOverflow*](https://stackoverflow.com/questions/5590381/easiest-way-to-convert-int-to-string-in-c) [*Shuffy's Blog*](http://cppblog.com/Sandywin/archive/2007/07/13/27984.html)

---

[sprintf](http://www.cplusplus.com/reference/cstdio/sprintf/) / [sprintf_s](https://msdn.microsoft.com/en-us/library/ce3zzk1k.aspx)

- 与熟悉的[printf](http://www.cplusplus.com/reference/cstdio/printf/)很像,只是printf是将内容打印出来,而sprintf是将内容储存到指定的字符串中

- 同样可以使用`%x.xf`来格式化字符串,非常方便


核心代码:

``` c++
#include <cstdio> //std::sprintf
char s[50]; //字符串的长度根据需要修改
float length=888.88, width=666.66;
std::sprintf(s, "Size:%5.1fx%5.1f", length, width);
```
注意:
- 字符数组的长度要大于字符串的长度
- 格式化输出时保证数据类型一致，如`%f`与`float`对应,否则会输出错误，可查看[对应表](http://www.cplusplus.com/reference/cstdio/printf/)
- sprintf在VS环境中默认不能编译通过，详情查看`bug0001`




### 字符数组转化成字符串

[string constructor](http://www.cplusplus.com/reference/string/string/string/)

核心代码：

``` C++
#include <string> // string
char arr[] = "Hello";
std::string str(arr); //等价于std::string str; str = arr;
```

参考：[*stackoverflow-How to convert a char array to a string?*](https://stackoverflow.com/questions/8960087/how-to-convert-a-char-array-to-a-string)

### 获取系统时间用来作为文件名

[time](http://www.cplusplus.com/reference/ctime/time/)

返回值是UTC时间从1900年1月1日00:00开始的秒数。（文档上都显示是1970年但根据实验是1900年）

[localtime](http://www.cplusplus.com/reference/ctime/localtime/)

输入time()返回值，输出指向储存当地时间的tm结构体的指针。

tm结构体定义如下：

``` c++
struct tm
{
    int tm_sec;   // seconds after the minute - [0, 60] including leap second
    int tm_min;   // minutes after the hour - [0, 59]
    int tm_hour;  // hours since midnight - [0, 23]
    int tm_mday;  // day of the month - [1, 31]
    int tm_mon;   // months since January - [0, 11]
    int tm_year;  // years since 1900
    int tm_wday;  // days since Sunday - [0, 6]
    int tm_yday;  // days since January 1 - [0, 365]
    int tm_isdst; // daylight savings time flag
};
```

核心代码：

``` C++
#include <time.h> // time_t struct tm
// 获取秒数
time_t rawtime; // time_t为64位的数据类型
time(&rawtime); // rawtime = time(NULL);
// 转换为本地时间
struct tm * timeinfo; // tm为储存时间的结构体，包含如，年份，月份，小时等时间相关信息 struct在C++中可省略
timeinfo = localtime(&rawtime);
// 根据需求提取结构体中需要的信息
int year = 1900 + timeinfo->tm_year; // 年份需要加1900
int month = 1 + timeinfo->tm_mon; // 月份需要加1
int day = timeinfo->tm_mday;
int hour = timeinfo->tm_hour;
int minute = timeinfo->tm_min;
int second = timeinfo->tm_sec;
// 写入到字符串中
char filename[20];
sprintf(filename, "%d%02d%02d%02d%02d%02d.jpg", year, month, day, hour, minute, second); //以jpg图片为例
imwrite(filename, image); // 以OpenCV中的保存图片函数为例
```

注意：文件名中不能包含`\ / : * ? " < > |`， 所以不能以20:08:09这样的时间格式作为文件名。

### 线程休眠

[sleep_for (C++11)](http://www.cplusplus.com/reference/thread/this_thread/sleep_for/?kw=sleep_for)

``` c++
#include <thread> // std::this_thread::sleep_for
#include <chrono> // std::chrono::milliseconds
std::this_thread::sleep_for(std::chrono::milliseconds(10));
```

### 字符串比较

`==`

参考：[StackOverflow-How to compare strings](https://stackoverflow.com/questions/6222583/how-to-compare-strings)

 ### 字符串数组

**初始化**

``` C++
string colour[4] = {"Blue", "Red", "Orange", "Yellow"};
```

参考：[GeeksforGeeks-Array of Strings in C++ (3 Different Ways to Create)](https://www.geeksforgeeks.org/array-strings-c-3-different-ways-create/)

**字符串数组长度**

``` C++
sizeof(colour)/sizeof(colour[0])
```

参考：[StackOverflow-Finding the size of an String array in C++](https://stackoverflow.com/questions/14308935/finding-the-size-of-an-string-array-in-c)

### 枚举使用

``` C++
enum weekday{ sun,mou,tue,wed,thu,fri,sat };
enum weekday a,b,c;
```

### 延时1s

``` c++
#include <iostream>
_sleep(1000);
```

#### 将vector<char>赋值给string

``` c++
std::vector<char> v;
std::string str(v.begin(),v.end());
```

参考自：[How to construct a std::string from a std::vector?](https://stackoverflow.com/questions/5115166/how-to-construct-a-stdstring-from-a-stdvectorchar)



## 大功能

### 进程间的通信

IPC(Interprocess Communications)

进程间通信方式有很多种，要根据具体的使用情况来选择适合自己的：

- 本机进程间通信？不同电脑的进程之间通过网络通信？不同电脑不同操作系统的进程之间通过网络通信？
- 一对一通信？一对多通信？
- 进程是GUI应用？是控制台应用？

通信方式总结如下：

- 共享内存

  程序：

  - 使用Boost库中的[Boost.Interprocess](https://theboostcpplibraries.com/boost.interprocess)

    两个C++进程间经过测试可以使用，一个C++一个C#程序之间没有成功。

  - 使用[Named Shared Memory](https://msdn.microsoft.com/en-us/library/windows/desktop/aa366551%28v=vs.85%29.aspx)

    一个C#和一个C++程序之间应该可以，待测试。

  参考：[*stackoverflow*](https://stackoverflow.com/questions/372198/best-way-for-interprocess-communication-in-c)

  ​

参考：[*Microsoft--总结了windows很多方法*](https://msdn.microsoft.com/en-us/library/windows/desktop/aa365574%28v=vs.85%29.aspx)  [*IBM--总结了UNIX上的方法*](https://www.ibm.com/developerworks/aix/library/au-spunix_sharedmemory/)



### 将源文件封装成.dll并供C++程序调用

参考：[MSDN-Walkthrough: Creating and Using a Dynamic Link Library (C++)](https://msdn.microsoft.com/en-us/library/ms235636.aspx)



### C#调用C++封装的dll

C#调用C++封装的dll比起C++去调用麻烦很多，特别是unmanaged dll。有一种方法是如果是将unmanaged修改成managed，我试过但没有成功[C# adding reference error - Checking a C++ DLL is valid for a C# project](http://frasergreenroyd.com/c-adding-reference-error-checking-a-c-dll-is-valid-for-a-c-project/)

如将C++源代码封装成example.dll供C#调用。

第一步：和上一步一样，将源文件封装成example.dll

第二步：如果需要调用的不是类里面的函数可以参考[Dynamically calling an unmanaged dll from .NET (C#)](https://blogs.msdn.microsoft.com/jonathanswift/2006/10/03/dynamically-calling-an-unmanaged-dll-from-net-c/)和[Calling an unmanaged dll from .NET (C#)](https://blogs.msdn.microsoft.com/jonathanswift/2006/10/02/calling-an-unmanaged-dll-from-net-c/)(没有试过，对类里的成员函数不适用)；

如果需要调用的是类里的成员函数，参考[using a class defined in a c++ dll in c# code](https://stackoverflow.com/questions/315051/using-a-class-defined-in-a-c-dll-in-c-sharp-code)（试了很多，这个成功了）

其原理是“Marshal C++ Class and use the PInvoke”，整理C++类并使用PInvoke，P/Invoke的全称是Platform Invoke (平台调用) 它实际上是一种函数调用机制通过P/Invoke我们就可以调用非托管DLL中的函数。实际上很多NET基类库中定义的类型内部部调用了从Kernel32.dll，User32.dll，gdi32.dll等非托管DLL中导出的函数。（参考：[C# PInvoke(DllImport使用) 进阶教程(一)](http://www.cnblogs.com/NatureSex/archive/2011/12/07/2278575.html)）

注意：1. C++源代码依赖的dll也要放到目录下，否则C#不能正常加载dll



### 多线程

[thread(C++11)](http://www.cplusplus.com/reference/thread/thread/)

``` C++
// thread example
#include <iostream>       // std::cout
#include <thread>         // std::thread
 
void foo() 
{
  // do stuff...
}

void bar(int x)
{
  // do stuff...
}

int main() 
{
  std::thread first (foo);     // spawn new thread that calls foo()
  std::thread second (bar,0);  // spawn new thread that calls bar(0)

  std::cout << "main, foo and bar now execute concurrently...\n";

  // synchronize threads:
  first.join();                // pauses until first finishes
  second.join();               // pauses until second finishes

  std::cout << "foo and bar completed.\n";

  return 0;
}
```



## 工程BUG

### 程序移植

WIN上使用VS2017开发的程序部署到其他计算机上，不能正常运行。主要BUG有以下几点：

* 无法启动程序，因为计算机中丢失MSVCP140.dll。尝试重新安装该程序以解决此问题。
* 无法启动程序，因为计算机中丢失VCRUNTIME140.dll。尝试重新安装该程序以解决此问题。

其中类似于xxx140.dll的文件都是因为使用了VS这个编译器，其中140是VS2017的编译工具代号。遇到这种问题没有必要从现有的计算机上寻找丢失的文件再复制过去，直接安装Visual C++的可再发行组件包即可解决，可从[VAllen's Blog](https://www.cnblogs.com/VAllen/p/Visual-C-Plus-Plus-Collection-Download.html)处下载，[官方下载地址](https://www.microsoft.com/en-us/download/developer-tools.aspx)。注意，根据程序自身的位数来安装对应的位数，与系统以及IDE位数无关。

* 应用程序无法正常启动(0x000007b)。请单击“确定”关闭应用程序。

导致这种错误的可能性有很多，但是在程序移植中往往是因为动态库的问题。例如，我的项目开发中使用的SDK是需要安装的，安装完毕后在目标文件夹下有.dll文件，这样将本机的.dll文件拷贝到.exe目录下可以运行，但是然后将.exe和.dll同时拷贝到其他计算机上就不能运行。解决这个问题需要在目标计算机上也安装SDK，然后将安装后的目标文件夹下的.dll文件覆盖之前的.dll文件才能正常运行。

目前我没有什么好的方法可以直接解决这个问题，比较笨但有效的办法是逐一排查，如程序使用了A.dll和B.dll，那就再编写一个只使用A.dll或只使用B.dll的程序进行实验，这样就能找到问题的所在。



### 使用.lib编译程序

.exe+.dll的方式在程序移植过程中可能会导致.dll的丢失，如果使用.lib进行编译程序就直接使用.exe就能运行。



### CPU占用率99%

**问题描述**

开发的程序中使用了4个线程，每个线程中都在不断循环执行，CPU为4核的。

**尝试解决**

* 在每个子线程中添加waitKey(20)函数，让每个子线程每次循环都等待一段时间。

  参考：[CSDN-代码运行时 CPU占用率100%的解决方法](https://blog.csdn.net/qq_21882325/article/details/66479195)

  效果：并没有什么效果。可能是waitKey()这个函数不对，它并没有阻塞线程还是在占用CPU。可以再试试[CSDN-如何阻塞当前线程一段时间？](https://bbs.csdn.net/topics/350023502)

  使用线程休眠也没用std::this_thread::sleep_for(std::chrono::milliseconds(200));

* 临时解决方法，在win任务管理器中强行不让该程序使用全部的核。

  参考：[techradar-Why is my CPU running at 100%?](https://www.techradar.com/news/computing/why-is-my-cpu-running-at-100-710254)

  效果：还未试

* 开的线程太多了？Mistake # 18:Creating many more "Runnable" threads than available cores?

  参考：[ACODERS JOURNEY-Top 20 C++ multithreading mistakes and how to avoid them](http://www.acodersjourney.com/2017/08/top-20-cplusplus-multithreading-mistakes/)

* 有个观点：CPU占用率越高越好？

  参考：[StackOverflow-What are the common causes for high CPU usage?](https://stackoverflow.com/questions/9275262/what-are-the-common-causes-for-high-cpu-usage)


**补充疑问**

如果两个这样的程序同时运行会是什么情况？




## 程序BUG

### WIN+VS2017

#### bug0001

*error C4996: 'sprintf': This function or variable may be unsafe. Consider using  sprintf_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details.*

原因：（确切原因还未知）sprintf若使用不当会不安全，VS中默认屏蔽了这个函数，其他IDE可以使用。

解决：1、（推荐）使用[sprintf_s](https://msdn.microsoft.com/en-us/library/ce3zzk1k.aspx)直接代替，无需修改参数；

	2、 [修改VS配置](https://jingyan.baidu.com/article/49711c616b8a1ffa441b7cdc.html)，即在属性-->C/C++-->预处理器-->预处理器定义中加入`_CRT_SECURE_NO_WARNINGS`



## IDE

### VisualStudio

#### 调试时默认的当前目录

答：.vcxproj文件所在目录。

#### VisualStudio版本号

近几年的产品版本号如下，更多信息的参考[WIKIPEDIA-Microsoft Visual Studio](https://en.wikipedia.org/wiki/Microsoft_Visual_Studio)。

|产品名             |版本号|平台工具集|
|:----------------:|:---:|:------:|
|Visual Studio 2017|15.0 |v141|
|Visual Studio 2015|14.0 |v140|
|Visual Studio 2013|12.0 |v120|
|Visual Studio 2012|11.0 |v110|
|Visual Studio 2010|10.0 |v100|

参考：[*MSDN-修改目标框架和平台工具集*](https://msdn.microsoft.com/zh-cn/library/ff770576.aspx)  [*StackOverflow-Version numbers for Visual Studio 2017, Boost and CMake*](https://stackoverflow.com/questions/42730478/version-numbers-for-visual-studio-2017-boost-and-cmake)



#### 修改整个工程的文件名

若想将NameA修改成NameB。

1. 修改所有NameA的文件夹为NameB；
2. 修改所有NameA.xx的文件名称为NameB.xx
3. 记事本打开.sln以及.vcxproj以及.vcxproj.filters文件，将NameA全部替换为NameB。



### QtCreator

qt的读音同cute。

#### MSVC和MinGW的区别




## 库

### Boost

#### 资料汇总

* 特性：
* [boost官网](https://www.boost.org)
* [boost文档](https://theboostcpplibraries.com/)

#### 使用

* WIN上安装Boost

  *注意：安装完后占用5-6G，所以注意放置位置。*

  1、官网下载Boost并解压；

  2、以管理员身份运行Windows PowerShell；

  3、进入Boost根目录；`cd <work_directory>`

  4、运行bootstrap.bat脚本文件；`.\bootstrap.bat`

  5、运行在该目录生成的bjam.exe文件，等待结束即可。`.\bjam.exe`

  参考：[*CSDN*](https://blog.csdn.net/yockie/article/details/8856190) [*CSDN*](https://blog.csdn.net/sunshinecj/article/details/52598488)

* [VisualStudio中调用Boost库](https://www.boost.org/doc/libs/1_67_0/more/getting_started/windows.html#id36)

  配置如下：

  1、*Configuration Properties* > *C/C++* > *General* > *Additional Include Directories* 中加入Boost库的根目录，如：*F:\WIN10\Boost\boost_1_67_0*

  2、In *Configuration Properties* > *C/C++* > *Precompiled Headers*, change *Use Precompiled Header (/Yu)* to *Not Using Precompiled Headers*.

  3、In *Configuration Properties* > *Linker* > *General* > *Additional Library Directories*, enter the path to the Boost binaries, e.g. *F:\WIN10\Boost\boost_1_67_0\stage\lib* （[官网](https://www.boost.org/doc/libs/1_67_0/more/getting_started/windows.html#simplified-build-from-source)上的路径不太对，使用这个）

  参考：[*CSDN*](https://blog.csdn.net/yockie/article/details/8856190) [*CSDN*](https://blog.csdn.net/sunshinecj/article/details/52598488)



## 题目

* [C++面试集锦( 面试被问到的问题 )](https://www.cnblogs.com/Y1Focus/p/6707121.html)