# PyQt


## &Buttons&

### Push Button

#### 按钮设置图标

用图标代替文字，更美观。
``` python
self.play_icon = QIcon.fromTheme('media-playback-start')
self.begin_button.setIcon(self.play_icon)
```
其中，
图标的内容，如`media-playback-start`来自于[Icon Naming Specification](https://specifications.freedesktop.org/icon-naming-spec/icon-naming-spec-latest.html)

#### 图片填充按钮
``` python
self.closed_door_icon = QIcon("closed_door_icon_path")
self.right_front_door_button.setIcon(self.closed_door_icon)
```


#### 设置按钮不可选
``` python
self.begin_button.setEnabled(True)  # 可选
self.begin_button.setEnabled(False) # 不可选
```

### [Radio Button](https://www.tutorialspoint.com/pyqt/pyqt_qradiobutton_widget.htm)

radio butto 单选按钮（radio无线电，可以理解为无线电一次只能一个频道，单选按钮一次只能选一个）

若要达到这种效果，要将这些radio button放置在同一个父窗口中，如创建一个Horizontal Layout， 将按钮都放置进去。

但是，如果要实现多组的布局，就要使用QButtonGroup，否则即使你在两个Horizontal Layout中分别放置按钮，所有的按钮也只有一个能被选中。

#### 设置初始状态
设置b1为选中状态。
``` python
Self.b1.setChecked(True)
```
#### 多组按钮
radio_button1和radio_button2一组，radio_button3和radio_button4一组，两组之间互不干扰。
``` python
from xxx.QtWidgets import *
# from xxx.QtWidgets import QWidget
# NameError: global name 'QButtonGroup' is not defined

self.bg1 = QButtonGroup()
self.bg1.addButton(self.radio_button1, 1)
self.bg1.addButton(self.radio_button2, 2)
self.radio_button1.setChecked(True)

self.bg2 = QButtonGroup()
self.bg2.addButton(self.radio_button3, 1)
self.bg2.addButton(self.radio_button4, 2)
self.radio_button3.setChecked(True)
```

## &Containers&

### Scroll Area

要设置Scroll Area的最小宽高。


### Tab Widget


## &Display Widgets&

### Label

#### 显示图片

调整图像大小与Label大小适配。

保持长宽比，将图片高度缩放至180
``` python
self.car_image_label.setPixmap(QPixmap("car_img_path").scaledToHeight(180))
```
[Python: How to Resize Raster Image with PyQt](https://stackoverflow.com/questions/21802868/python-how-to-resize-raster-image-with-pyqt)

## &Input Widgets&

### [Combo Box](https://www.tutorialspoint.com/pyqt/pyqt_qcombobox_widget.htm)

下拉选项效果。

#### 初始化下拉内容

``` python
self.cb.addItem("C++")  # 逐条添加
self.cb.addItems(["Java", "C#", "Python"])  # 一次性添加
```

#### 获取选定的内容
``` python
current_text = self.cb.currentText()
```

#### 变得不可选取
``` python
self.cb.setEnabled(False)
```

### Line Edit

用于输入单行文本

#### 限制输入格式

如文本框只能输入整数。

[Validating user input in PyQt4 using QValidator](https://snorfalorpagus.net/blog/2014/08/09/validating-user-input-in-pyqt4-using-qvalidator/)

#### 变得不可输入

分为两种：不可输入但是外观仍正常，不可输入且文本框变灰

* 不可输入但是外观仍正常。文本框中的内容仍可选择，但选中文本框鼠标不会变为光标。
  ``` python
  self.line_edit.setReadOnly(True)
  ```
* 不可输入且文本框变灰
  ``` python
  self.line_edit.setEnabled(False)
  ```

#### 获取文本框中的内容

``` python
var = self.line_edit.text()
```

### [Slider](https://www.tutorialspoint.com/pyqt/pyqt_qslider_widget_signal.htm)

滑块拖动效果。常用于有范围的值。

#### 获取滑块所在位置的值

``` python
val = self.my_slider.value()
```
#### 变得不可选取
``` python
self.my_slider.setEnabled(False)
```


## Bug

#### [折中方案]改变布局后，按钮被Label遮挡

Label是用来显示图片的，按钮放置在Label之上。将Widget修改为Tab Widget后，部分按钮被Label覆盖无法选取。

没有找到修改层级的选项，将被覆盖的按钮删除后，重新添加才解决。

#### [未解决]Widget如何随着窗体的缩放而自动适应

之前遇到过，如果不这样设计，设计出的UI在不同分辨率电脑上显示不全的问题，导致无法使用。