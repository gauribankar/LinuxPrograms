// 4) Accept file name and bytes from user and read those bytes
#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
    int fd = 0;
    int Ret = 0;
    char *Buffer = NULL;
    int Size = 0;
    
    if(argc != 3)
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

    //Dynamic memory
    Size = atoi(argv[2]);
    Buffer = (char *)malloc(Size);

    Ret = read(fd, Buffer, atoi(argv[2]));

    if(Ret == 0)
    {
        printf("Unable to read file!\n");
        return -1;
    }

    printf("Data from file is : %s\n", Buffer);

    return 0;
}