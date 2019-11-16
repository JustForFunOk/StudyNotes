---
title: CMake
date: 2018-06-16 16:54:07
tags:
---



## Cmake





IDE中使用一个库一般要设置如下几个

* 头文件（.h），`-I`（GCC） 

  INCLUDE_DIRECTORIES()
  include_directories(../include/)

* 库文件（.so/.dll/.lib/.dylib/...），`-L`（GCC） 

  LINK_DIRECTORIES()
  link_directories("../lib/x86/")

* 库文件的名字：`-l`（GCC） 

  LINK_LIBRARIES(库名称即可)
  link_libraries(realsense2)







