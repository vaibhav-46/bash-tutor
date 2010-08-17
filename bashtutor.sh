#!/bin/bash
screen 
screen -X eval "stuff './start.shq'"
screen -X eval "stuff 'source navigate.sh'"
screen -X eval "stuff 'clear'"
screen -X eval "stuff './start.sh'"
###for j in `seq 1 1000`;
###    do 
###     screen -X eval "stuff 'echo foo'";
###done 
