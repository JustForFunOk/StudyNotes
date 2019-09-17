# 360度全景环视

> 关键词： `360 degree surround view`

## 参考资料
* [ADAS漫谈之三：360全景环视系统简析](http://www.shujubang.com/Htmls/NewsInfo/NewsInfo_14274.html)  
  大致讲了流程，没有理论没有实践，结合实际市场来讲的  
  标定方法：棋盘式，框线式
* [w77AYU的博客](https://blog.csdn.net/w77ayu/article/category/7460847)  
  讲的很浅，只有理论没有实践
* [Image Bird's view and image stitching for surround view in opencv c++](https://stackoverflow.com/questions/48661190/image-birds-view-and-image-stitching-for-surround-view-in-opencv-c#)  
  他做了相机标定、畸变矫正、生成鸟瞰图、使用opencv中的stitching的方法进行四张图的拼接  
  他用的生成生成鸟瞰图的[代码](https://gist.github.com/anujonthemove/7b35b7c1e05f01dd11d74d94784c1e58)
* [Image registration with ground plane for surround view](https://robotics.stackexchange.com/questions/12616/image-registration-with-ground-plane-for-surround-view)  
  他成功的进行了四张图的拼接，但是拼接处有错位，拼接的不是很完美。
* [SurroundViewSystem_Demo](https://github.com/striver13/SurroundViewSystem_Demo)  
  github上有源代码。
* [A surround view camera solution for embedded systems](https://www.cv-foundation.org/openaccess/content_cvpr_workshops_2014/W17/papers/Zhang_A_Surround_View_2014_CVPR_paper.pdf)  
  CVPR2014,TI公司的，没有找到源码
* [Three Dimensional Surround View System](https://pdfs.semanticscholar.org/601e/bc8063046bde3ac48339186af31a21343de4.pdf)  
  论文：将图像投影到碗状模型上，这样更加真实，没有找到源代码  
* [REAL-TIME IMAGE STITCHING FOR AUTOMOTIVE 360◦VISION SYSTEMS](https://core.ac.uk/download/pdf/41813777.pdf)  
  论文，硕士论文？还没细看


  