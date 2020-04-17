# CMakeList

### 在CMakeLists中包含一个package后

不用include该库的头文件就能调用该库中的函数？

``` cmake
find_package(
        catkin REQUIRED
        COMPONENTS roscpp
             rospy
             tf2_ros
             std_msgs
             geometry_msgs
             sensor_base_logic_lib)
```

不用include库sensor_base_logic_lib中的头文件就能使用该库？