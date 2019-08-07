#!/bin/bash

mkdir 3125
mkdir 3126

mkdir 3225
mkdir 3226
mkdir 3227
mkdir 3228
mkdir 3229

find . -size 24c |xargs rm  -f 

for file in `ls 1-*`
do
	tshark -r $file -Y "vlan.id == 3125" -w 3125/$file
	tshark -r $file -Y "vlan.id == 3125" -w 3125/$file
	
	tshark -r $file -Y "vlan.id == 3125" -w 3225/$file
	tshark -r $file -Y "vlan.id == 3125" -w 3226/$file
	tshark -r $file -Y "vlan.id == 3125" -w 3227/$file
	tshark -r $file -Y "vlan.id == 3125" -w 3228/$file
	tshark -r $file -Y "vlan.id == 3125" -w 3229/$file
done