##############################################################################################################
# File Description: Bashtutor script that provides all the navigation commands
# Author          : Vaibhav Agarwal
# Date            : 26/07/2010
# Remarks         :
#
# Known issues    : Does not check for boundary conditions - going before the
#                   first chapter and beyond the last chapter
#
# Future Work     : Listing the index
#
##############################################################################################################

function readfile()
{
        printf "\e[8;70;180;t"
        clear
        size=$(stty size | awk '{print $2}')
        python create.py $CURRENT_CHAPTER $PWD $size
}


function next()
{
        CURRENT_CHAPTER=$(($CURRENT_CHAPTER + 1))
        export CURRENT_CHAPTER
        readfile 
}


function prev()
{
        CURRENT_CHAPTER=$(($CURRENT_CHAPTER - 1))
        export CURRENT_CHAPTER
        readfile
}


function goto()
{
        CURRENT_CHAPTER=$1
        export CURRENT_CHAPTER
        readfile 
}

function index()
{
    echo "To be done"
}
