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

///////////////////////////////////////////////////////////

time_t x;

it is ued to give the time in seconds after 1970s ;

///////////////////////////////////////////////////////////

Common Functions in <unistd.h>

    File and Directory Operations:
        access(): Check the accessibility of a file (e.g., read, write, execute permissions).
        chdir(): Change the current working directory of the calling process.
        close(): Close a file descriptor.
        unlink(): Remove a file.
        read(), write(): Perform low-level I/O operations on file descriptors.
        lseek(): Move the file offset for a file descriptor.
        dup(), dup2(): Duplicate file descriptors.

    Process Control:
        fork(): Create a new process by duplicating the calling process.
        exec() family of functions (execl(), execvp(), etc.): Replace the current process image with a new one, effectively executing a different program.
        _exit(): Terminate the calling process.
        getpid(), getppid(): Get the process ID and parent process ID of the calling process.
        getuid(), geteuid(): Get the real and effective user ID of the calling process.
        getgid(), getegid(): Get the real and effective group ID of the calling process.

    System Configuration:
        sysconf(): Get configuration information at runtime (e.g., the number of processors, page size, etc.).
        pathconf(): Get configuration information about a specific file or directory.

    Sleeping and Delays:
        sleep(): Suspend the calling process for a specified number of seconds.
        usleep(): Suspend the calling process for a specified number of microseconds.

    Inter-process Communication (IPC):
        pipe(): Create a pipe, a unidirectional data channel that can be used for IPC between related processes.
        ftruncate(): Truncate a file to a specified length.

    Environment Variables:
        getenv(): Retrieve the value of an environment variable.
        setenv(), unsetenv(): Set or unset environment variables.


///////////////////////////////////////////////////////////////////////////////////////////

Key Uses of <fcntl.h>

    File Control Operations:
        File Descriptor Flags: Modify the behavior of open file descriptors using fcntl() to set or get flags.
        File Locks: Control file access by setting advisory locks (shared or exclusive) using fcntl().

    File Opening Modes:
        <fcntl.h> defines flags used with the open() and fcntl() functions to control how files are opened or managed. These flags include read/write access modes, creation options, and various options for managing file behavior.

Common Functions and Macros in <fcntl.h>

    File Descriptor Flags and Control with fcntl():
        fcntl() is the central function provided by <fcntl.h> and is used to perform operations on file descriptors. It can modify file descriptor flags, set locks, duplicate file descriptors, and more.

    c

int fcntl(int fd, int cmd, ...);

    Common Commands for fcntl():
        F_GETFL: Get file status flags for a file descriptor.
        F_SETFL: Set file status flags for a file descriptor (e.g., make it non-blocking).
        F_GETFD: Get file descriptor flags (e.g., close-on-exec flag).
        F_SETFD: Set file descriptor flags.
        F_GETLK, F_SETLK, F_SETLKW: Get or set file locks.

File Opening Flags for open():

    <fcntl.h> defines various flags that control how files are opened. These flags are used with the open() system call.
    Common File Opening Flags:
        O_RDONLY: Open the file for reading only.
        O_WRONLY: Open the file for writing only.
        O_RDWR: Open the file for both reading and writing.
        O_CREAT: Create the file if it does not exist.
        O_TRUNC: Truncate the file to zero length if it already exists.
        O_APPEND: Open the file in append mode (writes go to the end).
        O_NONBLOCK: Open the file in non-blocking mode.
        O_EXCL: When combined with O_CREAT, ensures that the file is created, and the call will fail if the file already exists.

File Locking:

    Advisory Locking: You can use fcntl() with F_SETLK or F_SETLKW to establish advisory locks on files. Advisory locks are not enforced by the kernel but are respected by cooperating processes.

    Lock Types:
        F_RDLCK: Shared or read lock.
        F_WRLCK: Exclusive or write lock.
        F_UNLCK: Unlock.

    Locks are specified by a struct flock structure that defines the type, start, and length of the lock.

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    Purpose of <sys/types.h>

