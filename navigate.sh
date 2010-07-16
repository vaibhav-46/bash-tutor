#!/bin/bash

next()
{

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
rm out*
rm temp.txt

}

resume()
{
next
}

restart()
{
echo 1>file.txt
next
}

#index()--This will output an "echo ls command " that will show all the symbolic links in the code and then the user can go to the chapter that he wants


previous()
{
num=`cat file.txt`
if (( "$num" -lt "3" ))
then
echo "The tutorial has just started..no previous chapter"
exit 1
fi
prev=$(($num-2))
echo $prev>file.txt
next
}



