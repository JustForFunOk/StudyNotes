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



## 通过SSH传输文件

1. 网线互联。一个开无线wifi热点，另一个连接？没有测试过
2. 将网段设置为同一网段，并ping通测试。
3. 通过ssh和远程主机建立连接。
    ``` bash
    # -X 打开X11图像界面
    $ ssh -X <远程主机user>@<远程主机ip地址>
    ``` 
4. 复制文件
   ``` bash
   # scp - secure copy (remote file copy program)
   # 更多内容参见 man scp
   # 将本地文件copy到远程主机
   $ scp <本地文件或文件夹路径> <远程主机user>@<远程主机ip地址>：<远程主机要放置文件的路径>
   # 除此之外，还可以在两台主机之间copy文件，从远程主机1拷贝到远程主机2
   $ scp <远程主机1的user>@<远程主机1的ip地址>：<远程主机1中要copy文件的路径> <远程主机2的user>@<远程主机2的ip地址>：<远程主机2中欲放置文件的路径>
   ```

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

### /bin

|命令|功能|举例|备注|
|:--:|:--:|:--:|:--:|
|date|Display the current time in the given FORMAT, or set the system date.|date +%Y%m%d%H%M%S|`date`命令在sh脚本中很有用|



### /usr/bin

|命令|功能|举例|备注|
|:--:|:--:|:--:|:--:|
|stat|Display file or file system status.|stat filename|
|touch|Update the access and modification times of each FILE to the current time.</br>  A FILE argument that does not exist is created empty|touch filename|常用来创建空文件|