The primary role of <sys/types.h> is to define system-specific data types that abstract the underlying system architecture. This allows developers to write portable code that can work on various Unix-like systems.
Common Data Types Defined in <sys/types.h>

    Process and User IDs:
        pid_t: Represents process IDs (used for process control operations).
        uid_t: Represents user IDs (used for user identification).
        gid_t: Represents group IDs (used for group identification).

    File Types and Sizes:
        off_t: Represents file sizes and offsets within a file (used for file operations like lseek()).
        ssize_t: Represents signed sizes of objects (used for functions that return a size or indicate an error with a negative value, e.g., read(), write()).
        size_t: Represents the size of an object (used for memory-related operations, e.g., malloc()).

    Device Types:
        dev_t: Represents device IDs (used for identifying devices, e.g., in file operations).
        mode_t: Represents file mode (permissions) and types (used in functions like chmod()).

    File System Types:
        ino_t: Represents inode numbers (used for file identification in the file system).
        nlink_t: Represents link counts (number of hard links to a file).
        blksize_t: Represents block sizes (used in file system operations).
        blkcnt_t: Represents block counts (used in file system operations).

    System-Specific Types:
        clock_t: Represents CPU time (used for measuring processor time).
        time_t: Represents time in seconds since the Epoch (used for time-related operations).
        key_t: Represents IPC keys (used for inter-process communication resources).



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Key Uses of <sys/stat.h>

    File Information:
        Functions like stat(), fstat(), and lstat() retrieve information about files, including their type, permissions, size, ownership, and timestamps.
    File Permissions and Modes:
        It defines constants used for setting and checking file permissions, such as read, write, a

        nd execute bits for the owner, group, and others.
    File Creation:
        mkdir() and mknod() are functions used to create directories and special files (e.g., device files).

Common Functions and Macros in <sys/stat.h>

    File Information Retrieval Functions:
        stat(): Gets the status of a file, returning information in a struct stat.
        fstat(): Like stat(), but works on a file descriptor.
        lstat(): Like stat(), but does not follow symbolic links (returns information about the link itself).

    These functions fill in a struct stat structure with information about the file, including:
        st_mode: The file type and permissions.
        st_size: The size of the file in bytes.
        st_uid: The user ID of the file's owner.
        st_gid: The group ID of the file's group.
        st_atime, st_mtime, st_ctime: The last access, modification, and status change times, respectively.

    File Permissions Macros:

    Permission Bits:
        S_IRUSR, S_IWUSR, S_IXUSR: Read, write, and execute permissions for the owner.
        S_IRGRP, S_IWGRP, S_IXGRP: Read, write, and execute permissions for the group.
        S_IROTH, S_IWOTH, S_IXOTH: Read, write, and execute permissions for others.
    File Type Macros:
        S_IFREG: Regular file.
        S_IFDIR: Directory.
        S_IFLNK: Symbolic link.
        S_IFCHR: Character device.
        S_IFBLK: Block device.
        S_IFIFO: FIFO (named pipe).
        S_IFSOCK: Socket.
    Macros to Check File Type: These macros are used with the st_mode field of struct stat to check the type of a file.
        S_ISREG(m): Checks if a file is a regular file.
        S_ISDIR(m): Checks if a file is a directory.
        S_ISLNK(m): Checks if a file is a symbolic link.
        S_ISCHR(m): Checks if a file is a character device.
        S_ISBLK(m): Checks if a file is a block device.
        S_ISFIFO(m): Checks if a file is a FIFO.
        S_ISSOCK(m): Checks if a file is a socket.


        ///////////////////////////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////////////////
        . errno is a global variable that stores error codes that can be checked after a function returns an error.
Key Concepts of <errno.h>

    errno Variable:
        errno is set by system calls and library functions when an error occurs. By checking its value, a program can determine what kind of error happened.
        It is automatically reset by the system, so you should check it immediately after a function call that is known to set errno on failure.

    Error Codes:
        <errno.h> defines symbolic constants for various error codes, such as EACCES, ENOENT, ENOMEM, etc. These constants represent common errors encountered in system calls and library functions.
        Each error code corresponds to a specific condition, like "No such file or directory" (ENOENT) or "Permission denied" (EACCES).

