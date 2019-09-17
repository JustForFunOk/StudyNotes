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

## 通信方式1：Topic和Message

### Topic
* Node间通过publish-subscribe机制通信
* ROS中的**异步**通信方式，发布者只管向topic发送消息，订阅者只管从topic上接收消息  
  
#### 常用指令

1. 列出当前所有topic
    ``` bash
    $ rostopic list
    ```
2. 显示某个topic上的属性信息(消息类型、发布者、订阅者)
    ``` bash
    $ rostopic info <topic_name>
    ```     
3. 显示发布到某个topic上的内容
    ``` bash
    $ rostopic echo <topic_name>
    ```    

### Message

#### std_msgs
常用的msg类型包括： 


#### 自定义msgs

使用自定义的msg格式时，在`/msg`文件夹中新建`<msg_name>.msg`文件。  
通过`catkin_make`编译后，会生成`~/catkin_wa/devel/include/<package_name>/<msg_name>.h`头文件。  
通过这样我们只需在`.msg`文件中定一个消息格式即可，编译后会自动生成对应的`.h`文件。  
`.cpp`文件中添加对应头文件即可使用该消息。

#### 常用指令

1. 列出系统上所有msg
    ``` bash
    $ rosmsg list
    ```
2. 显示某个msg的内部结构
    ``` bash
    $ rosmsg show <msg_name>
创建新的package并编译  ```


### 代码模板

消息定义  
`/msg/gps.msg`
``` text
float32 x
float32 y
string state
```


发布者
``` cpp
#include <ros/ros.h>
#include <<package_name>/<msg_name>.h>
int main(int argc, char** argv){
    ros::init(argc, argv, "<node_name>");
    ros::NodeHandle nh;
}




```

程序解析：  
1. `#include <ros/ros.h>`  
    ros程序里必加头文件
2. `#include <<package_name>/<msg_name>.h>`  
   `<package_name>`表示包名，`<msg_name>.h`表示通过`.msg`文件生成的头文件。包含该头文件以使用自定义的消息
3. `int main(int argc, char** argv){`  
    程序入口  
4. `ros::init(argc, argv, "<node_name>");`  
    解析参数，命名节点，<node_name>表示节点名，名称自己定  
5. `ros::NodeHandle nh;`  
    创建句柄，实例化node。句柄可以理解为一个把手，其提供了操作node的很多方法。 

}


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