# workspace

## [初始化工作空间并配置环境](http://wiki.ros.org/catkin/Tutorials/create_a_workspace)

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

## 工作空间目录结构

`catkin_ws` 工作空间
&emsp;&emsp;├──`build` 存放cmake和catkin缓存和中间文件
&emsp;&emsp;├──`devel` 存放目标文件(头文件、可执行文件、动、静态链接库)
&emsp;&emsp;└──`src` 存放源文件
&emsp;&emsp;&emsp;&emsp;├──`package1` 每个[package的目录结构](#package目录结构)
&emsp;&emsp;&emsp;&emsp;├──`package2`
&emsp;&emsp;&emsp;&emsp;├──`folder_name` 因为catkin**会在src目录下递归的查找每一个package**
&emsp;&emsp;&emsp;&emsp;│&emsp;&emsp;├──`package3` 所以可以将package放置在子文件夹下
&emsp;&emsp;&emsp;&emsp;│&emsp;&emsp;└──`package4`
&emsp;&emsp;&emsp;&emsp;└──`package#`

## 多个workspace

source ./devel/setup.bash会覆盖而不是追加之前的路径.

所以在~/.bashrc中
``` shell
source ~/catkin_ws/devel/setup.bash
source ~/catkin_ws1/devel/setup.bash
```
最终只会source catkin_ws1的workspace.

若存在多个workspace,需要在使用前主动source目标workspace的setup.bash

### 参考
* [Sourcing from multiple workspaces](https://answers.ros.org/question/205976/sourcing-from-multiple-workspaces/)