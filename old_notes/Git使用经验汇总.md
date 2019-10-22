---
title: Git使用经验汇总
date: 2018-05-04 12:48:48
categories: 编程语言
author: SunJian
tags:
   - Git
   - 汇总
cover_picture:  http://p4j4n6s3q.bkt.clouddn.com/image/Git%E4%BD%BF%E7%94%A8%E7%BB%8F%E9%AA%8C%E6%B1%87%E6%80%BB/git.jpg
---



## 资料汇总

[Git官网](https://git-scm.com/)

* [Git小抄(英文)](https://services.github.com/on-demand/downloads/github-git-cheat-sheet.pdf)

  2页pdf文档，里面有最常用的一些命令。

* [**Git参考文档**(英文)](https://git-scm.com/docs)

  最全面最官方的使用文档了吧。里面有所有命令的具体使用格式，还有使用例子，想知道某个命令怎么使用必须来这里啊。

[git - 简明指南](http://rogerdudler.github.io/git-guide/index.zh.html)

​	概括了常用的命令

[Git 分支的最佳实践](http://jiongks.name/blog/a-successful-git-branching-model/)

​	译文，里面有经典的流程图



## 单词

staged 暂存的

branch 分支

merge 合并

reset 重置

checkout 检出

repository 仓库

origin 起源



## 新手误区

* git并不一定要结合github之类的远程仓库，本机使用git完全可以实现版本控制，包括分支切换，版本退回等功能。

  Git works entirely offline. Commits, branches, merges, re-bases, resetting history, even searching through those historical events, all happens in an offline mode.（From [Git官网教学视频-Git Basics Episode 4](https://git-scm.com/video/quick-wins)）



## 常见疑问

### 配置用户名和邮箱有什么用？

您需要配置您的用户名和电子邮件地址。 这些不用于任何Git托管站点的凭证。 它们只是本地记录，可以让您对版本控制系统中将要执行的工作有信心。

You need to configure your user name and email address. These are not used for credentials on any of the Git hosting sites. They're simply local records to give you credit for the work that you'll be doing in the version control system.

These are not credentials used for any hosting service. They're merely who to give credit to when it records the historical events that we call commits. You'll first configure your username. In this case, we'll just make it friendly name that you would go by for team members, or more publicly known on the net. Its corresponding cousin is user.email, and we'll set that to whatever we would like, again, to record in our commits and to be known by, either within the team or, if we share this code open-source, publicly. That's all the configuration that's necessary.(From [Git官网教学视频-Git Basics Episode 3](https://git-scm.com/video/get-going))

没有配置也能正常使用啊？

如果你的用户名和邮箱跟你的github账号一致，提交修改时，会将这两者关联起来.

没有配置好用户名和邮箱时，账号头像无法显示，也无法点击用户进入用户资料页。配置好后Github能将提交作者和其相关账号关联，可以点击作者名进入作者账户资料页。（参考自：[百度知道-git中用户名和邮箱有什么用？特别是邮箱](https://zhidao.baidu.com/question/530437180.html)）

确实是这样，github上的stereo_vision项目的[提交记录](https://github.com/JustForFunOk/stereo_vision/commits/master)中使用没有设置用户名和邮箱的电脑提交时就显示的是电脑的用户名jason，而使用配置用户名和邮箱的树莓派提交时显示的就是github的用户名并且有头像显示。

### 暂存区有什么用？

借鉴于SVN，其最重要的特性之一就是原子性提交，每一个提交都是由多个文件的修改组成，而且这个提交是原子性的，要么这些修改全部成功，要么全部失败。原子性提交带来的好处是显而易见的，这使得我们把项目整体还原到某个阶段或者时间点变得极为简便，就这一点SVN就完虐VSS等源代码管理工具。

Git要实现这个效果只需要在commit前面，添加一个暂存区就好了。暂存区是可以随意的将各种文件的修改放进去的，这样我们就可以用多个指令精确的挑选出我们需要提交的所有修改，然后再一次性的（原子性的）提交到版本库。（参考自：[知乎-为什么要先 git add 才能 git commit ？-lvony的回答](https://www.zhihu.com/question/19946553)）

### git checkout [branch]会覆盖工作区中的内容吗？

工作区中修改了文件没有提交，然后checkout到其他分支，为什么没有覆盖掉当前工作区的内容？

工作区的修改提交了以后能够正常切换分支并更新工作区中的文件。

## 基础知识

本地仓库包括三个部分：



## 常用命令

常用的命令都在官方的小抄里了，所以这部分相当于小抄的增强翻译版。
### 配置信息

对本地所有仓库配置使用者信息。

``` git
$ git config --global user.name "[name]"
$ git config --global user.email "[email address]"
```

不设置用户名和邮箱时，git log中的作者信息默认使用电脑用户名

``` git 
Author: Jian Sun <Jian Sun>
```

设置之后

``` git 
Author: SunJian <slgsunjian@163.com>
```
### 初始化仓库
创建文件两种途径：1、本地新建一个新的仓库；2、从网络链接中获取一个。

**`git init <project-name>`**

创建一个指定名称的本地仓库

**`git clone [url]`**

下载工程以及其整个的版本历史

### 设置版本控制文件

#### 创建.gitignore文件

**`touch .gitignore`**

注意：win下不能直接创建无文件名的文件，只能通过命令行来创建

#### 设置指定文件

[gitignore](https://git-scm.com/docs/gitignore)

gitignore也有很多语法规则。

当某一行中没有"/"时，则支持shell glob模式，可参考[Shell glob](http://www.cnblogs.com/chaoguo1234/p/5313721.html)

不支持正则表达式regular expression

注意：不要使用命令行中常用的"./"来表示当前目录，直接使用"/"或者什么都不用即可表示当前目录。

.gitignore文件过滤有两种模式，开放模式和保守模式（参考：[CSDN-windows下创建.gitignore文件（git提交时忽略某些文件）](https://blog.csdn.net/tang9140/article/details/45338609)）

* 开放模式负责设置过滤哪些文件和文件夹 

  *.zip 过滤zip后缀文件 
  Test.java 过滤该文件

* 保守模式负责设置哪些文件不被过滤，也就是哪些文件要被跟踪，也就是在前面加上！号

  !*.java 跟踪java源文件 
  !Test.java 跟踪该文件

#### 执行

``` git
git rm -r --cached .
git add .
git commit -m "<commit message>"
```

参考：[StackOverflow-.gitignore is not working](https://stackoverflow.com/questions/11451535/gitignore-is-not-working)




### 查看状态

#### 查看工作树中文件状态

**`git status`**

列出所有还没有被提交的新的或修改过的文件。

``` git
$ git status
On branch develop
Changes to be committed: # 修改后放在暂存区里还没有提交的文件
  (use "git reset HEAD <file>..." to unstage)

        modified:   TestB.txt

Changes not staged for commit: # 修改后没有放到暂存区也没有提交的文件
  (use "git add <file>..." to update what will be committed)
  (use "git checkout -- <file>..." to discard changes in working directory)

        modified:   TestB.txt
        
```

#### 查看哪些文件加入了版本管理

**`git ls-files`**



#### 查看所有分支

**`git branch`**

列出当前仓库中所有的本地分支。*代表当然所在分支

```git
$ git branch
* develop
```

`git branch -a`列出本地和远程的分支。

#### 查看历史版本信息[git log](https://git-scm.com/docs/git-log)

**`git log`**

查看当前分支的版本历史（指的是commit到分支的版本历史）

``` git
$ git log
commit acb134faff2bbdd538b66b41d3bc8d0864541826
Author: SunJian <slgsunjian@163.com>
Date:   Sat May 5 13:29:01 2018 +0800

    Hello World

commit bcb9255a1daff0739fbde23039a5d276b4417d6c
Author: Jian Sun <Jian Sun>
Date:   Fri May 4 13:30:49 2018 +0800

    Hello
    
```

* 简化输出可以使用命令：`git log --pretty=oneline`

``` git
$ git log --pretty=oneline
acb134faff2bbdd538b66b41d3bc8d0864541826 Hello World
bcb9255a1daff0739fbde23039a5d276b4417d6c Hello
```

* 只查看指定文件的历史版本:`git log --follow [file]`

查看某个文件在当前分支的版本历史。

注意：1、若此文件修改过文件名则修改文件名之前的版本历史不可查看。

2、此命令和git log结果往往不相同，因为git提交的是文件的更改，若你修改了文件A并提交了，则git log中会有记录，而git log --follow B中并不会有记录，因为它并没有发生改变。

* 树形结构展示所有分支以及其之间的关系：`git log --graph --oneline --decorate -all`

``` git
$ git log --graph --oneline  --decorate --all
* a956c98 (HEAD -> develop) TestC I amnot SJ
| * 08fe7d1 (TryDebug) TestC - I am SJ
|/
* 31de047 TestC haha
* 42cf452 TryDebug Delete
* f849d8e TryDebug branch
* 2e8e341 add SunJian
* 13107c1 add file TestC
* 03307e5 change filename TestB
* acb134f Hello World
* bcb9255 (origin/develop) Hello
```

#### 查看所有重要操作记录

**`git reflog`**

显示所有重要操作。

``` git
$ git reflog
31de047 HEAD@{0}: commit: TestC haha
42cf452 HEAD@{1}: checkout: moving from develop to TryDebug
f849d8e HEAD@{2}: checkout: moving from TryDebug to develop
42cf452 HEAD@{3}: checkout: moving from develop to TryDebug
f849d8e HEAD@{4}: checkout: moving from TryDebug to develop
42cf452 HEAD@{5}: commit: TryDebug Delete
f849d8e HEAD@{6}: checkout: moving from develop to TryDebug
f849d8e HEAD@{7}: merge TryDebug: Fast-forward
2e8e341 HEAD@{8}: checkout: moving from TryDebug to develop
f849d8e HEAD@{9}: commit: TryDebug branch
2e8e341 HEAD@{10}: checkout: moving from develop to TryDebug
2e8e341 HEAD@{11}: commit: add SunJian
13107c1 HEAD@{12}: commit: add file TestC
03307e5 HEAD@{13}: commit: change filename TestB
acb134f HEAD@{14}: commit: Hello World
bcb9255 HEAD@{15}: commit (initial): Hello
```

### 工作树中文件操作

工作树分为三部分：工作区、暂存区、提交区。

#### 工作区到暂存区

**`git add <file>`**

快照某个指定文件以准备版本控制。只是对暂存区中的内容做了修改。

常用`git add .`快照所有文件。注意：会将除了.git之外所有文件加入版本控制，隐藏文件也是，所以要用.gitignore来控制。

#### 暂存区到提交区

**`git commit -m "<descriptive message>"`**

在版本记录中永久记录文件快照。

#### 工作区到提交区

工作区到暂存区+暂存区到提交区

#### 暂存区到工作区

**`git checkout -- <file-name>`**

撤回对工作区中指定文件的修改。只是对工作区的内容做了修改。实质上就是将暂存区内的内容“覆盖”掉工作区的内容以达到撤回的目的。

注意：

1. `--`是为了避免文件名与分支名相同，而导致该命令与切换分支命令冲突，不冲突的情况下是可以省略的。

2. 被修改和删除的可以撤回，新建的文件不能撤回。

3. `git checkout -- .`撤回工作区内所有文件的修改。

   `git checkout -- '*.c'`撤回所有.c文件的修改。

#### 提交区到暂存区

无。

#### 提交区到工作区

这部分属于版本回退的内容。

### 对分支的操作

#### 创建分支

**`git branch <branch-name>`**

创建一条新的分支。

注意：该分支会继承创建分支时所在分支的版本历史。

`git checkout -b <branch-name>`创建并切换分支。

#### 切换分支

**`git checkout <branch-name>`**

切换到指定的分支并更新工作区的内容。

注意：

1. 切换到其他分支之前要保证先提交当前分支的修改，否则会报错：

   error: Your local changes to the following files would be overwritten by checkout:
           TestB.txt
   Please, commit your changes or stash them before you can switch branches.
   Aborting

#### 合并分支

**`git merge <branch-name>`**

将指定分支的历史记录合并到当前分支中。

注意：指定分支的历史版本都会合并到当前分支。

疑问：那如果merge到master分支时，所有的历史版本都合并过去的话，那创建其他分支还有什么作用，怎么保证master所谓的”干净“？

#### 删除分支

**`git branch -d <branch-name>`**

删除指定分支。

注意：

1. 先切换到其他分支才能删除该分支。否则会报错：

   error: Cannot delete the branch 'TryDebug' which you are currently on.

2. 若要删除的分支有内容没有合并到其他分支则会报错：

   error: The branch 'TryDebug' is not fully merged.
   If you are sure you want to delete it, run 'git branch -D TryDebug'.

### 比较不同

可以比较任意两处的不同。具体使用可参见：[git diff](https://git-scm.com/docs/git-diff)

分为以下三种情况：

#### 1. 同一分支同一版本不同工作树之间的比较

比较的是三个工作树之间的不同。

##### git diff

显示工作区和暂存区中文件的不同。显示的结果等价于`git diff <暂存区> <工作区>`

疑问：这个有什么用呀？一般修改后要提交都会git add然后再git commit，谁会把修改后的放在暂存区里却不提交呀。

答：不是，提交后暂存区会一直储存你放入暂存区的最新版本。所以你修改完文件后可以使用git diff查看你做了哪些修改。

##### git diff --staged

显示暂存区和最新提交版本中文件的不同。

##### git diff HEAD

显示工作区和最新提交版本中文件的不同。

`git diff HEAD -- ./<filename>`指定文件的不同

`git diff HEAD -- ./'*.txt'`所有指定类型文件的不同

#### 2. 同一分支不同版本之间的比较

##### git diff HEAD^ HEAD

比较上一个版本和最新版本之间的区别。

同理`HEAD^^`代表上上一个版本，也可以写作`HEAD~2`。

#### 3. 不同分支之间的比较

比较的是分支之间提交过的内容的不同，未提交的内容无法比较。

##### git diff <specified-branch>

比较指定分支与当前分支之间的不同。等价于`git diff <specified-branch> <current-branch>`

##### git diff <first-branch> <second-branch>

比较两分支之间最新内容的不同。同`git diff <first-branch>..<second-branch>`

##### git diff <version1-id> <version2-id>

更通用的方法，比较任意两个版本之间的不同。先用`git reflog`查找需要比较的两个版本的ID号，然后进行比较。

##### git diff <first-branch>...<second-branch>

比较两分支自上次同步后，second-branch作了哪些修改。

### 版本回退

回到过去。

#### git reset [commit]

#### git reset --hard [commit]

退回到之前提交过的一个版本并更新工作区文件。

commit可以是版本的ID，一般使用前7位即可，如`git reset --hard 42cf452`

也可以使用`git reset --hard HEAD^`或者`git reset --hard HEAD~1`退回到上一个版本，可以此类推回到之前的任意版本。

此命令也可以用于退回到旧的版本后想再回到新的版本，需要配合`git reflog`找到新的版本的版本ID，然后`gitreset --hard [ID]`即可在各个版本之间切换自如。（参考自：[廖雪峰的官方网站-版本回退](https://www.liaoxuefeng.com/wiki/0013739516305929606dd18361248578c67b8067c8c017b000/0013744142037508cf42e51debf49668810645e02887691000/)）

注意：这种方法对于有远程仓库的使用起来会有问题。详见上述网站的评论。可以使用revert+push

### 删除

#### 删除仓库

直接删除.git文件夹

#### 取消某文件的版本控制

**`git rm --cached <file>`**

一次性取消所有文件的版本控制

`git rm -rf --cached .`

### 结合远程仓库

#### 添加远程仓库

**`git remote add <remote-repository-name> <url>`**

将本地仓库添加到远程仓库中。

`<repository-name>`为远程仓库的名称，一般教程上为`origin`。

`<url>`为远程仓库的地址。

#### 查看远程仓库

**`git remote`**

查看已有的远程仓库。

**`git branch -r`**

查看远程仓库的分支。

**`git remote -v`**

查看本地仓库都链接到了哪些远程仓库。

`-v`中v是verbose详细的。（参考自：[CSDN-git命令之git remote的用法](https://blog.csdn.net/wangjia55/article/details/8802490)）

#### 推送本地仓库到远程仓库

**`git push <remote-repository-name> <branch-name> `**

推送指定分支到远程仓库中相同名称的分支。如果远程仓库没有这个名称的分支则会创建一个。

`git push <remote-repository-name> HEAD`

推送当前分支到远程仓库中相同名称的分支。

#### 拉取远程仓库到本地仓库

**`git pull`**

从远程仓库获取最新版本并合并到本地。

git pull的操作相当于，git fetch + git merge。

**`git fetch`**

将远程仓库的最新版本拉取到本地，但是不自动合并。

在实际使用中，git fetch更安全一些，因为在merge前，我们可以查看更新情况，然后再决定是否合并。（参考自：[CSDN-Git fetch和git pull的区别](https://blog.csdn.net/hudashi/article/details/7664457)）

#### 查看版本

`git tag`

列出所有版本

`git tag -a v1.4 -m 'my version 1.4'`  

打标签，打版本号

#### 切换版本

`git checkout <版本号>`



## 使用场景



## BUG

### bug0001

$ git checkout master

error: pathspec 'master' did not match any file(s) known to git.

描述：本地新建仓库后，新建develop进行操作，操作完毕想切回master分支出现错误，此时master分支里是空的。

解决：新建仓库后需要有个初始的commit之后master分支才存在。也就是说正常操作流程应该是git init > 创建文件并提交 > 创建新分支 > 切换到新分支进行一系列操作

### bug0002

$ git add .

warning: LF will be replaced by CRLF in CMake.md.
The file will have its original line endings in your working directory.

描述：git add .时提示错误

解决：Unix系统中，行末以换行符line feed（LF）结尾。而Windows中，以回车符carriage return(CR)和换行符line feed(LF)，即CRLF结尾。所以该warning是跨系统导致的。

可以通过`git config core.autocrlf true`来关掉warning。

参考：[LF will be replaced by CRLF in git - What is that and is it important? [duplicate]](https://stackoverflow.com/questions/5834014/lf-will-be-replaced-by-crlf-in-git-what-is-that-and-is-it-important?rq=1)



