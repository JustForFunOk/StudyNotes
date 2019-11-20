# 字符串

## 字符串太长，分割到多行


## 字符串包含变量

``` python
>>> shepherd = "Mary"
>>> age = 32
>>> stuff_in_string = "Shepherd {} is {} years old.".format(shepherd, age)
>>> print(stuff_in_string)
Shepherd Mary is 32 years old.

>>> print("Number {:03d} is here.".format(11))
Number 011 is here.

>>> 'A formatted number - {:.4f}'.format(.2)
'A formatted number - 0.2000'
```

特例：若字符串中有{}则需用{{}}带替原来的{}
``` python
>>> x = " {{ Hello }} {0} "
>>> print x.format(42)
' { Hello } 42 '
```

[Inserting values into strings](https://matthew-brett.github.io/teaching/string_formatting.html)
[How can I print literal curly-brace characters in python string and also use .format on it?]()


