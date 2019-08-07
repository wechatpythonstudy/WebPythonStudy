

# Virtual Extensible LAN VxLAN

虚拟局域网扩展是一种网络虚拟化技术，它试图改善大云计算部署相关的可扩展性问题。它类似V-LAN封装技术封装基于MAC包括第3层的UDP数据包的OSI第2层的以太网帧，使用4789作为默认分配的IANA目的地UDP端口号。

VXLAN是努力覆盖封装协议的演变，它提高了可扩展性达到1600万个逻辑网络，并允许透过IP网络邻接第2层。使用HER（Head-End Replication）的多播或单播用来淹没BUM（Broadcast，Unknown destination address，multicast）流量。

VXLAN 规格一开始是由 VMware、Arista Networks 和 Cisco 创建的 [2][3]，其他的 VXLAN 技术拥护者包括Huawei, Broadcom、Citrix、Pica8、Cumulus Networks、Dell、Mellanox、[4] OpenBSD、[5] Red Hat[6] 和 Juniper Networks。

## VXLAN 的作用

VXLAN可以为网络提供以下作用：

- 突破 VLAN的最多 4096 个终端的数量限制，以满足大规模云计算数据中心的需求。目前因为现在虚拟化技术的发展，在数据中心里的服务器都模拟成虚拟机 (VM)，而且 VM 一般都会需要分区成组，达成二层隔离，目前大多是透过 VLAN 技术实现的。但 VLAN 技术的缺陷是 VLAN Header 预留的长度只有12 bit，最多只能支持4096个，无法满足日益增长的需求。目前 VXLAN 的报文 Header 内有 24 bit，可以支持 2的24次方的 VNI 个数。(VXLAN中透过 VNI 来识别，相当于VLAN ID)
- 解决 STP在大型网络设备带宽浪费和收敛性能变慢的缺陷。在数据中心一旦启动 STP，将导致链路带宽的浪费。此外，当拓扑增加到二百台网络设备时，收敛性能会显变慢。
- 解决 TOR 交换机 MAC表耗尽问题。二层网络出现后，不仅要记录数据中心二层设备的 MAC 地址，还得记录其他数据中心二层范围内的地址，这包括了海量的虚拟机的 MAC 地址，这增加了 TOR MAC表的需求。但目前的交换机芯片远远无法满足此一需求。

![vxlan](https://regmedia.co.uk/2011/08/30/vmware_vxlan.jpg)