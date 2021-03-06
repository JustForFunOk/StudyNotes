# git remote

## 修改远程仓库链接

如远程仓库名修改后，链接就失效了，不能进行push了。

``` bash
# 查看目前链接
$ git remote -v
# 修改链接
# git remote set-url [--push] <name> <newurl> [<oldurl>]
$ git remote set-url origin <new_url>
# 验证修改
$ git remote -v
```
name一般设置为origin

### 从http连接修改为ssh连接

公钥配置好后还要修改remote的url，从`http:xxx`修改为`git@xxx`,使用`git remote set-url origin git@xxx`

## 查看本地仓库链接的远程仓库

**`git remote -v`**

查看本地仓库都链接到了哪些远程仓库。

`-v`中v是verbose详细的。（参考自：[CSDN-git命令之git remote的用法](https://blog.csdn.net/wangjia55/article/details/8802490)）


## 本地remotes-tracking

本地的remotes区域也保存了一份远端所有的分支,叫做`remote-tracking reference`，通过`git branch -a`可查看，`git fetch`时会将远端分支同步到该区域。

### 有什么作用？
`git checkout -b new_branch origin/develop`这个创建新分支的命令中`origin/develop`就是本地的remotes-tracking，新建的分支就是基于本地的，可能落后于远端分支。

经常看到
"Your branch is behind 'origin/develop' by 6 commits, ...", 就是与本地的remotes-tracking develop分支进行比较的。




## 清理过时的本地remotes分支

> Those tracking branches are created in order to track changes but they may become obsolete if remote branches were deleted on the server.

merge分支到主分支后，源分支在远端会被删除，而本地却不会，这就会导致本地有很多无效的过期分支，如何清理呢？
``` bash
# 查看有哪些过期分支
$ git remote prune -n origin
 * [would prune] origin/L4UPS-36
 * [would prune] origin/L4UPS-51
 * [would prune] origin/L4UPS-88

# 删除这些过期分支
$ git remote prune origin
 * [pruned] origin/L4UPS-36
 * [pruned] origin/L4UPS-51
 * [pruned] origin/L4UPS-88
```

[How To Clean Up Git Branches](https://devconnected.com/how-to-clean-up-git-branches/) ;
[cleaning up old remote git branches](https://stackoverflow.com/questions/3184555/cleaning-up-old-remote-git-branches)