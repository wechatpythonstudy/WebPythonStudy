

# DRIVER

#### 字符设备 ，块设备区别

字符设

提供连续的数据流，应用程序可以顺序读取，通常不支持随机存取。相反，此类设备支持按字节/字符来读写数据。举例来说，键盘、串口、调制解调器都是典型的字符设备。

块设备

应用程序可以随机访问设备数据，程序可自行确定读取数据的位置。硬盘、软盘、CD-ROM驱动器和闪存都是典型的块设备，应用程序可以寻址磁盘上的任何位置，并由此读取数据。此外，数据的读写只能以块(通常是512B)的倍数进行。与字符设备不同，块设备并不支持基于字符的寻址。

字符设备与块设备的区别

这两种类型的设备的根本区别在于它们是否可以被随机访问——换句话说就是，能否在访问设备时随意地从一个位置跳转到另一个位置。举个例子，键盘这种设备提供的就是一个数据流，当你敲入"fox" 这个字符串时，键盘驱动程序会按照和输入完全相同的顺序返回这个由三个字符组成的数据流。如果让键盘驱动程序打乱顺序来读字符串，或读取其他字符，都是没有意义的。所以键盘就是一种典型的字符设备，它提供的就是用户从键盘输入的字符流。对键盘进行读操作会得到一个字符流，首先是"f"，然后是"o"，最后是"x"，最终是文件的结束（EOF）。当没人敲键盘时，字符流就是空的。硬盘设备的情况就不大一样了。硬盘设备的驱动可能要求读取磁盘上任意块的内容，然后又转去读取别的块的内容，而被读取的块在磁盘上位置不一定要连续，所以说硬盘可以被随机访问，而不是以流的方式被访问，显然它是一个块设备。
 内核管理块设备要比管理字符设备细致得多，需要考虑的问题和完成的工作相比字符设备来说要复杂许多。这是因为字符设备仅仅需要控制一个位置—当前位置—而块设备访问的位置必须能够在介质的不同区间前后移动。所以事实上内核不必提供一个专门的子系统来管理字符设备，但是对块设备的管理却必须要有一个专门的提供服务的子系统。不仅仅是因为块设备的复杂性远远高于字符设备，更重要的原因是块设备对执行性能的要求很高；对硬盘每多一分利用都会对整个系统的性能带来提升，其效果要远远比键盘吞吐速度成倍的提高大得多。另外，我们将会看到，块设备的复杂性会为这种优化留下很大的施展空间。

```bash
[root@tom /]# cd /dev                           /*进入/dev目录*/  
[root@tom dev]# ls -l                           /*列出/dev中文件的信息*/、 
 /*第1字段     2  3  4      5    6         7      8  */  
crw-rw----+     1 root root    14,  12  12-21 22:56 adsp  
crw-------      1 root root    10, 175  12-21 22:56 agpgart  
crw-rw----+     1 root root    14,   4  12-21 22:56 audio  
brw-r-----      1 root disk   253,   0  12-21 22:56 dm-0  
brw-r-----      1 root disk   253,   1  12-21 22:56 dm-1  
crw-rw----      1 root root    14,   9  12-21 22:56 dmmidi 
```



# 4 字符设备与块设备的区分

每一个字符设备或者块设备都在/dev目录下对应一个设备文件。读者可以通过查看/dev目录下的文件的属性，来区分设备是字符设备还是块设备。使用cd命令进入/dev目录，并执行ls -l命令就可以看到设备的属性

作者：CodeMyLove

链接：https://www.jianshu.com/p/477c5b583fbe

来源：简书

简书著作权归作者所有，任何形式的转载都请联系作者获得授权并注明出处。



##### 驱动示例

```c
/**
 * @file    hello.c
 * @author  Akshat Sinha
 * @date    10 Sept 2016
 * @version 0.1
 * @brief  An introductory "Hello World!" loadable kernel
 *  module (LKM) that can display a message in the /var/log/kern.log
 *  file when the module is loaded and removed. The module can accept
 *  an argument when it is loaded -- the name, which appears in the
 *  kernel log files.
*/
#include <linux/module.h>     /* Needed by all modules */
#include <linux/kernel.h>     /* Needed for KERN_INFO */
#include <linux/init.h>       /* Needed for the macros */
///< The license type -- this affects runtime behavior
MODULE_LICENSE("GPL");
///< The author -- visible when you use modinfo
MODULE_AUTHOR("Akshat Sinha");
///< The description -- see modinfo
MODULE_DESCRIPTION("A simple Hello world LKM!");
///< The version of the module
MODULE_VERSION("0.1");
static int __init hello_start(void)
{
    printk(KERN_INFO "Loading hello module...\n");
    printk(KERN_INFO "Hello world\n");
    return 0;
}
static void __exit hello_end(void)
{
    printk(KERN_INFO "Goodbye Mr.\n");
}
module_init(hello_start);
module_exit(hello_end);

```

##### 带参数的内核模块

```c
#include <linux/init.h>
#include <linux/module.h>
static char *book_name = "dissecting Linux Device Driver";
module_param(book_name, charp, S_IRUGO);

static int book_num = 4000;
module_param(book_num, int, S_IRUGO);

static int __init book_init(void)
{
   printk(KERN_INFO "book name:%s\n", book_name);
   printk(KERN_INFO "book num:%d\n", book_num);
   return 0;
}
module_init(book_init);
static void __exit book_exit(void)
{
	printk(KERN_INFO "book module exit\n ");
}
module_exit(book_exit);
MODULE_AUTHOR("Barry Song <baohua@kernel.org>");
MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("A simple Module for testing module params");
MODULE_VERSION("V1.0");
```

##### 模块的声明与描述 MODULE_ALIAS

```c
MODULE_AUTHOR(author);
MODULE_DESCRIPTION(description);
MODULE_VERSION(version_string);
MODULE_DEVICE_TABLE(table_info);
MODULE_ALIAS(alternate_name);
```

##### 设备驱动支持列表 MODDULE_DEVICE_TABEL

```c
/* table of devices that work with this driver */
static struct usb_device_id skel_table [] = {
{ USB_DEVICE(USB_SKEL_VENDOR_ID,
USB_SKEL_PRODUCT_ID) },
{ } /* terminating enttry */
};
MODULE_DEVICE_TABLE (usb, skel_table);
```

##### 模块的编译

```makefile
KVERS = $(shell uname -r)
	# Kernel modules
obj-m += hello.o
	# Specify flags for the module compilation.
	# EXTRA_CFLAGS=-g -O0
build: kernel_modules
kernel_modules:
	make -C /lib/modules/$(KVERS)/build M=$(CURDIR) modules
clean:
	make -C /lib/modules/$(KVERS)/build M=$(CURDIR) clean
```

​	包含多个.c文件

```
obj-m := modulename.o
modulename-objs := file1.o file2.o
```

##### GPL

the symbols exported by EXPORT_SYMBOL_GPL()can only be seen by modules with a MODULE_LICENSE()that specifies a GPL
compatible license.”

由此可见内核用EXPORT_SYMBOL_GPL()导出的符号是不可以被非GPL模块引用的