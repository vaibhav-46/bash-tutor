#!/bin/bash -f

x=`cat file.txt`
export x
y=$(($x+1))
export y
echo >out.txt
clear
python create.py $x
python new.py
sed  -e 's/<.*>//g' <out.txt >out 
if [[ "$y" -gt "5" ]];then
  y=1
fi
echo $y>file.txt
echo -e  `cat out`
echo -e "\033[0m "

