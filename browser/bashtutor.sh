#!/bin/bash
screen 
#CURRENT_CHAPTER=`cat chapter.txt`
screen -X eval "stuff '../browser/start.shq'"
screen -X eval "stuff 'source ../browser/navigate.sh'"
screen -X eval "stuff 'clear'"
screen -X eval "stuff 'goto $1'"
