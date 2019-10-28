# roslaunch

[roslaunch官方文档](http://wiki.ros.org/roslaunch)

* roslaunch is a tool for easily launching multiple ROS nodes locally and remotely via SSH, as well as setting parameters on the Parameter Server.   
  roslaunch用来启动多个node，设置参数

* It includes options to automatically respawn processes that have already died.  
  
* roslaunch takes in one or more XML configuration files (with the .launch extension) that specify the parameters to set and nodes to launch, as well as the machines that they should be run on.


roslaunch工具安装在/opt/ros/kinetic/bin/目录下。



## *.launch格式

[launch文件格式官方文档](http://wiki.ros.org/roslaunch/XML)

.launch文件使用XML格式，是一种标记语言。


### 标签

#### [`<param>`](http://wiki.ros.org/roslaunch/XML/param)


  


