#!/bin/bash
screen -c screenrc
screen -X eval "stuff './start.shq'"
screen -X eval "stuff 'source navigate.sh'"
screen -X eval "stuff 'clear'"
screen -X eval "stuff './start.sh'"
