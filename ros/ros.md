# ROS








## IDE


## 安装

### Kinetic
* 一键安装脚本

### 必装工具

#### catkin-tools
ros自带的catkin_make工具并不好用，所以额外安装catkin-tools工具  
使用手册：[Catkin Command Line Tools](https://catkin-tools.readthedocs.io/en/latest/index.html)
``` bash
#  安装ROS之后再安装catkin，否则还要先添加源
$ sudo apt-get install python-catkin-tools
```
**Att**：这里要弄清楚，这里的catkin是命令行工具,能在bash中执行`catkin build`等命令，这个工具独立于ros，安装在/usr/bin下。而`rospack find catkin`也能找到catkin，路径如下，`/opt/ros/kinetic/share/catkin`，不过这个是package，是要放到`CMakeLists.txt`中`find_package(catkin REQUIRED)`。

### 辅助工具

#### tree  
可以直观的列出指定文件夹下所有文件的**结构层次**
``` bash
# 安装
$ sudo apt-get install tree
# 使用说明
$ tree --help
# 常用命令
# 显示1级目录
$ tree -L 1 <floder_name>  # -L level Descend only level directories deep.
```


## ROS简介
* ROS包含的四大模块
* 为什么要用ROS？
* 起源
* 版本

## [Workspace](workspace.md)
* 初始化工作空间、配置环境
* workspace目录结构

## [Package](package.md)
* 创建、编译新的package
* package目录结构
* 常用指令
* 封装package供其他包调用


## 通信方式

* Topic  
* Service  
* Parameter Service  
* Actionlib

## [CMakeLists.txt](ros_cmakelists.md)


## roslaunch



