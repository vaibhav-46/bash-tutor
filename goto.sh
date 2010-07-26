#############################################################################################################
# File  Description:      Bashtutor Script That Moves To A Particular Chapter
#                   This script displays the given chapter, a partially interactive
#                   application meant to give terminal newbies a complete picture of most available shell
#                   utilities.
# Author          : Vaibhav Agarwal
# Date            : 26/07/2010
# Remarks         :
#
# Known issues    : 
#
# Future Work     :
#
##############################################################################################################

#!/bin/bash

if [[ "$#" -ne 1 ]];then
echo "Usage: ./goto.sh file_number"
exit 1
fi

x=$1
y=$(($x+1))
size=$(stty size | awk '{print $2}')
clear
python create.py $x $PWD $size
echo $y>file.txt
