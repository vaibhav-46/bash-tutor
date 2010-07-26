##############################################################################################################
# File Description: Bashtutor Script That Runs Through The Script
#                   This script is what runs through the bash tutor, a partially interactive
#                   application meant to give terminal newbies a complete picture of most available shell
#                   utilities.
# Author          : Vaibhav Agarwal
# Date            : 26/07/2010
# Remarks         :
#
# Known issues    :As of now there are no issues found with this 
#
# Future Work     :Maybe make the file saving process more error free
#
##############################################################################################################
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
