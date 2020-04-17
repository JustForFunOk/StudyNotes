# spin和spinOnce

## 原理
回调机制内部是通过多线程实现的，多线程实现网络管理和时序等。但是对于我们使用者他们是单线程的。





## 使用demo

### spin

spin()内部自带while()循环，程序会一直停留在这里直到结束。
``` C++
ros::init(argc, argv, "my_node");
ros::NodeHandle nh;
ros::Subscriber sub = nh.subscribe(...);
...
ros::spin();
```

#### Q：消息收到会立刻进回调吗？

不会，有默认的处理频率。默认时10Hz，这么低？

```C++
//spinner.cpp
00037 void SingleThreadedSpinner::spin(CallbackQueue* queue)
00038 {
00039   ros::WallDuration timeout(0.1f); // 0.1s
00040
00041   if (!queue)
00042   {
00043     queue = getGlobalCallbackQueue();
00044   }
00045
00046   ros::NodeHandle n;
00047   while (n.ok())
00048   {
00049     queue->callAvailable(timeout);
00050   }
00051 }
```
疑问：这个spin是SingleThreadedSpinner的成员函数，但是我们平时使用的时候就直接ros::spin();？？这里调用的貌似是一个全局函数。

#### Q: 如果node不涉及消息接收，用while(1)替代可以吗？


### spinOnce

spinOnce()只执行一次，需要搭配while循环以及sleep使用。

``` C++
ros::Rate r(10); // 10 hz
while (should_continue)
{
  ... do some work, publish some messages, etc. ...
  ros::spinOnce();
  r.sleep();
}
```


## reference
1. https://www.cnblogs.com/liu-fa/p/5925381.html
2. http://wiki.ros.org/roscpp/Overview/Callbacks%20and%20Spinning
3. https://xwlu.github.io/wiki/ros/multi-thread/#rosasyncspinner