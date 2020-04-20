# CMake

## 功能

### 将所有的warning变成error
在CMakeLIsts.txt文件中，添加
``` CMake
add_compile_options(-Wall -Wextra -pedantic -Werror)
```
这样能够将warning显示出来，并将所有的warning变成error，这样只要有warning程序都不能通过编译。

[How to set warning level in CMake?](https://stackoverflow.com/questions/2368811/how-to-set-warning-level-in-cmake/50882216#50882216)





## target_complie_definitions

在CMakeLists.txt中添加宏，使得.cpp中能够进行宏编译


## add_compile_options


## 将类的实例化放在while循环里会怎么样？