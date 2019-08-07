
# NAT（Network Address Translation，网络地址转换）



配置服务的设备，其中 `wlx30b49ea3f383`为无线网卡名称

```
echo 1 > /proc/sys/net/ipv4/ip_forward

iptables -F
iptables -P INPUT ACCEPT
iptables -P FORWARD ACCEPT
iptables -t nat -A POSTROUTING -o wlx30b49ea3f383 -j MASQUERADE
sudo ifconfig  enp0s31f6 10.0.0.1

```

配置客户端设备gateway,10.0.0.1为  wlx30b49ea3f383 的ip，

```
sudo ifconfig eth0 10.0.0.10
sudo route add default gw 10.0.0.1
```

