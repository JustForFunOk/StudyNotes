# GDB

编译程序时需要添加`-g`参数，`g++ -g test_gdb.cpp -o test_gdb`

## 帮助信息

help `<command>`
``` bash
(gdb) help help
Print list of commands.
```

## 查看源文件

**List** specified function or line.

`l` --> `list`
``` bash
(gdb) l 1,10  # 打印出从第1行到第10行的代码
```

## 查看断点信息

Status of specified breakpoints (all user-settable breakpoints if no argument).

`i b` 或者 `info breakpoints`

``` bash
(gdb) i b
Num     Type           Disp Enb Address            What
1       breakpoint     keep n   0x00000000004008a5 in main() at test_gdb.cpp:5
2       breakpoint     keep y   0x00000000004008d1 in main() at test_gdb.cpp:6
        breakpoint already hit 1 time
```
其中，`Num`代表该断点的序号；`Enb`为`n`代表该断点已禁用，为`y`代表该断点已启用。

## 插入断点的方法

### 运行到断点处停止

这个断点和IDE中的断点功能一致，运行到该断点后程序停止在断点处。

``` bash
(gdb) break 5 # 在程序的第5行处插入断点，程序会运行完第4行，停留在第5行的开始
```


### 运行到断点出打印信息

程序并不会在此处停止。

Set a **dynamic printf** at specified location.

`dprintf`

语法：`dprintf location,format string,arg1,arg2,...`

``` bash
(gdb) dprintf 6,"a=%d\n",a
```

## 删除断点

Delete some breakpoints or auto-display expressions.

`d` --> `delete breakpoints`

``` bash
(gdb) d # 删除所有断点
(gdb) d 1 # 删除序号为１的断点
```

## 禁用断点

Disable some breakpoints.

``` bash
(gdb) disable # 禁用所有断点
(gdb) disable 1 # 禁用序号为１的断点
```

## 启用断点

Enable some breakpoints.

``` bash
(gdb) enable # 启用所有断点
(gdb) enable 1 # 启用序号为１的断点
```

## 保存断点信息

Save breakpoint definitions as a script.

`save breakpoints <filename>`

下次重新启动gdb后加载设置

`source <filename>`

## 开始调试/从头开始调试

`r` 或者 `run`

## 继续运行

`c` 或者 `continue`

## 终止调试

`k` 或者 `kill`

## 步入/step into

进入函数内部

`s` 或者 `step`

## step over


`n` 或者 `next`

## step out


## 查看调用栈

`bt`

backtrace