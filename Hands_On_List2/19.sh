#!/bin/bash


# /*
# ============================================================================================
# File Name : 19.sh
# Author : Naval Kishore Singh Bisht
# Roll No : MT2024099
# Description : 19. Create a FIFO file by
#                     a. mknod command
#                     b. mkfifo command
#                     c. use strace command to find out, which command (mknod or mkfifo) is better.
#                     d. mknod system call
#                     e. mkfifo library function
# Data : 18/09/2024
# ============================================================================================
# */

mknod fifo_file p
