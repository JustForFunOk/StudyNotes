# python

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