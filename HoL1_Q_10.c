//  Rollno: MT2024099 
//  Name : Naval Kihsore Singh Bisht 
//  Question No 10 of Hands On List 1 
/*
10. Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
bytes (use lseek) and write again 10 bytes.
a. check the return value of lseek
b. open the file with od and check the empty spaces in between the data.
*/
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<errno.h>
#include<string.h>
#include<stdlib.h>

int main(){ 
    char c1[100];

    printf("enter file name \n");
    fgets(c1,100,stdin); 
    c1[strcspn(c1, "\n")] = 0;
   
     int fd = open(c1, O_RDWR |O_TRUNC| O_CREAT, 0666);
    if (fd == -1) {
        perror("open");
        return 1;
    }
    char *c2 = strdup("Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Aenean");

    if (write(fd, c2, strlen(c2) + 1) == -1) {
        perror("write error ");
        close(fd);
        return 1;
    }
    int k= lseek(fd, 11, SEEK_SET);
    if ( k == -1) {
        perror("lseek error ");
        close(fd);
        return 1;
    }
     printf("the value of lseek is %d\n",k);
     char c3[11];

    printf("enter next 10 bytes \n");
     if (fgets(c3, sizeof(c3), stdin) == NULL) {
        perror("fgets error ");
        close(fd);
        return 1;
    }

    // Ensure c3 length is exactly 10 bytes, truncate if necessary
    if (strlen(c3) > 10) {
        c3[10] = '\0'; // Null-terminate and truncate if necessary
    }

    if (write(fd, c3, 10) == -1) { // Write exactly 10 bytes
        perror("write error ");
        close(fd);
        return 1;
    }
   
    
    
    // od command 
    char x[250];
    snprintf(x,sizeof(x),"od -c %s",c1);
    printf("Data in %s \n",c1);
    if(system(x)==-1){
        perror("error in od");
        return 1;
    }

    close(fd);
   
    return 0;
 
 
}






// I removed thsi code beacuse it is showing the \0 in the middle

    //  printf("the value of lseek is %d\n",k);
    //  char c3[11];

    // printf("enter next 10 bytes \n");
    // fgets(c3,11,stdin);  
    // c3[strcspn(c3, "\n")] = 0;

    // if (write(fd, c3, sizeof(c3)) == -1) {
    //     perror("write");
    //     close(fd);
    //     return 1;
    // }
    // 