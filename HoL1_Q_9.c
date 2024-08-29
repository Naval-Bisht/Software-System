//  Rollno: MT2024099 
//  Name : Naval Kihsore Singh Bisht 
//  Question No 9 of Hands On List 1 
/*
9. Write a program to print the following information about a given file.
a. inode
b. number of hard links
c. uid
d. gid
e. size
f. block size
g. number of blocks
h. time of last access
i. time of last modification
j. time of last change
*/
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<errno.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
// man fstat
// more about the types
// man 3 stat
// man 2 chmod

int main(int argc, char *argv[]) {
    int i=0;
    int k= 0;
    if (argc != 2) {
        printf("please enter one file at a time \n");
        while(k<argc){
                 printf("file entered  %s  \n", argv[k]);
                 k++;           
        }
       
        return 1;
    }
    struct stat st ;
    if (stat(argv[1], &st) == -1) {
        perror("stat has error");
        return 1;
    }
    printf("\n");
    printf("File name : %s\n",argv[1]);
    printf("Inode N0: %lu\n", st.st_ino);
    printf("Hard links: %lu\n", st.st_nlink);
    printf("UID: %u\n", st.st_uid);
    printf("GID: %u\n", st.st_gid);
    printf("Size: %ld bytes\n", st.st_size);
    printf("Block size: %ld\n", st.st_blksize);
    printf("Number of blocks: %ld\n", st.st_blocks);
    printf("Last access time: %s", ctime(&st.st_atime));
    printf("Last modification time: %s", ctime(&st.st_mtime));
    printf("Last change time: %s", ctime(&st.st_ctime));
    return 0;
}

// int the argc it count the no of argument that are passed 
// 1 is name of file 
// 2 is (name of file + 1 argument)

// the  aggument are stored like array you can access them like argv[00,argv[1]


