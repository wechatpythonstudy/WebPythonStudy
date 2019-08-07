

# Link Aggregation Group and Link Aggregation Control Protocol

Link Aggregation Group and Link Aggregation Control Protocol链路聚合\链路聚合控制协议

## Understanding IEEE 802.3ad Link Bundling

The IEEE 802.3ad link bundling feature provides a method for aggregating multiple Ethernet links into a
single logical channel based on the IEEE 802.3ad standard. This feature helps improve the cost effectiveness
of a device by increasing cumulative bandwidth without necessarily requiring hardware upgrades. In addition,
the IEEE 802.3ad link bundling feature provides a capability to dynamically provision, manage, and monitor
various aggregated links and enablesinteroperability between various Cisco devices and devices of third-party
vendors.

### Benefits of Link Bundling

The IEEE 802.3ad link bundling feature provides the following benefits:
- Increased network capacity without changing physical connections or upgrading hardware.
- Cost savings resulting from use of existing hardware and software for additional functions.
- A standard solution that enables interoperability of network devices.
- Port redundancy without user intervention when an operational port fails.

## Understanding LACP

The LACP is part of the IEEE802.3ad standard that enables you to bundle several physical ports together to
form a single logical channel. LACP enables a network device, such as a switch, to negotiate an automatic
bundling of links by sending LACP packets to the peer device. The LACP is a control protocol over LAG to
check for any LAG misconfigurations.
LACP enables you to form a single Layer 2 link automatically from two or more Ethernet links. This protocol
ensures that both ends of the Ethernet link are functional and agree to be members of the aggregation group.
LACP must be enabled at both ends of the link to be operational.
For more information on LACP, see the IEEE802.3ad standard document.

### LACP Advantages

LACP provides high reliability and redundancy. If a port fails, traffic continues on the remaining ports

### LACP Functions

LACP performs the following functions in the system:
- Maintains configuration information to control aggregation.
- Exchanges configuration information with other peer devices.
- Attaches or detaches ports from the LAG based on the exchanged configuration information.

### LACP Modes

LACP can be configured in the following modes:
- Active—In this mode, the ports send LACP packets at regular intervals to the partner ports
- Passive—In this mode, the ports do not send LACP packets until the partner port sends LACP packets.
After receiving the LACP packets from the partner port, the ports send LACP packets to the partner
port.


# 


