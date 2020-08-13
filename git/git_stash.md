# git stash

## 如何存放单个文件

`git stash`会存放所有的修改，那么如何只stash指定的文件呢？

通过`git stash -p`命令，打开交互，会针对所有修改组个询问，对于需要stash的ｙ，对于不需要的n即可。

## 查看stash中修改的文件

`stash list`太多搞不清楚每个stash中存放了什么东西

`git stash show stash@{x}`可以查看每个stash对应的修改。