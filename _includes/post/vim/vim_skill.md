

# vim skill

vim 复制

`sudo apt-get install vim-gnome`



#### vim normal find

press `/` and  paset what you want to find.

#####  vim find with case sensitive

`/word_for_find\c` without case sensitive
`/word_for_find\C` with case sensitive

#####  vim case sensitive configure

`:set ignorecase` configure case unsensitive
`:set smartcase` configure case sensitive while have a case in `word_for_find`

#####  vim find present words

press `*` same as `shift + 8` `#` `shift + 3`

####  vim replace

`:{action ragne}s/{target}/{replace_word}/{replace sign}`

#### 注释

```
       ,ca在可选的注释方式之间切换，比如C/C++ 的块注释/* */和行注释//  
       ,cc注释当前行
       ,c<space> 切换注释/非注释状态
       ,cs 以”性感”的方式注释
       ,cA 在当前行尾添加注释符，并进入Insert模式
       ,cu 取消注释
      ,c$ 从光标开始到行尾注释  ，这个要说说因为c$也是从光标到行尾的快捷键，这个按过逗号（，）要快一点按c$
      2,cc 光标以下count行添加注释 
      2,cu 光标以下count行取消注释
      2,cm:光标以下count行添加块注释(2,cm)
      Normal模式下，几乎所有命令前面都可以指定行数
      Visual模式下执行命令，会对选中的特定区块进行注释/反注释
```

*在使用",c"时候,按键要迅速,然后再按后续的a,c,s,A等字符来表示选择那种操作*

## 字符插入与删除

#### 行首插入字符

`:10,20 s/^/insertString`表示在10,20行行前插入字符`insertString`
需要注意，这些行必须存在才能插入字符，如果是一个空文件没有对应行是不能插入字符的。

```









insertString
insertString
insertString
insertString
insertString
insertString
insertString
insertString
insertString
insertString
insertString
insertString






```

`:10,$ s/^/insertString` 2行至末尾插入`insertString` `$`表示末尾，`^/`表示行首

`:% s/^/insertString` 表示所有行插入`insertString`


####  行尾部插入字符

`:% s/$/  thisendofstring`

```
    thisis end of string
    thisis end of string
    thisis end of string
    thisis end of string
    thisis end of string
    thisis end of string
    thisis end of string
    thisis end of string
    thisis end of string
insertString    thisis end of string
insertString    thisis end of string
insertString    thisis end of string
insertString    thisis end of string
insertString    thisis end of string
insertString    thisis end of string
insertString    thisis end of string
insertString    thisis end of string
insertString    thisis end of string
insertString    thisis end of string
insertString    thisis end of string
insertString    thisis end of string
    thisis end of string
    thisis end of string
    thisis end of string
    thisis end of string
    thisis end of string
    thisis end of string

```

`:10,27 s/$/    thisis end of string` 注意从最后`/`开始空格也是算字符的。

#### 行首删除字符

`:15,19 s/insert/`

```
    thisis end of string
    thisis end of string
    thisis end of string
    thisis end of string
    thisis end of string
    thisis end of string
    thisis end of string
    thisis end of string
    thisis end of string
insertString    thisis end of string
insertString    thisis end of string
insertString    thisis end of string
insertString    thisis end of string
insertString    thisis end of string
String    thisis end of string
String    thisis end of string
String    thisis end of string
String    thisis end of string
String    thisis end of string
insertString    thisis end of string
insertString    thisis end of string
    thisis end of string
    thisis end of string
    thisis end of string
    thisis end of string
    thisis end of string
    thisis end of string
```
可以看到15-19行的insert字符被删除。

`:% s/ing$//g`
`$`表示匹配末尾，`//g`表示结束字符串，也可以使用`:% s/ing$/`

```
    thisis end of str
    thisis end of str
    thisis end of str
    thisis end of str
    thisis end of str
    thisis end of str
    thisis end of str
    thisis end of str
    thisis end of str
insertString    thisis end of str
insertString    thisis end of str
insertString    thisis end of str
insertString    thisis end of str
insertString    thisis end of str
String    thisis end of str
String    thisis end of str
String    thisis end of str
String    thisis end of str
String    thisis end of str
insertString    thisis end of str
insertString    thisis end of str
    thisis end of str
    thisis end of str
    thisis end of str
    thisis end of str
    thisis end of str
    thisis end of str
```

可以看到所有行末尾的`ing`字符全被删除

`:% s/ing/`
表示删除该行从左到右第一个`ing`字符

```
    thisis end of str
    thisis end of str
    thisis end of str
    thisis end of str
    thisis end of str
    thisis end of str
    thisis end of str
    thisis end of str
    thisis end of str
insertStr    thisis end of string
insertStr    thisis end of string
insertStr    thisis end of string
insertStr    thisis end of string
insertStr    thisis end of string
Str    thisis end of string
Str    thisis end of string
Str    thisis end of string
Str    thisis end of string
Str    thisis end of string
insertStr    thisis end of string
insertStr    thisis end of string
    thisis end of str
    thisis end of str
    thisis end of str
    thisis end of str
    thisis end of str
    thisis end of str
```