//<sys/stat.h> header shall define the structure of the data returned by the functions fstat(), lstat(), and stat()
/*
he stat structure shall contain at least the following members:

dev_t     st_dev     Device ID of device containing file. 
ino_t     st_ino     File serial number. 
mode_t    st_mode    Mode of file (see below). 
nlink_t   st_nlink   Number of hard links to the file. 
uid_t     st_uid     User ID of file. 
gid_t     st_gid     Group ID of file. 
[XSI][Option Start]
dev_t     st_rdev    Device ID (if file is character or block special). 
[Option End]
off_t     st_size    For regular files, the file size in bytes. 
                     For symbolic links, the length in bytes of the 
                     pathname contained in the symbolic link. 
[SHM][Option Start]
                     For a shared memory object, the length in bytes. 
[Option End]
[TYM][Option Start]
                     For a typed memory object, the length in bytes. 
[Option End]
                     For other file types, the use of this field is 
                     unspecified. 
time_t    st_atime   Time of last access. 
time_t    st_mtime   Time of last data modification. 
time_t    st_ctime   Time of last status change. 
[XSI][Option Start]
blksize_t st_blksize A file system-specific preferred I/O block size for 
                     this object. In some file system types, this may 
                     vary from file to file. 
blkcnt_t  st_blocks  Number of blocks allocated for this object. 
[Option End]

The st_ino and st_dev fields taken together uniquely identify the file within the system. The blkcnt_t, blksize_t, dev_t, ino_t, mode_t, nlink_t, uid_t, gid_t, off_t, and time_t types shall be defined as described in <sys/types.h>. The timespec structure may be defined as described in <time.h>. Times shall be given in seconds since the Epoch.

Unless otherwise specified, the structure members st_mode, st_ino, st_dev, st_uid, st_gid, st_atime, st_ctime, and st_mtime shall have meaningful values for all file types defined in IEEE Std 1003.1-2001.

For symbolic links, the st_mode member shall contain meaningful information, which can be used with the file type macros described below, that take a mode argument. The st_size member shall contain the length, in bytes, of the pathname contained in the symbolic link. File mode bits and the contents of the remaining members of the stat structure are unspecified. The value returned in the st_size field shall be the length of the contents of the symbolic link, and shall not count a trailing null if one is present.

The following symbolic names for the values of type mode_t shall also be defined.

File type:
[XSI] [Option Start]

S_IFMT
    Type of file.

    S_IFBLK
        Block special.
    S_IFCHR
        Character special.
    S_IFIFO
        FIFO special.
    S_IFREG
        Regular.
    S_IFDIR
        Directory.
    S_IFLNK
        Symbolic link.
    S_IFSOCK
        Socket. [Option End]

File mode bits:

S_IRWXU
    Read, write, execute/search by owner.

    S_IRUSR
        Read permission, owner.
    S_IWUSR
        Write permission, owner.
    S_IXUSR
        Execute/search permission, owner.

S_IRWXG
    Read, write, execute/search by group.

    S_IRGRP
        Read permission, group.
    S_IWGRP
        Write permission, group.
    S_IXGRP
        Execute/search permission, group.

S_IRWXO
    Read, write, execute/search by others.

    S_IROTH
        Read permission, others.
    S_IWOTH
        Write permission, others.
    S_IXOTH
        Execute/search permission, others.

S_ISUID
    Set-user-ID on execution.
S_ISGID
    Set-group-ID on execution.
S_ISVTX
    [XSI] [Option Start] On directories, restricted deletion flag. [Option End]

The bits defined by S_IRUSR, S_IWUSR, S_IXUSR, S_IRGRP, S_IWGRP, S_IXGRP, S_IROTH, S_IWOTH, S_IXOTH, S_ISUID, S_ISGID, [XSI] [Option Start]  and S_ISVTX [Option End]  shall be unique.

S_IRWXU is the bitwise-inclusive OR of S_IRUSR, S_IWUSR, and S_IXUSR.

S_IRWXG is the bitwise-inclusive OR of S_IRGRP, S_IWGRP, and S_IXGRP.

S_IRWXO is the bitwise-inclusive OR of S_IROTH, S_IWOTH, and S_IXOTH.

Implementations may OR other implementation-defined bits into S_IRWXU, S_IRWXG, and S_IRWXO, but they shall not overlap any of the other bits defined in this volume of IEEE Std 1003.1-2001. The file permission bits are defined to be those corresponding to the bitwise-inclusive OR of S_IRWXU, S_IRWXG, and S_IRWXO.

The following macros shall be provided to test whether a file is of the specified type. The value m supplied to the macros is the value of st_mode from a stat structure. The macro shall evaluate to a non-zero value if the test is true; 0 if the test is false.

S_ISBLK(m)
    Test for a block special file.
S_ISCHR(m)
    Test for a character special file.
S_ISDIR(m)
    Test for a directory.
S_ISFIFO(m)
    Test for a pipe or FIFO special file.
S_ISREG(m)
    Test for a regular file.
S_ISLNK(m)
    Test for a symbolic link.
S_ISSOCK(m)
    Test for a socket.

The implementation may implement message queues, semaphores, or shared memory objects as distinct file types. The following macros shall be provided to test whether a file is of the specified type. The value of the buf argument supplied to the macros is a pointer to a stat structure. The macro shall evaluate to a non-zero value if the specified object is implemented as a distinct file type and the specified file type is contained in the stat structure referenced by buf. Otherwise, the macro shall evaluate to zero.

S_TYPEISMQ(buf)
    Test for a message queue.
S_TYPEISSEM(buf)
    Test for a semaphore.
S_TYPEISSHM(buf)
    Test for a shared memory object.

[TYM] [Option Start] The implementation may implement typed memory objects as distinct file types, and the following macro shall test whether a file is of the specified type. The value of the buf argument supplied to the macros is a pointer to a stat structure. The macro shall evaluate to a non-zero value if the specified object is implemented as a distinct file type and the specified file type is contained in the stat structure referenced by buf. Otherwise, the macro shall evaluate to zero.

S_TYPEISTMO(buf)
    Test macro for a typed memory object.

[Option End]

The following shall be declared as functions and may also be defined as macros. Function prototypes shall be provided.

int    chmod(const char *, mode_t);
int    fchmod(int, mode_t);
int    fstat(int, struct stat *);
int    lstat(const char *restrict, struct stat *restrict);
int    mkdir(const char *, mode_t);
int    mkfifo(const char *, mode_t);
[XSI][Option Start]
int    mknod(const char *, mode_t, dev_t);
[Option End]
int    stat(const char *restrict, struct stat *restrict);
mode_t umask(mode_t);



*/