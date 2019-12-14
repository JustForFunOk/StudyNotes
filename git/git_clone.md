# git clone

## git clone速度太慢

前提条件：有代理

即使电脑已经开了代理，速度也非常慢10-20KiB/s。这是因为git默认不使用代理，需要进行设置。具体端口号要看代理中`http代理端口`这一项中的设置，如我的是`10240`。
``` bash
git config --global http.https://github.com.proxy https://127.0.0.1:10240
git config --global https.https://github.com.proxy https://127.0.0.1:10240
```
而且这种方式只针对于http传输，ssh传输无效。
``` bash
# http有效
git clone https://github.com/opencv/opencv.git
# ssh无效
git clone git@github.com:opencv/opencv.git
```
修改后速度可以高达数MiB/s。

[git clone一个github上的仓库，太慢，经常连接失败，但是github官网流畅访问，为什么？ - 汪小九的回答 - 知乎](
https://www.zhihu.com/question/27159393/answer/141047266)