# git diff

> git diff - Show changes between the working tree and the index or a tree, changes between the index and a tree, changes between two trees, changes between two blob objects, or changes between two files on disk.


## 输出格式

``` bash
diff <fileA> <fileB>

diff --git a/<fileA> b/<fileB>
--- a/<fileA>
+++ b/<fileB>

xxxxx
```
那么接下来的输出中，前面带`+`号的就是fileB比fileA多出来的，用绿色字体显示，前面带`-`号的部分是fileA比fileB多出来的，用红色字体显示。


## 对比本地两个文件的不同

彩色形式输出两个文件中的不同。

``` bash
$ git diff --no-index <file1_path> <file2_path>
```
Tip: 如果仅仅是用来比较本地相同分支下的两个文件可以使用安装在`/usr/bin`目录下的`diff`工具，`diff <file1_path <file2_path>`，但是`git diff`能输出彩色的，比较直观。

[git diff two files on same branch, same commit](https://stackoverflow.com/questions/13964328/git-diff-two-files-on-same-branch-same-commit)