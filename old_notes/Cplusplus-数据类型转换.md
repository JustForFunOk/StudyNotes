---
title: Cplusplus-数据类型转换
date: 2018-09-13 17:31:52
tags:
---



### int 与 unsigned int

``` C++
int i;
unsigned int j;

// 进行运算
// 使用unsigned int类型来储存结果
cout << i+j << endl; 
// i=-2 j=3 i+j=1
// i=-2 j=2 i+j=0
// i=-2 j=1 i+j=4294967295(-1)

// 比较大小
// 先将int类型转换成unsigned int类型再进行比较
// i=-1 j=1 i>j
// i=0  j=1 i<j
```

int与unsigned int参与运算，结果转换成unsigned int类型

* 真题
