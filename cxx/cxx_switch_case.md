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

## 没有break的case

``` C++
int x = 2;
switch (x)
{
    case 1:
        cout << "Choice is 1";
        break;
    case 2:
        cout << "Choice is 2";
        //break;  // 会继续无条件执行接下来的语句，直到遇见break
    case 3:
        cout << "Choice is 3";
        break;
    default:
        cout << "Choice other than 1, 2 and 3";
        break;
}
----------Output-----------
Choice is 2Choice is 3
```

## switch case原理





## Reference
1. [stack overflow -- Error: Jump to case label](https://stackoverflow.com/questions/5685471/error-jump-to-case-label)
2. [Switch底层执行原理](https://blog.csdn.net/Abrazen_zz/article/details/79250450)