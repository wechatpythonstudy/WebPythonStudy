

# SONiC compilation record

There are many problems encountered in compiling SONiC. Now it is mainly recorded. Our platform at compile time is cavium.
The SONiC compilation process is mainly divided into steps. The first step is to compile the docker image. After the compilation is successful, 4 docker images are generated.
You can use the `docker images` query. The second step is to compile the SONiC image on the previously compiled docker image.


In the process of compiling we used the proxy tool and then used it.

## SONiC Compilation Introduction

我们编译的版本是基于cavium平台的sonic.bin文件，期间使用了代理，编译使用的代码relase版本为201803版本。
关于代理的使用，需要代理的账号的朋友可以找我借代理账号，发邮件到我的邮箱`wangzhui@asterfusion.com`
`http_proxy=http://172.17.0.1:8123 https_proxy=https://172.17.0.1:8123 make configure PLATFORM=cavium`

## record of the compilation process

编译的步骤概述:SONIC编译的过程主要分为两步骤，1、编译SONiC编译所需的docker镜像，2、编译SONiC本身以及上面所运行的docker images.

### step 1 : compile docker 编译docker镜像

国内网路的原v"我们需要设置代理，有两个工具，shadowsocks 、 privoxy。

shadowsocks /etc/shadowsocks/config
```
{
    "server":"35.200.87.95",
    "server_port":1194,
    "local_address": "127.0.0.1",
    "local_port":1080,
    "password":"soledad",
    "timeout":300,
    "method":"aes-256-cfb",
    "fast_open": false,
    "workers": 1
}
```

privoxy   /etc/privoxy/config 修改这两个配置到如下，目的是为了讲sock5t封包转发为htttp封包，并且映射到docker0 172.17.0.1这个网桥上，这样docker编译时候才能走代理。

    forward-socks5t   /               127.0.0.1:1080 .
    listen-address  172.17.0.1:8123



配置好代理后下来我们开始配置 git 代理
```
git config --global http.proxy 'http://172.17.0.1:8123'
git config --global https.proxy 'https://172.17.0.1:8123'
```
因为docker编译时候可能从git下载一些东西，所以也需要git代理，否则会编译失败

设置好镜像还要安装 `sudo apt-get install docker-engine`
讲当前用户添加进入docker 用户组，这一步很重要。
```
git clone https://github.com/Azure/sonic-buildimage.git
git checkout 201803
make init
http_proxy=http://172.17.0.1:8123 https_proxy=https://172.17.0.1:8123 make configure PLATFORM=cavium
```

docker 编译成功后会生成四个镜像
```
 wangzhui@OptiPlex  ~/zhuiwang.github.io/_posts   master ●  docker images
REPOSITORY             TAG                 IMAGE ID            CREATED             SIZE
sonic-slave-wangzhui   a694c536112         7b59ff83a185        32 hours ago        4GB
sonic-slave-wangzhui   latest              7b59ff83a185        32 hours ago        4GB
sonic-slave-base       9fc3fc961c4         cf6c9c1611ac        32 hours ago        4GB
sonic-slave-base       latest              cf6c9c1611ac        32 hours ago        4GB
```

#### setp 2 : compile sonic

需要改变两个文件
/home/wangzhui/sonic-buildimage/platform/cavium/cavm-platform-modules.mk

```
CAVM_PLATFORM_DEB = cavm_platform_modules.deb
$(CAVM_PLATFORM_DEB)_SRC_PATH = $(PLATFORM_PATH)/cavm_platform_modules
$(CAVM_PLATFORM_DEB)_DEPENDS = $(LINUX_HEADERS) $(LINUX_HEADERS_COMMON)
SONIC_MAKE_DEBS += $(CAVM_PLATFORM_DEB)'
```

/home/wangzhui/sonic-buildimage/platform/cavium/cavm-sai.mk

```
# Cavium SAI

CAVM_SAI_GITHUB = https://github.com/zhuiwang/cavium_sai/raw/master/

CAVM_LIBSAI = libsai.deb
CAVM_SAI = sai.deb
XP_TOOLS = xp-tools.deb

$(CAVM_LIBSAI)_URL = $(CAVM_SAI_GITHUB)/$(CAVM_LIBSAI)
$(CAVM_SAI)_URL = $(CAVM_SAI_GITHUB)/$(CAVM_SAI)
$(XP_TOOLS)_URL = $(CAVM_SAI_GITHUB)/$(XP_TOOLS)

SONIC_ONLINE_DEBS += $(CAVM_LIBSAI) $(CAVM_SAI) $(XP_TOOLS)

```

修改完文件之后，下来就是进行编译了，在/home/$(USER)/sonic-buildimage下执行

`http_proxy=http://172.17.0.1:8123 https_proxy=https://172.17.0.1:8123 make`


#### Problem 1:


Linux kernel version mismatch problem, can not find 0.5-amd64

Solution: Modify `cavm-platform-modules.mk` to

`/home/$(USER)/sonic-buildimage/platform/cavium`
```
CAVM_PLATFORM_DEB = cavm_platform_modules.deb
$(CAVM_PLATFORM_DEB)_SRC_PATH = $(PLATFORM_PATH)/cavm_platform_modules
$(CAVM_PLATFORM_DEB)_DEPENDS = $(LINUX_HEADERS) $(LINUX_HEADERS_COMMON)
SONIC_MAKE_DEBS += $(CAVM_PLATFORM_DEB)'
```


