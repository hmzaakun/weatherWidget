#!/bin/bash
# lauch.sh
gcc `pkg-config --cflags gtk+-3.0` -o weatherwidget weatherwidget.c `pkg-config --libs gtk+-3.0` -rdynamic -ljson-c -lcurl
./weatherwidget
exit
