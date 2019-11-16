# USB摄像头

## Linux

使用`v4l2-ctl`工具。

> The  v4l2-ctl  tool is used to control video4linux devices, either video, vbi, radio or swradio, both input and output. It is able to control almost any aspect of such devices convering the full V4L2 API.

### 获取摄像头支持的分辨率

这个命令在`v4l2-ctl`工具的help页面中并没有写。

``` bash
$ v4l2-ctl --list-formats-ext

ioctl: VIDIOC_ENUM_FMT
	Index       : 0
	Type        : Video Capture
	Pixel Format: 'MJPG' (compressed)
	Name        : Motion-JPEG
		Size: Discrete 1280x720
			Interval: Discrete 0.032s (31.000 fps)
		Size: Discrete 1280x1024
			Interval: Discrete 0.033s (30.000 fps)
		Size: Discrete 1920x1080
			Interval: Discrete 0.033s (30.000 fps)
		Size: Discrete 320x240
			Interval: Discrete 0.033s (30.000 fps)
		Size: Discrete 640x480
			Interval: Discrete 0.033s (30.000 fps)
		Size: Discrete 800x600
			Interval: Discrete 0.033s (30.000 fps)
		Size: Discrete 1024x768
			Interval: Discrete 0.033s (30.000 fps)

	Index       : 1
	Type        : Video Capture
	Pixel Format: 'YUYV'
	Name        : YUYV 4:2:2
		Size: Discrete 1280x720
			Interval: Discrete 0.111s (9.000 fps)
		Size: Discrete 1280x1024
			Interval: Discrete 0.167s (6.000 fps)
		Size: Discrete 1920x1080
			Interval: Discrete 0.200s (5.000 fps)
		Size: Discrete 320x240
			Interval: Discrete 0.033s (30.000 fps)
		Size: Discrete 640x480
			Interval: Discrete 0.033s (30.000 fps)
		Size: Discrete 800x600
			Interval: Discrete 0.048s (21.000 fps)
		Size: Discrete 1024x768
			Interval: Discrete 0.077s (13.000 fps)

```

### 获取摄像头支持的其他参数

``` bash
$ v4l2-ctl -L # --list-ctrls-menus
                     brightness (int)    : min=-64 max=64 step=1 default=0 value=0
                       contrast (int)    : min=0 max=64 step=1 default=32 value=32
                     saturation (int)    : min=0 max=128 step=1 default=64 value=64
                            hue (int)    : min=-40 max=40 step=1 default=0 value=0
 white_balance_temperature_auto (bool)   : default=1 value=1
                          gamma (int)    : min=72 max=500 step=1 default=100 value=100
                           gain (int)    : min=0 max=100 step=1 default=0 value=0
           power_line_frequency (menu)   : min=0 max=2 default=1 value=1
				0: Disabled
				1: 50 Hz
				2: 60 Hz
      white_balance_temperature (int)    : min=2800 max=6500 step=1 default=4600 value=4600 flags=inactive
                      sharpness (int)    : min=0 max=6 step=1 default=2 value=2
         backlight_compensation (int)    : min=0 max=2 step=1 default=1 value=1
                  exposure_auto (menu)   : min=0 max=3 default=3 value=3
				1: Manual Mode
				3: Aperture Priority Mode
              exposure_absolute (int)    : min=1 max=5000 step=1 default=157 value=157 flags=inactive
         exposure_auto_priority (bool)   : default=0 value=1

```


## ROS--[usb_cam](http://wiki.ros.org/usb_cam)

### 代码分析

#### 使用的库

* camera_info_manager

  C++ interface for saving, restoring and setting camera calibration information. Mostly used by camera drivers.

  用来设置标定参数的，摄像头内参



### Published Topics

* <camera_name>/image (sensor_msgs/Image)  
  The image

### Parameters

* video_device (string, default: "/dev/video0")  
  The device the camera is on.

