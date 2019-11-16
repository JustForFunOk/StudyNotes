# roslaunch

[roslaunch官方文档](http://wiki.ros.org/roslaunch)

* roslaunch is a tool for easily launching multiple ROS nodes locally and remotely via SSH, as well as setting parameters on the Parameter Server.   
  roslaunch用来启动多个node，设置参数

* It includes options to automatically respawn processes that have already died.  
  
* roslaunch takes in one or more XML configuration files (with the .launch extension) that specify the parameters to set and nodes to launch, as well as the machines that they should be run on.


roslaunch工具安装在/opt/ros/kinetic/bin/目录下。



## *.launch格式

[launch文件格式官方文档](http://wiki.ros.org/roslaunch/XML)

.launch文件使用XML格式，是一种标记语言。其使用标签以及属性的形式，类似于python中的键值对。

### 注释

``` xml
<!-- annotation -->
```

### 标签及属性

#### 标签的嵌套关系

├── launch   
│&emsp;&emsp;└── node  
│&emsp;&emsp;&emsp;&emsp;&emsp;├── env  
│&emsp;&emsp;&emsp;&emsp;&emsp;├── [remap](####remap)   
│&emsp;&emsp;&emsp;&emsp;&emsp;├── rosparam  
│&emsp;&emsp;&emsp;&emsp;&emsp;└── param


#### [launch](http://wiki.ros.org/roslaunch/XML/launch)

根标签

#### [node](http://wiki.ros.org/roslaunch/XML/node)

注意： 因为无法从外部获得这个节点的初始化进度，所以并不能保证是按照launch文件中的node顺序依次启动的。所以设计程序时要保证所有的node都能以任何顺序进行启动。

必须的3个属性
* name  
  

* `pkg`  
  node所在的package，如usb_cam

* `type`  
  要运行的node，对应着可执行文件，如usb_cam_node  
  
可选的属性
* output  
  * log  
  默认参数。stdout/stderr输出会保存在`$ROS_HOME/log`文件中，stderr也会打印到屏幕。
  * screen  
  将stdout/stderr的输出打印到屏幕。

* respawn  
  默认为`false`。如果为`true`，则该node退出后会自动重启，重生（respawn）。


#### [param](http://wiki.ros.org/roslaunch/XML/param)

如果放置到`node`标签内，`param`参数会被作为私有参数。

* name  
  参数名称。参数名称可以通过package的使用文档来获得，如`image_view` package下的`image_view` node的参数有`autosize`,`filename_format`,`image_transport`,`window_name`  

* value  



#### [remap](http://wiki.ros.org/roslaunch/XML/remap)

为了匹配node之间的接口。特别使用已有的package，他们的接口都是固定的，如果node之间要通信的话，就要使用remap进行接口对接。

如，对于`image_view` node来说，其订阅`/image`这个topic，然后将发布到该topic上的message即图像显示出来。但是对于`usb_cam` node来说，其采集USB摄像头数据，然后将图像message发布到`/usb_cam/image_raw`这个topic上。那么对于`image_view`这个node，如果想要订阅到该topic就要remap `/image` to `/usb_cam/image_raw`。

两个属性，一起使用。

* from  
  原始名称
* to  
  目标名称

## 例子

下面是`usb_cam`的launch文件

``` xml
<launch>
  <node name="usb_cam" pkg="usb_cam" type="usb_cam_node" output="screen" >
    <param name="video_device" value="/dev/video0" />
    <param name="image_width" value="640" />
    <param name="image_height" value="480" />
    <param name="pixel_format" value="yuyv" />
    <param name="camera_frame_id" value="usb_cam" />
    <param name="io_method" value="mmap"/>
  </node>
  <node name="image_view" pkg="image_view" type="image_view" respawn="false" output="screen">
    <remap from="image" to="/usb_cam/image_raw"/>
    <param name="autosize" value="true" />
  </node>
</launch>
```
