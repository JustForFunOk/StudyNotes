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
$ ssh -T git@github.com
```

## [可选][修改SSH密钥密码](https://help.github.com/cn/articles/working-with-ssh-key-passphrases)

``` bash
$ ssh-keygen -p
```