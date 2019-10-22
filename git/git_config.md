# git config

> git-config - Get and set repository or global options


`--global`会将设置写入到`~/.gitconfig`文件中  

`--local`会将设置写入到当前项目的`.git/config`文件中


## 查看配置
> -l, --list  
List all variables set in config file, along with their values.


* 查看global设置
    ``` bash
    git config --global -l
    ```
* 查看local设置
    ``` bash
    git config -l
    ```
## 参考
1. `git config --help`
