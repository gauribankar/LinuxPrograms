// 2.2) Accept file name from user and write string in file
#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char *argv[])
{
    int fd = 0;
    
    if(argc != 2)
    {
        printf("Please provide all arguments!\n");
        return -1;
    }

    fd = creat(argv[1], 0777);
    
    if(fd == -1)
    {
        printf("Unable to create file!\n");
        return -1;
    }

    write(fd, "Hello\n", strlen("Hello\n"));

    close(fd);

    return 0;
}