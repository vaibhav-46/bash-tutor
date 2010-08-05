##############################################################################################################
# File Description: Bashtutor Script That Starts the tutorial
#                   This script displays the first chapter. The tutor is a partially interactive application 
#                   meant to give terminal newbies a complete picture of most available shell utilities.
# Author          : Vaibhav Agarwal
# Date            : 26/07/2010
# Remarks         :
#
# Known issues    : 
#
# Future Work     :
#
##############################################################################################################

# The total number of tutorials in the chapter.
NUM_CHAPTERS=$((`ls [0-9]*.txt | wc -l`))
# This variable needs to be persistent, hence it is exported whenever changed
CURRENT_CHAPTER=1

export NUM_CHAPTERS
export CURRENT_CHAPTER

# Setting the terminal screen to display the tutorial
# This enlarges the terminal to the maximum size
printf "\e[8;70;120;t"
clear
# Make the required navigation functions available
source navigate.sh

rm -f temp.txt
rm -f out.txt
touch temp.txt
touch out.txt
# This gets the terminal width to use in the printing routine
width=$(stty size | awk '{print $2}')
python create.py 1 $PWD $(($width-10)) 
cat out.txt | less -r

