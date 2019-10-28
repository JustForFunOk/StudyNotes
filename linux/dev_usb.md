# 设备

## USB串口
若要获得串口使用权限,需要将当前用户添加到dialout组中
``` bash
# 1.将用户添加到dialout组中
# -a append -G groups
$ sudo usermod -aG dialout $USER
# 2.[可选]检查
$ groups $USER
# 3.登出或重启更新生效
```

## 多个USB设备的管理

插入主机的相同类型的USB设备会按照顺序在`/dev`下分配索引，这样无法固定。下面操作可以将自定义名称与USB口关联起来，无论设备何时插入该USB口，该设备必会分配到固定的自定义名称。

下面以USB转串口设备为例，其他类型的设备一个道理，如多个USB摄像头会被为video0, video1, video2 ...

1. 查询USB端口对应的设备号
   ``` bash
   $ ls /sys/class/tty/ttyUSB* -l
   ```
   若是USB摄像头则为 `$ ll /sys/class/video4linux`

   通过拔插设备确定USB端口和输出信息的对应关系。  
   如，连接两个设备时输出如下：  
   ``` txt
    lrwxrwxrwx 1 root root 0 9月  10 17:35 /sys/class/tty/ttyUSB0 -> ../../devices/pci0000:00/0000:00:14.0/usb1/1-1/1-1:1.0/ttyUSB0/tty/ttyUSB0  
    lrwxrwxrwx 1 root root 0 9月  10 17:35 /sys/class/tty/ttyUSB1 -> ../../devices/pci0000:00/0000:00:14.0/usb1/1-2/1-2:1.0/ttyUSB1/tty/ttyUSB1  
    ```
    这里的`1-1:1.0`对应右边的USB口，`1-2:1.0`对应左边的USB口。

2. 创建并编辑配置文件
   ``` bash
   $ vi /etc/udev/rules.d/10-local.rules
   ```
   `10-local.rules`这个文件的名称和后缀有什么讲究吗？  
   文件中加入
   ``` txt
   ACTION=="add",KERNELS=="1-1:1.0",SUBSYSTEMS=="usb",MODE:="0777",SYMLINK+="right"
   ACTION=="add",KERNELS=="1-2:1.0",SUBSYSTEMS=="usb",MODE:="0777",SYMLINK+="left"
   ```
3. 重新插入USB即可生效。或者重启。
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
不同的设备。
