---
title: OpenCV探究
date: 2018-07-10 20:04:21
tags:
---



## 参考书目

[1] Learning OpenCV 3. Adrian Kaehler and Gary Bradski



### Mat



#### 疑问

* Mat中是以什么样的数据结构储存像素数据的？单纯的多维数组吗？链表？vector？

自己思考：应该是数组，这样访问起来比较快。只是对内存的连续性有一定要求。

（并没有解决这个问题）参考书目[1]中的第四章，对于图像一般以稠密矩阵（dense matrix）的方式储存即Mat，而对于大部分元素都为0的[稀疏矩阵](https://zh.wikipedia.org/wiki/%E7%A8%80%E7%96%8F%E7%9F%A9%E9%98%B5)(sparse matrix)，如直方图，使用SparseMat来储存。



### 拟合

* 给定一系列点，拟合出矩形

  通过查询资料发现，这个比较困难。OpenCV中也只有拟合出椭圆的功能。凑合着用的话就使用将轮廓拟合成多边形的功能approxPolyDP，但是这个需要人工指定误差，并且对于一系列点组成的形状和标准矩形差距较大的情况下，会得到多边形。而且，拟合的效果并不好，拟合得到的四边形往往偏小，而且不是矩形。

  [Fitting a Rectangle](https://www.inf.ethz.ch/personal/arbenz/MatlabKurs/node88.html)这里拟合出矩形的前提是知道这一系列点中分别属于矩形的哪一条边，然后使用最小二乘法拟合四条边，再通过约束条件，修正为矩形。