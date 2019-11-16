---
title: NeuralNet
date: 2018-08-19 19:30:34
tags:
---





### Caffe

#### 特点：

* 几乎不需要写代码，只需要修改配置文件
* CPU/GPU无缝切换
* 非常多的开放训练模型
* C++编写，速度快
* 接口支持C++，python，matlab

#### 资源汇总

* [Caffe官网](http://caffe.berkeleyvision.org/)  

* [Caffe的Github](https://github.com/BVLC/caffe)：`https://github.com/BVLC/caffe`

  BLVC(伯克利Berkeley Vision and Learning Center)

* [Cuda下载地址](https://developer.nvidia.com/cuda-downloads)  [Cuda在Linux下的安装指南](https://docs.nvidia.com/cuda/cuda-installation-guide-linux/#abstract)

* [caffe官方教程](http://caffe.berkeleyvision.org/tutorial/)

#### 安装步骤

``` bash
## 于2018年
# 1. 下载caffe源码
$ git clone https://github.com/BVLC/caffe
# 参考：http://caffe.berkeleyvision.org/install_apt.html
# 2. 安装ubuntu上需要安装的依赖项
$ sudo apt-get install git cmake build-essential
$ sudo apt-get install libprotobuf-dev libleveldb-dev libsnappy-dev libopencv-dev libhdf5-serial-dev protobuf-compiler
$ sudo apt-get install --no-install-recommends libboost-all-dev
# 4. 安装BLAS和OpenBLAS
$ sudo apt-get install libatlas-base-dev libopenblas-dev
# 5. （可选）如果要使用python接口则需要安装python的头文件来构建pycaffe接口
$ sudo apt-get install python-dev

```



#### Cuda在Linux下的安装指南

[Ubuntu16.04 Caffe 安装步骤记录（超详尽)](https://blog.csdn.net/yhaolpz/article/details/71375762)



#### 常用命令

* 查看nvidia显卡状态

  `nvidia-msi`



#### 详细内容

LEVELDB, LMDB是caffe里用到的数据库

[BLAS](https://zh.wikipedia.org/wiki/BLAS)(Basic Linear Algebra Subprograms)基础线性代数程序集 ，Caffe中可以使用ATLAS, MKL, OpenBLAS

CUDA is a parallel computing platform and programming model invented by NVIDIA.并行计算平台和编程模型。

编译完成后进入build文件夹，tools/caffe  这是个入口程序，后面可以接命令还有参数



caffe使用