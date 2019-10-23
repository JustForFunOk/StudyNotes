# CMake

## 功能

* 将所有的warning变成error
  [How to set warning level in CMake?](https://stackoverflow.com/questions/2368811/how-to-set-warning-level-in-cmake/50882216#50882216)


## find_package

`find_package`能够自动配置第三方库的头文件以及链接文件路径。

### 原理

1. 在相应路径中查找第三方库的配置文件
2. 读取配置文件，并设置相关变量（如，头文件路径）
3. 使用相关变量进行编译

### 配置文件查找路径

使用时只指定了第三方库的名称，该命令是如何定位到相应的配置文件的呢？

该命令会在可能的某些路径中查找`<name>Config.cmake`或`Find<name>.cmake`配置文件。

如，linux环境下会在以下路径中查找配置文件：

``` txt
<prefix>/(lib/<arch>|lib|share)/cmake/<name>*/          
<prefix>/(lib/<arch>|lib|share)/<name>*/                
<prefix>/(lib/<arch>|lib|share)/<name>*/(cmake|CMake)/  
```
如通过`apt-get install`安装的库就放置在`<prefix>`为`/usr`的路径中。


### 配置文件设置的相关变量
.cmake文件中会配置相关变量，如头文件以及动静态链接路径。

`OpenCVConfig.cmake`文件

``` txt
# ===================================================================================
#  The OpenCV CMake configuration file
#
#             ** File generated automatically, do not modify **
#
#  Usage from an external project:
#    In your CMakeLists.txt, add these lines:
#
#    find_package(OpenCV REQUIRED)
#    include_directories(${OpenCV_INCLUDE_DIRS}) # Not needed for CMake >= 2.8.11
#    target_link_libraries(MY_TARGET_NAME ${OpenCV_LIBS})
#
#    Or you can search for specific OpenCV modules:
#
#    find_package(OpenCV REQUIRED core videoio)
#
#    You can also mark OpenCV components as optional:

#    find_package(OpenCV REQUIRED core OPTIONAL_COMPONENTS viz)
#
#    If the module is found then OPENCV_<MODULE>_FOUND is set to TRUE.
#
#    This file will define the following variables:
#      - OpenCV_LIBS                     : The list of all imported targets for OpenCV modules.
#      - OpenCV_INCLUDE_DIRS             : The OpenCV include directories.
#      - OpenCV_COMPUTE_CAPABILITIES     : The version of compute capability.
#      - OpenCV_ANDROID_NATIVE_API_LEVEL : Minimum required level of Android API.
#      - OpenCV_VERSION                  : The version of this OpenCV build: "3.3.1"
#      - OpenCV_VERSION_MAJOR            : Major version part of OpenCV_VERSION: "3"
#      - OpenCV_VERSION_MINOR            : Minor version part of OpenCV_VERSION: "3"
#      - OpenCV_VERSION_PATCH            : Patch version part of OpenCV_VERSION: "1"
#      - OpenCV_VERSION_STATUS           : Development status of this build: "-dev"
#
#    Advanced variables:
#      - OpenCV_SHARED                   : Use OpenCV as shared library
#      - OpenCV_INSTALL_PATH             : OpenCV location
#      - OpenCV_LIB_COMPONENTS           : Present OpenCV modules list
#      - OpenCV_USE_MANGLED_PATHS        : Mangled OpenCV path flag
#
#    Deprecated variables:
#      - OpenCV_VERSION_TWEAK            : Always "0"
#
# ===================================================================================

```

### 参考
1. [find_package](https://cmake.org/cmake/help/v3.5/command/find_package.html)  
   官方文档上最为详细，但内容较多，不好理解
2. [CMAKE手册](https://www.zybuluo.com/khan-lau/note/254724)  
   官方教程中文翻译版，可参考
3. [cmake find_package路径详解](https://zhuanlan.zhihu.com/p/50829542)


## target_complie_definitions

在CMakeLists.txt中添加宏，使得.cpp中能够进行宏编译


## add_compile_options

