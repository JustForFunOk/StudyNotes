# OpenCV安装

OpenCV官方教程:[Installation in Linux](https://docs.opencv.org/4.1.2/d7/d9f/tutorial_linux_install.html)

本篇中以4.1.2版本为例。

感叹git clone的好处：
1. 方便更新。git clone的代码与远程仓库建立了连接，需要更新最新代码时，只需`git pull`即可。
2. 版本管理。git clone的代码每个版本都有，需要用哪个版本直接`git checkout`对应分支即可，很好管理。
3. 代码管理。在源文件上作出的修改不想要直接`git checkout .`即可恢复原样。
4. 大而全。将所有版本都下载到本地了，急用哪个版本时也不用临时再去下载。

所以，这种方式适合研究OpenCV，尝试OpenCV中的算法，探究版本之间的差异。

若工程中已经确定使用的OpenCV的版本，那么就没有必要使用`git clone`的方式获取源代码，毕竟会占用很大的硬盘空间。直接下载对应版本的压缩包即可。

## 1.安装依赖

``` bash
[compiler] 
$ sudo apt-get install build-essential
[required] 
$ sudo apt-get install cmake git libgtk2.0-dev pkg-config libavcodec-dev libavformat-dev libswscale-dev
[optional] 
$ sudo apt-get install python-dev python-numpy libtbb2 libtbb-dev libjpeg-dev libpng-dev libtiff-dev libjasper-dev libdc1394-22-dev
```




## 2.下载源代码

### 2.1 修改git clone的代理
使用git clone下载源代码速度太慢，而且经常出现错误。根据[git_clone.md](../git/git_clone.md)中`git clone速度太慢`部分的操作，配置git的代理。

### 2.2 下载
* opencv
* opencv_contrib
* opencv_3rdparty

``` bash
# 创建OpenCV文件夹
$ cd ~
$ mkdir OpenCV
$ cd OpenCV/
# 注意，git中设置的代理只适用于http协议。
$ git clone https://github.com/opencv/opencv.git
$ git clone https://github.com/opencv/opencv_contrib.git
$ git clone https://github.com/opencv/opencv_3rdparty.git
```

### 2.3 切换到对应版本
``` bash
# opencv
cd ~/OpenCV/opencv/
git checkout 4.1.2
# opencv_contrib
cd ~/OpenCV/opencv_contrib/
git checkout 4.1.2
```

## 3.编译

### 3.1 创建目录结构

``` bash
# 切换到opencv根目录下
$ cd opencv/
# 创建文件夹用于存放编译生成的文件
$ mkdir build # 这里文件夹名称一定是build，因为build文件夹加入到.gitignore中了，这样该文件夹内的内容不会影响你切换到其他分支
# 为某版本的编译结果单独创建文件夹
$ cd build
$ mkdir build_412_1 # 在build文件夹下创建子文件夹，方便管理不同版本的编译结果，412表示版本4.1.2，1表示第一个编译配置
$ mkdir install_412_1 # 默认路径为/usr/local/，但是多个版本都安装在这会出现版本管理问题，所以单独创建文件夹用于存放
```

### 3.2 编译

这一步就是

编译生成的可执行demo就存放在bin文件夹中。

``` bash
$ cd build_412_1/
$ cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/home/sunjian4/OpenCV/opencv/build/install_412_1 -DBUILD_DOCS=ON -DBUILD_EXAMPLES=ON -DOPENCV_EXTRA_MODULES_PATH=/home/sunjian4/OpenCV/opencv_contrib/modules ../..
$ make -j7
```
cmake命令中参数的设置见[附录1](###参数说明)

若编译过程中下载文件失败，见[附录2](##修改本地安装)

### 3.3 安装
这一步就是将使用OpenCV库所需要的头文件，库文件等安装到指定目录。
``` bash
$ sudo make install
```
---
## cmake中参数说明（Appendix1）

在3.2编译中，cmake后需要设置参数，可以通过cmake-gui查看所有参数，以及默认设置。

### 参数说明


## 修改本地安装（Appendix2）
OpenCV安装中需要的几个第三方库，都是安装时去网上下载的，很难下载成功。所以我们可以手动下载后放在本地，然后修改从本地读取。

一般来说，是看编译过程中哪个库下载不下来就去修改哪个库。


创建文件夹用于存放第三方库。由于`opencv_3rdparty`是以单个库建立分支的，同一时间只能显示一个库，这样无法安装，所以要将所有需要的库放到一个文件夹下。
``` bash
$ cd ~/OpenCV/
$ mkdir opencv_3rdparty_gather
```

### 整理好的目录

该目录结构是参考了`opencv/.cache`文件夹(该文件夹是编译过程生成的，其将第三方库处理后存放在此处，这样即使编译中断重新编译，下载过的第三方库就无需重新下载了)下的目录结构，方便管理。

``` txt
opencv_3rdparty_gather
├── data
│   └── face_landmark_model.dat                       #8afa57abc8229d611c4937165d20e2a2d9fc5a12
├── ippicv
│   └── ippicv_2019_lnx_intel64_general_20180723.tgz  #32e315a5b106a7b89dbed51c28f8120a48b368b4
└── xfeatures2d
    ├── boostdesc                                     #34e4206aef44d50e6bbcd0ab06354b52e7466d26
    │   ├── boostdesc_bgm_bi.i
    │   ├── boostdesc_bgm_hd.i
    │   ├── boostdesc_bgm.i
    │   ├── boostdesc_binboost_064.i
    │   ├── boostdesc_binboost_128.i
    │   ├── boostdesc_binboost_256.i
    │   └── boostdesc_lbgm.i
    └── vgg                                           #fccf7cd6a4b12079f73bbfb21745f9babcd4eb1d
        ├── vgg_generated_120.i
        ├── vgg_generated_48.i
        ├── vgg_generated_64.i
        └── vgg_generated_80.i
```
上述目录结构中`#`后的代表该文件对应的commit的id，如若要获取ippicv
文件夹下的内容，则`git checkout 32e315a5b106a7b89dbed51c28f8120a48b368b4`。


### 库
---
#### ippicv

对应`opencv/3rdparty/ippicv/ippicv.cmake`文件

1. 查看对应的commit序列号
``` cmake
set(IPPICV_COMMIT "32e315a5b106a7b89dbed51c28f8120a48b368b4")
```
2. 切换到对应分支
``` bash
git checkout 32e315a5b106a7b89dbed51c28f8120a48b368b4
```
3. 复制文件
4. 修改网络下载至本地读取
``` cmake
"https://raw.githubusercontent.com/opencv/opencv_3rdparty/${IPPICV_COMMIT}/ippicv/"
```
修改为
``` cmake
"file:/home/sunjian4/OpenCV/opencv_3rdparty_gather/ippicv/"
```

---
下面是opencv_contrib中模块用到的。

#### face_landmark_model.dat

对应`opencv_contrib/modules/face/CMakeLists.txt`文件

1. 查看对应的commit序列号
``` cmake
set(__commit_hash "8afa57abc8229d611c4937165d20e2a2d9fc5a12")
```
2. 切换到对应分支
``` bash
git checkout 8afa57abc8229d611c4937165d20e2a2d9fc5a12
```
3. 复制文件
4. 修改网络下载至本地读取
``` cmake
"https://raw.githubusercontent.com/opencv/opencv_3rdparty/${__commit_hash}/"
```
修改为
``` cmake
"file:/home/sunjian4/OpenCV/opencv_3rdparty_gather/data/"
```

#### boost

对应于`opencv_contrib/modules/xfeatures2d/cmake/download_boostdesc.cmake`文件

1. 查看对应的commit序列号
``` cmake
set(OPENCV_3RDPARTY_COMMIT "34e4206aef44d50e6bbcd0ab06354b52e7466d26")
```
2. 切换到对应分支
``` bash
git checkout 34e4206aef44d50e6bbcd0ab06354b52e7466d26
```
3. 复制文件
4. 修改网络下载至本地读取
``` cmake
"https://raw.githubusercontent.com/opencv/opencv_3rdparty/${OPENCV_3RDPARTY_COMMIT}/"
```
修改为
``` cmake
"file:/home/sunjian4/OpenCV/opencv_3rdparty_gather/xfeatures2d/boostdesc/"
```
#### vgg

对应`opencv_contrib/modules/xfeatures2d/cmake/download_vgg.cmake`文件

1. 查看对应的commit序列号
``` cmake
set(OPENCV_3RDPARTY_COMMIT "fccf7cd6a4b12079f73bbfb21745f9babcd4eb1d")
```
2. 切换到对应分支
``` bash
git checkout fccf7cd6a4b12079f73bbfb21745f9babcd4eb1d
```
3. 复制文件
4. 修改网络下载至本地读取
``` cmake
"https://raw.githubusercontent.com/opencv/opencv_3rdparty/${OPENCV_3RDPARTY_COMMIT}/"
```
修改为
``` cmake
"file:/home/sunjian4/OpenCV/opencv_3rdparty_gather/xfeatures2d/vgg/"
```


