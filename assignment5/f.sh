#!/bin/bash

#Author: Sama Ahmed
#Author email: 26samahmed@csu.fullerton.edu

#Program name: Read File


echo "Remove old un-needed files, if any."
rm *.o
rm *.out

echo "Compile the C main function search.c according to C standard 2017"
gcc -c -Wall -m64 -no-pie -o menu.o menu.c -lm -std=c2x

echo "Link object files"
gcc -m64 -no-pie -o menu.out menu.o -lm -std=c2x

echo "Run the program \"String search\""
./menu.out

echo "The bash file has terminated."
