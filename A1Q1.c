// 1) Accept file name and mode from user and open that file
#include<stdio.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
    int fd = 0;
    
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

    printf("File is opened successfully!\nFD is : %d\n", fd);

    return 0;
}