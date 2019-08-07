

# Link Layer Discovery Protocol

Link Layer Discovery Protocol 链路发现层协议，是一种数据链路层协议，网络设备可以通过在本地网络中发送LLPDU Link Layer Protocol Discovery Data Unit 来通告其他设备自身的状态。
是一种能够使网络中的设备相互发现并通告状态、交互信息的协议。

## 概述

LLDP属于链路发现层协议，它的以太类型未0X88cc。标准的LLDP帧格式如下:


### 目的MAC地址

LLDP协议的目的MAC地址总是几个固定值之一：
- Nearest Bridge 01-80-C2-00-00-0E 包被限制在本地网络中，无法被任何网桥或者路由设备转发。
- Nearest non-TPMR Bridge 01-80-C2-00-00-03 包只被Two-Port MAC Relay（TPMR）转发，其他任何桥或者路由设备都不转发该数据包。
- Nearest Customer Bridge 01-80-C2-00-00-00 只在两个Customer Bridge 之间传播。

### 数据格式 TLV

TLV 是type length value 的缩写，LLDP中的主要数据格式。该数据类型的格式为：
- TLV类型 7bit
- TLV数据部分长度 9bit
- TLV数据部分 0-511字节
