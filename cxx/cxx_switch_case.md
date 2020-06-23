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

case数量较少时，会逐个case判断；当case数量多时，才会创建一个数组来存放每个case要执行代码段的地址，这样执行的时间复杂度为O(1)。当case后的条件相差较大时情况又不一样。


``` c++
switch (x)
{
    case 1:
        cout << "Choice is 1";
        break;
    case 2:
        cout << "Choice is 2";
        break;
    case 3:
        cout << "Choice is 3";
        break;
    default:
        cout << "Choice other than 1, 2 and 3";
        break;
}
```

``` asm
cmpl	$2, %eax
je	.L3
cmpl	$3, %eax
je	.L4
cmpl	$1, %eax
jne	.L8
```

case数量多时

``` c++
switch (x)
{
    case 1:
        cout << "Choice is 1";
        break;
    case 2:
        cout << "Choice is 2";
        break;
    case 3:
        cout << "Choice is 3";
        break;
    case 4:
        cout << "Choice is 4";
        break;
    case 5:
        cout << "Choice is 5";
        break;
    case 6:
        cout << "Choice is 6";
        break;
    case 7:
        cout << "Choice is 7";
        break;
    case 8:
        cout << "Choice is 8";
        break;
    case 10:
        cout << "Choice is 9";
        break;
    default:
        cout << "Choice other than 1, 2 and 3";
        break;
}
```

``` asm
movq	.L4(,%rax,8), %rax
jmp	*%rax


.L4:
	.quad	.L2
	.quad	.L3
	.quad	.L5
	.quad	.L6
	.quad	.L7
	.quad	.L8
	.quad	.L9
	.quad	.L10
	.quad	.L11
	.quad	.L2
	.quad	.L12
	.text
```

当case后的值相差较大时，switch-case的时间效率就不能体现了

``` c++
switch (x)
{
    case 1:
        cout << "Choice is 1";
        break;
    case 2:
        cout << "Choice is 2";
        break;
    case 3:
        cout << "Choice is 3";
        break;
    case 4:
        cout << "Choice is 4";
        break;
    case 5:
        cout << "Choice is 5";
        break;
    case 6:
        cout << "Choice is 6";
        break;
    case 7:
        cout << "Choice is 7";
        break;
    case 8:
        cout << "Choice is 8";
        break;
    case 100:
        cout << "Choice is 9";
        break;
    default:
        cout << "Choice other than 1, 2 and 3";
        break;
}
```

``` asm
	cmpl	$5, %eax
	je	.L3
	cmpl	$5, %eax
	jg	.L4
	cmpl	$2, %eax
	je	.L5
	cmpl	$2, %eax
	jg	.L6
	cmpl	$1, %eax
	je	.L7
	jmp	.L2
.L6:
	cmpl	$3, %eax
	je	.L8
	cmpl	$4, %eax
	je	.L9
	jmp	.L2
.L4:
	cmpl	$7, %eax
	je	.L10
	cmpl	$7, %eax
	jl	.L11
	cmpl	$8, %eax
	je	.L12
	cmpl	$100, %eax
	je	.L13
	jmp	.L2
```



## Reference
1. [stack overflow -- Error: Jump to case label](https://stackoverflow.com/questions/5685471/error-jump-to-case-label)
2. [Switch底层执行原理](https://blog.csdn.net/Abrazen_zz/article/details/79250450)