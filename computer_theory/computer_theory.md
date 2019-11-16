# 计算机理论


### 数组在物理内存中是连续的吗

不一定连续。物理内存和进程内存之间有操作系统，操作系统进行了物理内存的重映射，进程中数组的连续地址是操作系统对物理内存映射之后的地址。


 [Are std::vector elements contiguous in physical memory?](https://stackoverflow.com/questions/18540935/are-stdvector-elements-contiguous-in-physical-memory)


 ### 程序储存区域

 Linux使用`readelf`命令查看可执行文件的内部结构，如`readelf ./a.out`