##############################################################################################################
# File Description: Bashtutor Script That Starts the tutorial
#                   This script displays the first chapter, a partially interactive
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
echo "2">file.txt
printf "\e[8;70;180;t"
clear
size=$(stty size | awk '{print $2}')
python create.py 1 $PWD $size

