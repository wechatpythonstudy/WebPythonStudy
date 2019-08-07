

# shell number

[chengmo@centos5 ~]$ ((num=0123));
[chengmo@centos5 ~]$ echo $num;
83

[chengmo@centos5 ~]$ ((num=8#123));
[chengmo@centos5 ~]$ echo $num;    
83

((表达式))，（（））里面可以是任意数据表达式。如果前面加入：”$”可以读取计算结果。

**十六进制转十进制：**

[chengmo@centos5 ~]$ ((num=0xff)); 
[chengmo@centos5 ~]$ echo $num;    
255
[chengmo@centos5 ~]$ ((num=16#ff));
[chengmo@centos5 ~]$ echo $num;    
255

**base-32转十进制：**

[chengmo@centos5 ~]$ ((num=32#ffff));
[chengmo@centos5 ~]$ echo $num;      
507375

**base64转十进制：**

[chengmo@centos5 ~]$ ((num=64#abc_)); 
[chengmo@centos5 ~]$ echo $num;       
2667327

**二进制转十进制**

[chengmo@centos5 ~]$ ((num=2#11111111));  
[chengmo@centos5 ~]$ echo $num;
255