---
title: Cplusplus-Style-Guide
date: 2018-06-22 20:15:47
tags:
---



> 本篇文章主推谷歌开源的C++编程规范



## 资料汇总

### Google编程规范资料

#### 文档篇

[Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html)

* 官方英文文档
* Google对于几乎所有语言都有对应的编程风格的文档：[styleguide](https://github.com/google/styleguide)

[谷歌C++风格指南](http://zh-google-styleguide.readthedocs.io/en/latest/google-cpp-styleguide/)

* 中文开源项目，由英文文档翻译而来
* 里面还有Python等语言的风格指南

[一张图总结Google C++编程规范(Google C++ Style Guide)](https://blog.csdn.net/voidccc/article/details/37599203)

* 作者原创的一幅图，不错

[一份中文pdf文档](http://oin03u33p.bkt.clouddn.com/Google+C+++%E7%BC%96%E7%A8%8B%E8%A7%84%E8%8C%83.pdf)

#### 工具篇

##### Cpplint

[cpplint](https://github.com/google/styleguide/tree/gh-pages/cpplint)

* 官方链接

* Cpplint是一个python脚本，Google使用它作为自己的C++代码规范检查工具

[Google代码规范工具Cpplint的使用](https://blog.csdn.net/fengbingchun/article/details/47341765)

* 使用教程

#### 讨论篇

[匈牙利命名法的辩思](https://blog.csdn.net/fullsail/article/details/8039253)

* 讨论了这个命名法的发展，以及为什么不推荐使用
* 文档最后还推荐了几本编程分割相关的书
* 里面提到在VisualStudio中安装Visual Assist，了解一下这个/



## 内容篇

### [预处理宏](http://zh-google-styleguide.readthedocs.io/en/latest/google-cpp-styleguide/others/#preprocessor-macros)

* 用宏表示常量可被 const 变量代替



### 命名

| 命名形式                 | 规则                             | 适用于                                                       |
| ------------------------ | -------------------------------- | ------------------------------------------------------------ |
| helloworld  hello_world  | 全部小写                         | 文件名（注意win下不区分大小写）、一般变量名（包括形参、结构体成员）、取值或设值功能的函数名、命名空间 |
| helloworld_ hello_world_ | 全部小写，最后接下划线           | 类的成员变量                                                 |
| helloWorld               |                                  | 竟然没有                                                     |
| kHelloWorld              | 以‘k’开头，大小写混写            | 静态储存类型的变量（const，static，extern，全局变量）、枚举常量（推荐） |
| HelloWorld               | 每个单词首字母大写，不包含下划线 | 类型命名（类、结构体、类型别名、枚举类型、类型模板参数）；函数名（除取值和设值功能外。缩写也要只是首字母大写） |
| HELLO_WORLD              | 全部大写，以下划线隔开           | 宏、枚举常量（不推荐）                                       |

​ 特殊情况：

1.  类型别名：uint



### 下划线

什么时候使用以下划线开头的命名方式？

为什么OpenCV库里有以下划线开始或结束命名的习惯？

如[Point_ (_Tp _x, _Tp _y)](https://docs.opencv.org/3.4.1/db/d4e/classcv_1_1Point__.html)中的`Point_`和`_x`以及`_y`

[Why _type (underscore before identifier and variable)](http://www.cplusplus.com/forum/general/95813/)

[What are the rules about using an underscore in a C++ identifier?](https://stackoverflow.com/questions/228783/what-are-the-rules-about-using-an-underscore-in-a-c-identifier)

以下划线开头的命名方式一般出现在各种库中。我们平时编程命名不要这样。



### [注释](http://zh-google-styleguide.readthedocs.io/en/latest/google-cpp-styleguide/comments/)(加入个人倾向)

列出个人感觉要做笔记的部分，更全面的内容参考链接。

* 平时使用`//`来进行注释，不使用`/* */`

* 文件的注释（每行注释前空两格空格）

  ``` c++
  /** @file bits/stl_list.h
   *  This is an internal header file, included by other library headers.
   *  Do not attempt to use it directly. @headername{list}
   */
  #ifndef _STL_LIST_H
  #define _STL_LIST_H
  
  #endif /* _STL_LIST_H */
  ```

* 函数和类的注释使用如下形式（参考stl中的库函数）

  例子如下：

  单词前加@可以高亮，所以brief，param以及注释里提及参数时前面都加@来突出。

  ``` c++
  /**
   *  @brief  Builds a %vector from an initializer list.
   *  @param  __l  An initializer_list.
   *  @param  __a  An allocator.
   *
   *  Create a %vector consisting of copies of the elements in the
   *  initializer_list @a __l.
   *
   *  This will call the element type's copy constructor N times
   *  (where N is @a __l.size()) and do no memory reallocation.
   */
  vector(initializer_list<value_type> __l,
  	  const allocator_type& __a = allocator_type())
  : _Base(__a)
  {
    _M_range_initialize(__l.begin(), __l.end(),
  			         random_access_iterator_tag());
  }
  ```

* 使用`TODO`来表示后续要做的改进

  ``` c
  // TODO(kl@gmail.com): Use a "*" here for concatenation operator.
  // TODO(Zeke) change this to use relations.
  // TODO(bug 12345): remove the "Last visitors" feature
  ```



### API文档--Doxygen

使用doxygen自动生成像OpenCV一样的在线文档，教程参考：[Doxygen overview](https://docs.opencv.org/3.4.3/d4/db1/tutorial_documentation.html)

#### Doxygen

Doxygen（程序生成器）是用于从带注释的C ++源文件生成文档的工具，它也支持其他流行的编程语言。可以生成在线的html网页或者离线的Latex文档