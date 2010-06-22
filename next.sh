#!/bin/bash -f

x=`cat file.txt`
export x
y=$(($x+1))
export y
python create.py $x
sed -i -e 's/<\/*.*>//g' temp.txt
if [[ "$y" -gt "5" ]];then
  y=1
fi
echo $y>file.txt
echo -e  `cat temp.txt`
echo -e "\033[0m "

