
# http-server

```bash
wangzhui@OptiPlex:~/Downloads$ http-server
Starting up http-server, serving ./
Available on:
  http://127.0.0.1:8080
  http://192.168.100.145:8080
  http://172.16.123.1:8080
  http://192.168.35.1:8080
Hit CTRL-C to stop the server
```
![](https://ws1.sinaimg.cn/large/74394f79gy1fy3qtb24vrj20zd0itwj1.jpg)

安装http-server主要分为如下步骤
* 安装node.js
* 更新npm
* 设定package.json
* 安装

## install node.js

下载lts版本的node.js
![](https://ws1.sinaimg.cn/large/74394f79gy1fy3r6dia1ej21hc0tcdjh.jpg)
解压得到如下文件
```bash
wangzhui@OptiPlex:~/Downloads/node-v10.14.2-linux-x64$ ls
bin  CHANGELOG.md  include  lib  LICENSE  README.md  share
```
/usr/目录结构
```bash
wangzhui@OptiPlex:~/Downloads/node-v10.14.2-linux-x64$ tree /usr -L 1
/usr
├── bin
├── CHANGELOG.md
├── games
├── include
├── lib
├── LICENSE
├── local
├── locale
├── README.md
├── sbin
├── share
├── software
└── src
```
拷贝到/usr/目录并覆盖
```bash
wangzhui@OptiPlex:~/Downloads/node-v10.14.2-linux-x64$sudo cp -rf ./* /usr/
```
检查是否安装成功
```bash
wangzhui@OptiPlex:~/Downloads/node-v10.14.2-linux-x64$ node -v
v10.14.2
wangzhui@OptiPlex:~/Downloads/node-v10.14.2-linux-x64$ npm -v
6.5.0
wangzhui@OptiPlex:~/Downloads/node-v10.14.2-linux-x64$ npx -v
6.5.0
```

## update npm
`sudo npm install npm -g`
注意，如果开了代理的话需要关掉代理才能更新npm，安装http-server
## make package.json
`cd /usr/bin/`
`npm init --yes`
生成package.json 到/usr/bin/目录
`cat package.json`
```json
{
  "name": "bin",
  "version": "1.0.0",
  "main": "index.js",
  "directories": {
    "man": "man",
    "test": "test"
  },
  "dependencies": {
    "http-server": "^0.11.1"
  },
  "devDependencies": {},
  "scripts": {
    "test": "echo \"Error: no test specified\" && exit 1"
  },
  "keywords": [],
  "author": "",
  "license": "ISC",
  "description": ""
}
```
## install http-server
`sudo npm install http-server -g`

## Refrence link
- [1] [ http-server: a command-line http server](https://www.npmjs.com/package/http-server)
- [2] [node js](https://nodejs.org/en/)