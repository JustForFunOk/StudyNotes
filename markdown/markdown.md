# MarkDown常用语法

> 里面的内容有不仅仅包含MarkDown部分，因为我写MarkDown一般是用于放到网页上，所以也有html的内容。

## 目录

* [资源汇总](#资源汇总)
* [推荐编辑器](#推荐编辑器)
* [常用语法](#常用语法)
   * [文字强调](#文字强调)



## 资源汇总



## 推荐编辑器

### 离线--[Typora](https://typora.io/#)

### 在线--[Cmd Markdown](https://www.zybuluo.com/)


## **字体**

### 1. 加粗

``` markdown
**你好!**
__Hello!__
```

**你好**  

__Hello!__

### 2. 斜体

``` markdown
*你好!*
_Hello!_
```

*你好*

_Hello!_

### 3. 颜色 字号 字体

这个使用的是html语法，MarkDown编辑器不一定支持预览，但是网站都支持。

```markdown
<font color=#ff0000 size=4 face='楷体'>你好!</font>
```

<font color=#ff0000 size=4 face='楷体'>你好!</font>

### 4. 强调

``` markdown
`Hello!`
```

`Hello`

### 5.删除线

两对双波浪号包含的文字

``` markdown
~~你好！~~ 
```

~~你好！~~

---
## **段落**

### 1. 项目符号
``` markdown
* 1
   * 1.1
* 2
* 3

- 1
   - 1.1
- 2
- 3
```
* 1
   * 1.1
* 2
* 3

- 1
   - 1.1
- 2
- 3


### 2. 编号
``` markdown
1. Hello
2. World
```
1. Hello
2. World


### 3. 段落对齐
html语法

``` html
<div align = right>靠右对齐</div>
```

<div align = right>靠右对齐</div>

``` html
<center>居中对齐</center>
```

<center>居中对齐</center>

### 4.分割线

``` markdown
---
两者皆可
***
```

---  
两者皆可  
***


## **链接**

### 本地文件链接

### 文字链接

``` markdown
[文字](链接)
```



## 媒体

### 图片

``` markdown
![图片说明](链接)
```

#### 图片缩放

使用了HTML代码，将图片缩小一半，居中。

``` html
<img src="<image-url>" width = "50%" height = "50%" algin = center alt="图片名称">
```

#### 视频

``` markdown
<iframe height=450 width=800 src="http://xxx" frameborder=0 allowfullscreen autostart= "true"></iframe>
```

经测试属性设置那几个选项好像没有什么用

#### 音频

未测试。

``` markdown
<embed src="http:xxx" type="application/x-shockwave-flash" width="xxx" height="xxx" wmode="transparent"></embed>
```



## **表格**

格式如下，其中，`:---`或`---`表示左对齐，`---:`表示右对齐， `:---:`表示居中对齐。`-`的数量没有什么影响,可以用来源码上的对齐，美观。

``` markdown
|产品名            |版本号|
|:----------------:|:---:|
|Visual Studio 2017|15.0 |
|Visual Studio 2015|14.0 |
```

|产品名             |版本号|
|:----------------:|:---:|
|Visual Studio 2017|15.0 |
|Visual Studio 2015|14.0 |

### 表格内换行

html语法

`<br>`

## **目录**

``` markdown
[目录名](#链接文字)
```

链接文字：只能是标题，所以最干脆的方法就是把目录名和链接文字设置成一样的。如：`[BUG](#BUG)`

效果：见文章初始的目录

存在问题：如果有目录名称是一样的话就不行了，等待解决。。。看到github上只需要用那一段中的关键词即可链接，我试了不行



## **特殊符号**

### 段首空格、多个空格

``` markdown
helloworld
&nbsp;helloworld
helloworld
&ensp;helloworld
你好
&emsp;你好
```
helloworld  
&nbsp;helloworld  
helloworld  
&ensp;helloworld  
你好  
&emsp;你好

其中nbsp(non-breaking space)

### 回车

使用键盘依次打出`空格`+`空格`+`回车`这三个键。

### 方括号[ ]
如二维数组`int a[3][10]`就不能正常显示，遇到这种特殊符号可以在符号前加`\`变成转义字符就能显示原字符。

`int a[3][10];` --> int a[3][10];

`int a\[3\]\[10\];` --> int a\[3\]\[10\];

int a[1][2];


### 括号( )

网址中包含（）导致链接错误

``` markdown
[链接](https://msdn.microsoft.com/en-us/library/windows/desktop/aa365574(v=vs.85).aspx)
```

如上述网站链接就因为网址中包含（）导致下面这种效果

[链接](https://msdn.microsoft.com/en-us/library/windows/desktop/aa365574(v=vs.85).aspx)

解决方法：使用`%28`代替`(`，使用`%29`代替`)`。

参考：[*Hom's Blog*](http://gohom.win/2015/12/24/MD-bracket/)



---

参考：

[CSDN-MarkDown中的HTML语法](https://blog.csdn.net/qq_37059483/article/details/78293672)


