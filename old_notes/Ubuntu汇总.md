---
title: Ubuntu汇总
date: 2018-04-01 22:52:39
categories: Ubuntu
author: SunJian
tags:
    - Ubuntu
    - 汇总
cover_picture: http://p4j4n6s3q.bkt.clouddn.com/image/Ubuntu%E7%B3%BB%E7%BB%9F%E4%B8%AD%E5%90%84%E7%A7%8D%E7%BC%A9%E5%86%99%E7%9A%84%E5%90%AB%E4%B9%89/ubuntu2ps.jpg
---



### Ubuntu制作系统启动盘

Ubuntu自带工具：usb-creator-gtk（启动盘创建器）

首先要格式化U盘，

``` bash
sudo fdisk -l # 找到U盘序号，如/dev/sdc1
# 关掉所有与U盘相关的窗口
sudo umount /dev/sdc1 # 卸除U盘
sudo mkfs.vfat -F 32 /dev/sdc1 # 将U盘格式化成FAT32格式
```

然后拔掉U盘重新插上进行识别，或通过mount命令进行挂载

最后运行usb-creator-gtk，

![usb-creator-gtk](/home/jason/Pictures/usb-creator-gtk.png)

制作完成，弹出U盘即可。

参考：[*脚本之家*](http://www.jb51.net/os/Ubuntu/66912.html)



格式化硬盘要注意格式化成的格式：

- FAT

  一般的U盘和储存卡

- NTFS

  Windows下的硬盘、要储存较大文件的U盘

- Ext4

  第四代扩展文件系统（Fourth extended filesystem）Linux下使用

### 格式化错误导致无法读取U盘

现象描述：格式化没有完成，导致U盘插上电脑后无法识别。

``` bash
sudo fdisk -l # 首先找到U盘序号，如/dev/sdc1
sudo mkfs.vfat -F 32 /dev/sdc1 # 然后将U盘格式化成FAT32格式
```



