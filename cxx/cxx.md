# C++

- 引用&
    - 函数形参、返回值的引用



## 多个文件使用同一个变量

### C


### C++



## 大端小端

* 小端低低 - 小端是将低字节的存放在低地址
* 大端小段无关优劣
* 0x12345678 小端


[详解大端模式和小端模式](https://blog.csdn.net/ce123_zhouwei/article/details/6971544)





## 变量占用空间大小



## bug调试

``` bash
error: ‘LogFile’ has not been declared

Log.hpp:339:17:
#define logInfo LogFile::_logInfo(__FILE__, __func__, __LINE__)

sensor_ibeo_ros_node.cpp:54:9: note: in expansion of macro ‘logInfo’
logInfo << argv_[0] << " Version " << appVersion.toString() << "  using IbeoSDK "


debug
logInfo --> LogFile::logInfo
```

### 未添加库路径 undefined reference to

``` bash
undefined reference to `ibeosdk::Version::Version(ibeosdk::Version::MajorVersion, ibeosdk::Version::MinorVersion, ibeosdk::Version::Revision, ibeosdk::Version::PatchLevel, ibeosdk::Version::Build, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&)'

debug
头文件设置正常，但没有设置库路径

cmakelists.txt中
target_link_libraries(${PROJECT_NAME}_node
  ${catkin_LIBRARIES}
)
添加静态库路径
cmakelists.txt中
target_link_libraries(${PROJECT_NAME}_node
  ${catkin_LIBRARIES}
  ${IBEO_SDK}/libs/libibeosdk.a
)
```

### c++11才有的功能  only available with -std=c++11

``` bash
warning: non-static data member initializers only available with -std=c++11 or -std=gnu++11

class A
{
private:
    bool wait_for_all_lines_ = false;
}


debug
cmakelists.txt中取消注释使用c++11编译
## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)


```

## 闭包

闭包存在的意义