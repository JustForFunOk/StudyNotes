# 摄像头

## 感光芯片

* 感光芯片  
  常见[豪威科技](http://www.ovt.com.cn/)产品，产品名称OVxxxx，智能车竞赛中用的OV7225,OV5116,汽车环视中用的OV10640等。
* 分辨率  
  常见分辨率表示方式有1080P，2K，2MP。其中`1080P`表示共有1080行像素，`P`为progressive表示逐行扫描，与之对应的是`1080i`中的`i`为interlace表示隔行扫描。`2K`表示约为2000列像素，`K`为kilo表示千。`2MP`表示2百万像素，`MP`为million pixels表示百万像素。  

  常见分辨率如下：  
    |格式|像素分辨率|别名|
    |:---:|:---:|:---:|
    |720P |1280*720 |高清 HD|
    |1080P|1920*1080|全高清FHD|
    其中，`FHD`为Full High Definition表示全高清；

* 焦距  
  
* 相面
  `''`表示英寸
* FOV(Field of View)  
  H水平角度 V垂直角度 D(Diagonal)对角角度 
* 输出图像格式  
  注意区分感光芯片的输出格式和摄像头的输出格式，一般摄像头会在感光芯片后添加一块额外的ISP芯片用于采集数据，格式转换等功能。 
    * 感光芯片输出格式  
        `10-bit RAW RGB`表示每个像素的R,G,B都用10bit来表示。这是由于感光芯片内部使用的10-bitADC将模拟信号转换为10bit的数字信号。
    * 摄像头输出格式  
        `YUY2`同`YUYV`同`YUV422`格式，为每个像素保留Y分量，而UV分量在水平方向上每两个像素采样一次。每个像素点使用16bit表示。[其他类似格式](https://blog.csdn.net/u014260892/article/details/51883723)  
        `MJPEG`为压缩格式  
        `YUY2`和`MJPEG`对比，前者未经压缩，所以图像质量高；采集完无需解码，占用系统资源少；但是数据量大，对传输带宽要求高。
  
* 像元尺寸  
  单个像素点的物理尺寸，如OV2710为$3um\times3um$，OV7725为$6um\times6um$
* 成像区域尺寸  
  感光芯片成像区域物理尺寸，如OV2710为$5856um\times3276um$，OV7725为$3984um\times2952um$。

## 镜头



如何选择镜头？  
相同规格，如M12，不同焦距的镜头也通用？  
是否需要考虑分辨率？

参照车载环视镜头FOV:194/134(H/V)

### 焦距和FOV之间的对应关系

 



|序号|焦距</br>(mm)|FOV</br>(度)|
|:---:|:---:|:---:|
|1|||
||2.1|H:$90^{\circ}$ |


## 驱动

### UVC or USB

UVC(USB Video Class)为Microsoft与另外几家设备厂商联合推出的为USB视频捕获设备定义的协议标准，现主流操作系统都已提供UVC设备驱动，因此符合UVC规格的硬件设备在不需要安装任何的驱动程序下即可在主机中正常使用。购买的USB摄像头都支持标准UVC协议。

[ROS下的usb_cam驱动](http://wiki.ros.org/usb_cam)
[ROS下的uvc_cam驱动](http://wiki.ros.org/libuvc_camera)

[通过摄像头设备的ID来获取图像](https://blog.csdn.net/qq_24894159/article/details/82939542)

[如何判断是usb_cam还是uvc_cam？](https://www.jianshu.com/p/e0d96f55f307)
``` bash
1. 列出当前USB设备
$ lsusb
2. 找到摄像头对应的ID，如ID 04f2:b66a
3. 在 http://www.ideasonboard.org/uvc/ 上进行查询
```
