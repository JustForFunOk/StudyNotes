# 功率消耗

## 电源

参数：5200mAh 5S 35C

充满电21V

额定：18.5V  

总功率：$18.5V\times5.2Ah=96.2Wh$

若满功率可使用时间：$96.2Wh/300W \times 60 min/h= 19.24min$

# Test1

## 硬件
1. 大水牛300W开关电源
2. usb键盘
3. 屏幕是单独外接电源
4. 一个Camera
5. wifi on  bluetooth on

|功耗(W)|System Monitor|usb_cam 1080p|rviz|image_view|
|:--:|:--:|:--:|:--:|:--:|:--:|
|57W|/|/|/|/|
|40W|/|/|x|/|
|55W|/|/|/|x|
|27.3W(浮动较小)|/|x|x|x|
|26.9W(拔掉Camera)|/|x|x|x|
|28.0W(4个Camera)|/|x|x|x|


## CPU

4camera 1080p + rviz

6核 100% 能达到实时显示

不加rviz

1核 60-70  1核 40%  1核 20
