

# LINUX Driver File Node



```c
static struct file_operations fops = {
        .owner = THIS_MODULE,
        .read = dev_read,
        .write = dev_write,
        .open = dev_open,
        .release = dev_release
};
```



dev_read:





