---
title: Cplusplus-Bug-Collection
date: 2018-08-16 10:50:46
tags:
---



> C++使用过程中遇到的各种bug



### static

* invalid use of non-static data member 'xx::xx'

  通过类名来访问非static的数据成员。

  通过类名只能访问static的数据成员，非static的数据成员只能通过对象来访问。

* invalid use of member 'xx::xx' in static member function

  static成员函数访问了非static数据成员。

  static修饰的成员函数不能访问非static的数据成员。

* cannot call member function 'xx::xxx' without object

  static成员函数访问了非static成员函数xxx。

  static修饰的成员函数不能访问非static的成员函数。