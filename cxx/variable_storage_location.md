# 存放区域

代码区、常量区、静态全局区、堆区、栈区

.data .rodata .text .bss



<img src="./images/program_memory_layout.jpg" width = "30%" height = "30%" alt="图片名称">

上图中，从上到下，地址从高到低。

|区域|区域|存放内容|读写|
|:---:|:--:|:--:|:--:|
|.text|代码区|代码、预设的变量值|只读|
|.data|静态全局区|已经初始化的全局变量|可读可写|
|.bss|静态全局区|未初始化的全局变量，默认赋值为0|可读可写|
|heap|堆区|malloc、new|向上成长|
|stack|栈区|临时变量、函数入口|向下生长|


``` c



```



.text中预设的变量值会在程序启动阶段拷贝到.data区域为全局变量赋值。

stack的指针指向栈的最高处。




```c++
class D
{
public:
    void printA()
    {
        cout<<"printA"<<endl;
    }
    virtual void printB()
    {
        cout<<"printB"<<endl;
    }
};
int main(void)
{
    D *d=NULL;
    d->printA();
    d->printB();

--- Output ---


```

## 几个疑问

### 程序运行时系统会分配给他多大的空间？

因为栈是向下生长的，堆是向上生长的，那么分配给程序的大小就已知了。这个大小是怎么确定的？在程序运行的时候会变化吗？


## Reference

1. [linux 堆、栈、全局变量存放](https://blog.csdn.net/kkxgx/article/details/7520902)

2. [什么是代码区、常量区、静态区（全局区）、堆区、栈区？](https://blog.csdn.net/u014470361/article/details/79297601)

3. [C++成员函数在内存中的存储方式](https://blog.csdn.net/fuzhongmin05/article/details/59112081)

4. [Wikipedia - Data segment](https://en.wikipedia.org/wiki/Data_segment)

5. [程序各个段text,data,bss,stack,heap](https://www.cnblogs.com/jamesnt/p/3747216.html)

6. [浅谈程序中的text段、data段和bss段](https://zhuanlan.zhihu.com/p/28659560)