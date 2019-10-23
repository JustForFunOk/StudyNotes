---
title: Markdown常用语法
date: 2018-02-27 12:31:18
categories: 编程语言
tags:
   - Markdown
cover_picture: http://p4j4n6s3q.bkt.clouddn.com/image/MarkDown%E5%B8%B8%E7%94%A8%E8%AF%AD%E6%B3%95/markdown.jpg

---

## 写在前面

里面的内容有不仅仅包含MarkDown部分，因为我写MarkDown一般是用于放到网页上，所以也有html的内容。



## 目录

* [资源汇总](#资源汇总)
* [推荐编辑器](#推荐编辑器)
* [常用语法](#常用语法)
* [BUG](#BUG)
* [BUG1](#BUG-bug)
  * [bug001](#bug001)
* [BUG2](#BUG2)
  * [bug001](#bug001)

## 资源汇总



## 推荐编辑器

### 离线--[Typora](https://typora.io/#)



### 在线--[Cmd Markdown](https://www.zybuluo.com/)



## 常用语法

### 文字强调

#### 加粗(2种方法)

``` markdown
**你好!**
__Hello!__
```

**你好**

__Hello!__

#### 斜体(2种方法)

``` markdown
*你好!*
_Hello!_
```

*你好*

_Hello!_

#### 底纹 边框

``` markdown
`Hello!`
```

`Hello`

#### 颜色 字号 字体

这个使用的是html语法，MarkDown编辑器不一定支持预览，但是网站都支持。

```markdown
<font color=#ff0000 size=8 face='宋体'>你好!</font>
```

<font color=#ff0000 size=6 face='宋体'>你好!</font>

### 位置

html语法

``` html
<div align = right>靠右</div>
```

<div align = right>靠右</div>

``` html
<center>居中</center>
```

<center>居中</center>

### 分割线

```  markdown
---
```

---



### 删除线

两队双波浪号包含的文字

``` markdown
~~你好！~~ 
```

~~你好！~~



### 编号

``` markdown
- 你好!
- Hello!
```

- 你好!
- Hello!

### 链接

#### 文字链接

``` markdown
[文字](链接)
```



### 媒体

#### 图片

``` markdown
![图片说明](链接)
```

##### 图片缩放

使用了HTML代码，将图片缩小一半。

``` html
<img src="<image-url>" width = "50%" height = "50%" alt="图片名称">
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



### 表格

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

#### 表格内换行

html语法

`<br>`

### 目录

``` markdown
[目录名](#链接文字)
```

链接文字：只能是标题，所以最干脆的方法就是把目录名和链接文字设置成一样的。如：`[BUG](#BUG)`

效果：见文章初始的目录

存在问题：如果有目录名称是一样的话就不行了，等待解决。。。看到github上只需要用那一段中的关键词即可链接，我试了不行



### 特殊符号

如二维数组`int a[3][10]`就不能正常显示，遇到这种特殊符号可以在符号前加`\`变成转义字符就能显示原字符。

`int a[3][10];` --> int a[3][10];

`int a\[3\]\[10\];` --> int a\[3\]\[10\];






## BUG

### 网址中包含（）导致链接错误

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



## BUG bug

### bug001

BUG1-bug001

## BUG2

### bug001

BUG2-bug001

