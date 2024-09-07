//  Rollno: MT2024099 
//  Name : Naval Kihsore Singh Bisht 
//  Question No 18 of Hands On List 1 
/*
18. Write a program to perform Record locking.
a. Implement write lock
b. Implement read lock
Create three records in a file. Whenever you access a particular record, first lock it then modify/access
to avoid race condition.
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<errno.h>
#include<string.h>
#include<stdlib.h>



#define size 20  // Size of each record including newline

// Function prototypes
void rd(int fd, int ind);
void wr(int fd, int ind, const char *new_record);
void unlocking(int fd, off_t offset, int len);
void locking(int fd, off_t offset, int len, int lktyp);



// Function to read a record
void rd(int fd, int ind) {
    off_t offset = ind * size;
    locking(fd, offset, size, F_RDLCK);  // Shared lock for read

    lseek(fd, offset, SEEK_SET);
    char bfr[size];
    read(fd, bfr, size);
    printf("Read record data --> %d: %s\n", ind+ 1, bfr);

    printf("Press enter to unlock\n");
    getchar(); 
    getchar(); 


    unlocking(fd, offset, size);
}

// Function to write a record
void wr(int fd, int ind, const char *new_record) {
    off_t offset = ind * size;
    locking(fd, offset, size, F_WRLCK);  // Exclusive lock for write

    lseek(fd, offset, SEEK_SET);
    write(fd, new_record, size);

    printf("Updated record of record %d -->: %s\n", ind + 1, new_record);

    printf("Press enter to unlock\n");
    getchar(); 
    getchar(); 

    unlocking(fd, offset, size);
}

// Function to release a lock
void unlocking(int fd, off_t offset, int len) {
    struct flock lock;
    lock.l_type = F_UNLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = offset;
    lock.l_len = len;
    fcntl(fd, F_SETLK, &lock);
    printf("Unlocked \n");
}

// Function to acquire a lock
void locking(int fd, off_t offset, int len, int lktyp) {
    struct flock lock;
    lock.l_type = lktyp;
    lock.l_whence = SEEK_SET;
    lock.l_start = offset;
    lock.l_len = len;
    fcntl(fd, F_SETLKW, &lock);
        
    printf("Locked \n");
}
int main(){ 
    int fd = open("18.txt",O_RDWR|O_CREAT,0666);
    struct flock lock;
    int block,m;
    //  write(fd, "Record 1          \n",size);
    // write(fd, "Record 2          \n", size);
    // write(fd, "Record 3          \n", size);

    printf("enter block no 1,2,3\n");
    scanf("%d",&block);
    switch (block)
    {
    case 1:
    
    printf("enter mode no 1 for read and 2 for write \n");
    scanf("%d",&m);
        switch (m)
        {
        case 1:
                         rd(fd, 0);  
                 
                    break;
        case 2:
                        wr(fd, 0, "New Record 1        \n");  

            break;
        default:
            printf("wrong choice");
            break;
        }
        
        
        break;
    
    case 2:
    
    printf("enter mode no 1 for read and 2 for write \n");
    scanf("%d",&m);
        switch (m)
        {
        case 1:
                         rd(fd, 1);  
                 
                    break;
        case 2:
                        wr(fd, 1, "New Record 2        \n");  
            break;
        default:
            printf("wrong choice");
            break;
        }
        
        
        break;
    
    case 3:

    printf("enter mode no 1 for read and 2 for write \n");
    scanf("%d",&m);
        switch (m)
        {
        case 1:
                         rd(fd, 2);  
                 
                    break;
        case 2:
                        wr(fd, 2, "New Record 3        \n");  

            break;
        default:
            printf("wrong choice");
            break;
        }
        break;
    default:
    printf("wrong choice");
        break;
    }
    
   
 close(fd);
 
return 0; 
} 
