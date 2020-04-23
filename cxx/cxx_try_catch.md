# try...catch...

## 使用方法

用YAML加载`.yaml`文件

```C++
try
{
    YAML::Node conf = YAML::LoadFile(path);
}
catch(YAML::Exception exception)
{
    cout << exception.what());
}
```



## Reference

1. [知乎-为什么不建议用 try catch？-pigpig回答](https://www.zhihu.com/question/29459586)