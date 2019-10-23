---
title: Qt
date: 2018-06-16 14:37:31
tags:
---

## 资源汇总

### 下载地址

[清华大学开源软件镜像站](https://mirrors.tuna.tsinghua.edu.cn/qt/)

[QtCreator](https://mirrors.tuna.tsinghua.edu.cn/qt/official_releases/qtcreator/)

[Qt库](https://mirrors.tuna.tsinghua.edu.cn/qt/official_releases/qt/)

### 文档

[官方文档](http://doc.qt.io/)

## 单词

manual 手册

## 常见疑问

### MinGW和MSVC选择哪一个？

首先明确一点，如果只是使用QtCreator作为IDE，~~并没有使用Qt中的库那么完全不用考虑这个问题~~好像不是，还是需要使用里面带的Win32API。

MSVC：MicroSoft Visual Studio

[MinGW](http://mingw.org/)：Minimalist GNU for Windows ，又称mingw32，是将GCC编译器和GNU Binutils移植到Win32平台下的产物，包括一系列头文件（Win32API）、库和可执行文件。另有可用于产生32位及64位Windows可执行文件的MinGW-w64项目，是从原本MinGW产生的分支。

## QtCreator

[添加编译器](http://doc.qt.io/qtcreator/creator-tool-chains.html)



### 三种构建工程的工具

#### qmake

qmake由Trolltech（现为Qt公司）创建。

[qmake官方手册](http://doc.qt.io/qt-5/qmake-manual.html)

#### Qbs

其前身为qmake！Qbs最初由Nokia创建，现在主要由The Qt Company开发。

[Qbs官方手册](http://doc.qt.io/qbs/index.html)

#### CMake

[CMake官方手册](https://cmake.org/documentation/)、[CMake使用Qt库](http://doc.qt.io/qt-5/cmake-manual.html)




### QtCreator中加入库的API（Application Programming Interface ）的使用文档

加入.qch格式的文档

实现`F1`即可查看某函数的使用说明

支持的有，如：[CMake](https://cmake.org/documentation/)



## 例子

### CMake构建工程中使用OpenCV

OpenCV官方文档：[Using OpenCV with gcc and CMake](https://docs.opencv.org/3.3.0/db/df5/tutorial_linux_gcc_cmake.html)

``` CMake
cmake_minimum_required(VERSION 2.8)
project( DisplayImage )
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable( DisplayImage DisplayImage.cpp )
target_link_libraries( DisplayImage ${OpenCV_LIBS} )
```



### CMake构建DLL工程

