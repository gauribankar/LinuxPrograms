// 3) Accept file name and mode from user and check if file can be accessed with that mode
#include<stdio.h>
#include<fcntl.h>
#include<string.h>

int main(int argc, char *argv[])
{
    int Mode = 0;
    int fd = 0;
    
    if(argc != 3)
    {
        printf("Please provide all arguments!\n");
        return -1;
    }

    if(strcmp(argv[2], "Read") == 0)
    {
        Mode = O_RDONLY;
    }
    else if(strcmp(argv[2], "Write") == 0)
    {
        Mode = O_WRONLY;
    }
    else
    {
        Mode = O_RDONLY;
    }

    fd = access(argv[1], Mode);

    if(fd == -1)
    {
        printf("File cannot be accessed!\n");
        return -1;
    }

    printf("File is accessable!\n");

    return 0;
}