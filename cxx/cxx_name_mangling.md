# 名字重整name mangling

* 为什么C++可以有同名函数（函数重载function overloading），而C中却不可以？
* 为什么C++中定义的函数在C中引用时需要`extern "C"`？


## 原理

* 可以用参数来保留中间文件`g++ -save-temps ./test_name_mangling.cpp`，在生成的`.s`文件中可以看到name mangling后的结果。
* gcc和g++的版本为，g++/gcc (Ubuntu 5.4.0-6ubuntu1~16.04.12) 5.4.0 20160609。

``` C++
// _Z17print_hello_worldv
void print_hello_world()
{
    std::cout << "Hello World!" << std::endl;
}
// _Z7cal_sumii
int cal_sum(int a, int b)
{
    return (a+b);
}
```

`_Z17print_hello_worldv`，其中，`_Z`为name mangling标识符；`17`为`print_hello_world`的长度；`print_hello_world`为函数名；`v`表示1个形参，类型为void.


``` C++
namespace test_name_mangling
{
// _ZN18test_name_mangling17print_hello_worldEv
void print_hello_world()
{
    std::cout << "Hello World!" << std::endl;
}
// _ZN18test_name_mangling7cal_sumEii
int cal_sum(int a, int b)
{
    return (a+b);
}
}
```

`_ZN18test_name_mangling17print_hello_worldEv`，其中，`N`表示nested嵌套的；`E`表示end.


## Reference
1. [Wikipedia -- Name mangling](https://en.wikipedia.org/wiki/Name_mangling)