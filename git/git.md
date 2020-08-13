# Git

## 资料
1. [Git FAQ](https://git.wiki.kernel.org/index.php/Git_FAQ)
   上面有很多经典问题，可以过一遍

2. [Git书籍Pro Git中文版](https://git-scm.com/book/zh/v2)

## 目录

> 本地仓库

- [初次使用](#初次使用)



> 本地与远程仓库协作

- [通过SSH密钥建立本地与云端的连接](#通过SSH密钥建立本地与云端的连接)
- [本地仓库首次托管到远程仓库](#本地仓库首次托管到远程仓库)


---

---

# 初次使用

``` bash
git init
git add .
git commit -m "first commit"
```

---

# [通过SSH密钥建立本地与云端的连接](https://help.github.com/cn/articles/connecting-to-github-with-ssh)

## [关于SSH](https://help.github.com/cn/articles/about-ssh)

使用SSH协议，可以建立与远程服务器的连接和认证。而使用SSH密钥，可以在不使用用户名和密码的情况下连接服务器。

如果 SSH 密钥一年未使用，则 GitHub 会出于安全保护而自动删除非活动的 SSH 密钥。

## [检查是否已有SSH密钥](https://help.github.com/cn/articles/checking-for-existing-ssh-keys)

``` bash
$ ls -la ~/.ssh
```

## [生成新的SSH密钥](https://help.github.com/cn/articles/generating-a-new-ssh-key-and-adding-it-to-the-ssh-agent)

``` bash
$ ssh-keygen -t rsa -b 4096 -C "GitHub上的电子邮件地址"
```

## [在Github中添加SSH密钥](https://help.github.com/cn/articles/adding-a-new-ssh-key-to-your-github-account)

1. 复制SSH密钥到剪贴板
命令行的方式反而不好用，直接打开公钥复制出来即可。
    ``` bash
    # win
    $ clip < ~/.ssh/id_rsa.pub
    # linux
    $ sudo apt-get install xclip
    $ xclip -sel clip < ~/.ssh/id_rsa.pub
    ```

2. 添加到github账户

    Settings --> SSH and GPG keys --> New SSH key

## [可选][测试SSH连接](https://help.github.com/cn/articles/testing-your-ssh-connection)

``` bash
# github
$ ssh -T git@github.com
# gitlab

```

## [可选][修改SSH密钥密码](https://help.github.com/cn/articles/working-with-ssh-key-passphrases)

``` bash
$ ssh-keygen -p
```

---

## SSH密钥共存

1. `ssh-keygen`生成密钥时保存成不同的名称。
2. 后台启动ssh-agent
    ``` bash
    $ eval $(ssh-agent -s)
    > Agent pid xxxxx
    ```
3. 将 SSH 私钥添加到 ssh-agent

    没有`.pub`后缀的是私钥
    ``` bash
    $ ssh-add ~/.ssh/<private_ssh_key_name>
    ```
4. [可选]查看已经添加的密钥
    ``` bash
    $ ssh-add -l
    ```
5. 添加配置文件
    ``` bash
    $ cd ~/.ssh
    $ touch config
    ```
6. 配置文件config内容如下
    ``` txt
    # gitlab
    Host gitlab.com
    RSAAuthentication yes
    IdentityFile ~/.ssh/<private_ssh_key_name1>
    # github
    Host github.com
    RSAAuthentication yes
    IdentityFile ~/.ssh/<private_ssh_key_name2>
    ```
最终,`ssh -T git@gitlab.com`没有成功,但是能够正常连接

# 多个远程仓库共用一个SSH密钥

更简单的方法如下,一台电脑一个SSH密钥,多个所有账户共用一个密钥,用户名的配置只和git有关,和SSH无关。
1. 本地生成密钥
    ``` bash
    $ ssh-keygen
    ```
2. 将公钥添加到远程仓库的账户中
3. 在对应的目录下设置对应的局部user信息
    ``` bash
    $ git config user.email "you@example.com"
    $ git config user.name "Your Name"
    ```

# 本地仓库首次托管到远程仓库



``` bash
git remote add origin git@github.com:JustForFunOk/StudyNotes.git
git push -u origin master
```

# 远程仓库强制覆盖本地仓库

``` bash
$ git fetch --all && git reset --hard origin/<master> && git pull
```

# git status

## 查看被忽略的文件
> --ignored
> Show ignored files as well.

.gitignore中设置忽略文件后，可以通过下述命令验证结果
``` bash
git status --ignored
```

# git push

> -u, --set-upstream
    For every branch that is up to date or successfully pushed, add upstream (tracking) reference, used by argument-less git-pull(1) and other commands.

本地分支推送到远端develop

``` bash
git push origin HEAD:develop
```

其中，origin指要远程仓库，HEAD指本地当前所在分支的最新状态，develop是远端分支名

## git 管理空文件夹

场景：文件夹下的文件是程序生成的文件，不需要加入版本管理，但是程序写的不鲁棒，不能自动创建文件夹，需要该文件夹存在。

理论上来将是不行的，因为git管理的是文件，如果该文件夹下没有文件，则不会加入管理。
因此解决方法：
1. 改善程序，能自动生成该目录
2. 在该文件夹下添加一个隐藏文件`.gitignore`，这样就能加入版本管理了

### 参考
1. [How can I add an empty directory to a Git repository?](https://stackoverflow.com/questions/115983/how-can-i-add-an-empty-directory-to-a-git-repository)
2. [Git FAQ](https://git.wiki.kernel.org/index.php/GitFaq#Can_I_add_empty_directories.3F)

## git ahead of

``` bash
$ git status
On branch develop
Your branch is ahead of 'origin/develop' by 1 commit.
  (use "git push" to publish your local commits)
nothing to commit, working directory clean
```
本地代码已经push，没有做任何修改，为什么会ahead of ?

因为你push之后没有更新远端状态，执行`git pull --rebase`操作后，将远端情况更新到本地就没问题了。
``` bash
On branch develop
Your branch is up-to-date with 'origin/develop'.
nothing to commit, working directory clean
```

## 对比本地分支和远端分支内容的不同

``` bash
git fetch
# git diff <local_branch> <remote_branch>
git diff master origin/master
```

[How to compare a local git branch with its remote branch?](https://stackoverflow.com/questions/1800783/how-to-compare-a-local-git-branch-with-its-remote-branch)

## 在远程分支最新状态的基础上建立新的本地分支

建立在`remote_branch`的基础上建立`local_new_branch`分支。

创建分支后还是要手动`git pull`一下，因为这是在**本地暂存的`remote_branch`上建立的分支**, 只是建立了`upstream`，并没有从远端拉取最新代码，这时远端的改变并没有更新到本地。

``` bash
$ git checkout -b <local_new_branch> origin/<remote_branch>
$ git pull
```

我之前还有一种做法是：在本地develop分支上`git pull`获取远端develop分支上的最新状态，然后`git checkout -b <local_new_branch>`。

第一种方法能够建立upstream，通过`git branch -vv`能看到新的本地分支的upstream branch。如果没有upstream，则不能push？需要--set-upstream

-vv verbose信息  When in list mode, show sha1 and commit subject line for each head, along with relationship to upstream branch (if any). If given twice, print the name of the upstream branch, as well (see also git remote show <remote>).


[How do I check out a remote Git branch?](https://stackoverflow.com/questions/1783405/how-do-i-check-out-a-remote-git-branch)

## 忽略权限的管理
文件拷贝到U盘，权限发生了变化
``` bash
$ git diff
old mode 100644
new mode 100755
```
不将文件的权限加入到版本管理中
``` bash
$ git config core.filemode false
```

[How do I remove files saying “old mode 100755 new mode 100644” from unstaged changes in Git?](https://stackoverflow.com/questions/1257592/how-do-i-remove-files-saying-old-mode-100755-new-mode-100644-from-unstaged-cha)


## 父节点不同了

``` bash
$ git pull --rebase
First, rewinding head to replay your work on top of it...
Applying: framework of ibeo sub-class 0 error
Applying: migrate ibeo code from ap2

$ git pull
Already up-to-date.

$ git status
On branch L4UPS-51
Your branch is ahead of 'origin/develop' by 2 commits.
  (use "git push" to publish your local commits)
nothing to commit, working directory clean


$ git push origin HEAD:L4UPS-51
To git@gitlab.csvw.com:SVW_ER_DEV/AP/urban-pilot/vehicle/research-platform.git
 ! [rejected]        HEAD -> L4UPS-51 (non-fast-forward)
error: failed to push some refs to 'git@gitlab.csvw.com:SVW_ER_DEV/AP/urban-pilot/vehicle/research-platform.git'
hint: Updates were rejected because the tip of your current branch is behind
hint: its remote counterpart. Integrate the remote changes (e.g.
hint: 'git pull ...') before pushing again.
hint: See the 'Note about fast-forwards' in 'git push --help' for details.

```

--rebase会将自己的提交放到最后面

解决方法：
``` bash
$ git push -f origin HEAD:L4UPS-51
```

https://stackoverflow.com/questions/10298291/cannot-push-to-github-keeps-saying-need-merge

## 空分支

创建一个空的全新的分支。如果仓库中已经有了提交，那么之后的分支都要base到之前的分支上，如何创建一个全新的啥都不包含的分支？

`--orphan`

``` bash
$ git checkout --orphan dev2
Switched to a new branch 'dev2'
$ git reset # unstage all the files, you probably don't want to commit all of them
$ git commit --allow-empty -m 'Initial empty commit'
[dev2 (root-commit) a515c28] Initial empty commit
```
[How to create a new (and empty!) “root” branch?](https://stackoverflow.com/questions/15034390/how-to-create-a-new-and-empty-root-branch)