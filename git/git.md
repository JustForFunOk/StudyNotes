# Git

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

更简单的方法如下,一台电脑一个SSH密钥,多个所有账户共用一个密钥,用户名的配置只和git有关,和SSH无关
1. 本地生成密钥
    ``` bash
    $ ssh-keygen
    ```
2. 将公钥添加到远程仓库的账户中
3. 在对应的工程下设置局部user信息

# 本地仓库首次托管到远程仓库

``` bash
git remote add origin git@github.com:JustForFunOk/StudyNotes.git
git push -u origin master
```