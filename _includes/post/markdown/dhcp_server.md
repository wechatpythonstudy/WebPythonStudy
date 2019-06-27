

# Dhcp server

1. use docker build dhcp server contanier

2.  or us docker pull from internet

`docker pull modularitycontainers/dhcp-server`

```
wangzhui@OptiPlex:~$ docker pull modularitycontainers/dhcp-server
Using default tag: latest
latest: Pulling from modularitycontainers/dhcp-server
ba6eab2ebb3d: Pull complete 
091db40a7d94: Pull complete 
abe7d7e1e03f: Pull complete 
6f426a8d50e7: Pull complete 
3b9b9507bbe5: Pull complete 
Digest: sha256:f178b8034a8ee310569d54f156f3271c2be3b67e626fd15316b1a16af5727d86
Status: Downloaded newer image for modularitycontainers/dhcp-server:latest
docker.io/modularitycontainers/dhcp-server:latest
```



#### DHCP DISCOVER

   When a server receives a DHCPDISCOVER message from a client, the
   server chooses a network address for the requesting client.  If no
   address is available, the server may choose to report the problem to
   the system administrator. If an address is available, the new address
   SHOULD be chosen as follows:

* The client's current add ress as recorded in the client's current binding,
     ELSE
  *客户端记录在当前绑定的地址*

* The clinet's previous address as recorded in the client's (Now expired or 
     released) binding, if that address is in the server's pool of available addresss
     and not already allocated, ELES

  *客户端之前记录客户端的地址,即便已经释放,在地址池中尚未分配*

* The address requested in the 'Requested IP Addresss ' Option, if that address
     is valid and not alreadly allocated, ELES

  *请求的IP地址,选项中请求的地址,地址有效尚未分配*

* A new address allocated from the server's pool of availible addresses;
     the address is selected based on the subnet form which the massage was
     recieved ( if 'giaddr' is 0 ) or on the address of the relay agent that forwarded 
     the message ( 'giaddr ' when not 0 ).

  *一个新的地址从服务器可用池中分配的地址,根据子网中收到消息,或地址转发消息的中继代理*

   As described in section 4.2, a server MAY, for administrative
   reasons, assign an address other than the one requested, or may
   refuse to allocate an address to a particular client even though free
   addresses are available.

   Note that, in some network architectures (e.g., internets with more
   than one IP subnet assigned to a physical network segment), it may be
   the case that the DHCP client should be assigned an address from a
   different subnet than the address recorded in 'giaddr'.  Thus, DHCP
   does not require that the client be assigned as address from the
   subnet in 'giaddr'.  A server is free to choose some other subnet,
   and it is beyond the scope of the DHCP specification to describe ways
   in which the assigned IP address might be chosen.

   While not required for correct operation of DHCP, the server SHOULD
   NOT reuse the selected network address before the client responds to
   the server's DHCPOFFER message.  The server may choose to record the
   address as offered to the client.

   The server must also choose an expiration time for the lease, as
   follows:


#### DHCP REQUEST




#### DHCP DECLINE

   If the server receives a DHCPDECLINE message, the client has
   discovered through some other means that the suggested network
   address is already in use.  The server MUST mark the network address
   as not available and SHOULD notify the local system administrator of
   a possible configuration problem.

#### DHCP RELEASE

   Upon receipt of a DHCPRELEASE message, the server marks the network
   address as not allocated.  The server SHOULD retain a record of the
   client's initialization parameters for possible reuse in response to
   subsequent requests from the client.

#### DHCP INFORM

   The server responds to a DHCPINFORM message by sending a DHCPACK
   message directly to the address given in the 'ciaddr' field of the
   DHCPINFORM message.  The server MUST NOT send a lease expiration time
   to the client and SHOULD NOT fill in 'yiaddr'.  The server includes
   other parameters in the DHCPACK message as defined in section 4.3.1.
