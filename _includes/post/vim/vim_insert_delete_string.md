
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

