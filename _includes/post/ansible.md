开启sonic-mgmt

docker container start testbed



docker exec -it testbed bash




sonic@Asterfusion:~$ virsh list --all

Id    Name                           State

----------------------------------------------------
 -     VM0102                         shut off
 -     VM0103                         shut off
 -     VM0104                         shut off
 -     VM0105                         shut off
 -     VM0106                         shut off
 -     VM0107                         shut off
 -     VM0112                         shut off
 -     VM0113                         shut off
 -     VM0114                         shut off
 -     VM0115                         shut off
 -     VM0116                         shut off
 -     VM0117                         shut off
 -     VM0118                         shut off
 -     VM0119                         shut off
 -     VM0120                         shut off
 -     VM0121                         shut off
 -     VM0122                         shut off
 -     VM0123                         shut off
 -     VM0124                         shut off
 -     VM0125                         shut off
 -     VM0126                         shut off
 -     VM0127                         shut off
 -     VM0128                         shut off
 -     VM0129                         shut off
 -     VM0130                         shut off



oxl@52db682e4d9d:~/sonic-mgmt/ansible$ ./testbed-cli.sh start-vms Twz-t02 password.txt
Starting VMs on topo 'Twz-t02'
reading
Found topology Twz-t02

PLAY ***************************************************************************

TASK [Check that variable topo is defined] *************************************
Thursday 11 April 2019  04:20:09 +0000 (0:00:00.128)       0:00:00.128 ******** 
skipping: [STR-ACS-SERV-01]


Twz-t12,wz-t12,t1-2,docker-ptf,10.250.0.185/24,server_1,enp130s0f1,VM0100,48S-wz,Tests aster switch
Twz-t14,wz-t14,t1-4,docker-ptf,10.250.0.185/24,server_1,enp130s0f1,VM0100,48S-wz,Tests aster switch
Twz-t02,wz-t02,t0-2,docker-ptf,10.250.0.185/24,server_1,enp130s0f1,VM0100,48S-wz,Tests aster switch
Twz-t1la,wz-t1la,t1-lag,docker-ptf,10.250.0.185/24,server_1,enp130s0f1,VM0100,48S-wz,Tests aster switch


sonic@Asterfusion:~$ virsh list  --all

 Id    Name                           State

----------------------------------------------------
 1     VM0101                         running
 -     VM0102                         shut off
 -     VM0103                         shut off
 -     VM0104                         shut off
 -     VM0105                         shut off
 -     VM0106                         shut off
 -     VM0107                         shut off
 -     VM0112                         shut off
 -     VM0113                         shut off
 -     VM0114                         shut off
 -     VM0115                         shut off
 -     VM0116                         shut off
 -     VM0117                         shut off
 -     VM0118                         shut off
 -     VM0119                         shut off
 -     VM0120                         shut off
 -     VM0121                         shut off
 -     VM0122                         shut off
 -     VM0123                         shut off
 -     VM0124                         shut off
 -     VM0125                         shut off
 -     VM0126                         shut off
 -     VM0127                         shut off
 -     VM0128                         shut off
 -     VM0129                         shut off
 -     VM0130                         shut off
 -     VM0203                         shut off



sonic@Asterfusion:~$ docker ps
CONTAINER ID        IMAGE               COMMAND             CREATED             STATUS              PORTS               NAMES
52db682e4d9d        docker-sonic-mgmt   "bash"              2 months ago        Up 5 minutes        22/tcp              testbed







ptf --test-dir ptftests dhcp_relay_test.DHCPTest   --platform-dir ptftests  --platform remote  -t \"hostname=\\\"48S-wz\\\";client_port_index=\\\"0\\\";client_iface_alias=\\\"tenGigE1\\\";leaf_port_indices=\\\"[47, 46]\\\";num_dhcp_servers=\\\"4\\\";server_ip=\\\"192.0.0.1\\\";relay_iface_ip=\\\"192.168.0.1\\\";relay_iface_mac=\\\"00:a0:c9:00:00:00\\\";relay_iface_netmask=\\\"255.255.248.0\\\"\"  --relax 2>&1

ptf --test-dir ptftests dhcp_relay_test.DHCPTest   --platform-dir ptftests  --platform remote  -t \"hostname=\\\"48S-wz\\\";client_port_index=\\\"0\\\";client_iface_alias=\\\"tenGigE1\\\";leaf_port_indices=\\\"[47, 46]\\\";num_dhcp_servers=\\\"4\\\";server_ip=\\\"192.0.0.1\\\";relay_iface_ip=\\\"192.168.0.1\\\";relay_iface_mac=\\\"00:a0:c9:00:02:25\\\";relay_iface_netmask=\\\"255.255.248.0\\\"\"  --relax 2>&1


