

# Dynamic Host Configuration Protocol

DHCP（Dynamic Host Configuration Protocol，动态主机配置协议）是一个局域网的网络协议，使用UDP协议工作， 主要有两个用途：给内部网络或网络服务供应商自动分配IP地址，给用户或者内部网络管理员作为对所有计算机作中央管理的手段，在RFC 2131中有详细的描述

## DHCP Relay

DHCPRelay（DHCPR）DHCP中继（也叫做DHCP中继代理）是一个小程序，其可以实现在不同子网和物理网段之间处理和转发dhcp信息的功能。
如果DHCP客户机与DHCP服务器在同一个物理网段，则客户机可以正确地获得动态分配的ip地址。如果不在同一个物理网段，则需要DHCP Relay Agent(中继代理)。

![DHCP](https://community.emc.com/servlet/JiveServlet/showImage/2-877019-109637/image002.jpg)
