#!/bin/bash
screen -c screenrc
screen -X eval "stuff '../browser/start.shq'"
screen -X eval "stuff 'source ../browser/navigate.sh'"
screen -X eval "stuff 'clear'"
screen -X eval "stuff '../browser/start.sh'"
