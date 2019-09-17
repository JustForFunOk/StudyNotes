# 我的项目

## 图片emoji效果

* 参照开源项目 - [emoji-mosaic](https://github.com/ericandrewlewis/emoji-mosaic)
* 效果图中密密麻麻的都是emoji符号堆叠的，堆叠方法涉及到一定的算法 
* 我的改进：修改成C++或python的，可以方便集成到自己的程序中去

## 自动抠图

* 参照[remove.bg](https://www.remove.bg/)中的效果
* 我的改进：自己用算法实现，能否达到他那种效果

## 全景图像拼接

* 论文 - [Automatic Panoramic Image Stitching using Invariant Features](http://matthewalunbrown.com/papers/ijcv2007.pdf)  
* 开源代码实现 - [OpenPano](https://github.com/ppwwyyxx/OpenPano)
* 我的任务  
    1. 读懂论文，理解代码  
    2. 单纯依靠特征点，速度较慢，不能达到手机中实时的全景效果
    3. 加入相机运动信息，是否能够改善，粗匹配+细匹配

## ubuntu中一键配置环境

* 简洁的操作界面  
  1. 列表列出装机必备常用软件，以字母排序  
  2. 能检测本机目前软件是否安装，软件版本  
  3. 通过勾选来选择要安装的软件
  4. 通过勾选来卸载已安装软件
  5. 可以添加扩展安装列表
* 后台实现  
  各种安装脚本
* 疑问  
  不同的方式安装会对应着不同的卸载方法，如何同步？
