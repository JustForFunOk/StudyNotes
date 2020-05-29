# const

``` C++
# 1          2             3          4       5
const int* const Method3(const int* const&) const;
```

#5 const

* it cannot call any non-const member functions
* it cannot change any member variables.
* it can be called by a const object(const objects can only call const functions). Non-const objects can also call a const function.

#3 const

the parameter passed cannot be changed within the function

## Reference

1. [C++ Const Usage Explanation](https://stackoverflow.com/questions/5598703/c-const-usage-explanation)
2. [const before parameter vs const after function name c++](https://stackoverflow.com/questions/15999123/const-before-parameter-vs-const-after-function-name-c/15999152)

## 5# const outside class

``` C++
void testConst(int _param) const
{
    xxx
}

int main()
{
    testConst(666);
}

------------build error-----------------
cannot have cv-qualifier void testConst(int _par1) const
                                                   ^
```
Root Cause

5#const是用来修饰隐藏的`this`指针的(是用来修饰成员函数的)，testConst不是类内的成员函数，没有`this`指针。

> The const modifier at the end of the function declaration applies to the hidden `this` parameter for member functions.
As this is a free function, there is no `this` and that modifier is not needed.


cv-qualifier [c-const  v-volatile]


### Reference
[non-member function cannot have cv-qualifier](https://stackoverflow.com/questions/10982628/non-member-function-cannot-have-cv-qualifier)