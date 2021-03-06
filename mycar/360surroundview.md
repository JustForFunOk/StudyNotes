# 360度全景环视

 关键词
 * `360 degree surround view`
 * `areaview`  
 * `fisheye`

## 相机模型

### pinhole



cv: pinhole + Radtan

cv::fisheye: pinhole + Equi 鱼眼用的是针孔模型？

cv::omnidir: Omni + Radtan

### 

## 畸变模型

### Radial Distortion Model

TI公司用的

## 多相机标定

### Matlab Stereo


### OpenCV Contirb Multi-camera-calibration






## Papers

1. [Dr. Juho Kannala](https://users.aalto.fi/~kannalj1/)  
   Kannala J , Brandt S S . A Generic Camera Model and Calibration Method for Conventional, Wide-Angle, and Fish-Eye Lenses[J]. IEEE Transactions on Pattern Analysis and Machine Intelligence, 2006, 28(8):1335-1340.  
   1.1. [Camera Calibration Toolbox for Generic Lenses](http://www.ee.oulu.fi/~jkannala/calibration/calibration.html)  Matlab Calibration Tool和这个什么关系？
2. 

## 参考资料

* [鱼眼相机成像模型](https://blog.csdn.net/u010128736/article/details/52864024#commentBox)  
  等距投影模型，OpenCV中用的模型，畸变用多项式近似模型，貌似韩国公司用的也是这个模型？

* [SLAM 中常用的相机模型&畸变模型总结](https://blog.csdn.net/OKasy/article/details/90665534)  
  里面介绍了多种相机模型，畸变模型，投影模型，好像不错，里面参考的几个链接貌似也有料

* [A surround view camera solution for embedded systems](https://www.cv-foundation.org/openaccess/content_cvpr_workshops_2014/W17/papers/Zhang_A_Surround_View_2014_CVPR_paper.pdf)  
  CVPR2014,TI公司的，没有找到源码。这个里面没讲到用的什么相机模型？

  其作者值得关注，专注于相机的。Buyue Zhang  

  [Linkedin主页上有很多信息](https://www.linkedin.com/in/buyue-zhang-9970734) 包括其所有的论文

* [ADAS漫谈之三：360全景环视系统简析](http://www.shujubang.com/Htmls/NewsInfo/NewsInfo_14274.html)  
  大致讲了流程，没有理论没有实践，结合实际市场来讲的  
  标定方法：棋盘式，框线式
* [w77AYU的博客](https://blog.csdn.net/w77ayu/article/category/7460847)  
  讲了车载环视的几个大步骤，很浅，只有理论没有实践
* [Image Bird's view and image stitching for surround view in opencv c++](https://stackoverflow.com/questions/48661190/image-birds-view-and-image-stitching-for-surround-view-in-opencv-c#)  
  他做了相机标定、畸变矫正、生成鸟瞰图、使用opencv中的stitching的方法进行四张图的拼接  
  他用的生成生成鸟瞰图的[代码](https://gist.github.com/anujonthemove/7b35b7c1e05f01dd11d74d94784c1e58)
* [Image registration with ground plane for surround view](https://robotics.stackexchange.com/questions/12616/image-registration-with-ground-plane-for-surround-view)  
  他成功的进行了四张图的拼接，但是拼接处有错位，拼接的不是很完美。
* [SurroundViewSystem_Demo](https://github.com/striver13/SurroundViewSystem_Demo)  
  github上有源代码。


* [Three Dimensional Surround View System](https://pdfs.semanticscholar.org/601e/bc8063046bde3ac48339186af31a21343de4.pdf)  
  论文：将图像投影到碗状模型上，这样更加真实，没有找到源代码  
* [REAL-TIME IMAGE STITCHING FOR AUTOMOTIVE 360◦VISION SYSTEMS](https://core.ac.uk/download/pdf/41813777.pdf)  
  论文，硕士论文？还没细看

* [相机模型--Omnidirectional Camera](https://blog.csdn.net/zhangjunhit/article/details/89137958)  
  meixuan推荐，说道标定工具the toolbox of Scaramuzza

* [Models for the various classical lens projections](http://michel.thoby.free.fr/Fisheye_history_short/Projections/Models_of_classical_projections.html)  
  暂时没看懂，里面有很多图。

* [各相机模型(针孔+鱼眼)综述](https://blog.csdn.net/u011178262/article/details/86656153)
  里面放了很多论文链接。



## 标定示例

### 外参

汽车坐标系，以汽车后轴中点为原点，以[自动驾驶中的时空坐标系](https://cloud.tencent.com/developer/article/1063270)

四个摄像头相对于原点的平移和旋转矩阵，原点一般为后轴中心。

``` xml
<item channel="0">front camera
    <rotation x="78.0147" y="-7.83883" z="7.63825" />
    <translation x="1.82672" y="-230.197" z="41.2708" />
</item>
<item channel="1">right camera
    <rotation x="23.7714" y="11.8741" z="-2.4676" />
    <translation x="-68.7608" y="-98.2236" z="106.908" />
</item>
<item channel="2">rear camera
    <rotation x="43.9628" y="-2.68753" z="3.12228" />
    <translation x="-6.05253" y="-230.197" z="85.283" />
</item>
<item channel="3">left camera
    <rotation x="26.7685" y="-7.8226" z="1.46457" />
    <translation x="73.8574" y="-98.2236" z="106.302" />
</item>
```

### 内参


``` xml
<item channel="0">front camera
    <sensor width="1280" height="720" />
    <lens focal_length="1.28683" />
    <image width="1280" height="720" />
    <intrinsic focal_length="237" pp_x="-9.01192" pp_y="0.839236" curvature="POLYNOMIAL" />
    <polynomial>
        <forward degree="6" c0="0" c1="1.0084" c2="-0.0177" c3="0.1488" c4="-0.1409" c5="0.0895" c6="-0.0206" c7="0" c8="0" />
        <backward degree="6" c0="0.0003" c1="0.9905" c2="0.0073" c3="-0.088" c4="0.0441" c5="-0.0143" c6="0.0024" c7="0" c8="0" />
    </polynomial>
    <misc flip="false" interlaced="false" />
</item>
<item channel="1">right camera
    <sensor width="1280" height="720" />
    <lens focal_length="1.29955" />
    <image width="1280" height="720" />
    <intrinsic focal_length="237" pp_x="-8.69216" pp_y="1.53686" curvature="POLYNOMIAL" />
    <polynomial>
        <forward degree="6" c0="0" c1="1.0084" c2="-0.0177" c3="0.1488" c4="-0.1409" c5="0.0895" c6="-0.0206" c7="0" c8="0" />
        <backward degree="6" c0="0.0003" c1="0.9905" c2="0.0073" c3="-0.088" c4="0.0441" c5="-0.0143" c6="0.0024" c7="0" c8="0" />
    </polynomial>
    <misc flip="false" interlaced="false" />
</item>
<item channel="2">rear camera
    <sensor width="1280" height="720" />
    <lens focal_length="1.26724" />
    <image width="1280" height="720" />
    <intrinsic focal_length="238" pp_x="-0.157304" pp_y="-6.11612" curvature="POLYNOMIAL" />
    <polynomial>
        <forward degree="6" c0="0" c1="1.0084" c2="-0.0177" c3="0.1488" c4="-0.1409" c5="0.0895" c6="-0.0206" c7="0" c8="0" />
        <backward degree="6" c0="0.0003" c1="0.9905" c2="0.0073" c3="-0.088" c4="0.0441" c5="-0.0143" c6="0.0024" c7="0" c8="0" />
    </polynomial>
    <misc flip="false" interlaced="false" />
</item>
<item channel="3">left camera
    <sensor width="1280" height="720" />
    <lens focal_length="1.28945" />
    <image width="1280" height="720" />
    <intrinsic focal_length="237" pp_x="0.721118" pp_y="-3.69123" curvature="POLYNOMIAL" />
    <polynomial>
        <forward degree="6" c0="0" c1="1.0084" c2="-0.0177" c3="0.1488" c4="-0.1409" c5="0.0895" c6="-0.0206" c7="0" c8="0" />
        <backward degree="6" c0="0.0003" c1="0.9905" c2="0.0073" c3="-0.088" c4="0.0441" c5="-0.0143" c6="0.0024" c7="0" c8="0" />
    </polynomial>
    <misc flip="false" interlaced="false" />
</item>

```