图像分辨率，要设置为摄像头支持的分辨率，否则会报错[BUG1](###BugLists)，使用`v4l2-ctl --list-formats-ext`进行查询。

在MJPEG格式下，我的摄像头支持：`1920x1080`, `1280x1024`, `1280x720`, `1024x768`, `800x600`, `640x480`, `320x240`

* image_width (integer, default: 640)  
  Image width

* image_height (integer, default: 480)  
  Image height



* pixel_format (string, default: "mjpeg")  
  Possible values are mjpeg, yuyv, uyvy


* io_method (string, default: "mmap")  
  Possible values are mmap, read, userptr

* camera_frame_id (string, default: "head_camera")  
  The camera's tf frame

* framerate (integer, default: 30)  
  The required framerate

* contrast (integer, default: 32)  
  Contrast of video image (0-255)

* brightness (integer, default: 32)  
  Brightness of video image (0-255)

* saturation (integer, default: 32)  
  Saturation of video image (0-255)

* sharpness (integer, default: 22)  
  Sharpness of video image (0-255)

* autofocus (boolean, default: false)  
  Enable camera's autofocus

* focus (integer, default: 51)  
  If autofocus is disabled, the focus of the camera (0=at infinity)

* camera_info_url (string, default: )  
  An url to the camera calibration file that will be read by the CameraInfoManager class

* camera_name (string, default: head_camera)  
  The camera name. This must match the name in the camera calibration



### BugLists

#### [BUG1] outbuf size mismatch. pic_size: 960000 bufsize: 1036800  
   
分辨率设置的不对，摄像头不支持。

[outbuff size mismatch](https://github.com/ros-drivers/usb_cam/issues/35)

#### [BUG2] [swscaler @ 0xa4afa0] deprecated pixel format used, make sure you did set range correctly

使用`mjpeg`格式进行传输时，控制台一直输出的warning，不影响输出，影响心情。

这个是libswscale库输出的，


[Ref1](https://www.cnblogs.com/zoneofmine/p/10839355.html)

[AVPixelFormat](https://libav.org/documentation/doxygen/master/pixfmt_8h.html#a9a8e335cf3be472042bc9f0cf80cd4c5)

[ffmpeg 中 swscale 的用法](https://www.cnblogs.com/mmix2009/p/3585981.html)

[swscaler warning : deprecated pixel format used](https://stackoverflow.com/questions/23067722/swscaler-warning-deprecated-pixel-format-used)
#### [BUG3] [mjpeg @ 0x27034a0] Changeing bps to 8

``` bash
[ INFO] [1573557432.932084474]: using default calibration URL
[ INFO] [1573557432.932140700]: camera calibration URL: file:///home/sunjian4/.ros/camera_info/head_camera.yaml
[ INFO] [1573557432.932182272]: Unable to open camera calibration file [/home/sunjian4/.ros/camera_info/head_camera.yaml]
[ WARN] [1573557432.932201260]: Camera calibration file /home/sunjian4/.ros/camera_info/head_camera.yaml not found.
[ INFO] [1573557432.932225749]: Starting 'head_camera' (/dev/video2) at 320x240 via mmap (mjpeg) at 30 FPS
[ INFO] [1573557432.982201777]: Using transport "raw"
[ WARN] [1573557433.108511481]: unknown control 'focus_auto'

[mjpeg @ 0x27034a0] Changeing bps to 8
[swscaler @ 0x2736c80] deprecated pixel format used, make sure you did set range correctly
```
bps波特率？不理解这里修改为8会有什么影响。

## Q&A
1. 摄像头的分辨率是可以随意设置的吗？  
   
   答：不像OpenCV中可以对图像进行任意尺寸的resize，这是后处理，需要花费时间和资源进行计算的。usb_cam中设置的分辨率是通过通信方式对摄像头参数进行设定的，能让摄像头直接输出理想的分辨率，所以需要设置为摄像头支持的分辨率才行，可以通过[`v4l2-ctl --list-formats-ext`](###获取摄像头支持的分辨率)获取摄像头支持的分辨率，否则会报错`outbuf size mismatch`.

2. launch中对摄像头设置的参数是如何传到摄像头硬件上的？

   答：程序内部调用linux内置的`v4l2-ctl`工具对摄像头进行参数设置的。