---
title: OpenCV汇总
date: 2018-03-26 14:27:51
categories: OpenCV
tags:
   - OpenCV
   - 汇总
cover_picture: http://p4j4n6s3q.bkt.clouddn.com/image/OpenCV%E6%B1%87%E6%80%BB/OpenCV.jpg
---



> 涉及到版本都按照写博客时的最新版本来。

## 资料汇总

[Learn OpenCV](https://www.learnopencv.com/)

基于OpenCV实现的工程功能，提供源码，做项目时可参考。

### 书本

排名不分先后

【1】OpenCV3编程入门--毛星云





## 单词笔记

* speck 斑点

  filterSpeckles 滤除斑点

* disparity map 差分图

  Filters off small noise blobs (speckles) in the disparity map.



### 缩写

* `ddepth` --> Destination depth



## OpenCV模块介绍

参考自：[OpenCV-Introduction](https://docs.opencv.org/3.4.3/d1/dfb/intro.html)，每个模块更详细的功能可参考书本【1】中的p8-11

我们在使用OpenCV时`#include <opencv2/opencv.hpp>`时已经将很多头文件包含进去了，头文件如下

``` C++
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/photo.hpp"
#include "opencv2/video.hpp"
#include "opencv2/features2d.hpp"
#include "opencv2/objdetect.hpp"
#include "opencv2/calib3d.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/ml.hpp"
```

* core

  定义了基本数据结构，包括矩阵Mat、其他模块使用的基本功能

* imgproc

  image processing图像处理模块，包括线性和非线性的图像滤波、图像几何变换、颜色空间转化、直方图等等

* video

  视频分析模块，包括运动估计、背景分离、目标跟踪算法

* calib3d

  calibration标定，包括基本的多视角几何算法、单目多目相机标定、物体姿态估计、立体匹配算法、3D重建

* features2d

  特征提取、特征描述符、描述符匹配

* objdetect

  object detect，包括目标检测、预定义的类别实例（如：脸、眼睛、人、车等）

* highgui

  high gui高层的GUI，实现了简单UI的接口

* videoio

  video I/O视频输入输出，实现了视频捕捉以及编解码接口

* gpu

  来自各个模块的GPU加速算法

* 等等



## 常用函数

* 图像的均值和方差 [meanStdDev()](https://docs.opencv.org/3.4.1/d2/de8/group__core__array.html#ga846c858f4004d59493d7c6a4354b301d)
* 图像中的最大值和最小值以及位置 [minMaxLoc()](https://docs.opencv.org/3.4.1/d2/de8/group__core__array.html#gab473bf2eb6d14ff97e89b355dac20707) [minMaxIdx()](https://docs.opencv.org/3.4.1/d2/de8/group__core__array.html#ga7622c466c628a75d9ed008b42250a73f)
* 中值滤波 [medianBlur()](https://docs.opencv.org/3.4.1/d4/d86/group__imgproc__filter.html#ga564869aa33e58769b4469101aac458f9)

## 安装

### Linux平台

#### 默认安装

##### 准备工作：安装所需要的包

1. 安装编译器

``` bash
sudo apt-get install build-essential
```

2. 安装必需的包

``` bash
sudo apt-get install cmake git libgtk2.0-dev pkg-config libavcodec-dev libavformat-dev libswscale-dev
```

##### 获取OpenCV源代码

``` bash
cd ~/<my_working_directory>
git clone https://github.com/opencv/opencv.git
git clone https://github.com/opencv/opencv_contrib.git
```

##### Build OpenCV

1. 创建用于放置编译文件的文件夹

``` bash
cd ~/opencv
mkdir build
cd build
```

2. 配置

最简单的配置：

``` cm
cmake -D CMAKE_BUILD_TYPE=Release -D CMAKE_INSTALL_PREFIX=/usr/local ..
```

参数说明：





[官方安装教程](https://docs.opencv.org/3.4.1/d7/d9f/tutorial_linux_install.html)

*学会方法不迷路：[OpenCV官网](https://opencv.org/) >> RELEASES >> 对应版本的Documentation >> OpenCV Tutorials >> Introduction to OpenCV >> Installation in Linux*



## 工程配置

### VisualStudio

以VS2017和OpenCV-3.4.1为例

（OpenCV-3.4.1默认只支持x64平台，若要x86则需要重新编译源码。这里只能选择Debug x64或Release x64模式）

* 配置属性 > VC++目录 > 可执行文件目录

  E:\WIN10\openCV\opencv-3.4.1\opencv\build\x64\vc15\bin

  E:\WIN10\openCV\opencv-3.4.1\opencv\build\x64\vc15

* 配置属性 > VC++目录 > 包含目录

  E:\WIN10\openCV\opencv-3.4.1\opencv\build\include

  E:\WIN10\openCV\opencv-3.4.1\opencv\build\include\opencv

  E:\WIN10\openCV\opencv-3.4.1\opencv\build\include\opencv2

* 配置属性 > VC++目录 > 库目录

  E:\WIN10\openCV\opencv-3.4.1\opencv\build\x64\vc15

  E:\WIN10\openCV\opencv-3.4.1\opencv\build\x64\vc15\lib

* 配置属性 > 链接器 > 输入 > 附加依赖项

  (所填写的是E:\WIN10\openCV\opencv-3.4.1\opencv\build\x64\vc15\lib文件夹下的对应静态库的文件名)

  * Debug模式下

    opencv_world341d.lib

  * Release模式下

    opencv_world341.lib

## 小功能

### 一个窗口同时显示多张图片

OpenCV内部没有能实现这个功能的函数,但是OpenCV官方团队提供了能实现这个功能的函数[DisplayManyImages](https://github.com/opencv/opencv/wiki/DisplayManyImages)



### 将图片储存到unsigned char[]中



参考：[*stackoverflow-Convert Mat to Array/Vector in OpenCV*](https://stackoverflow.com/questions/26681713/convert-mat-to-array-vector-in-opencv) [*stackoverflow-How to convert vector to array*](https://stackoverflow.com/questions/2923272/how-to-convert-vector-to-array)



### 初始化一幅图像

```c++
Mat image(Size(640, 480), CV_8UC3); // 8位3通道的640x480的图像
image = Scalar::all(0); //全部初始化为0
```



### 绘制直方图

绘制深度数据的直方图

参考：[【OpenCV】绘制直方图](https://blog.csdn.net/xiaowei_cqu/article/details/8833799) 



### 改变图像中指定的像素值

只能用循环操作？

参考：[StackOverflow-c++ and opencv get and set pixel color to Mat](https://stackoverflow.com/questions/23001512/c-and-opencv-get-and-set-pixel-color-to-mat)



## 图像操作

### 16位深度图

深度相机输出的都是16为unsigned数据。

* [filterSpeckles()](https://docs.opencv.org/3.4.1/d9/d0c/group__calib3d.html#gabe331f205a6dd7a9aa5db8a38157d25b)

  滤除深度图中的噪声点

* convertTo()

  srcImg.convertTo(destImg, CV_8UC1);

  转换成8位图像用于显示。

  注意：16位有符号和16位无符号转换成8位图显示出来都是一样的？！

* [Canny()](https://docs.opencv.org/3.4.1/dd/d1a/group__imgproc__feature.html#ga2a671611e104c093843d7b7fc46d24af)

  直接在16位图上检测边缘。

  ``` C++
  Mat blurImage,dx,dy;
  Scharr(blurImage,dx,CV_16S,1,0);
  Scharr(blurImage,dy,CV_16S,0,1);
  Canny( dx,dy, edge2, edgeThreshScharr, edgeThreshScharr*3 );
  ```


### 读取显示.raw类型的文件

不能直接将.raw读取到Mat中要以文件流来读取再放入到Mat中



参考：[opencv-Unable to open raw image through opencv](http://answers.opencv.org/question/58106/unable-to-open-raw-image-through-opencv/)



### 在类中使用cvSetMouseCallback()



参考：[StackOverflow-How to use cv::setMouseCallback in class?](https://stackoverflow.com/questions/25748404/how-to-use-cvsetmousecallback-in-class)



### 单阈值分割图像

Ostu只支持8位单通道图像。

参考：[OpenCV-Image Thresholding](https://docs.opencv.org/trunk/d7/d4d/tutorial_py_thresholding.html) [StackOverflow-How to use the OTSU Threshold in opencv?](https://stackoverflow.com/questions/17141535/how-to-use-the-otsu-threshold-in-opencv)

### 多阈值分割图像

参考：[StackOverflow-Multi otsu(multi-thresholding) with openCV](https://stackoverflow.com/questions/22706742/multi-otsumulti-thresholding-with-opencv) [StackOverflow-multi-level (4) Otsu thresholding](https://stackoverflow.com/questions/35056760/multi-level-4-otsu-thresholding)  [Multi otsu(multi-thresholding) with openCV](https://stackoverflow.com/questions/22706742/multi-otsumulti-thresholding-with-opencv) [Multi-Level Thresholding. Otsu's Method](https://stackoverflow.com/questions/34856019/multi-level-thresholding-otsus-method)

 

 ### 给定轮廓点拟合矩形

Opencv中的[approxPolyDP()](https://docs.opencv.org/3.4.1/d3/dc0/group__imgproc__shape.html#ga0012a5fdaea70b8a9970165d98722b4c)是指定拟合误差后用多边形拟合给定轮廓，很可能拟合出了五边六边形，不能满足拟合出四边形的效果，而且拟合出的四边形偏小，四边形被给定轮廓全部包围，所以并没有达到拟合的效果。用的原理是[Ramer–Douglas–Peucker algorithm](https://en.wikipedia.org/wiki/Ramer%E2%80%93Douglas%E2%80%93Peucker_algorithm)

 ### [findContours](https://docs.opencv.org/3.4.1/d3/dc0/group__imgproc__shape.html#ga17ed9f5d79ae97bd4c7cf18403e1689a)的用法

``` C++
void cv::findContours(InputOutputArray 	    image,
                      OutputArrayOfArrays 	contours,
                      OutputArray 	        hierarchy,
                      int 	                mode,
                      int 	                method,
                      Point 	            offset = Point() 
                     )	
```

其中的`hierarchy`和`mode`这两个参数不好理解，可以参考：[findContours函数参数详解](https://blog.csdn.net/dcrmg/article/details/51987348)

* hierarchy向量内每一个元素的4个int型变量——`hierarchy[i][0]` ~`hierarchy[i][3]`，分别表示第i个轮廓的后一个轮廓、前一个轮廓、父轮廓、内嵌轮廓的索引编号。如果当前轮廓没有对应的后一个轮廓、前一个轮廓、父轮廓或内嵌轮廓的话，则相应位被设置为默认值-1。
* mode的有四种情况：
  1. RETR_EXTERNAL只检测最外围轮廓，包含在外围轮廓内的内围轮廓被忽略；
  2. RETR_LIST   检测所有的轮廓，包括内围、外围轮廓，但是检测到的轮廓不建立等级关系，彼此之间独立，没有等级关系，这就意味着这个检索模式下不存在父轮廓或内嵌轮廓，所以hierarchy向量内所有元素的第3、第4个分量都会被置为-1；
  3. RETR_CCOMP  检测所有的轮廓，但所有轮廓只建立两个等级关系，外围为顶层，若外围内的内围轮廓还包含了其他的轮廓信息，则内围内的所有轮廓均归属于顶层；
  4. RETR_TREE， 检测所有轮廓，所有轮廓建立一个等级树结构。外层轮廓包含内层轮廓，内层轮廓还可以继续包含内嵌轮廓。

#### 轮廓是否闭合

可以直接通过这个函数判断轮廓是否是闭合的：[Recognize open and closed shapes opencv](https://stackoverflow.com/questions/22240746/recognize-open-and-closed-shapes-opencv)

* 就是判断`hierarchy[i][2]`这一位的值，若为`-1`则不是闭合的，否则是闭合的。



### 使用RotatedRect截取图像中的一部分

OpenCV只有使用非旋转的Rect来构造Mat，`Mat (const Mat &m, const Rect &roi)`，若要实现此功能需要考虑旋转问题。

参考：[Extract a RotatedRect area](http://answers.opencv.org/question/497/extract-a-rotatedrect-area/)

``` c++
// 此代码经测试可用
// rect is the RotatedRect (I got it from a contour...)
RotatedRect rect;
// matrices we'll use
Mat M, rotated, cropped;
// get angle and size from the bounding box
float angle = rect.angle;
Size rect_size = rect.size;
// thanks to http://felix.abecassis.me/2011/10/opencv-rotation-deskewing/
if (rect.angle < -45.) {
    angle += 90.0;
    swap(rect_size.width, rect_size.height);
}
// get the rotation matrix
M = getRotationMatrix2D(rect.center, angle, 1.0);
// perform the affine transformation
warpAffine(src, rotated, M, src.size(), INTER_CUBIC);
// crop the resulting image
getRectSubPix(rotated, rect_size, rect.center, cropped);
```

注意：

* [getRectSubPix()](http://answers.opencv.org/question/497/extract-a-rotatedrect-area/)这个函数的输入和输出图像的深度有要求，而官方文档上没有说，通过查看源代码可以看出。

  ``` c++
  //xxx\opencv\sources\modules\imgproc\src\samplers.cpp
  depth == CV_8U && ddepth == CV_8U
  depth == CV_8U && ddepth == CV_32F
  depth == CV_32F && ddepth == CV_32F
  ```

  若上述三种情况都不满足吗，则会报错"Unsupported combination of input and output formats"。



### Mat的深拷贝和浅拷贝

Mat A，B；

* 浅拷贝
  * B = A；
  * Mat B(A);
* 深拷贝
  * B = A.clone();
  * A.copyTo(B);

