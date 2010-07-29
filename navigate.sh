##############################################################################################################
# File Description: Bashtutor script that provides all the navigation commands
# Author          : Vaibhav Agarwal
# Date            : 26/07/2010
# Remarks         :
#
# Known issues    : 
#                   
#
# Future Work     : Listing the index
#
##############################################################################################################

function readfile()
{
        printf "\e[8;70;180;t"
        clear
        size=$(stty size | awk '{print $2}')
	rm -f temp.txt
	touch temp.txt
        python create.py $CURRENT_CHAPTER $PWD $size
}


function next()
{
        if [[ "$CURRENT_CHAPTER" -lt "1" ]]
	then
	CURRENT_CHAPTER=1
	fi
	$NUM_CHAPTERS=$(( `ls [0-9]*.txt | wc -l ` ))
	if [[ "$CURRENT_CHAPTER" -eq "$NUM_CHAPTERS" ]]
	then 
        echo "Chapters done...hope you liked the tutorial"
        exit 0
        fi
        CURRENT_CHAPTER=$(($CURRENT_CHAPTER + 1))
	export CURRENT_CHAPTER
        readfile
         
}


function prev()
{
        if [[ "$CURRENT_CHAPTER" -eq "1" ]]
	then 
        echo "This is the first chapter....there is nothing before this"
	exit 1
        fi
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