Common Error Codes Defined in <errno.h>

    EACCES: Permission denied.
    ENOENT: No such file or directory.
    ENOMEM: Not enough memory.
    EIO: Input/output error.
    EBADF: Bad file descriptor.
    EEXIST: File exists.
    EINVAL: Invalid argument.
    EPERM: Operation not permitted.
    EINTR: Interrupted function call.
    EAGAIN: Resource temporarily unavailable (non-blocking I/O).

Error Handling Using errno

    Checking errno:
        After a function call that might fail, you can check the value of errno to determine what went wrong.
        The standard library function perror() or strerror() can be used to print a human-readable error message based on the value of errno.

    c

#include <stdio.h>
#include <errno.h>
#include <string.h>

int main() {
    FILE *fp = fopen("non_existent_file.txt", "r");
    if (fp == NULL) {
        printf("Error opening file: %s\n", strerror(errno));
    }
    return 0;
}

In this example, fopen() tries to open a file that doesn't exist. Since the file cannot be opened, errno is set to ENOENT, and strerror(errno) returns the corresponding error message, "No such file or directory".

Using perror() for Error Reporting:

    perror() prints a message to stderr that includes the user-supplied string (usually a description of the operation that failed) followed by the corresponding error message for errno.

c

#include <stdio.h>
#include <errno.h>

int main() {
    FILE *fp = fopen("non_existent_file.txt", "r");
    if (fp == NULL) {
        perror("File opening failed");
    }
    return 0;
}

Here, perror("File opening failed") will print a message like File opening failed: No such file or directory to the standard error output.

Resetting errno:

    errno is not reset by system calls or library functions that succeed. Therefore, you should manually reset errno to 0 if you want to check for errors explicitly after a sequence of operations.
    Example:

    c

        errno = 0;  // Reset errno
        if (some_function() == -1 && errno != 0) {
            // Handle error
        }

When to Use <errno.h>

    System Calls and Library Functions: Many functions in the standard C library and POSIX APIs return -1 or NULL on failure and set errno to indicate the type of error. You should use <errno.h> to check and handle these errors correctly.

    Debugging: Access to errno helps you diagnose why a particular system call or library function failed, allowing you to print informative error messages or take corrective actions.

Example: File Open Error Handling

c

#include <stdio.h>
#include <errno.h>
#include <string.h>

int main() {
    FILE *file = fopen("test.txt", "r");
    if (file == NULL) {
        // If fopen fails, errno will be set
        if (errno == ENOENT) {
            printf("File not found.\n");
        } else if (errno == EACCES) {
            printf("Permission denied.\n");
        } else {
            printf("An error occurred: %s\n", strerror(errno));
        }
    } else {
        // If the file is successfully opened, close it
        fclose(file);
    }

    return 0;
}

In this example, errno is used to check why fopen() failed and print an appropriate message based on the specific error condition.
Why Use <errno.h>?

    Error Diagnosis: It provides a standardized way to diagnose errors in system calls and standard library functions.
    Portable Error Handling: Error codes in <errno.h> are standardized across POSIX-compliant systems, making your error handling code portable.
    Human-Readable Error Messages: Functions like perror() and strerror() convert error codes into human-readable messages, which are useful for debugging and logging.

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


Key Features of <stdlib.h>

    Memory Allocation and Deallocation:
        Functions like malloc(), calloc(), realloc(), and free() are provided for dynamic memory management.

    Process Control:
        Functions like exit(), atexit(), and abort() control the termination of a program.

    Conversions:
        Functions like atoi(), atof(), atol(), strtol(), strtod(), and strtoul() convert strings to numerical values.

    Random Number Generation:
        rand() and srand() functions are provided for generating pseudo-random numbers.

    Sorting and Searching:
        Functions like qsort() and bsearch() are provided for general-purpose sorting and searching operations.

    Environment Access:
        Functions like getenv() and system() are used to access environment variables and execute system commands.

