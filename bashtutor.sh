#!/bin/bash
screen 
CHAPTER_LAST=$(cat 'chapter.txt');
screen -X eval "stuff './start.sh
screen -X eval "stuff 'source navigate.sh
screen -X eval "stuff 'clear
screen -X eval "stuff 'goto $CHAPTER_LAST