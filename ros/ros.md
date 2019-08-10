# ROS

## ROS简介

ROS提供了类似于操作系统的功能（硬件抽象、底层设备控制、常用函数的实现、进程间消息传递、包管理），其是运行在Liunx上的中间件，连接了操作系统和用户写的程序。  

### ROS主要包含？

* 框架  
    通信框架。包括分布式架构（同时运行多个节点，扩展性好）、进程管理、进程间通信。  
* 工具  
    提供了很多基础工具，涵盖仿真(Gazebo)、数据可视化(Rviz)、图形界面(Rqt)、数据记录。  
* 功能  
    提供了很多基础功能包，涵盖控制、规划、视觉、建图等，可以直接使用。  
* 社区  
    软件包管理、文档、教程。ROS WiKi和Github



### 为什么要用ROS？

设计机器人工作量巨大：机械结构、电子电路、驱动程序、通信架构、组装集成、调试、上层算法。

参照操作系统，每个厂商按照操作系统规定的模型来提供驱动，开发者无需关心底层硬件。

同样机器人零部件厂商，如机械臂、底盘、摄像头、激光雷达等，都在机器人通用的软件平台上进行开发，用户买回来直接就能集成到自己的系统中，ROS就是这样一个平台。

### 起源

2000年，斯坦福大学，人工智能实验室，吴恩达也参与其中。



## IDE



### 小工具

* tree  
    可以直观的列出指定文件夹下所有文件的**结构层次**
    ``` bash
    # 安装
    sudo apt-get install tree
    # 使用说明
    tree --help
    # 常用命令
    ```


## 工作空间

### [创建工作空间并进行编译](http://wiki.ros.org/catkin/Tutorials/create_a_workspace)

``` bash
# 1.创建工作空间
$ mkdir -p ~/catkin_ws/src  # -p --parents 表示递归的创建文件夹，包括父文件夹
# 2.初始编译
$ cd ~/catkin_ws/
$ catkin_make  # 会在src文件夹下创建CMakeLists.txt链接文件，并编译生成build和devel文件夹，以及devel文件夹中的setup.bash和setup.zsh文件
# 3.设置ROS环境变量
$ echo "source ~/catkin_ws/devel/setup.bash" >> ~/.bashrc  # 将路径添加到~/.bashrc中，永久有效，否则每次在新终端使用自己工作空间中的包都需要source ~/catkin_ws/devel/setup.bash
$ source ~/.bashrc # 在本终端中立即生效
# 4.[可选]测试是否成功
$ echo $ROS_PACKAGE_PATH  # 检查ROS包路径，添加成功则输出：/home/<user>/catkin_ws/src:/opt/ros/kinetic/share

```

### 工作空间目录结构

`catkin_ws` 工作空间  
&emsp;&emsp;|—`build` 存放cmake和catkin缓存和中间文件  
&emsp;&emsp;|—`devel` 存放目标文件(头文件、可执行文件、动、静态链接库)  
&emsp;&emsp;|—`src` 存放源文件  
&emsp;&emsp;&emsp;&emsp;|—`package1` 每个[package的目录结构](#package目录结构)     
&emsp;&emsp;&emsp;&emsp;|—`package2`  
&emsp;&emsp;&emsp;&emsp;|—`folder_name` 因为catkin**会在src目录下递归的查找每一个package**  
&emsp;&emsp;&emsp;&emsp;|&emsp;&emsp;&emsp;|—`package3` 所以可以将package放置在子文件夹下  
&emsp;&emsp;&emsp;&emsp;|&emsp;&emsp;&emsp;|—`package4`  
&emsp;&emsp;&emsp;&emsp;|—`packagen` 


## package

ROS软件的基本组织形式  
catkin编译的基本单元  
一个package可以包含多个可执行文件(节点)

### [创建新的package并编译](http://wiki.ros.org/catkin/Tutorials/CreatingPackage)

``` bash
# 1.创建新的package
$ cd ~/catkin_ws/src  # 注意这个路径，会在src目录下创建package，也可以在自定义的子文件夹下创建
$ catkin_create_pkg <package_name> [depend1] [depend2] [depend3]  # 在当前目录创建package，依赖包常用的有roscpp rospy std_msgs, 可后续在package.xml和CMakeLists.txt中添加其他依赖包
# 2.编译
$ cd ~/catkin_ws
$ catkin_make
```

### package目录结构

`package`  
&emsp;&emsp;|—`CMakeLists.txt` 规定catkin编译的规则（源文件、依赖项、目标文件）  
&emsp;&emsp;|—`package.xml` 定义package的属性（包名、版本号、作者、依赖等） 这两个文件构成package最小构成单元  
&emsp;&emsp;|—`scripts` *.py *.sh源文件  
&emsp;&emsp;|—`src` *.cpp源文件  
&emsp;&emsp;|—`include` *.h源文件   
&emsp;&emsp;|—`msg` *.msg通信格式  
&emsp;&emsp;|—`srv` *.srv通信格式  
&emsp;&emsp;|—`action` *.action通信格式  
&emsp;&emsp;|—`config` *.yaml配置文件  
&emsp;&emsp;|—`launch` *.launch启动文件  

### 常用指令

1. 创建一个pkg
    ``` bash
    $ catkin_create_pkg <new_package_name> <depend1> <depend2> # 注意先切换到pkg存放路径
    ```
2. 查找某个pkg地址  
    ``` bash
    $ rospack find <package_name>  # 会在ROS_PACKAGE_PATH中的目录下寻找包，应用于pkg非常多时查找pkg
    ```
3. 列出本机所有的pkg
    ``` bash
    $ rospack list  # 列出ROS_PACKAGE_PATH中的目录下所有pkg名及地址
    ```
4. 跳转到某个pkg的路径下
    ``` bash
    $ roscd <package_name>  # cd
    ```
5. 列出某个pkg目录下的文件信息  
    ``` bash
    $ rosls <package_name>  # ls
    ```
6. 编辑某个pkg下的某个文件
    ``` bash
    $ rosed <package_name> <file_name> # edit
    ```
7. 安装某个pkg所需的依赖
    ``` bash
    $ rosdep install <package_name> # 应用于从其他地方获取pkg后，需要安装该pkg的依赖的场景
    ```
8. 查看某个pkg所需的依赖
    ``` bash
    $ rospack depends1 <package_name>  # 包的直接依赖，一级依赖
    $ rospack depends <package_name>  # 包的所有依赖，包括依赖的依赖
    ```

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
2. 显示发布到某个topic上的内容
    ``` bash
    $ rostopic echo <topic_name>
    ```    

### Message

常用的msg类型包括： 

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
    ```


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