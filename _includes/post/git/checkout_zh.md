

# git checkout

## 初始创建

`git init`

## 工作回退

### 回退单个文件

```bash
wangzhui@OptiPlex:~/tex$ git status 
On branch master
Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git checkout -- <file>..." to discard changes in working directory)

	modified:   book/ONIE/Script/onie_nos_install.tex
	modified:   book/xxxxbook.tex

no changes added to commit (use "git add" and/or "git commit -a")
```
我们可以通过`git status` 查看当前修改的文件，通过`git diff .`来查看所有被修改过文件的修改内容与上一次commit的不同，

```shell
wangzhui@OptiPlex:~/tex$ git diff book/xxxxbook.tex
diff --git a/book/xxxxbook.tex b/book/xxxxbook.tex
index f452740..e173388 100644
--- a/book/xxxxbook.tex
+++ b/book/xxxxbook.tex
@@ -90,6 +90,7 @@
 
 
 \chapter{ONIE INSTALLER}
+\chapter{ONIE INSTALLER}
 \include{./ONIE/Script/onie_nos_install}
 \include{./ONIE/Script/exec_installer}
 \chapter{SONiC INSTALL}
wangzhui@OptiPlex:~/tex$
```
通过`git diff book/xxxxbook.tex`查看单个文件

```shell
wangzhui@OptiPlex:~/tex$ git diff .
diff --git a/book/ONIE/Script/onie_nos_install.tex b/book/ONIE/Script/onie_nos_install.tex
index 8b13789..de01375 100644
--- a/book/ONIE/Script/onie_nos_install.tex
+++ b/book/ONIE/Script/onie_nos_install.tex
@@ -1 +1,2 @@
 
+\chapter{ONIE INSTALLER}
\ No newline at end of file
diff --git a/book/xxxxbook.tex b/book/xxxxbook.tex
index f452740..e173388 100644
--- a/book/xxxxbook.tex
+++ b/book/xxxxbook.tex
@@ -90,6 +90,7 @@
 
 
 \chapter{ONIE INSTALLER}
+\chapter{ONIE INSTALLER}
 \include{./ONIE/Script/onie_nos_install}
 \include{./ONIE/Script/exec_installer}
 \chapter{SONiC INSTALL}
```

`git checkout -- book/xxxxbook.tex` 


```bash
wangzhui@OptiPlex:~/tex$ ls
article  beamer  book  examples  fonts  Pandoc  README.md  vitae

wangzhui@OptiPlex:~/tex$ git checkout -- book/xxxxbook.tex
wangzhui@OptiPlex:~/tex$ git status 
On branch master
Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git checkout -- <file>..." to discard changes in working directory)

	modified:   book/ONIE/Script/onie_nos_install.tex

no changes added to commit (use "git add" and/or "git commit -a")
wangzhui@OptiPlex:~/tex$ 
```

### 回退当前所有未commit修改

`git checkout -- .`





## GIT 中文显示数字

```bash
git config --global core.quotepath false
```







