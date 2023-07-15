// 4) Accept file name from user and print all info of file
#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
    struct stat sobj;
    
    if(argc != 2)
    {
        printf("Please provide all arguments!\n");
        return -1;
    }

    stat(argv[1], &sobj);

    printf("File name : %s\n", argv[1]);
    printf("Size of file is : %d\n", sobj.st_size);
    printf("Number of links : %d\n", sobj.st_nlink);
    printf("Inode number : %d\n", sobj.st_ino);
    printf("Block number : %d\n", sobj.st_blocks);
    printf("Block size : %d\n", sobj.st_blksize);
    printf("File system number : %d\n", sobj.st_dev);

    return 0;
}