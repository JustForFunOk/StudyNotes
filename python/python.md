# python

## VSCode配置

[官方指导](https://code.visualstudio.com/docs/languages/python)


## 变量类型

### 列表list

#### 列表长度
``` python
length = len(list_example)
```

#### 遍历列表中每一个元素

``` python
list = [1, 3, 5, 7, 9]

for i in list:
    print(i)
```

#### 列表末尾添加元素
``` python
my_list = ['geeks', 'for']
my_list.append('geeks')
print my_list  # ['geeks', 'for', 'geeks']
```



### 字典dict


## 统计目录下所有指定类型的文件

返回的列表内容是随机的，并不是按照文件名排序的

参考：[Find all files in a directory with extension .txt in Python](https://stackoverflow.com/questions/3964681/find-all-files-in-a-directory-with-extension-txt-in-python)

## 查找字符串中所有的数字

参考：[How to extract numbers from a string in Python?](https://stackoverflow.com/questions/4289331/how-to-extract-numbers-from-a-string-in-python)
[Python 正则表达式](https://www.runoob.com/python/python-reg-expressions.html)

## 终止程序运行

能否同时打印错误信息

[Python程序退出: os._exit()和sys.exit()](https://blog.csdn.net/index20001/article/details/74294945)


## 逻辑运算符

等于`==` 不等于`！=`  大于等于`>=` 小于等于`<=`

与`and` 或`or` 非`not`

## 字符串转数字

字符串中只包含整数
`int(string)`
字符串中为浮点数
`float(string)`

## 打印中文

要在文件开头添加`# -*- coding: utf-8 -*-`编码方式，否则会报错

## 多个print内容打印到一行

python2
``` python
print "hello",
print "world"
```
python3
``` python
print("hello", end="")
print("world")
```

## 对list中字符串进行排序

``` python
string_list.sort()
```
参考：[Python | How to sort a list of strings](https://www.geeksforgeeks.org/python-how-to-sort-a-list-of-strings/)


## 条件表达式

### if else
``` python
if name == 'hello' :
    # xxx
else :
    # xxx
```

### 三元表达式

``` python
smaller = x if x<y else y
```


## 查找字符串在文件中的位置并返回行号

[Get Line Number of certain phrase in file Python](https://stackoverflow.com/questions/3961265/get-line-number-of-certain-phrase-in-file-python)

## 在文件某一行插入内容

看到的方法都是先将文件内容读取到列表中，然后执行插入操作后，再重新写入到文件中。

[Insert line at middle of file with Python?](https://stackoverflow.com/questions/10507230/insert-line-at-middle-of-file-with-python)

而且写入的时候还要循环，将列表中的内容一条一条的写进去:[Writing a list to a file with Python](https://stackoverflow.com/questions/899103/writing-a-list-to-a-file-with-python/899176)，若按上述链接中的方法则会报错：`TypeError: expected a character buffer object`，同时还要注意要以字符串的格式写入，否则也会[有问题](https://stackoverflow.com/questions/24439988/typeerror-expected-a-character-buffer-object)



若要对文件进行读写操作，`open()`时打开模式有一定的说法，还没有研究，[这里](https://www.runoob.com/python/python-func-open.html)有讲



## copy文件
[How do I copy a file in Python?](https://stackoverflow.com/questions/123198/how-do-i-copy-a-file-in-python/30359308)

## python2和python3同时存在
这时若使用`pip install`安装包，则使用Python3解释器编译时会提示找不到包
因为包不是共用的，要`sudo apt-get install python3-pip`，再使用`pip3 install`安装包，这时才能在python3中使用该包
``` bash
$ pip --version
pip 8.1.1 from /usr/lib/python2.7/dist-packages (python 2.7)
$ pip3 --version
pip 8.1.1 from /usr/lib/python3/dist-packages (python 3.5)
```

## 检查是否有某文件夹，若无自动创建

``` python
import os
if not os.path.exists(directory):
    os.makedirs(directory)
```

[How can I safely create a nested directory?](https://stackoverflow.com/questions/273192/how-can-i-safely-create-a-nested-directory)


## VSCode调试时查看全局变量

调试时只能在`VARIABLES`中查看`Locals`局部变量。查看全局变量需要在`WATCH`窗口中，手动添加全局变量

## 全局变量

全局变量首先要在所有函数外进行定义和初始化。
函数中使用到该全局变量，若只是引用则无需其他操作，若要对该变量赋值，则要加`global`关键词，否则会在局部创建同名的局部变量，从而导致错误。

Q: 若不知道该变量的类型，该如何进行初始化？
``` python
a = None
```


[Using global variables in a function](https://stackoverflow.com/questions/423379/using-global-variables-in-a-function)


## None的使用方法

* 定义函数形参时def spam(foo=None):
    if foo is not None:

[What is a None value?](https://stackoverflow.com/questions/19473185/what-is-a-none-value)


## 删除字符串中的字符

先裁剪再拼接

``` python
newstr = oldstr[:4] + oldstr[5:]
```
如上，删除`oldstr`中第5个字符

[Remove char at specific index - python](https://stackoverflow.com/questions/14198497/remove-char-at-specific-index-python)

## 删除字符串中的子字符串

直接替换为空

``` python
x = 'Pear.good'
y = x.replace('.good','')
print(y)  # 'Pear'
```
[How to remove specific substrings from a set of strings in Python?](https://stackoverflow.com/questions/37372603/how-to-remove-specific-substrings-from-a-set-of-strings-in-python)

## 单引号和双引号有什么区别

不像C中，`‘’`用来表示一个字符，`“”`用来表示字符串
Python中两者没有什么区别，通用，但是他们有如下额外用途：
``` python
print('he"l"lo')  # he"l"lo
print("he'l'lo")  # he'l'lo
```
交叉使用他们，可以用来在字符串中打印单引号和双引号。

[Difference between using ' and "? [duplicate]](https://stackoverflow.com/questions/5087425/difference-between-using-and)


## 删除最后一个字符

``` python
newstr = oldstr[:-1]
```
如上，相当于截取了字符串从第0个到倒数第2个字符串

[Remove final character from string (Python)](https://stackoverflow.com/questions/15478127/remove-final-character-from-string-python)

## 生成一连串数字


``` python
input = 8
output = range(input + 1)  # Python2
output = list(range(input + 1))  # Python3
print output
[0, 1, 2, 3, 4, 5, 6, 7, 8]
```

[How can I generate a list of consecutive numbers?](https://stackoverflow.com/questions/29558007/how-can-i-generate-a-list-of-consecutive-numbers/29558077)


## 一个列表中插入另一个列表的内容

``` python
a = [0, 1, 4, 5, 6]
b = [2, 3]
a[2:len(b)] = b  # [insert_position : insert_length]
print(a)  # [0, 1, 2, 3, 4, 5, 6]
```

[Python | Insert list in another list](https://www.geeksforgeeks.org/python-insert-list-in-another-list/)

## 浅拷贝和深拷贝

浅拷贝
``` python
import copy
a = b
a = copy.copy(b)
```

深拷贝
``` python
import copy
a = copy.deepcopy(b)
```

## 查看某个字符串是否在字符串列表中

使用字符串的`find()`方法。

``` python
for str in str_list:
    if str.find('hello') >= 0:
        # find it
```
[Check if a Python list item contains a string inside another string](https://stackoverflow.com/questions/4843158/check-if-a-python-list-item-contains-a-string-inside-another-string/4843172)

## pprint

pprint能够将内容排版后打印出来，更加美观直观。
``` python
from pprint import pprint
print a
pptint(a)
```

## 数字进制间转换

* 十进制转十六进制 `hex(十进制数)`

[Python 二进制，十进制，十六进制转换](https://blog.csdn.net/u012063703/article/details/42609833)


## 定义函数返回值

``` python
# 函数定义
def func():
    # xxxx
    return a  # 单返回值
    return (a,b)  # 多返回值

# 函数调用
a = func()  # 单返回值
a,b = func()  # 多返回值

```
## 主函数

``` python
if __name__ == "__main__":
    # xxx
```
## 文件开头

/usr/bin/env输出的是系统的环境变量和路径。

`#!`叫做`shebang line`，在Unix系统中比较有用.
> In a Unix-like operating system, the program loader takes the presence of these two characters as an indication that the file is a script, and tries to execute that script using the interpreter specified by the rest of the first line in the file.

``` python
#! /usr/bin/env python
# -*- coding: utf-8 -*-
```

若要指定某个版本也可以下述的形式指定。
``` python
#! /usr/bin/env python
#! /usr/bin/env python2.6
#! /usr/bin/env python3
```

[Why do people write the #!/usr/bin/env python shebang on the first line of a Python script?](https://stackoverflow.com/questions/2429511/why-do-people-write-the-usr-bin-env-python-shebang-on-the-first-line-of-a-pyt)

## 获取字符串中的指定一段

``` python
a = "hello world"
b = a[7:12] # 从0开始，左闭右开
```
b即为“world”

## 字符串转数字

``` python
a = "112233"
b = int(a)
```
b即为整数112233

## 除法

和C语言相同，两个整数相除结果为整数，其中一个为小数则结果为小数

## 保留小数

``` python
a =  3.1415
b = round(a, 2)
print b
```
b即为3.14

## ubuntu安装python包

``` shell
$ sudo apt-get install python-pip
$ sudo pip install <python-package>
```

## 分离字符串中的元素

按照空格分离
``` txt
0 0 0 0.247953 0.342936 150 181 151 181 150 182 151 182
```
``` python
list = str.split()
```
[How to split a string into a list?](https://stackoverflow.com/questions/743806/how-to-split-a-string-into-a-list)

按照逗号分离
``` python
list = str.split(",")
```

## 枚举

``` python
from enum import Enum

class CAMERA_MODEL(Enum):  # 继承Enum类
    PINHOLE = 0
    FISHEYE = 1
```

[Python中枚举的使用](https://blog.csdn.net/m0_38061927/article/details/76058133)


### 注释中包含中文字符
SyntaxError: Non-ASCII character '\xef' in file /home/sunjian/workspace/AP2.0/src/ui/obj_pos_vis/scripts/obj_pos_vis.py on line 12, but no encoding declared; see http://python.org/dev/peps/pep-0263/ for details
``` python
"""
--- para
id： given by user
(time，x，y)
"""
```