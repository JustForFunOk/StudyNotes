# shell脚本

* shell处理数据的速度并不快
  因为其常常需要调用外部的函数库，不适合处理大量数值运算

## 例子

### if
`~/.profile`文件中有：
``` bash
# include .bashrc if it exists
if [ -f "$HOME/.bashrc" ]; then
    . "$HOME/.bashrc"
fi
```
* 其中包含了条件判断语法`if[]; then fi`，类似于C语言中的`if()`条件判断函数。
* 参数`-f`用于判断该文件名是否存在且为文件
* 双引号`""`括住文件名用于？
* 点`.`表示？
### export

常用来设置环境变量
``` bash
export PATH=$PATH:/
```
通过`help export`来查看使用帮助，为shell变量设置export属性。