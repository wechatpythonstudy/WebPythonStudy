

# For aster compile  SONiC step general Guide



### step 1. config  environment 

首先需要clone代码，clone时候具备以下条件：

- 连通公司git server (git server 必须通过vpn才能访问， 使用办公室代理，或者在自己电脑搭建WireGuard，搭建细节参考vpn搭建邮件)
- 联网网卡接口 mtu (巨帧))为 1400，默认启动为1500，不能够访问公司git.teraspek.cn
- 有公司Git账户，（此账户与公司的jira账户是一个账户)，通过ssh方式clone需要在公司git账户上添加自己主机ssh公钥。



### step 2. clone code and init code

将sonic-buildimage代码clone完后需要进行下面操作：

- 切换分支到201811`git checkout 201811`
- 下载submodule代码`make init`

SONiC 工程使用git管理，除了sonic-buildimage 之外还有很多submodule ，可以查看 工程目录下`.git\config`文件，在`sonic-buildimage`下执行`make init`会·同步所有的submodule 模块所对应的提交，如果没有某个submodule会从网上clone下载，下载到 `sonic-buildimage\src`，有部分模块在公司git，有部分模块在Github上,使用公司vpn下载会很慢大概不到100KB/s；



### step 3. compile preparation

在开始编译前需要做一些准备工作，

- docker 安装，以及添加 用户到docker组

- 在编译SONiC之前，会预先编译几个Docker镜像，作为容器，也就是提供SONiC本身的编译环境，该容器包括两个部分，slave-base，strentch-username，部分，可以通过从服务器拷贝两个tar文件，然后load到自己主机，这样就可以不预先编译该镜像。(slave-base 镜像可以编译通过，strentch-username 镜像因为依赖的问题，暂时无法编译通过，从服务器拷贝，然后修改docker tag即可)

  - http代理使用，编译过程可以使用http代理会快很多

- 开始编译，编译产生的目标会存在 `sonic-buildimage\target`目录

  - ```shell
    wangzhui@OptiPlex:~/sonic-for-push-compile/target$ ls -artl
    total 1586992
    -rw-r--r--  1 wangzhui wangzhui     30269 5月  22 11:14 docker-base.gz.log
    -rw-r--r--  1 wangzhui wangzhui  75410586 5月  22 11:14 docker-base.gz
    -rw-r--r--  1 wangzhui wangzhui        33 5月  22 11:14 docker-base.gz-load.log
    -rw-r--r--  1 wangzhui wangzhui     23661 5月  22 11:18 docker-config-engine.gz.log
    -rw-r--r--  1 wangzhui wangzhui 106976034 5月  22 11:18 docker-config-engine.gz
    -rw-r--r--  1 wangzhui wangzhui        42 5月  22 11:18 docker-config-engine.gz-load.log
    -rw-r--r--  1 wangzhui wangzhui     20169 5月  22 11:22 docker-fpm-frr.gz.log
    -rw-r--r--  1 wangzhui wangzhui 115522694 5月  22 11:22 docker-fpm-frr.gz
    -rw-r--r--  1 wangzhui wangzhui     34599 5月  22 11:27 docker-platform-monitor.gz.log
    -rw-r--r--  1 wangzhui wangzhui 118556658 5月  22 11:28 docker-platform-monitor.gz
    -rw-r--r--  1 wangzhui wangzhui      9391 5月  22 11:29 docker-router-advertiser.gz.log
    -rw-r--r--  1 wangzhui wangzhui 107352582 5月  22 11:29 docker-router-advertiser.gz
    -rw-r--r--  1 wangzhui wangzhui     13240 5月  22 11:31 docker-teamd.gz.log
    -rw-r--r--  1 wangzhui wangzhui 113031140 5月  22 11:32 docker-teamd.gz
    -rw-r--r--  1 wangzhui wangzhui     46104 5月  22 11:46 docker-snmp-sv2.gz.log
    -rw-r--r--  1 wangzhui wangzhui 119705400 5月  22 11:46 docker-snmp-sv2.gz
    -rw-r--r--  1 wangzhui wangzhui      8559 5月  22 11:48 docker-database.gz.log
    -rw-r--r--  1 wangzhui wangzhui 107768529 5月  22 11:48 docker-database.gz
    -rw-r--r--  1 wangzhui wangzhui     10452 5月  22 11:51 docker-dhcp-relay.gz.log
    -rw-r--r--  1 wangzhui wangzhui 108995558 5月  22 11:52 docker-dhcp-relay.gz
    -rw-r--r--  1 wangzhui wangzhui     24449 5月  22 11:56 docker-lldp-sv2.gz.log
    -rw-r--r--  1 wangzhui wangzhui 113427371 5月  22 11:57 docker-lldp-sv2.gz
    -rw-r--r--  1 wangzhui wangzhui     16395 5月  22 12:00 docker-syncd-cavm.gz.log
    -rw-r--r--  1 wangzhui wangzhui 171592893 5月  22 12:00 docker-syncd-cavm.gz
    -rw-r--r--  1 wangzhui wangzhui        39 5月  22 12:00 docker-syncd-cavm.gz-load.log
    -rw-r--r--  1 wangzhui wangzhui     77580 5月  22 12:06 docker-syncd-cavm-rpc.gz.log
    -rw-r--r--  1 wangzhui wangzhui 248281333 5月  22 12:06 docker-syncd-cavm-rpc.gz
    drwxr-xr-x  2 wangzhui wangzhui     12288 5月  22 12:07 debs
    drwxr-xr-x  2 wangzhui wangzhui      4096 5月  22 12:07 files
    -rw-r--r--  1 wangzhui wangzhui     21572 5月  22 12:10 docker-orchagent-cavm.gz.log
    -rw-r--r--  1 wangzhui wangzhui 117842691 5月  22 12:10 docker-orchagent-cavm.gz
    drwxr-xr-x  2 wangzhui wangzhui      4096 5月  22 12:10 python-wheels
    drwxrwxr-x 15 wangzhui wangzhui      4096 5月  22 12:10 ..
    drwxr-xr-x  5 wangzhui wangzhui      4096 5月  22 12:10 .
    -rw-r--r--  1 wangzhui wangzhui    141555 5月  22 12:26 sonic-cavium.bin.log
    最后一个文件就是正在编译的文件
    ```
    
  - 查看编译打印，通过`tail -f <filename.log>`可以实时查看log文件更新

    ```bash
    wangzhui@OptiPlex:~/sonic-for-push-compile/target$ tail -f sonic-cavium.bin.log 
    The following packages were automatically installed and are no longer required:
      distro-info-data gir1.2-glib-2.0 gir1.2-packagekitglib-1.0 iso-codes
      libdbus-glib-1-2 libgirepository-1.0-1 libglib2.0-0 libpackagekit-glib2-18
      lsb-release python3-apt python3-dbus python3-gi python3-pycurl
      python3-software-properties
    Use 'sudo apt autoremove' to remove them.
    The following additional packages will be installed:
      python-colorama
    ```

  - 编译可能出现的错误

    libesai.deb 不是deb类型包，是因为libsai.deb下载下来为空文件，

    从链接下载拷贝到`target/debs`目录





