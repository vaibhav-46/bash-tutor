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

# Make the terminal silent and add the keybindings for goto command to the
# existing screen sessions 

for i in `seq 1 $NUM_CHAPTERS`; 
    do
        screen -X eval "bindkey -t g$i stuff 'qgoto $i 
'" 2> /dev/null &> /dev/null;
done


function readfile()
{
        printf "\e[8;70;120;t"
	echo $NUM_CHAPTERS
        clear
        size=$(stty size | awk '{print $2}')
	rm -f temp.txt
        rm -f out.txt
	touch temp.txt
	touch out.txt
        python create.py $CURRENT_CHAPTER $PWD $(($size-10))
	cat out.txt | less -r
}


function next()
{
        if [[ "$CURRENT_CHAPTER" -lt "1" ]]
	then
	CURRENT_CHAPTER=1
	fi
	NUM_CHAPTERS=$(( `ls [0-9]*.txt | wc -l ` ))
	if [[ "$CURRENT_CHAPTER" -eq "$NUM_CHAPTERS" ]]
	then
	clear 
        echo "Chapters done...hope you liked the tutorial"
        else
        CURRENT_CHAPTER=$(($CURRENT_CHAPTER + 1))
	export CURRENT_CHAPTER
        readfile
        fi
}


function prev()
{
        if [[ "$CURRENT_CHAPTER" -eq "1" ]]
	then 
	clear
        echo "This is the first chapter....there is nothing before this!!"
        else
	CURRENT_CHAPTER=$(($CURRENT_CHAPTER - 1))
        export CURRENT_CHAPTER
        readfile
	fi
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
