// 2.1) Accept file name from user and read whole file
#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>

#define BLOCKSIZE 1024

int main(int argc, char *argv[])
{
    int fd = 0;
    int Ret = 0;
    char *Buffer[BLOCKSIZE];
    
    if(argc != 2)
    {
        printf("Please provide all arguments!\n");
        return -1;
    }

    fd = open(argv[1], O_RDONLY);
    
    if(fd == -1)
    {
        printf("Unable to open file!\n");
        return -1;
    }

    while((Ret = read(fd, Buffer, sizeof(Buffer))) != 0)
    {
        //writes on screen
        write(1, Buffer, Ret);
    }

    printf("\n");

    close(fd);

    return 0;
}