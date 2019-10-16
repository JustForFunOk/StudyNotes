# 环境变量

查看当前环境变量
``` bash
$ printenv
```

## PATH
我们在任何路径下都能执行`ls`,`cd`等命令，这是因为放置这些命令的路径被加入到了环境变量`PATH`中。

### 查看环境变量PATH
查看当前用户的环境变量PATH  
``` bash
echo $PATH
```
输出如下：
``` txt
/opt/ros/kinetic/bin:/home/sunjian4/bin:/home/sunjian4/.local/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin
```
整理之后如下：
 ``` txt
/opt/ros/kinetic/bin
/home/sunjian4/bin
/home/sunjian4/.local/bin
/usr/local/sbin
/usr/local/bin
/usr/sbin
/usr/bin
/sbin
/bin
/usr/games
/usr/local/games
/snap/bin
```
* 每个目录之间以`:`隔开
* 目录有先后顺序之分，在前面的路径有更高的优先级
* 不同的用户有不同的环境变量，如`root`用户就只有后面几个环境变量
  
#### 环境变量放置的路径
* root的环境变量通过`/etc/environment`文件设置：
    ``` bash
    PATH="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games"
    ```
* 其他用户的环境变量通过`~/.profile`文件以及`~/.bashrc`文件设置：
    ``` bash
    # if running bash
    if [ -n "$BASH_VERSION" ]; then
        # include .bashrc if it exists
        if [ -f "$HOME/.bashrc" ]; then
	        . "$HOME/.bashrc"
        fi
    fi
    # set PATH so it includes user's private bin directories
    PATH="$HOME/bin:$HOME/.local/bin:$PATH"
    ```  
    
    注意：`~/.bash_profile`,`~/.bash_login`,`~/.profile`三个文件优先级越来越低，当优先级高的文件存在时则不会解析优先级低的文件，在我的电脑里只有`~/.profile`文件，故会解析该文件。

总结下来，ubuntu中的PATH会通过多个文件，甚至多次引用进行设置，不像windows中那么集中明了。

## 以下放到ROS环境变量设置的部分里面

其中，`/opt/ros/kinetic/bin`这个环境变量设置的过程较为复杂，其通过文件
`~/.profile` --> `~/.bashrc` --> `/opt/ros/kinetic/setup.bash` --> `/opt/ros/kinetic/setup.sh` --> `/opt/ros/kinetic/_setup_util.py` --> `/tmp/setup.sh.XXXXXXXXXX`的层层调用。

其中， `setup.sh`
``` bash
: ${_CATKIN_SETUP_DIR:=/opt/ros/kinetic}
_SETUP_UTIL="$_CATKIN_SETUP_DIR/_setup_util.py"

CATKIN_SHELL=$CATKIN_SHELL "$_SETUP_UTIL" $@ ${CATKIN_SETUP_UTIL_ARGS:-} >> "$_SETUP_TMP"
. "$_SETUP_TMP"
```
核心步骤放到了`_setup_util.py`文件中，执行后生成最终的`/tmp/setup.sh.XXXXXXXXXX`

其中，`$_SETUP_TMP`即为文件`/tmp/setup.sh.XXXXXXXXXX`，其中的`XXXXXXXXXX`每次打开bash时都不一样，像是一串随机字符串。这样做的目的？


其中，`setup.sh.oTirPyaDGc`文件的内容如下：
``` bash
# prepend folders of workspaces to environment variables
export CMAKE_PREFIX_PATH="/opt/ros/kinetic"
export LD_LIBRARY_PATH="/opt/ros/kinetic/lib:/opt/ros/kinetic/lib/x86_64-linux-gnu"
export PATH="/opt/ros/kinetic/bin:$PATH"
export PKG_CONFIG_PATH="/opt/ros/kinetic/lib/pkgconfig:/opt/ros/kinetic/lib/x86_64-linux-gnu/pkgconfig"
export PYTHONPATH="/opt/ros/kinetic/lib/python2.7/dist-packages"
# found environment hooks in workspaces
export _CATKIN_ENVIRONMENT_HOOKS_COUNT="11"
export _CATKIN_ENVIRONMENT_HOOKS_0="/opt/ros/kinetic/etc/catkin/profile.d/1.ros_distro.sh"
export _CATKIN_ENVIRONMENT_HOOKS_0_WORKSPACE="/opt/ros/kinetic"
export _CATKIN_ENVIRONMENT_HOOKS_1="/opt/ros/kinetic/etc/catkin/profile.d/1.ros_etc_dir.sh"
export _CATKIN_ENVIRONMENT_HOOKS_1_WORKSPACE="/opt/ros/kinetic"
export _CATKIN_ENVIRONMENT_HOOKS_2="/opt/ros/kinetic/etc/catkin/profile.d/1.ros_package_path.sh"
export _CATKIN_ENVIRONMENT_HOOKS_2_WORKSPACE="/opt/ros/kinetic"
export _CATKIN_ENVIRONMENT_HOOKS_3="/opt/ros/kinetic/etc/catkin/profile.d/1.ros_version.sh"
export _CATKIN_ENVIRONMENT_HOOKS_3_WORKSPACE="/opt/ros/kinetic"
export _CATKIN_ENVIRONMENT_HOOKS_4="/opt/ros/kinetic/etc/catkin/profile.d/10.rosbuild.sh"
export _CATKIN_ENVIRONMENT_HOOKS_4_WORKSPACE="/opt/ros/kinetic"
export _CATKIN_ENVIRONMENT_HOOKS_5="/opt/ros/kinetic/etc/catkin/profile.d/10.roslaunch.sh"
export _CATKIN_ENVIRONMENT_HOOKS_5_WORKSPACE="/opt/ros/kinetic"
export _CATKIN_ENVIRONMENT_HOOKS_6="/opt/ros/kinetic/etc/catkin/profile.d/99.roslisp.sh"
export _CATKIN_ENVIRONMENT_HOOKS_6_WORKSPACE="/opt/ros/kinetic"
export _CATKIN_ENVIRONMENT_HOOKS_7="/opt/ros/kinetic/etc/catkin/profile.d/05.catkin_make.bash"
export _CATKIN_ENVIRONMENT_HOOKS_7_WORKSPACE="/opt/ros/kinetic"
export _CATKIN_ENVIRONMENT_HOOKS_8="/opt/ros/kinetic/etc/catkin/profile.d/05.catkin_make_isolated.bash"
export _CATKIN_ENVIRONMENT_HOOKS_8_WORKSPACE="/opt/ros/kinetic"
export _CATKIN_ENVIRONMENT_HOOKS_9="/opt/ros/kinetic/etc/catkin/profile.d/15.rosbash.bash"
export _CATKIN_ENVIRONMENT_HOOKS_9_WORKSPACE="/opt/ros/kinetic"
export _CATKIN_ENVIRONMENT_HOOKS_10="/opt/ros/kinetic/etc/catkin/profile.d/20.transform.bash"
export _CATKIN_ENVIRONMENT_HOOKS_10_WORKSPACE="/opt/ros/kinetic"
```
其中的`export PATH="/opt/ros/kinetic/bin:$PATH"`就进行了环境变量的设置。

### 修改环境变量PATH
添加环境变量
``` bash

```
删除环境变量


### 参考
1. [EnvironmentVariables](https://help.ubuntu.com/community/EnvironmentVariables)
2. [How to add a directory to the PATH?
](https://askubuntu.com/questions/60218/how-to-add-a-directory-to-the-path)