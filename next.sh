#!/bin/bash 

x=`cat file.txt`
export x
y=$(($x+1))
export y
let NUM_FILE=$((`ls [0-9]*.txt| wc -l `))
echo >out.txt
echo >out
echo >temp.txt
printf "\e[8;70;180;t"
clear
python create.py $x `echo $PWD`
python new.py `echo $PWD`
sed -e 's/<.\{,7\}>//g' <out.txt >out
if [[ "$y" -gt "$NUM_FILE" ]];then
  y=1
fi
echo $y>file.txt
echo -e  `cat out`
echo -e "\033[0m "
rm out*                       #Removes the unrequired files
rm temp.txt    
