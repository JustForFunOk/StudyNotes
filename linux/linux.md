# Linux

## ubutnu必备软件

* 中文输入法--[谷歌拼音](https://blog.csdn.net/lybhit/article/details/78663731)
    ``` bash
    1. 安装汉语语言包
    $ sudo apt-get install language-pack-zh-hans
    2. 安装谷歌拼音输入法
    $ sudo apt-get installfcitx-googlepinyin
    3. 输入方式切换为fcitx
    SystemSettings --> Language Support--> Lauguage --> Keyboard input method system中选择fcitx，重启或注销，重新进入。
    4. 配置输入法
    $ fcitx-configtool
    配置界面左下角，选择+号添加输入方法，选择Google Pinyin即可。
    ```
    中文简体和繁体之间的切换，桌面右上角点开谷歌拼音，点击`Traditional Chinese`即可切换到`Simplified Chinese`。

* 

## 设备

* [USB](./dev_usb.md)  
  * 权限
  * 多个USB管理 


## 通过SSH传输文件

1. 网线互联。一个开无线wifi热点，另一个连接？没有测试过
2. 将网段设置为同一网段，并ping通测试。
3. [第一次使用] 被控制方准备好环境    
    ``` bash
    # 被控制方要安装openssh-server,默认没有安装
    $ sudo apt-get install openssh-server
    # 查看状态
    $ sudo service ssh status
    # 若未启动，可启动
    $ sudo service ssh start
    ```
4. 通过ssh和远程主机建立连接。
    ``` bash
    # 控制方需要ssh工具，默认已安装在/usr/bin目录下
    # -X 打开X11图像界面
    $ ssh -X <远程主机user>@<远程主机ip地址>
    ``` 
5. 复制文件
   ``` bash
   # scp - secure copy (remote file copy program)
   # 更多内容参见 man scp
   # 将本地文件copy到远程主机
   $ scp <本地文件或文件夹路径> <远程主机user>@<远程主机ip地址>：<远程主机要放置文件的路径>
   # 除此之外，还可以在两台主机之间copy文件，从远程主机1拷贝到远程主机2
   $ scp <远程主机1的user>@<远程主机1的ip地址>：<远程主机1中要copy文件的路径> <远程主机2的user>@<远程主机2的ip地址>：<远程主机2中欲放置文件的路径>
   ```
6. bug  
   * Destination Host Unreachable  
     遇到过一次，ping不同同一网段其他IP，重启一下路由器就好了。


## 获取电脑硬件状态
获取CPU，Memory，MotherBoard等硬件的占用率，温度等。  
Python开源库：[psutil](https://github.com/giampaolo/psutil)

## 常见单词来源

|单词|来源|含义|举例|
|:---:|:---:|:---:|:---:|
|l|**l**ong|长列表|ls -**l** ~|
|ls|**l**i**s**t|列清单|ls ~|
|man|**man**ual|手册|man which|
|stat|**stat**us|状态|stat filename|


## 判断某个软件有没有被安装

Linux下不像WIN下对软件统一管理，如：apt方法安装的软件和dpkg安装的软件分别被各自独立管理。

1. apt方法安装的软件
   apt-cache policy firefox
2. 


[How can I find out if a specific program is installed? [duplicate]](https://askubuntu.com/questions/87415/how-can-i-find-out-if-a-specific-program-is-installed)

## Ubuntu工具

这些工具还可以在写shell脚本时进行调用，实现自动化

### /bin

|命令|功能|举例|备注|
|:--:|:--:|:--:|:--:|
|date|Display the current time in the given FORMAT, or set the system date.|date +%Y%m%d%H%M%S|`date`命令在sh脚本中很有用|



### /usr/bin

|命令|功能|举例|备注|
|:--:|:--:|:--:|:--:|
|diff|Compare FILES line by line.|diff ./a.txt ./b.txt|类似git diff </br> 相同返回0 不同返回1|
|find|search for files in a directory hierarchy|find -name <file_name>|比`ll -R`好用，支持正则|
|pkg-config|The  top program provides a dynamic real-time view of a running system.|pkg-config --modverison opencv|查询版本等|
|stat|Display file or file system status.|stat filename|
|touch|Update the access and modification times of each FILE to the current time.</br>  A FILE argument that does not exist is created empty|touch filename|常用来创建空文件|
|top|The  top program provides a dynamic real-time view of a running system.|top|可以获得进程PID|


### /usr/sbin

|命令|功能|举例|备注|
|:--:|:--:|:--:|:--:|
|service|run a System V init script|sudo service ssh start|更接近操作系统底层的命令？|
|usermod|modify a user account|sudo usermod -aG dialout $USER||
|kill|modify a user account|sudo usermod -aG dialout $USER||
|v4l2-ctl|An application to control video4linux drivers|v4l2-ctl --list-formats-ext|获取摄像头支持的分辨率|



## 创建自己的bash命令

如cd之后经常会接ls，将这两步结合成一步cs。  

将下面函数添加到`~/.bashrc`文件中，`source ~/.bashrc`后即可使用`cs`命令。

``` bash
function cs () {
    cd "$@" && ls
    }
```

[How can I create an alias for cd and ls?](https://askubuntu.com/questions/16106/how-can-i-create-an-alias-for-cd-and-ls)  
[Make cd automatically ls](https://unix.stackexchange.com/questions/20396/make-cd-automatically-ls)


使用别名alias，同样也添加到`～/.bashrc`文件中
``` bash
alias ll='ls -l'
```
[How do I create a permanent Bash alias?](https://askubuntu.com/questions/17536/how-do-i-create-a-permanent-bash-alias)

## /etc/udev/.list文件的编写

[1](https://www.ibm.com/developerworks/cn/linux/l-cn-udev/index.html) 这个讲的挺清楚，包括语法，中文

尝试了很多方法都不能成功链接摄像头，串口的设备可以。

## 保存控制台输出到文件

使用重定向`>`

如将catkin build打印信息保存到log.txt文件。
``` bash
$ catkin build > log.txt
```
## 记录所有操作以及输出到文件


