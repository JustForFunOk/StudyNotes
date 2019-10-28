# rosbag

## rosbag播放工具--[webviz](https://webviz.io/)  

* 拖拽`.bag`文件即可播放
* 可调整layout，可导入导出layout文件
* 可使用html技术隐藏前端部件，如时间戳，`style=“display:none”`

## *.bag.active恢复

`rosbag record <topic>`会保存成`.bag.active`为后缀的文件，需要恢复成`.bag`文件才能播放。
``` bash
$ rosbag reindex *.bag.active
$ rosbag fix *.bag.active repaired.bag
```

## 常用指令

* rosbag play  
  Play back the contents of one or more bag files in a time-synchronized fashion.