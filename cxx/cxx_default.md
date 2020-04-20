# default

## 几个问题

### 在析构函数后往往会加上`=default`，有什么用？

``` c++
~TestDefault() = default;
```