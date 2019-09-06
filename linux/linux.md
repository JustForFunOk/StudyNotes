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

## 计算机硬件

* 进制  
数据容量使用二进制，1GB=1024x1024x1024B  
速度单位使用十进制，1GHz=1000x1000x1000Hz

* 网络  
网络中使用位(bit)为单位，常说的20M带宽，其单位为`Mbit/s`，而我们下载时显示的速度以数据容量衡量，其单位为字节(Byte)，所以20M带宽,其理论最大传输速度为2.5MB/s。  

* 主板  
主板上的芯片组**早期**通常分为两个网桥来控制各组件通信：  
    * 北桥  
    负责连接速度较快的CPU、内存与显卡等组件  
    * 南桥  
    负责连接速度较慢的设备接口，包括硬盘、USB设备、网卡等  
    
    由于北桥最重要的就是CPU与内存之间的桥接，所以目前主流架构中，**大多将北桥的内存控制器整合到了CPU当中**。

* CPU  
以i7-8700为例：  
处理器内核数：6核心  
处理器线程数：12线程(超线程技术Hyper-Threading)  
处理器基础频率：3.2GHz  
字长：CPU每次能够处理的数据量，我们所说的32位或64位，主要是依据CPU解析的字长而来的。  



* 内存条  
内存条主要组件为动态随机存取内存(Dynamic Random Access Memory,DRAM)  
以DDR4 3000 8G为例，,DDR4中DDR是指双倍数据传输速度(Double Data Rate,DDR)，内存条的带宽=频率x位宽=3000MHzx64bit=3000MHzx8Byte=24GB/s  
多通道，如主板支持双通道，两条内存条可使位宽达到128bit  

* 二级缓存  
二级缓存(L2 Cache)属于静态随机存取内存(Static Random Access Memory,SRAM)。  
因为要整合到CPU内部，L2内存的速度要和CPU频率相同，DRAM无法达到这个速度，而SRAM在设计中使用的晶体管数量较多，价格较高，且不易做成大容量。  

* 显卡  


* 硬盘  
以硬盘的SATA3.0接口为例，其支持最大带宽6Gbit/s，则最大传输速度=6/(8+2)=600MB/s，8表示8位数据位，2表示2位校验位。  
以移动硬盘USB接口为例，USB2.0仅有60MB/s的理论传输速率，USB3.0可达500MB/s，USB3.1可达1000MB/s。  
但机械硬盘由于其物理组成的限制，一般极限速度在150MB/s～200MB/s之间。所以对于移动机械硬盘只需USB3.0即可，而移动固态硬盘就支持USB3.1。



## 权限

### 文件权限

文件基本权限有9个：`-rwxrwxrwx`  
`-` 类型为文件，其他类型  
`r` = read 读  
`w` = write 写  
`x` = execute 执行  
从左向右`rwx`依次为拥有者(owner)、所属群组(group)、其他人(others)三种身份

#### 修改文件权限

`chmod` = **ch**ange **mod**e  

``` bash
## 数字类型修改文件权限 ##
chmod 777 <file_name>  # 将文件权限修改为，所有人，可读可写可执行
# r:4 w:2 x:1
# 777表示[4+2+1][4+2+1][4+2+1]，其余类推

## 符号类型修改文件权限 ##
chmod u=rwx,g=rwx,o=r <file_name>  # 用户和组用户成员，可读可写可执行,其他人只可读
chmod a+x <file_name>  # 为文件添加所有人可执行权限，其余权限保持不变
chmod a-x <file_name>  # 所有人均不可执行，其余权限保持不变
# 用户: u = user, g = group, o = other, a = all
# 权限: +添加权限 -移除权限 =设置权限
```
数字类型方法：直接修改为目标权限，不管文件之前的权限。  
符号类型方法：修改某些权限，而其余权限保持不变。

## 设备

### 串口
若要获得串口使用权限,需要将当前用户添加到dialout组中
``` bash
# 将用户添加到dialout组中
$ sudo usermod -aG dialout $USER
# [可选]检查
$ groups $USER
```
### 多个USB设备的管理

插入主机的USB设备会按照顺序在`/dev`下分配索引，这样无法固定。下面操作可以将索引与USB口关联起来，无论设备何时插入该USB口，该设备必会分配到固定的索引。

https://blog.csdn.net/weixin_38717571/article/details/83045040


ACTION=="add",KERNELS=="1-2:1.0",SUBSYSTEMS=="usb",MODE:="0777",SYMLINK+="name"

ls /sys/class/tty/ttyUSB* -l


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
