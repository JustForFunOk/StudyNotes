# git remote

## 修改远程仓库链接

如远程仓库名修改后，链接就失效了，不能进行push了。

``` bash
# 查看目前链接
$ git remote -v
# 修改链接
$ git remote set-url <new_url>
# 验证修改
$ git remote -v
```
