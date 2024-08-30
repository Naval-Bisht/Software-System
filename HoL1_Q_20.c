//  Rollno: MT2024099 
//  Name : Naval Kihsore Singh Bisht 
//  Question No 20 of Hands On List 1 
//20. Find out the priority of your running program. Modify the priority with nice command.
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<errno.h>
#include<string.h>
#include<stdlib.h>
#include<sys/resource.h> /// this is used to get the priorotu of the process
// man getpriority
// man sched

//       int getpriority(int which, id_t who);
//       int setpriority(int which, id_t who, int prio);
// prio ranges from -19 to 20 and -19 is higest priority and 20 is lowest
// man nice


int main(){ 

    int pid = getpid();
    int p= getpriority(PRIO_PROCESS,pid);
    printf("%d",p);
    // if(p==-1){
        
    // }
    while(1){ 
        sleep(10);
    }

    // nice -n 10 ./a.out    <-- running FG // 10 is the value you want to set your new process priority
// nice -n 10 ./a.out &  <-- running BG
// changing the ni value during starting of program

// renice -n 20 -p <PID>
// changing the ni value during running 

// ps -l -p <pid>  <--to get deatila of the the pid we given  
    printf("%d\n",p);
 
 
return 0; 
} 


// ig you want to change the priotity by setpriority method /
// not wantting with nice command
// int n ;
// scanf("%d",&n);
//int r = setpriority(PRIO_PROCESS, pid, p + n);