Common Functions in <stdlib.h>

    Memory Management:
        void *malloc(size_t size): Allocates a block of memory of size bytes and returns a pointer to it. The memory is uninitialized.
        void *calloc(size_t num, size_t size): Allocates memory for an array of num elements of size bytes each and initializes all bytes to zero.
        void *realloc(void *ptr, size_t size): Changes the size of the memory block pointed to by ptr to size bytes.
        void free(void *ptr): Deallocates the memory previously allocated by malloc(), calloc(), or realloc().

    c

#include <stdlib.h>
#include <stdio.h>

int main() {
    int *array = malloc(10 * sizeof(int));  // Allocate memory for an array of 10 integers
    if (array == NULL) {
        perror("Memory allocation failed");
        return 1;
    }

    // Use the allocated memory
    for (int i = 0; i < 10; i++) {
        array[i] = i;
        printf("%d ", array[i]);
    }

    free(array);  // Free the allocated memory
    return 0;
}

Conversions:

    int atoi(const char *str): Converts a string to an integer.
    double atof(const char *str): Converts a string to a double.
    long int strtol(const char *str, char **endptr, int base): Converts a string to a long integer.
    double strtod(const char *str, char **endptr): Converts a string to a double.

c

#include <stdlib.h>
#include <stdio.h>

int main() {
    const char *str = "123";
    int num = atoi(str);  // Convert string to integer
    printf("The number is: %d\n", num);

    return 0;
}

Random Number Generation:

    int rand(void): Returns a pseudo-random number between 0 and RAND_MAX.
    void srand(unsigned int seed): Seeds the random number generator with the given seed value.

c

#include <stdlib.h>
#include <stdio.h>

int main() {
    srand(42);  // Seed the random number generator

    for (int i = 0; i < 5; i++) {
        printf("Random number: %d\n", rand());
    }

    return 0;
}

Process Control:

    void exit(int status): Terminates the program and returns the given status to the operating system.
    void abort(void): Aborts the program and produces a core dump (if enabled).
    int system(const char *command): Executes a shell command.

c

#include <stdlib.h>
#include <stdio.h>

int main() {
    system("echo Hello, world!");  // Execute a system command
    return 0;
}

Sorting and Searching:

    void qsort(void *base, size_t num, size_t size, int (*compare)(const void *, const void *)): Sorts an array using the quicksort algorithm.
    void *bsearch(const void *key, const void *base, size_t num, size_t size, int (*compare)(const void *, const void *)): Searches a sorted array for a key using binary search.

c

    #include <stdlib.h>
    #include <stdio.h>

    int compare(const void *a, const void *b) {
        return (*(int *)a - *(int *)b);
    }

    int main() {
        int array[] = {5, 2, 9, 1, 6};
        size_t n = sizeof(array) / sizeof(array[0]);

        qsort(array, n, sizeof(int), compare);

        for (int i = 0; i < n; i++) {
            printf("%d ", array[i]);
        }

        return 0;
    }

Why Use <stdlib.h>?

    Memory Management: Essential for dynamically allocating, resizing, and freeing memory in your programs.
    Conversions: Provides convenient functions for converting between strings and various numeric types.
    Process Control: Offers functions for terminating a program, executing system commands, and registering cleanup functions.
    Random Numbers: Allows the generation of pseudo-random numbers, which are useful in simulations, games, and testing.
    Sorting and Searching: Provides built-in implementations of sorting and searching algorithms, making it easier to manipulate arrays.
    Portability: The functions in <stdlib.h> are part of the C standard library, making your code portable across different platforms.

In summary, <stdlib.h> is a fundamental header in C programming, providing essential functions for memory management, conversions, process control, random number generation, and more. It is widely used in various types of applications due to the broad range of functionality it offers.

//////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


The <time.h> header file in C provides functions and definitions for manipulating and formatting time and date. It is essential for performing time-related operations, such as measuring elapsed time, obtaining the current time, and formatting time and date for output.
Key Features of <time.h>

    Time Measurement:
        Functions to measure and track time intervals, such as clock(), time(), and difftime().

    Time Representation:
        Structures like struct tm for representing broken-down time components (e.g., year, month, day).

    Time Formatting:
        Functions to format and parse date and time strings, such as strftime() and strptime().

    Clock Management:
        Functions to manage and measure time with finer granularity, such as clock_gettime() for high-resolution timing.