ptf --test-dir ptftests dhcp_relay_test.DHCPTest --platform-dir ptftests  --platform remote  -t "hostname=\"48S-wz\";client_port_index=\"0\";client_iface_alias=\"tenGigE1\";leaf_port_indices=\"[47, 46]\";num_dhcp_ser[vers=\"4\";server_ip=\"192.0.0.1\";relay_iface_ip=\"192.168.0.1\";relay_iface_mac=\"00:a0:c9:00:00:00\";relay_iface_netmask=\"255.255.248.0\""  --relax 2>&1





ptf --test-dir ptftests dhcp_relay_test.DHCPTest   --platform-dir ptftests  --platform remote  -t "hostname=\"48S-wz\";client_port_index=\"0\";client_iface_alias=\"tenGigE1\";leaf_port_indices=\"[47, 46]\";num_dhcp_servers=\"4\";server_ip=\"192.0.0.1\";relay_iface_ip=\"192.168.0.1\";relay_iface_mac=\"00:a0:c9:00:02:25\";relay_iface_netmask=\"255.255.248.0\""  --relax 2>&1


#### success
ptf --test-dir ptftests dhcp_relay_test.DHCPTest   --platform-dir ptftests  --platform remote  -t "hostname=\"48S-wz\";client_port_index=\"0\";client_iface_alias=\"tenGigE1\";leaf_port_indices=\"[47, 46]\";num_dhcp_servers=\"4\";server_ip=\"192.0.0.1\";relay_iface_ip=\"192.168.0.1\";relay_iface_mac=\"00:a0:c9:00:02:25\";relay_iface_netmask=\"255.255.248.0\""  --relax 2>&1





ptf --test-dir ptftests dhcp_relay_test.DHCPTest   --platform-dir ptftests  --platform remote  -t \"hostname=\"48S-wz\";client_port_index=\"0\";client_iface_alias=\"tenGigE1\";leaf_port_indices=\"[47, 46]\";num_dhcp_servers=\"4\";server_ip=\"192.0.0.1\";relay_iface_ip=\"192.168.0.1\";relay_iface_mac=\"00:a0:c9:00:00:00\";relay_iface_netmask=\"255.255.248.0\"\"  --relax 2>&1







ptf --test-dir ptftests dhcp_relay_test.DHCPTest   --platform-dir ptftests  --platform remote  -t \"hostname=\"48S-wz\";client_port_index=\"0\";client_iface_alias=\"tenGigE1\";leaf_port_indices=\"[47, 46]\";num_dhcp_servers=\"4\";server_ip=\"192.0.0.1\";relay_iface_ip=\"192.168.0.1\";relay_iface_mac=\"00:a0:c9:00:00:00\";relay_iface_netmask=\"255.255.248.0\""  --relax 2>&1



ptf --test-dir ptftests dhcp_relay_test.DHCPTest   --platform-dir ptftests  --platform remote  -t \"hostname=\\\"48S-wz\\\";client_port_index=\\\"0\\\";client_iface_alias=\\\"tenGigE1\\\";leaf_port_indices=\\\"[47, 46]\\\";num_dhcp_servers=\\\"4\\\";server_ip=\\\"192.0.0.1\\\";relay_iface_ip=\\\"192.168.0.1\\\";relay_iface_mac=\\\"00:a0:c9:00:00:00\\\";relay_iface_netmask=\\\"255.255.248.0\\\"\"  --relax 2>&1

show ip route 192.0.0.2



#### success

ptf --test-dir ptftests dhcp_relay_test.DHCPTest   --platform-dir ptftests  --platform remote  -t "hostname=\"48S-wz\";client_port_index=\"0\";client_iface_alias=\"tenGigE1\";leaf_port_indices=\"[47, 46]\";num_dhcp_servers=\"4\";server_ip=\"192.0.0.1\";relay_iface_ip=\"192.168.0.1\";relay_iface_mac=\"00:a0:c9:00:00:00\";relay_iface_netmask=\"255.255.248.0\""  --relax 2>&1

