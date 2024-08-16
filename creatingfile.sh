#!/bin/bash

for i in {1..30}
do 
   touch "HoL1_Q_$i.c"
   echo "//  Rollno: MT2024099 " >>HoL1_Q_$i.c
   echo "//  Name : Naval Kihsore Singh Bisht "  >>HoL1_Q_$i.c
   echo "//  Question No $i of Hands On List 1 "  >>HoL1_Q_$i.c
   echo "#include<stdio.h>"  >>HoL1_Q_$i.c
   echo "#include<fcntl.h>"  >>HoL1_Q_$i.c
   echo "#include<unistd.h>"  >>HoL1_Q_$i.c
   echo "#include<sys/types.h>"  >>HoL1_Q_$i.c
   echo "#include<sys/stat.h>"  >>HoL1_Q_$i.c
   echo "#include<errno.h>"  >>HoL1_Q_$i.c
   echo "#include<string.h>"  >>HoL1_Q_$i.c
   echo "#include<stdlib.h>"  >>HoL1_Q_$i.c
   echo "int main(){ "  >>HoL1_Q_$i.c
   echo " "  >>HoL1_Q_$i.c
   echo " "  >>HoL1_Q_$i.c
   echo "return 0; "  >>HoL1_Q_$i.c
   echo "} "  >>HoL1_Q_$i.c
   

done

#to create a file of hands onlinst 1