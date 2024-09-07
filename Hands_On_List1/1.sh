#!/bin/bash

# //  Rollno: MT2024099 
# //  Name : Naval Kihsore Singh Bisht 
# //  Question No 1 of Hands On List 1 
# /*
# 1. Create the following types of a files using (i) shell command (ii) system call
# a. soft link (symlink system call)
# b. hard link (link system call)
# c. FIFO (mkfifo Library Function or mknod system call)
# */


touch file.txt
echo "This is the original file." > file.txt

# Create a symbolic link
ln -s file.txt sft-lnk.txt
#echo "Soft link created: sft-lnk.txt -> file.txt"

# Create a hard link
ln file.txt hd-lnk.txt
#echo "Hard link created: hd-lnk.txt -> file.txt"

# Create a FIFO (named pipe)
mkfifo fifo
#echo "FIFO created: fifo"

# Verify creation
ls -l file.txt sft-lnk.txt hd-lnk.txt fifo

