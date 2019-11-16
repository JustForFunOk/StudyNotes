# cpplint

## VSCode中配置



## BugLists

* Could not find a newline character at the end of the file. [whitespace/ending_newline]  
  在文件末尾加一行空行

*  { should almost always be at the end of the previous line  [whitespace/braces]  
  {不应该另起一行

*  Missing space before {  [whitespace/braces]
  { 前要有空格

*  Include the directory when naming .h files  [build/include_subdir]  
  ???

*  Found C system header after C++ system header. Should be: can_transmitter.h, c system, c++ system, other.  [build/include_order]  
  头文件的顺序有要求：自己库的头文件、C系统头文件、C++系统头文件、其他头文件

*  public: should be indented +1 space inside class Can_Transmitter  [whitespace/indent]  
  public前缩进一个空格

*  Redundant blank line at the start of a code block should be deleted.  [whitespace/blank_line]  
  删除无用的空白行