# 存放区域

代码区、常量区、静态全局区、堆区、栈区






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


## Reference

1. [linux 堆、栈、全局变量存放](https://blog.csdn.net/kkxgx/article/details/7520902)

2. [什么是代码区、常量区、静态区（全局区）、堆区、栈区？](https://blog.csdn.net/u014470361/article/details/79297601)

3. [C++成员函数在内存中的存储方式](https://blog.csdn.net/fuzhongmin05/article/details/59112081)