# 小工具

## png2jpg

将png图片转换为jpg格式。

其他格式的图片之间相互转换也可以，工具`convert`和`mogrify`均为ImageMagick下的工具。

``` bash
# 安装ImageMagick，ubuntu默认已安装
$ sudo apt-get install imagemagick
# 转换单个图片
$ convert image.png image.jpg
# 批量处理
$ mogrify -format jpg *.png
```