ptf --test-dir ptftests dhcp_relay_test.DHCPTest   --platform-dir ptftests  --platform remote  -t \"hostname=\"48S-wz\";client_port_index=\"0\";client_iface_alias=\"tenGigE1\";leaf_port_indices=\\\"[47, 46]\";num_dhcp_servers=\"4\";server_ip=\"192.0.0.1\";relay_iface_ip=\"192.168.0.1\";relay_iface_mac=\"00:a0:c9:00:00:00\";relay_iface_netmask=\"255.255.248.0\""  --relax 2>&1







wangzhui@Asterfusion:~/testbed_dump$ sudo tcpdump -i enp130s0f1 -w dhcp_0411.pcap







1。起虚拟机和关虚拟机
./testbed-cli.sh start-vms server_1 password.txt
./testbed-cli.sh stop-vms server_1 password.txt


Twz-t1la,wz-t1la,t1-lag,docker-ptf,10.250.0.185/24,server_1,enp130s0f1,VM0100,48S-wz,Tests aster switch







t1-lag拓扑下：
加拓扑
./testbed-cli.sh add-topo Twz-t1la password.txt
删拓扑
./testbed-cli.sh remove-topo Twz-t1la password.txt
配置sonic交换机
./testbed-cli.sh deploy-mg Twz-t1la lab password.txt
执行测试命令
ansible-playbook -i lab -l 48S-wz test_sonic.yml -e testbed_name=Twz-t1la -e testcase_name=condif -vvv

t0-2拓扑下：
加拓扑
./testbed-cli.sh remove-topo Twz-t02 password.txt -vvv
删拓扑
./testbed-cli.sh remove-topo Twz-t02 password.txt -vvv
配置sonic交换机
./testbed-cli.sh deploy-mg Twz-t02 lab password.txt -vvv
执行测试命令

ansible-playbook -i lab -l 48S-wz test_sonic.yml -e testbed_name=Twz-t02 -e testcase_name=sensors -vvv

ansible-playbook -i lab -l 48S-wz test_sonic.yml -e testbed_name=Twz-t02 -e testcase_name=mem_check

ansible-playbook -i lab -l 48S-wz test_sonic.yml -e testbed_name=Twz-t02 -e testcase_name=restart_syncd
ansible-playbook -i lab -l 48S-wz test_sonic.yml -e testbed_name=Twz-t02 -e testcase_name=dhcp_relay -vvv
ansible-playbook -i lab -l 48S-wz test_sonic.yml -e testbed_name=Twz-t02 -e testcase_name=lldp -vvv 



t0-s拓扑下：
加拓扑
./testbed-cli.sh add-topo Twz-t0s password.txt -vvv
删拓扑
./testbed-cli.sh remove-topo Twz-t0s password.txt -vvv
配置sonic交换机
./testbed-cli.sh deploy-mg Twz-t0s lab password.txt -vvv
执行测试命令





t1-2拓扑下：
加拓扑
./testbed-cli.sh add-topo Twz-t12 password.txt
删拓扑
./testbed-cli.sh remove-topo Twz-t12 password.txt
配置sonic交换机
./testbed-cli.sh deploy-mg Twz-t12 lab password.txt
执行测试命令
ansible-playbook -i lab -l 48S-wz test_sonic.yml -e testbed_name=Twz-t12 -e testcase_name=continuous_reboot



加拓扑
./testbed-cli.sh add-topo switch2-t0-2 password.txt 
删拓扑
./testbed-cli.sh remove-topo switch2-t0-2 password.txt 
配置sonic交换机
./testbed-cli.sh deploy-mg switch2-t0-2 lab password.txt 
执行测试命令

ansible-playbook -i lab -l CX306P-48S-1 test_sonic.yml -e testbed_name=switch2-t0-2 -e testcase_name=

t1-2拓扑下
加拓扑
./testbed-cli.sh add-topo switch2-t1-2 password.txt 
删拓扑
./testbed-cli.sh remove-topo switch2-t1-2 password.txt 
配置sonic交换机
./testbed-cli.sh deploy-mg switch2-t1-2 lab password.txt 
执行测试命令
ansible-playbook -i lab -l CX306P-48S-1 test_sonic.yml -e testbed_name=switch2-t1-2 -e testcase_name=acl


t1-2
syncd fial 
reason:



sensor fail 
reason:
:TASK [test : Gather sensors] ***************************************************
Friday 08 March 2019  08:47:31 +0000 (0:00:00.067)       0:03:21.324 ********** 
fatal: [CX306P-48S-1]: FAILED! => {"failed": true, "msg": "ERROR! 'dict object' has no attribute u'CX306P-48S'"}

