

# ssr config step

ssr 就是shadosocks 的升级版本，全称为shadowsockssr，使用该版本替换在启动步骤替换原来的 `sslocl -c  /etc/shadowsocks/config.json` 即可继续正常使用代理



### ssr client config

首先获取安装脚本ssr文件， `ssr install` 安装

```
wget http://www.djangoz.com/ssr

sudo mv ssr /usr/local/bin

sudo chmod 766 /usr/local/bin/ssr

ssr install
```

安装完毕后输入ssr config 文件 ，修改配置如下

```json
{
    "server": "217.69.14.7",
    "server_ipv6": "::",
    "server_port": 1463,
    "local_address": "127.0.0.1",
    "local_port": 1080,

    "password": "soledad",
    "method": "chacha20-ietf",
    "protocol": "auth_aes128_md5",
    "protocol_param": "",
    "obfs": "tls1.2_ticket_fastauth_compatible",
    "obfs_param": "",
    "speed_limit_per_con": 0,
    "speed_limit_per_user": 0,

    "additional_ports" : {}, // only works under multi-user mode
    "additional_ports_only" : false, // only works under multi-user mode
    "timeout": 120,
    "udp_timeout": 60,
    "dns_ipv6": false,
    "connect_verbose_info": 0,
    "redirect": "",
    "fast_open": false
}

```

主要就是`method` `protocol` `obfs` 以及IP等配置

启动方式 `ssr start`

停止 `ssr stop`



### chacha-20 算法包未安装解决

```
wangzhui@OptiPlex:~$ sudo ssr config
IPv6 support
2019-06-12 09:18:03 ERROR    shell.py:50 [Errno 2] No such file or directory: '/var/run/shadowsocksr.pid'
2019-06-12 09:18:03 ERROR    daemon.py:146 not running
IPv6 support
Traceback (most recent call last):
  File "local.py", line 81, in <module>
    main()
  File "local.py", line 43, in main
    config = shell.get_config(True)
  File "/usr/local/share/shadowsocksr/shadowsocks/../shadowsocks/shell.py", line 299, in get_config
    check_config(config, is_local)
  File "/usr/local/share/shadowsocksr/shadowsocks/../shadowsocks/shell.py", line 129, in check_config
    encrypt.try_cipher(config['password'], config['method'])
  File "/usr/local/share/shadowsocksr/shadowsocks/../shadowsocks/encrypt.py", line 46, in try_cipher
    Encryptor(key, method)
  File "/usr/local/share/shadowsocksr/shadowsocks/../shadowsocks/encrypt.py", line 90, in __init__
    random_string(self._method_info[1]))
  File "/usr/local/share/shadowsocksr/shadowsocks/../shadowsocks/encrypt.py", line 119, in get_cipher
    return m[2](method, key, iv, op)
  File "/usr/local/share/shadowsocksr/shadowsocks/../shadowsocks/crypto/sodium.py", line 71, in __init__
    load_libsodium()
  File "/usr/local/share/shadowsocksr/shadowsocks/../shadowsocks/crypto/sodium.py", line 42, in load_libsodium
    raise Exception('libsodium not found')
Exception: libsodium not found

```

因为没有 `libsodium`，`libsodium` 是 `chacha20` 加密算法所需要的一个包。所以接下来就安装它：

```
$ wget https://download.libsodium.org/libsodium/releases/LATEST.tar.gz
tar zxf LATEST.tar.gz
cd libsodium*
./configure
sudo make && sudo make install
```

如果编译报错

```
configure: error: no acceptable C compiler found in $PATH
```

安装C编译器

```
$ sudo apt-get install build-essential
# 安装成功之后再编译
$ sudo make && sudo make install
```

修改`/etc/ld.so.conf/`

```
include /etc/ld.so.conf.d/*.conf
/lib
/usr/lib64
/usr/local/lib
```

重新载入配置

```
sudo ldconfig
```

启动ssr

```
ssr start
```



