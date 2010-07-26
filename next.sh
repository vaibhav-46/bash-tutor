#!/bin/bash 

x=`cat file.txt`
export x
y=$(($x+1))
export y
let NUM_FILE=$((`ls [0-9]*.txt| wc -l `))
#printf "\e[8;70;180;t"
size=$(stty size | awk '{print $2}')
python create.py $x $PWD $size
if [[ "$y" -gt "$NUM_FILE" ]];then
  y=1
fi
echo $y>file.txt
