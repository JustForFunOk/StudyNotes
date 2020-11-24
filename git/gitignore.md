# .gitignore

## 格式

### /的用法

|用法|含义|
|:---:|:---:|
|target/|忽略所有的`target`文件夹（即使target文件夹位于子文件夹下）|
|target|忽略所有的`target`文件和文件夹|
|/target/|仅忽略根目录下的`target`文件夹|
|/target|仅忽略根目录下的`target`文件和文件夹|
|*.out|忽略所有.out文件|
|!/read.md|不要忽略根目录下的read.md文件|

总结：前置的`/`用来表示当前目录，若无，则会递归的找到所有文件夹下；后置的`/`用来表示为文件夹；

[Using .gitignore the Right Way](https://labs.consol.de/development/git/2017/02/22/gitignore.html)


### []的用法

单个字符的匹配列表

[Dd]ebug/ Debug/和debug/都会被忽略
[0-9] 匹配0到9所有的数字
[A-Z] 匹配A到Z所有的大写字母

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

