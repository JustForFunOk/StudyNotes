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

#### 设置按钮不可选
``` python
self.begin_button.setEnabled(True)  # 可选
self.begin_button.setEnabled(False) # 不可选
```

## &Input Widgets&

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

