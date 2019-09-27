# package

* ROS软件的基本组织形式  
* catkin编译的基本单元  
* 一个package可以包含多个可执行文件(节点)

## [创建新的package并编译](http://wiki.ros.org/catkin/Tutorials/CreatingPackage)

``` bash
# 1.切换到package要放置的目录
$ cd ~/catkin_ws/src  # 注意这个路径，会在src目录下创建package，也可以在自定义的子文件夹下创建
# 2.创建新的package
$ catkin_create_pkg <package_name> [depend1] [depend2] [depend3]  # 在当前目录创建package，依赖包常用的有roscpp rospy std_msgs, 可后续在package.xml和CMakeLists.txt中添加其他依赖包
# 2.或者clone已有工程
$ git clone xxxxxx.git <package_name>
# 3.切换到工作空间根目录
$ cd ~/catkin_ws
# 4.编译这个包
[1/2]$ catkin build <package_name1> <package_name2> # catkin build方式
[2/2]$ catkin_make -DCATKIN_WHITELIST_PACKAGES="<package_name1>;<package_name2>"  # catkin_make方式
# 5.或者编译当前工作空间中的所有包
[1/2]$ catkin build
[2/2]$ catkin_make
```
其中，关于编译的两种方式，尽量使用`catkin build`代替`catkin_make`，[原因在这](https://robotics.stackexchange.com/questions/16604/ros-catkin-make-vs-catkin-build)。  
要使用`catkin build`需要安装`sudo apt-get install python-catkin-tools`

## package目录结构

`package`  
&emsp;&emsp;├──`CMakeLists.txt` 规定catkin编译的规则（源文件、依赖项、目标文件）  
&emsp;&emsp;├──`package.xml` 定义package的属性（包名、版本号、作者、依赖等）  
&emsp;&emsp;├──`scripts` *.py *.sh源文件  
&emsp;&emsp;├──`src` *.cpp源文件  
&emsp;&emsp;├──`include` *.h源文件   
&emsp;&emsp;├──`msg` *.msg通信格式  
&emsp;&emsp;├──`srv` *.srv通信格式  
&emsp;&emsp;├──`action` *.action通信格式  
&emsp;&emsp;├──`config` *.yaml配置文件  
&emsp;&emsp;└──`launch` *.launch启动文件  

其中，前两个文件构成package最小构成单元。

`catkin_create_pkg`命令创建新的package时会生成如下目录结构  
├── CMakeLists.txt  
├── include  
│&emsp;&emsp;└── <package_name>  
├── package.xml  
└── src  
后续根据需求新建其他文件夹及文件。


## 常用指令

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