Common Functions and Types in <time.h>

    Getting and Setting Time:
        time_t time(time_t *t): Returns the current calendar time as a time_t value. If t is not NULL, the value is also stored in *t.
        void *localtime(const time_t *timep): Converts a time_t value to a struct tm representing local time.
        void *gmtime(const time_t *timep): Converts a time_t value to a struct tm representing Coordinated Universal Time (UTC).
        time_t mktime(struct tm *tm): Converts a struct tm representing local time to a time_t value.
        char *asctime(const struct tm *tm): Converts a struct tm to a string representing the local time.
        char *ctime(const time_t *timep): Converts a time_t value to a string representing the local time.

    c

#include <time.h>
#include <stdio.h>

int main() {
    time_t now;
    struct tm *timeinfo;
    char buffer[80];

    time(&now);  // Get the current time
    timeinfo = localtime(&now);  // Convert to local time

    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeinfo);  // Format time
    printf("Current local time: %s\n", buffer);

    return 0;
}

Time Differences:

    double difftime(time_t time1, time_t time0): Computes the difference in seconds between two time_t values.

c

#include <time.h>
#include <stdio.h>

int main() {
    time_t start, end;
    double difference;

    time(&start);  // Get the current time as start time

    // Simulate some processing
    sleep(2);

    time(&end);  // Get the current time as end time

    difference = difftime(end, start);  // Calculate the difference in seconds
    printf("Time taken: %.2f seconds\n", difference);

    return 0;
}

High-Resolution Timing:

    clock_t clock(void): Returns the processor time consumed by the program. The value can be used to measure CPU time consumed by the program.
    double clock() / CLOCKS_PER_SEC: Converts clock() result into seconds.

c

#include <time.h>
#include <stdio.h>

int main() {
    clock_t start, end;
    double cpu_time_used;

    start = clock();  // Start timing

    // Simulate some processing
    for (volatile int i = 0; i < 1000000; i++);

    end = clock();  // End timing
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;  // Convert to seconds

    printf("CPU time used: %f seconds\n", cpu_time_used);

    return 0;
}

Time Formatting and Parsing:

    char *strftime(char *s, size_t max, const char *format, const struct tm *tm): Formats time according to a specified format string.
    int strptime(const char *s, const char *format, struct tm *tm): Parses a time string into a struct tm (not part of the C standard but available in POSIX and some implementations).

c

    #include <time.h>
    #include <stdio.h>

    int main() {
        struct tm tm;
        char buffer[80];

        // Example of parsing date
        strptime("2024-08-20", "%Y-%m-%d", &tm);
        strftime(buffer, sizeof(buffer), "%A, %d %B %Y", &tm);
        printf("Parsed date: %s\n", buffer);

        return 0;
    }

Common Data Structures

    struct tm:
        This structure represents broken-down time. It includes members for year, month, day, hour, minute, second, and other time-related fields.
        Members include:
            int tm_year: Year since 1900.
            int tm_mon: Month of the year (0-11).
            int tm_mday: Day of the month (1-31).
            int tm_hour: Hours since midnight (0-23).
            int tm_min: Minutes after the hour (0-59).
            int tm_sec: Seconds after the minute (0-59).
            int tm_wday: Day of the week (0-6, Sunday = 0).
            int tm_yday: Day of the year (0-365).
            int tm_isdst: Daylight saving time flag.

Why Use <time.h>?

    Time Manipulation: Provides tools to manipulate and format time and date, which is crucial for time-based applications, logging, and scheduling.
    Performance Measurement: Allows for measuring elapsed time and CPU time, which is useful for performance analysis and benchmarking.
    Portability: The functions and types in <time.h> are part of the C standard library, ensuring that your code works across different platforms.

In summary, <time.h> is an essential header for handling time and date operations in C programs. It provides a range of functions for obtaining the current time, measuring elapsed time, formatting and parsing dates, and more. Whether you're dealing with performance timing, scheduling tasks, or formatting dates, <time.h> offers the functionality you need.



