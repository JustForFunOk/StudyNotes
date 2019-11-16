# 配置环境

## 安装

``` bash
sudo apt-get install 
chromium-browser  # chromium can install through apt
openssh-server    # for remote debug

```

## 配置

``` bash

## Install ROS ##

sudo sh -c 'echo "deb http://packages.ros.org/ros/ubuntu $(lsb_release -sc) main" > /etc/apt/sources.list.d/ros-latest.list'
sudo apt-key adv --keyserver 'hkp://keyserver.ubuntu.com:80' --recv-key C1CF6E31E6BADE8868B172B4F42ED6FBAB17C654
sudo apt-get update

sudo apt-get install ros-kinetic-desktop-full

sudo rosdep init
rosdep update

echo "source /opt/ros/kinetic/setup.bash" >> ~/.bashrc
source ~/.bashrc

sudo apt install python-rosinstall python-rosinstall-generator python-wstool build-essential

## python-catkin-tools ##

sudo apt-get install python-catkin-tools




## USB ##
$ sudo usermod -aG dialout $USER
# [test] 
$ groups $USER

## USB Camera ##

# $ ll /sys/class/video4linux
# lrwxrwxrwx  1 root root 0 10月 24 20:56 video0 -> ../../devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/video4linux/video0/
# lrwxrwxrwx  1 root root 0 10月 24 20:56 video1 -> ../../devices/pci0000:00/0000:00:14.0/usb1/1-4/1-4:1.0/video4linux/video1/
# lrwxrwxrwx  1 root root 0 10月 24 20:56 video2 -> ../../devices/pci0000:00/0000:00:14.0/usb1/1-5/1-5:1.0/video4linux/video2/
# lrwxrwxrwx  1 root root 0 10月 24 20:56 video3 -> ../../devices/pci0000:00/0000:00:14.0/usb1/1-6/1-6:1.0/video4linux/video3/
# $ ls /dev/ | grep video
# video0
# video1
# video2
# video3

#  --------------------
# |  Left   |   Right  |
# | 1-4:1.0 |  1-6:1.0 |
# |---------|----------|
# |  Front  |   Rear   |
# | 1-3:1.0 |  1-5:1.0 |
#  --------------------

# $ cd /etc/udev/rules.d/
# $ sudo touch 10-local.rules

# add content to file

ACTION=="add",KERNELS=="1-3:1.0",SUBSYSTEMS=="usb",MODE:="0777",SYMLINK+="AreaViewFront"
ACTION=="add",KERNELS=="1-4:1.0",SUBSYSTEMS=="usb",MODE:="0777",SYMLINK+="AreaViewLeft"
ACTION=="add",KERNELS=="1-5:1.0",SUBSYSTEMS=="usb",MODE:="0777",SYMLINK+="AreaViewRear"
ACTION=="add",KERNELS=="1-6:1.0",SUBSYSTEMS=="usb",MODE:="0777",SYMLINK+="AreaViewRight"




```