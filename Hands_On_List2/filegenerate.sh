#!/bin/bash

# Loop to create 34 .c files
for i in {1..34}
do
    # Define the filename
    filename="$i.c"
    
    # Create the file and add some data
    echo "/*" > $filename
    echo "============================================================================================" >>$filename
    echo "File Name : $filename" >> $filename
    echo "Author : Naval Kishore Singh Bisht">> $filename
    echo "Roll No : MT2024099" >> $filename
    echo "Description : " >> $filename
    echo "Data : --/09/2024" >> $filename
    echo "============================================================================================" >>$filename
    echo "*/" >> $filename

    echo "#include <stdio.h> "  >> $filename
    echo "#include <stdlib.h> " >> $filename
    echo "#include <pthread.h>" >> $filename
    echo "#include <semaphore.h>" >> $filename

    echo "int main(){" >> $filename 
    echo " ">> $filename
   echo " return 0;">> $filename
    echo " }" >> $filename 

done

echo "34 C files created successfully."
