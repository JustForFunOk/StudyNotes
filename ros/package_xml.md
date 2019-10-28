# package.xml

官方文档：

[catkin/package.xml](http://wiki.ros.org/catkin/package.xml)

[Package format 2 (recommended)¶](https://docs.ros.org/melodic/api/catkin/html/howto/format2/index.html)  
这个讲的详细，有例子。同时有CMakeList.txt的设置。

* package.xml和CMakeLists.txt两个文件是一个package的[最小组成单元](./package.md##package目录结构)。该文件是一个package必不可少的文件，其放置在一个package的根目录下。这两个文件相互独立，需要分别设置。

* package.xml遵循XML（可扩展标记语言 Extensible Markup Language）文件格式。

* 推荐新的格式，`<package format="2">`


## tag

### 必须的标签

* `<package>` - root tag
* `<name>` - The name of the package
* `<version>` - The version number of the package (required to be 3 dot-separated integers)
* `<description>` - A description of the package contents
* `<maintainer>` - The name of the person(s) that is/are maintaining the package
* `<license>` - The software license(s) (e.g. GPL, BSD, ASL) under which the code is released.

### 可选标签
* `<url>` - A URL for information on the package
* `<author>` - The author(s) of the package

### 表明依赖的几个标签

* `<buildtool_depend>` - 指定用哪种工具进行编译，基本上就是`catkin`自己，即`<buildtool_depend>catkin</buildtool_depend>`。这个也是必须的标签。

* `<build_depend>` - 指定要编译该package需要哪些package。提供了头文件的库。对应于CMakeLists.txt中的`find_package()`中的包。常见的有：

* `<exec_depend>` - 指定要运行该package时需要哪些package。提供了共享库的库
  
* `<depend>` - Use depend as a shortcut for packages that are both build and exec dependencies. 如果编译和运行时都需要的package就使用这个。如果分不清是<build_depend>还是<exec_depend>也用这个。
  ``` xml
  <depend>roscpp</depend>
  <!-- 等同于 -->
  <build_depend>roscpp</build_depend> 
  <exec_depend>roscpp</exec_depend>  
  ```



* `<build_export_depend>` - specify which packages are needed to build libraries against this package。对应于CMakeLists.txt中的`catkin_package()`中的`CATKIN_DEPENDS`和`DEPENDS`中的包。什么时候用这个？
  

  
* `<test_depend>` - specify only additional dependencies for unit tests. They should never duplicate any dependencies already mentioned as build or run dependencies.
  

  
* `<doc_depend>` - 指定该package需要什么工具来生成文档。如：`<doc_depend>doxygen</doc_depend>`

## 例子

最精简的package.xml文件
``` xml
<package format="2">
  <name>foo_core</name>
  <version>1.2.4</version>
  <description>
    This package provides foo capability.
  </description>
  <maintainer email="ivana@osrf.org">Ivana Bildbotz</maintainer>
  <license>BSD</license>

  <buildtool_depend>catkin</buildtool_depend>
</package>
```
package.xml例子：
``` xml
<package format="2">
  <name>foo_core</name>
  <version>1.2.4</version>
  <description>
    This package provides foo capability.
  </description>
  <maintainer email="ivana@willowgarage.com">Ivana Bildbotz</maintainer>
  <license>BSD</license>

  <url>http://ros.org/wiki/foo_core</url>
  <author>Ivana Bildbotz</author>

  <buildtool_depend>catkin</buildtool_depend>

  <depend>roscpp</depend>
  <depend>std_msgs</depend>

  <build_depend>message_generation</build_depend>

  <exec_depend>message_runtime</exec_depend>
  <exec_depend>rospy</exec_depend>

  <test_depend>python-mock</test_depend>

  <doc_depend>doxygen</doc_depend>
</package>
```



## 初始package.xml文件内容

``` xml
<?xml version="1.0"?>
<package format="2">
  <name>testpackagexml</name>
  <version>0.0.0</version>
  <description>The testpackagexml package</description>

  <!-- One maintainer tag required, multiple allowed, one person per tag -->
  <!-- Example:  -->
  <!-- <maintainer email="jane.doe@example.com">Jane Doe</maintainer> -->
  <maintainer email="sunjian4@todo.todo">sunjian4</maintainer>


  <!-- One license tag required, multiple allowed, one license per tag -->
  <!-- Commonly used license strings: -->
  <!--   BSD, MIT, Boost Software License, GPLv2, GPLv3, LGPLv2.1, LGPLv3 -->
  <license>TODO</license>


  <!-- Url tags are optional, but multiple are allowed, one per tag -->
  <!-- Optional attribute type can be: website, bugtracker, or repository -->
  <!-- Example: -->
  <!-- <url type="website">http://wiki.ros.org/testpackagexml</url> -->


  <!-- Author tags are optional, multiple are allowed, one per tag -->
  <!-- Authors do not have to be maintainers, but could be -->
  <!-- Example: -->
  <!-- <author email="jane.doe@example.com">Jane Doe</author> -->


  <!-- The *depend tags are used to specify dependencies -->
  <!-- Dependencies can be catkin packages or system dependencies -->
  <!-- Examples: -->
  <!-- Use depend as a shortcut for packages that are both build and exec dependencies -->
  <!--   <depend>roscpp</depend> -->
  <!--   Note that this is equivalent to the following: -->
  <!--   <build_depend>roscpp</build_depend> -->
  <!--   <exec_depend>roscpp</exec_depend> -->
  <!-- Use build_depend for packages you need at compile time: -->
  <!--   <build_depend>message_generation</build_depend> -->
  <!-- Use build_export_depend for packages you need in order to build against this package: -->
  <!--   <build_export_depend>message_generation</build_export_depend> -->
  <!-- Use buildtool_depend for build tool packages: -->
  <!--   <buildtool_depend>catkin</buildtool_depend> -->
  <!-- Use exec_depend for packages you need at runtime: -->
  <!--   <exec_depend>message_runtime</exec_depend> -->
  <!-- Use test_depend for packages you need only for testing: -->
  <!--   <test_depend>gtest</test_depend> -->
  <!-- Use doc_depend for packages you need only for building documentation: -->
  <!--   <doc_depend>doxygen</doc_depend> -->
  <buildtool_depend>catkin</buildtool_depend>


  <!-- The export tag contains other, unspecified, tags -->
  <export>
    <!-- Other tools can request additional information be placed here -->

  </export>
</package>

```