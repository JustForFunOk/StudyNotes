# TCP/IP五层模型

## 1应用层（application layer）

* DHCP

    动态主机设置协议（Dynamic Host Configuration Protocol）

    生活中最常用到的，设备连接配置路，路由器中的DHCP服务器为设备分配动态IP。

* DNS

    域名系统（Domain Name System）

    将网址与IP地址关联起来，这样直接输入便于记忆的网址即可。

* FTP

    文件传输协议（File Transfer Protocol）

    用于传输文件。

* HTTP

    超文本传输协议（HyperText Transfer Protocol）

    用于网页数据传输

    * HTTPS

        超文本传输安全协议（HyperText Transfer Protocol Secure）

        网页加密，用于网上支付，登录等。

* IMAP/POP

    因特网信息访问协议（Internet Message Access Protocol）

    邮局协议（Post Office Protocol）

    邮件通信协议，手机上邮箱设置信息中能看到。

* NTP

    网络时间协议（Network Time Protocol）

    用于网络中设备的时间同步，ROS中有相关应用。主从架构，主机开启NTP服务器，从机访问获取时间。

    * SNTP 简单网络时间协议（Simple Network Time Protocol）

        一个不太复杂的NTP实现，使用相同的协议但不需要存储较长时间的状态，它使用在某些嵌入式系统和不需要高精度时间的应用中。

* MQTT

    消息队列遥测传输（Message Queuing Telemetry Transport）

    基于发布 (Publish)/订阅 (Subscribe)范式的消息协议，为硬件性能低下的远程设备以及网络状况糟糕的情况下而设计的发布/订阅型消息协议。类似于ROS中的topic的发布与订阅的概念。

* SSH

    Secure Shell（安全外壳协议）

    SSH通过在网络中创建安全隧道来实现SSH客户端与服务器之间的连接，常用于远程登录。

* 更多应用层协议，参考[维基百科-应用层](https://zh.wikipedia.org/wiki/%E5%BA%94%E7%94%A8%E5%B1%82)


## 2传输层（transport layer）

* Socket

    传输层连接的两个端点，不是主机，不是应用程序，而是套接字（socket）。socket就是“IP地址:端口”的组合，故叫做"套接"。

* TCP
* UDP

## 3网络层（network layer）

* IP协议

    为每台机器分配IP地址。

## 4数据链路层（data link layer）

如Wi-Fi，以太网协议等。如，以太网规定一组电信号组成一个数据包，称为“帧”，每个帧分为帧头和数据，帧头定义了发送和接收者的MAC地址，数据类型等，单个数据包的大小不超过1518Bytes

## 5物理层（physical layer）

如网线，光纤，无线电波等。主要规定了网络的电气特性，负责0和1的传送



## Reference

1. [一张图了解TCP/IP五层网络模型](https://blog.csdn.net/u012909091/article/details/62888061)