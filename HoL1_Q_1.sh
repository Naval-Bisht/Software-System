#!/bin/bash
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

