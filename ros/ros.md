# ROS








## IDE



### 小工具

* tree  
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

## 安装
* 一键安装脚本

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


## 通信方式

* Topic  
* Service  
* Parameter Service  
* Actionlib

## [CMakeLists.txt](ros_cmakelists.md)

std_msg包括以下种类，使用std_msg时无需自定义msg  


## rosbag



### rosbag播放工具--[webviz](https://webviz.io/)  

* 拖拽`.bag`文件即可播放
* 可调整layout，可导入导出layout文件
* 可使用html技术隐藏前端部件，如时间戳，`style=“display:none”`

### *.bag.active恢复

`rosbag record <topic>`会保存成`.bag.active`为后缀的文件，需要恢复成`.bag`文件才能播放。
``` bash
$ rosbag reindex *.bag.active
$ rosbag fix *.bag.active repaired.bag
```