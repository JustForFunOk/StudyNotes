---
title: 数学基础知识
date: 2018-05-11 14:32:29
categories: 数学
tags:
   - 数学
   - 汇总
cover_picture: 
---



### 奇异值

[知乎-郑宁](https://www.zhihu.com/question/22237507)



### 向量

**一般把向量定义为列向量**

参考：[为什么一般把向量定义为列向量？](https://www.zhihu.com/question/26304877)



### 矩阵

稀疏矩阵(sparse matrix)：其中大多数元素为零的矩阵。对应于松散耦合的系统。

稠密矩阵(dense  matrix)：大多数元素非零。

稀疏度：零值元素的数量除以元素的总数（例如，m×n矩阵的m×n）被称为矩阵的稀疏度（其等于1减去矩阵的密度）。

* [方块矩阵](https://zh.wikipedia.org/wiki/%E6%96%B9%E5%9D%97%E7%9F%A9%E9%98%B5)

  方块矩阵，或简称方阵，是行数及列数皆相同的矩阵。

* [单位矩阵]()

  在线性代数中，n阶单位矩阵，是一个nxn的方形矩阵，其**主对角线元素为1，其余元素为0**。

* [正交矩阵](https://zh.wikipedia.org/zh-hans/%E6%AD%A3%E4%BA%A4%E7%9F%A9%E9%98%B5)

  正交矩阵(orthogonal matrix)：是一个方块矩阵Q，其元素为实数，而且行与列皆为正交的单位向量。我们常用的xyz三维空间坐标系就是正交矩阵。

  * 矩阵的转置矩阵为其逆矩阵
    $$
    Q^T=Q^{-1}等价于Q^TQ=QQ^T=I
    $$

  * 行列式必为+1或-1，当为+1时，正交矩阵称为特殊正交矩阵，是一个旋转矩阵。

* [旋转矩阵](https://zh.wikipedia.org/wiki/%E6%97%8B%E8%BD%AC%E7%9F%A9%E9%98%B5)

  旋转矩阵(Rotation matrix)：是在乘以一个向量的时候有改变向量的方向但不改变大小的效果并保持了手性的矩阵。

* SO

  SO(Special Orthogonal Group)：特殊正交群。就是特殊正交矩阵（旋转矩阵 ）的集合。SO(3)就是三维空间的旋转。

* SE

  SE(Special Euclidean Group)：特殊欧式群。

### Eigen

[官网](http://eigen.tuxfamily.org/index.php?title=Main_Page)  [在线文档(可下载离线使用)](http://eigen.tuxfamily.org/dox/index.html)

eigen/aigen/本征的，固有的

Eigen是线性代数的C ++模板库：矩阵，向量，数值求解器和相关算法。  

#### 安装

ubuntu sudo apt-get install libeigen3-dev

windows 下载解压后参考INSTALL文件（不安装和安装两种使用方式）

#### 使用

使用的时候有时候成员函数都不会进行提示。



``` C++
// 类型转换
// 必须显式地进行转换
Matrix<double, 2, 1> result = matrix_23.cast<double>() * v_3d;

// 矩阵维度如果定义错了会报错
// YOU_MIXED_MATRICES_OF_DIFFERENT_SIZES
```



定义矩阵

`Matrix<float, 2, 3> matrix_23;` 比vector多了维度。

输入元素

`matrix_23 << 1, 2, 3, 4, 5, 6;`

访问元素 

`matrix_23(i,j)`而数组中是`array[i][j]`

