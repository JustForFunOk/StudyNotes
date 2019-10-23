---
title: Ubuntu系统中各种缩写的含义
date: 2018-02-20 15:38:16
categories: Ubuntu
author: SunJian
tags:
    - Ubuntu
    - 助记
cover_picture: http://p4j4n6s3q.bkt.clouddn.com/image/Ubuntu%E7%B3%BB%E7%BB%9F%E4%B8%AD%E5%90%84%E7%A7%8D%E7%BC%A9%E5%86%99%E7%9A%84%E5%90%AB%E4%B9%89/ubuntu2ps.jpg

---


### **etc**
系统配置文件存放的目录。
```python
/etc
```
etc 不是什么缩写,是and so on的意思。来源于法语的et cetera翻译成中文就是 等等 的意思.
至于为什么在/etc下面存放配置文件，按照原始的UNIX的说法(linux文件结构参考UNIX的教学实现MINIX) 这下面放的都是一堆零零碎碎的东西，就叫etc好了。哈哈 ，这其实是个历史遗留。

### **opt**
给主机额外安装软件所摆放的目录。
```python
/opt
```
Optional application software packages 可选择的应用软件包

### **tty**
终端设备的统称。
```python
$ ls /dev  #会列出很多tty*的设备
```
tty一词源于Teletypes，或者teletypewriters，原来指的是电传打字机，是通过串行线用打印机键盘通过阅读和发送信息的东西，后来这东西被键盘与显示器取代，所以现在叫终端比较合适。
终端是一种字符型设备，它有多种类型，通常使用tty来简称各种类型的终端设备。
