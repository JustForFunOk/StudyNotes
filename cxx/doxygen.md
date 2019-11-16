# doxygen

官方文档：[doxygen](http://www.doxygen.nl/index.html)

可参考opencv的使用手册，其就是doxygen生成的。

[core/mat.hpp](https://github.com/opencv/opencv/blob/3.3.1/modules/core/include/opencv2/core/mat.hpp)  vs [cv::Mat Class Reference](https://docs.opencv.org/3.3.1/d3/d63/classcv_1_1Mat.html#af1d014cecd1510cdf580bf2ed7e5aafc)


doxyfile配置：[opencv的doxyfile](https://github.com/opencv/opencv/blob/master/doc/Doxyfile.in)

## 语法

|关键词|用法||
|:---:|:---:|:---:|
|@overload|函数重载||
|@param|形参||

### @overload

重载函数

效果：会在文档函数下方出现这样一句。`This is an overloaded member function, provided for convenience. It differs from the above function only in what argument(s) it accepts.`

### @param

参数的说明





## 工具：生成函数调用流程图

用于快速理解新的代码。

doxygen + graphviz

### 安装

``` bash

```


参考：[分析函数调用关系图(call graph)的几种方法](https://blog.csdn.net/solstice/article/details/488865)

[绘制函数调用图（call graph）（4）：doxygen + graphviz](https://blog.csdn.net/benkaoya/article/details/79763668)

实际配置：[Ubuntu使用doxygen将源码生成调用关系图](https://blog.csdn.net/ZeroLiko/article/details/78162408#commentBox)

[Ubuntu下doxygen+graphviz使用概录](https://www.cnblogs.com/arnoldlu/p/11552271.html)

[Graphs and diagrams](http://www.doxygen.nl/manual/diagrams.html)

[doxywizard](http://www.doxygen.nl/manual/doxywizard_usage.html)

[doxywizard Expert](http://www.doxygen.nl/manual/config.html)


