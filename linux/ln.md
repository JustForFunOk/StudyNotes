# ln

```bash
$ ln source destination  # hard link
$ ln -s source destination  # symbol link
```

## 硬链接 vs 软链接 vs 复制

硬链接 一份源文件  带计数器的引用 浅拷贝  删除其中一个另一个仍然存在并可用  只能用于文件不能用于文件夹

软链接 一份源文件 一个指向源文件的快捷方式 指针  删除链接文件源文件仍然存在并可用  删除源文件，链接文件仍存在但无意义  就是windows中的快捷方式

复制 两份源文件 深拷贝  两文件完全无关系