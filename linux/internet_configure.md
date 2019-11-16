# 网络配置


## 查看网关

网络建立连接后，想要获取网关IP地址

``` bash
$ route -n
```

## 配置网络相关配置

### 修改MAC地址

``` bash
iface eth0 inet dhcp
  hwaddress ether 08:00:00:00:00:01
```

[How to change the MAC address of pc? [duplicate]](https://askubuntu.com/questions/390147/how-to-change-the-mac-address-of-pc)

### DHCP

``` bash
auto eth0
   iface eth0 inet dhcp
```

### 静态IP

``` bash
auto eth0
   iface eth0 inet static
   address 10.0.0.100
   netmask 255.255.255.0
   network 10.0.0.1
   broadcast 10.0.0.255
   gateway 46.185.128.91
```

生效
``` bash
sudo /etc/init.d/networking restart
```
[I need to reset my computer's ip address to dhcp from static](https://askubuntu.com/questions/178970/i-need-to-reset-my-computers-ip-address-to-dhcp-from-static)