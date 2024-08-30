#!/bin/bash
#/*
#10. Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
#3bytes (use lseek) and write again 10 bytes.
#a. check the return value of lseek
#b. open the file with od and check the empty spaces in between the data.
#*/
od -c 10.txt | grep " "
od -t c 10.txt | grep -o "' '" | wc -l