PLAY RECAP *********************************************************************
CX306P-48S-1               : ok=36   changed=6    unreachable=0    failed=1   


lldp fail
reason:
fatal: [CX306P-48S-1]: FAILED! => {"changed": false, "failed": true, "msg": "lldpctl command failed. is lldpd running?"}

link_flap fail
reason:
TASK [test : Shut down neighbor interface XGE1/0/9 on 10.250.0.243] ************
Friday 08 March 2019  09:18:49 +0000 (0:00:00.raw_params148)       0:00:25.610 ********** 
fatal: [CX306P-48S-1]: FAILED! => {"failed": true, "msg": "ERROR! 'dict object' has no attribute u'H3C'"}

TASK [test : Bring up neighbor interface XGE1/0/9 on 10.250.0.243] *************
Friday 08 March 2019  09:18:49 +0000 (0:00:00.117)       0:00:25.727 ********** 
fatal: [CX306P-48S-1]: FAILED! => {"failed": true, "msg": "ERROR! 'dict object' has no attribute u'H3C'"}


snmp fail


TASK [test : Check all transceivers present in Entity MIB] *********************
Friday 08 March 2019  09:20:56 +0000 (0:00:00.114)       0:01:05.347 ********** 
failed: [CX306P-48S-1] => (item={'value': {u'alias': u'tenGigE1', u'name': u'Ethernet0'}, 'key': u'Ethernet0'}) => {"failed": true, "item": {"key": "Ethernet0", "value": {"alias": "tenGigE1", "name": "Ethernet0"}}, "msg": "1000"}
failed: [CX306P-48S-1] => (item={'value': {u'alias': u'tenGigE2', u'name': u'Ethernet1'}, 'key': u'Ethernet1'}) => {"failed": true, "item": {"key": "Ethernet1", "value": {"alias": "tenGigE2", "name": "Ethernet1"}}, "msg": "2000"}

PLAY RECAP *********************************************************************
CX306P-48S-1               : ok=38   changed=7    unreachable=0    failed=1   


syslog fail
reason:
TASK [test : Check syslog messages for the test message] ***********************
Friday 08 March 2019  09:39:04 +0000 (0:00:00.297)       0:00:19.447 ********** 
fatal: [CX306P-48S-1]: FAILED! => {"changed": true, "cmd": "grep CX306P-48S-1 /var/log/syslog | grep \"Basic Test Message\" | grep -v ansible", "delta": "0:00:00.381972", "end": "2019-03-08 09:39:04.615210", "failed": true, "rc": 1, "start": "2019-03-08 09:39:04.233238", "stderr": "", "stdout": "", "stdout_lines": [], "warnings": []}

PLAY RECAP *********************************************************************
CX306P-48S-1               : ok=37   changed=13   unreachable=0    failed=1   






t0-2

config fail
reason:
TASK [test : fail] *************************************************************
Friday 08 March 2019  09:48:34 +0000 (0:00:00.092)       0:00:07.837 ********** 
fatal: [CX306P-48S-1]: FAILED! => {"changed": false, "failed": true, "msg": "testbed_type t0-2 is not supported"}



fast-reboot
reason:
TASK [test : fail] *************************************************************
Friday 08 March 2019  10:27:52 +0000 (0:00:00.200)       0:05:47.778 ********** 
fatal: [CX306P-48S-1]: FAILED! => {"changed": false, "failed": true, "msg": "Failed test 'Advanced-reboot test'"}

TASK [test : Copy test results from ptf to the local box /tmp/reboot.log] ******
Friday 08 March 2019  10:27:52 +0000 (0:00:00.208)       0:05:47.986 ********** 
changed: [CX306P-48S-1 -> 10.250.0.178]

TASK [test : Remove existing ip from ptf host] *********************************
Friday 08 March 2019  10:27:52 +0000 (0:00:00.166)       0:05:48.153 ********** 
changed: [CX306P-48S-1 -> 10.250.0.178]

TASK [test : Extract all syslog entries since the last reboot] *****************
Friday 08 March 2019  10:27:53 +0000 (0:00:00.258)       0:05:48.412 ********** 
fatal: [CX306P-48S-1]: UNREACHABLE! => {"changed": false, "msg": "ERROR! SSH Error: data could not be sent to the remote host. Make sure this host can be reached over ssh", "unreachable": true}

PLAY ***************************************************************************
skipping: no hosts matched

PLAY RECAP *********************************************************************
CX306P-48S-1               : ok=46   changed=20   unreachable=1    failed=1   