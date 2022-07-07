#!/bin/bash
# installer.sh
sudo apt-get install gcc -y
sudo apt install libjson-c-dev -y
sudo apt-get install libcurl4-openssl-dev -y
sudo apt-get install libgtk-3-dev -y
cd ..
gcc `pkg-config --cflags gtk+-3.0` -o weatherwidget weatherwidget.c `pkg-config --libs gtk+-3.0` -rdynamic -ljson-c -lcurl
./weatherwidget
exit
