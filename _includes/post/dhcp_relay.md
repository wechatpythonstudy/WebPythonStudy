

# DHCP RELAY

### DHCP



![DHCP](https://www.cisco.com/c/dam/en/us/support/docs/security/adaptive-security-appliance-asa-software/116265-configure-product-00-00.png)



### DHCP RELAY

![EVNo5t.png](https://s2.ax1x.com/2019/04/24/EVNo5t.png)

[![EVNs4x.md.png](https://s2.ax1x.com/2019/04/24/EVNs4x.md.png)](https://imgchr.com/i/EVNs4x)

#### step1:Client Dhcp Discover

Clinet 产生一个dhcp discover 报文传送给ASA(switch) ==Client ----> DHCP relay Switch==

1. no src ip; broad cast 
2. Transaction ID;
3. Client IP address; Yor (client) IP address, Next server IP address, Relay agent IP address; 0.0.0.0
4. Option 53 l=1 *Dhcp discover*

![img](https://www.cisco.com/c/dam/en/us/support/docs/security/adaptive-security-appliance-asa-software/116265-configure-product-00-02.png)

----

*Note*: 

*==对于我们的设备来说 ，从ptf发送Discover 报文到 sonic deivce，==*

[![EVUaJP.png](https://s2.ax1x.com/2019/04/24/EVUaJP.png)](https://imgchr.com/i/EVUaJP)

----



#### step2:Client Dhcp Discover

get discover, 作为中继代理，DHCP DISCOVER 消息作为单播报文，转发到DHCP服务器的IP源，从而面向服务器的接口IP

Discover , ==DHCP-relay---->Next Realy or Client==

1. Src ip: ASA switch IP
2. Dst ip: ==DHCP server== 交换设备需要知道Server的IP地址在哪里
3. ==Relay Agent IP Address: 192.0.2.1== 与Clinet相链接的交换机DHCP RELAY接口，

![img](https://www.cisco.com/c/dam/en/us/support/docs/security/adaptive-security-appliance-asa-software/116265-configure-product-00-03.png)



------

*Note*:

[![EVUYdA.md.png](https://s2.ax1x.com/2019/04/24/EVUYdA.md.png)](https://imgchr.com/i/EVUYdA)

----



#### step3:Ser Dhcp offer 

==DHCP server ----> DHCP relay agent==

1. unicast packet to DHCP RELAY
2. Src ip : DHCP server ip
3. Dst ip : Relay agent ip
4. Offer ip 
5. Dhcp message type DHCP offer
6. DHCP server IP
7. Time
8. subnet mask
9. Domain name

![img](https://www.cisco.com/c/dam/en/us/support/docs/security/adaptive-security-appliance-asa-software/116265-configure-product-00-04.png)



------

*Note*:

[![EVUIL4.md.png](https://s2.ax1x.com/2019/04/24/EVUIL4.md.png)](https://imgchr.com/i/EVUIL4)

[![EVdMuD.png](https://s2.ax1x.com/2019/04/24/EVdMuD.png)

------





#### step4:Relay Agent DHCP Offer 

==DHCP Relay agent ---> DHCP Client==

1. unicast  packet
2. Src ip :  Relay agent ip
3. Dst ip :  Clinet IP Offer by DHCP server

![img](https://www.cisco.com/c/dam/en/us/support/docs/security/adaptive-security-appliance-asa-software/116265-configure-product-00-05.png)

---

*Note*:

[![EVaCTA.md.png](https://s2.ax1x.com/2019/04/24/EVaCTA.md.png)](https://imgchr.com/i/EVaCTA)



[![EVdQDe.png](https://s2.ax1x.com/2019/04/24/EVdQDe.png)](https://imgchr.com/i/EVdQDe)

---



#### step5:Clinet Dhcp Request

1. broadcast packet
2. bootp flags is 0.0.0.0
3. request



![img](https://www.cisco.com/c/dam/en/us/support/docs/security/adaptive-security-appliance-asa-software/116265-configure-product-00-06.png)



---

*Note*

[![EV0jNd.png](https://s2.ax1x.com/2019/04/24/EV0jNd.png)](https://imgchr.com/i/EV0jNd)

---



#### step6: Relay Agent Dhcp Request

![img](https://www.cisco.com/c/dam/en/us/support/docs/security/adaptive-security-appliance-asa-software/116265-configure-product-00-07.png)



------

*Note*

[![EVBpgP.png](https://s2.ax1x.com/2019/04/24/EVBpgP.png)](https://imgchr.com/i/EVBpgP)

---



#### step7: Server Dhcp Ack





![img](https://www.cisco.com/c/dam/en/us/support/docs/security/adaptive-security-appliance-asa-software/116265-configure-product-00-08.png)

------

*Note*

[![EV0v4A.png](https://s2.ax1x.com/2019/04/24/EV0v4A.png)](https://imgchr.com/i/EV0v4A)

---



#### step8: Relay Agent Dhcp Ack



![img](https://www.cisco.com/c/dam/en/us/support/docs/security/adaptive-security-appliance-asa-software/116265-configure-product-00-09.png)



------

*Note*

[![EV0z9I.png](https://s2.ax1x.com/2019/04/24/EV0z9I.png)](https://imgchr.com/i/EV0z9I)

---




