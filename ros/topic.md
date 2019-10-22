# 通信方式1：Topic和Message
> 这种通信方式类似于电台广播与收听，Topic的name类似于频道，广播台往某个指定频道上广播消息，收听者调到同个频道就能收听节目。
## Topic
* 用的最多的通信方式
* Node间通过publish-subscribe机制通信
* ROS中的**异步**通信方式，发布者只管向topic发送消息，订阅者只管从topic上接收消息
* 一个topic可以有多个subscriber 
* 一个topic可以有多个publisher，如rosout， tf

### 常用场景
摄像头图像采集node发布 --> rgb_image的topic --> 被图像处理的node订阅

### 常用指令

1. 列出当前所有topic
    ``` bash
    $ rostopic list
    ```
2. 显示某个topic上的属性信息(消息类型、发布者、订阅者)
    ``` bash
    $ rostopic info <topic_name>
    ```     
3. 显示发布到某个topic上的内容
    ``` bash
    $ rostopic echo <topic_name>
    ```    

## Message

msg中定义的Message相当于C++中的类，定义了消息格式，发布到Topic上一条条的Message相当于实例化的对象。

### std_msgs
常用的msg类型包括： 


### 自定义msgs

使用自定义的msg格式时，要在`/msg`文件夹中新建`<msg_name>.msg`文件，其中`msg_name`自行命名。  
通过`catkin_make`编译后，会生成`~/catkin_ws/devel/include/<package_name>/<msg_name>.h`头文件。  
通过这样我们只需在`.msg`文件中定一个消息格式即可，编译后会自动生成对应的`.h`文件。  
`.cpp`文件中添加对应头文件即可使用该消息。

### 常用指令

1. 列出系统上所有msg
    ``` bash
    $ rosmsg list
    ```
2. 显示某个msg的内部结构
    ``` bash
    $ rosmsg show <msg_name>


### 代码模板

消息定义  
`/msg/gps.msg`
``` text
float32 x
float32 y
string state
```


发布者
``` cpp
#include <ros/ros.h>
#include <<package_name>/<msg_name>.h>
int main(int argc, char** argv){
    ros::init(argc, argv, "<node_name>");
    ros::NodeHandle nh;
}
```

程序解析：  
1. `#include <ros/ros.h>`  
    ros程序里必加头文件
2. `#include <<package_name>/<msg_name>.h>`  
   `<package_name>`表示包名，`<msg_name>.h`表示通过`.msg`文件生成的头文件。包含该头文件以使用自定义的消息
3. `int main(int argc, char** argv){`  
    程序入口  
4. `ros::init(argc, argv, "<node_name>");`  
    解析参数，命名节点，<node_name>表示节点名，名称自己定  
5. `ros::NodeHandle nh;`  
    创建句柄，实例化node。句柄可以理解为一个把手，其提供了操作node的很多方法。 

}
