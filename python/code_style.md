# 编程规范

* [Python 风格指南 - 内容目录](https://zh-google-styleguide.readthedocs.io/en/latest/google-python-styleguide/contents/)

* [Google Python Style Guide](https://google.github.io/styleguide/pyguide.html)

## 工具

* [yapf](https://github.com/google/yapf/)  
  统一格式的工具，类似与clang-format。只是修改格式，不会做语法等错误检查。


### Shebang #!

#!先用于帮助内核找到Python解释器, 但是在导入模块时, 将会被忽略. 因此只有被直接执行的文件中才有必要加入#!.

### [注释](https://google.github.io/styleguide/pyguide.html#38-comments-and-docstrings)

使用`""" """`或`#`进行注释。

注释中不用描述该函数是怎么实现的（除非是一些复杂的算法），只要描述怎么使用该函数即可。

#### 函数与功能
* Args 参数
* Returns 返回值
* Raises 列出与接口有关的所有异常

``` python
def fetch_bigtable_rows(big_table, keys, other_silly_variable=None):
    """Fetches rows from a Bigtable.

    Retrieves rows pertaining to the given keys from the Table instance
    represented by big_table.  Silly things may happen if
    other_silly_variable is not None.

    Args:
        big_table: An open Bigtable Table instance.
        keys: A sequence of strings representing the key of each table row
            to fetch.
        other_silly_variable: Another optional variable, that has a much
            longer name than the other args, and which does nothing.

    Returns:
        A dict mapping keys to the corresponding table row data
        fetched. Each row is represented as a tuple of strings. For
        example:

        {'Serak': ('Rigel VII', 'Preparer'),
         'Zim': ('Irk', 'Invader'),
         'Lrrr': ('Omicron Persei 8', 'Emperor')}

        If a key from the keys argument is missing from the dictionary,
        then that row was not found in the table.

    Raises:
        IOError: An error occurred accessing the bigtable.Table object.
    """
    pass
```

#### 类
* Attributes 公共属性
``` python
class SampleClass(object):
    """Summary of class here.

    Longer class information....
    Longer class information....

    Attributes:
        likes_spam: A boolean indicating if we like SPAM or not.
        eggs: An integer count of the eggs we have laid.
    """

    def __init__(self, likes_spam=False):
        """Inits SampleClass with blah."""
        self.likes_spam = likes_spam
        self.eggs = 0

    def public_method(self):
        """Performs operation blah."""

```

#### 块注释和行注释
* 对于复杂的操作, 应该在其操作开始前写上若干行注释. 
* 对于不是一目了然的代码, 应在其行尾添加注释.
``` python

# We use a weighted dictionary search to find out where i is in
# the array.  We extrapolate position based on the largest num
# in the array and the array size and then do binary search to
# get the exact number.

if i & (i-1) == 0:        # True if i is 0 or a power of 2.
```

### 命名

|Type|Public|Internal|
|:--:|:--:|:--:|
|Modules |lower_with_under	|_lower_with_under|
|Packages|lower_with_under||	 
|Classes |CapWords	|_CapWords|
|Exceptions	|CapWords	| |
|Functions	|lower_with_under()|_lower_with_under()|
|Global/Class Constants|CAPS_WITH_UNDER|_CAPS_WITH_UNDER|
|Global/Class Variables|lower_with_under|_lower_with_under|
|Instance Variables|lower_with_under|_lower_with_under (protected) </br> __lower_with_under (private)|
|Method Names|lower_with_under()	|_lower_with_under() (protected) </br> __lower_with_under() (private)
|Function/Method Parameters	|lower_with_under| 
|Local Variables|	lower_with_under|	 