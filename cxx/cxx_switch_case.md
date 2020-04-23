# switch-case


## case中的局部变量

``` C++
switch(flag)
{
    case 1:
    {  // 必须要加
        int i = 0;
        break;
    }  // 必须要加
    case 2:
        break;
    default:
        break;
}

// 否则会报错
error: jump to case label [-fpermissive]
```

case中定义局部变量需要对整个case区域加`{}`，表明该局部变量的作用域仅该case中有效。

### 为什么要这样设计？

#### Example1
``` C++
int flag = 2;
switch(flag)
{
    case 1:
        int i = 0;
        break;
    case 2:
        i++; //执行到`case2`时，此时i并没有定义，会出现意想不到的结果。
        break;
    default:
        break;
}
```
#### Example2
``` C++
switch(flag)
{
    case 1:
        int i = 0; // 即使其他case中没有使用i，也是不被允许的
        break;
    case 2:
        break;
    default:
        break;
}
```


## Reference
1. [stack overflow -- Error: Jump to case label](https://stackoverflow.com/questions/5685471/error-jump-to-case-label)