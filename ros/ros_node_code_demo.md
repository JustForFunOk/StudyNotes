# Node Code DEMO

## [Python Node Demo](http://wiki.ros.org/ROS/Tutorials/WritingPublisherSubscriber%28python%29)


### 修改python文件权限
修改*.py文件的权限，否则
``` bash
[rosrun] Couldn't find executable named obj_pos_vis.py below /home/sunjian/workspace/AP2.0/src/ui/obj_pos_vis
[rosrun] Found the following, but they're either not files,
[rosrun] or not executable:
[rosrun] /home/sunjian/workspace/AP2.0/src/ui/obj_pos_vis/scripts/obj_pos_vis.py

```

### 配置文件

与C++不同，python的node无需配置CMake文件