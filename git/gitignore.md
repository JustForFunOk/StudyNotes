# .gitignore

## 格式
* 文件
  
* 文件夹


## 忽略已经追踪的文件

如果对于`file1`已经执行过`git add <file1>`，那么即使后续将`file1`加入到`.gitignore`文件内，git仍不会忽略该文件。  

在这种情况下，必须先取消跟踪该文件

``` bash
git rm --cached <file>
git add .
```
此时，`file1`就会被忽略了。

若要忽略的文件过多，可以先移除对所有文件的追踪。
``` bash
git rm --cached .
git add .
```

此时，添加到`.gitignore`的文件都会被忽略。


## 全局.gitignore

有这种能力，但用的很少。


## 参考

