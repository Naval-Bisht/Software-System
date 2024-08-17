//  just used as my notes for this handon list 

use this link to refresh the concpt
https://www.geeksforgeeks.org/basics-file-handling-c/?ref=lbp

// how to use read and write system calls
https://www.geeksforgeeks.org/input-output-system-calls-c-create-open-close-read-write/?ref=lbp



///////////////////////////////////////////////////////why not using gets in program 3 ///////////////////////////////////////////////////////////////////
as after c 13 the concept of gets is no more valid so use fgets to take string input . using it to help to get used to it 
using it but it is very large synatx was very bad.

we did not use scanf becouse it does not record the name after space 
eg
name --> naval kishore singh bisht
it will only take naval

thats why we use fgets
fgetc is used for single character






//////////////////////////////////////////       finding error            /////////////////////////////////////////////////////////////////////////////

// to trap error ////////////////////////////////////
#!/bin/bash

trap 'echo "Error occurred"; exit 1' ERR

cp source_file.txt destination_file.txt
echo "File copied successfully"
////

////////////////////////////////////////////////////

to set error when ever the code experice error it will stop
#!/bin/bash
set -e

cp source_file.txt destination_file.txt
echo "File copied successfully"
///

////////////////////////////////////////////////////////////
// using $?   // this will check the last run file if 
        // it is succesfully executed it will return 0 else sone other no 
        /// or random no
#!/bin/bash

cp source_file.txt destination_file.txt
if [ $? -ne 0 ]; then
    echo "Error: Failed to copy file"
    exit 1
fi

echo "File copied successfully"

// in c///////////////////////////////////////////////////////////////////

Many C functions return special values (such as -1 or NULL) to indicate errors. The errno variable is set by system calls and some library functions in the event of an error to indicate what went wrong.

 int fd = open("nonexistent_file.txt", O_RDONLY);
    if (fd == -1) {
        // Error handling
        perror("Error opening file");
        
    }

    // Do something with the file
    close(fd);

//////////////////////////////////////////////////////////////                              ///////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
ssize_t in = read(0, ch, 100);     here ssize_t is used to coutn the no of bytes used 
it range form [-1 to size ]

if -1 means sothing is wrong or we say error occur

