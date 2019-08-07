

# MLAG

Multichassis Link Aggregation(MLAG) is one of those features that should be so straightforward, but isn’t. MLAG allows a single device to be connected to 2 ethernet switches using a single Link Aggregation Group (LAG). The device is configured with a single LAG with ports that are connected to two switches, rather than a single switch. The two switches coordinate between each other and make it appear to the device as if they are single switch.
This part is actually straightforward, it really comes down to using a single LACP system-id across both links from both switches. The end device is blind to the fact there are different switches at the end of each link.



VLAG

SONiC LAG configure and test