# command: lspci awk sed grep

今天碰到一个问题，就是通过扫描设备PCI信息来匹配ONIE系统安装的版本，需要获得Switch ASIC 的 Device Vender 与 Device id 来确定厂商芯片型号，然后进行处理这样就涉及到字符的准确搜索的问题。
我主要是通过 awk sed grep 这些来进行字符搜索的。



## lspci -m

首先我么获取本机的 pci 信息
`lspci`

```
00:00.0 Host bridge: Intel Corporation Device 591f (rev 05)
00:02.0 VGA compatible controller: Intel Corporation Device 5912 (rev 04)
00:14.0 USB controller: Intel Corporation Device a2af
00:14.2 Signal processing controller: Intel Corporation Device a2b1
00:15.0 Signal processing controller: Intel Corporation Device a2e0
00:16.0 Communication controller: Intel Corporation Device a2ba
00:17.0 SATA controller: Intel Corporation Device a282
00:1c.0 PCI bridge: Intel Corporation Device a293 (rev f0)
00:1d.0 PCI bridge: Intel Corporation Device a298 (rev f0)
00:1f.0 ISA bridge: Intel Corporation Device a2c6
00:1f.2 Memory controller: Intel Corporation Device a2a1
00:1f.3 Audio device: Intel Corporation Device a2f0
00:1f.4 SMBus: Intel Corporation Device a2a3
00:1f.6 Ethernet controller: Intel Corporation Ethernet Connection (5) I219-LM
01:00.0 PCI bridge: Texas Instruments XIO2001 PCI Express-to-PCI Bridge

```

但是上面信息是通过空格分割的我们不好处理。

`lspci -m`

```
00:00.0 "Host bridge" "Intel Corporation" "Device 591f" -r05 "Dell" "Device 07a1"
00:02.0 "VGA compatible controller" "Intel Corporation" "Device 5912" -r04 "Dell" "Device 07a1"
00:14.0 "USB controller" "Intel Corporation" "Device a2af" -p30 "Dell" "Device 07a1"
00:14.2 "Signal processing controller" "Intel Corporation" "Device a2b1" "Dell" "Device 07a1"
00:15.0 "Signal processing controller" "Intel Corporation" "Device a2e0" "Dell" "Device 07a1"
00:16.0 "Communication controller" "Intel Corporation" "Device a2ba" "Dell" "Device 07a1"
00:17.0 "SATA controller" "Intel Corporation" "Device a282" -p01 "Dell" "Device 07a1"
00:1c.0 "PCI bridge" "Intel Corporation" "Device a293" -rf0 "" ""
00:1d.0 "PCI bridge" "Intel Corporation" "Device a298" -rf0 "" ""
00:1f.0 "ISA bridge" "Intel Corporation" "Device a2c6" "Dell" "Device 07a1"
00:1f.2 "Memory controller" "Intel Corporation" "Device a2a1" "Dell" "Device 07a1"
00:1f.3 "Audio device" "Intel Corporation" "Device a2f0" "Dell" "Device 07a1"
00:1f.4 "SMBus" "Intel Corporation" "Device a2a3" "Dell" "Device 07a1"
00:1f.6 "Ethernet controller" "Intel Corporation" "Ethernet Connection (5) I219-LM" "Dell" "Ethernet Connection (5) I219-LM"
01:00.0 "PCI bridge" "Texas Instruments" "XIO2001 PCI Express-to-PCI Bridge" "" ""

```

这样我们的信息是通过双引号隔开，我们只要按照双引号间隔就可以获取相应信息。
`lspci -m > pci.txt`保存到本地pci.txt文件中`>`表是重新定向输出

## awk
`awk '{print $1 $2 $3 }' pci.txt`表示按照空格为间隔分别打印第一列第二列第三列，打印如下。

```
00:00.0"Hostbridge"
00:02.0"VGAcompatible
00:14.0"USBcontroller"
00:14.2"Signalprocessing
00:15.0"Signalprocessing
00:16.0"Communicationcontroller"
00:17.0"SATAcontroller"
00:1c.0"PCIbridge"
00:1d.0"PCIbridge"
00:1f.0"ISAbridge"
00:1f.2"Memorycontroller"
00:1f.3"Audiodevice"
00:1f.4"SMBus""Intel
00:1f.6"Ethernetcontroller"
01:00.0"PCIbridge"

```
现在我们需要按照“ " ”为间隔
`awk -F '"' '{print $1 $2 $3}' pci.txt`

```
00:00.0 Host bridge 
00:02.0 VGA compatible controller 
00:14.0 USB controller 
00:14.2 Signal processing controller 
00:15.0 Signal processing controller 
00:16.0 Communication controller 
00:17.0 SATA controller 
00:1c.0 PCI bridge 
00:1d.0 PCI bridge 
00:1f.0 ISA bridge 
00:1f.2 Memory controller 
00:1f.3 Audio device 
00:1f.4 SMBus 
00:1f.6 Ethernet controller 
01:00.0 PCI bridge 

```
但是双引号将末尾的引号也作为了分割符号，
下来我们以空格和引号作为分割符号。
`awk -F ' "' '{print $1 $2 $3}' pci.txt`

```
00:00.0Host bridge"Intel Corporation"
00:02.0VGA compatible controller"Intel Corporation"
00:14.0USB controller"Intel Corporation"
00:14.2Signal processing controller"Intel Corporation"
00:15.0Signal processing controller"Intel Corporation"
00:16.0Communication controller"Intel Corporation"
00:17.0SATA controller"Intel Corporation"
00:1c.0PCI bridge"Intel Corporation"
00:1d.0PCI bridge"Intel Corporation"
00:1f.0ISA bridge"Intel Corporation"
00:1f.2Memory controller"Intel Corporation"
00:1f.3Audio device"Intel Corporation"
00:1f.4SMBus"Intel Corporation"
00:1f.6Ethernet controller"Intel Corporation"
01:00.0PCI bridge"Texas Instruments"

```
我们看到每列的末尾多了一个引号，删除即可得到我们所需要的字符。

## sed

`awk -F ' "' '{print $1 $2 $3 }' pci.txt  | sed 's/"//g'`

```
00:00.0Host bridgeIntel Corporation
00:02.0VGA compatible controllerIntel Corporation
00:14.0USB controllerIntel Corporation
00:14.2Signal processing controllerIntel Corporation
00:15.0Signal processing controllerIntel Corporation
00:16.0Communication controllerIntel Corporation
00:17.0SATA controllerIntel Corporation
00:1c.0PCI bridgeIntel Corporation
00:1d.0PCI bridgeIntel Corporation
00:1f.0ISA bridgeIntel Corporation
00:1f.2Memory controllerIntel Corporation
00:1f.3Audio deviceIntel Corporation
00:1f.4SMBusIntel Corporation
00:1f.6Ethernet controllerIntel Corporation
01:00.0PCI bridgeTexas Instruments

```

`sed 's/需要删除的字符//g'`


## grep

`(awk -F ' "' '{print $6 }' pci.txt  | sed 's/"//g') | grep -n "07a1"`  `grep -n`表示输出行号
查看 pci.txt第6列有没有07a1这个字符

```
1:Device 07a1
2:Device 07a1
3:Device 07a1
4:Device 07a1
5:Device 07a1
6:Device 07a1
7:Device 07a1
10:Device 07a1
11:Device 07a1
12:Device 07a1
13:Device 07a1

```

## bashshell "|"

`|`是将打印输出作为下一个命令的输入

## shell 嵌套

嵌套可以使用`()`将命令行作为分割这样来确保内外层嵌套
