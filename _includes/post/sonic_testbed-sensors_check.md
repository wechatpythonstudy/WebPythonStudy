

# SONiC Testbed ansible-playbook  testcase sensors_check.yml



ansible playbook 测试例 sensors , 使用 sensors_check.yml文件，调用library/sensors_facts.py 在docker 中运行 `sensors -U -a` 来对结果进行判断，从而来确定sensors的状态



```python
process = subprocess.Popen(['sensors', '-A', '-u'], stdout=subprocess.PIPE, stdin=subprocess.PIPE)
```

需要获取的信息样式如下

```bash
acpitz-virtual-0
CPU_0:
  temp1_input: 26.800
  temp1_crit: 100.000

coretemp-isa-0000
Core 0:
  temp1_input: 33.000
  temp1_max: 71.000
  temp1_crit: 91.000
  temp1_crit_alarm: 0.000
Core 3:
  temp4_input: 29.000
  temp4_max: 71.000
  temp4_crit: 91.000
  temp4_crit_alarm: 0.000
Core 6:
  temp8_input: 33.000
  temp8_max: 71.000
  temp8_crit: 91.000
  temp8_crit_alarm: 0.000
Core 8:
  temp10_input: 31.000
  temp10_max: 71.000
  temp10_crit: 91.000
  temp10_crit_alarm: 0.000
Core 12:
  temp14_input: 30.000
  temp14_max: 71.000
  temp14_crit: 91.000
  temp14_crit_alarm: 0.000

```



由于 sensors 是使用 lm-sensors 构建的二进制文件，没有必要直接修改该文件，所以选择写一个shell脚本来替换原来的 sensors -A -u 使得获取的信息和期待的信息样式一样。 只是用来做测试。讲该脚本放入到 pmon的docker 中去。



# Platform checklist

sfputil.py

- sfputil
  - sudo sfputil lpmode off/on EthernetQsfp
  - sudo sfputil show lpmode EthernetQsfp
  - sudo sfputil show eeprom 
  - sudo sfputil show presence 
  - sudo sfputil reset EthernetQsfp

- interface
  - show interface transceiver eeprom
  - show interface transceiver lpmod
  - show interface transceiver presence

platform

- show platform psustatus
- show platform  syseeprom

environment

- show environment all