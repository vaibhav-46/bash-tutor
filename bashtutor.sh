#!/bin/bash
screen 
CURRENT_CHAPTER=`cat chapter.txt`
screen -X eval "stuff './start.sh
screen -X eval "stuff 'source navigate.sh
screen -X eval "stuff 'clear
screen -X eval "stuff 'goto $CURRENT_CHAPTER