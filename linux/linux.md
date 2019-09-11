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
`-` 类型为文件，其他类型:`l`为链接，`c`为，  
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

插入主机的USB设备会按照顺序在`/dev`下分配索引，这样无法固定。下面操作可以将自定义名称与USB口关联起来，无论设备何时插入该USB口，该设备必会分配到固定的自定义名称。

1. 查询USB端口对应的设备号
   ``` bash
   $ ls /sys/class/tty/ttyUSB* -l
   ```
   通过拔插设备确定USB端口和输出信息的对应关系。  
   如，连接两个设备时输出如下：  
    lrwxrwxrwx 1 root root 0 9月  10 17:35 /sys/class/tty/ttyUSB0 -> ../../devices/pci0000:00/0000:00:14.0/usb1/1-1/<font color=#ff0000>1-1:1.0</font>/ttyUSB0/tty/ttyUSB0  
    lrwxrwxrwx 1 root root 0 9月  10 17:35 /sys/class/tty/ttyUSB1 -> ../../devices/pci0000:00/0000:00:14.0/usb1/1-2/<font color=#ff0000>1-2:1.0</font>/ttyUSB1/tty/ttyUSB1  
    这里的`1-1:1.0`对应右边的USB口，`1-2:1.0`对应左边的USB口。

2. 创建并编辑配置文件
   ``` bash
   $ vi /etc/udev/rules.d/10-local.rules
   ```
   `10-local.rules`这个文件的名称和后缀有什么讲究吗？  
   文件中加入
   ``` txt
   ACTION=="add",KERNELS=="1-1:1.0",SUBSYSTEMS=="usb",MODE:="0777",SYMLINK+=right"
   ACTION=="add",KERNELS=="1-2:1.0",SUBSYSTEMS=="usb",MODE:="0777",SYMLINK+="left"
   ```
3. 重新插入USB即可生效。
4. [可选]测试  
   ``` bash
   ls /dev -l | grep ttyUSB
   ```  
   如果先插入左边的USB口，后插右边的USB口，会输出：
   ``` txt
   lrwxrwxrwx  1 root root             7 9月  11 15:22 left -> ttyUSB0
   lrwxrwxrwx  1 root root             7 9月  11 15:22 right -> ttyUSB1
   crwxrwxrwx  1 root dialout 188,     0 9月  11 15:22 ttyUSB0
   crwxrwxrwx  1 root dialout 188,     1 9月  11 15:22 ttyUSB1
   ```
   反之，会输出：
   ``` txt
   lrwxrwxrwx  1 root root             7 9月  11 15:24 left -> ttyUSB1
   lrwxrwxrwx  1 root root             7 9月  11 15:23 right -> ttyUSB0
   crwxrwxrwx  1 root dialout 188,     0 9月  11 15:23 ttyUSB0
   crwxrwxrwx  1 root dialout 188,     1 9月  11 15:24 ttyUSB1
   ```
   由此，可以实现，无论设备插入顺序，只要USB口和设备对应起来就不会乱。若要使用左边USB口的设备则通过`/dev/left`，若要使用右边的USB口的设备则通过`/dev/right`。 

总结：  
1. 多个相同的设备也可使用这种方法；
2. 设备位置确定之后就不能变了，每个设备就只能插到固定的USB口上；
3. 为端口起别名时最好直接以设备功能命名，不要使用`ttyUSB`，以免引起混乱
4. 添加链接后，之前的`ttyUSB0`等还能正常使用？
5. 强行使用`ttyUSB*`命名时，若`ttyUSB0`正好对应上`ttyUSB0`时不会显示链接，多个`ttyUSB*`之间交叉对应时会发生莫名错误，所以避免这样使用。
   
效果还未测试，链接文件的群组是root，而不是dialout会不会影响使用。


参考：[[1]](https://blog.csdn.net/weixin_38717571/article/details/83045040)


另一种通过绑定USB设备识别号的方法？  




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