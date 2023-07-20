// 4.3) Accept two files and check if content is same
#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
    int fd1 = 0, fd2 = 0, ret = 0;
    struct stat sobj1, sobj2;
    char Buffer1[1024], Buffer2[1024];

    if(argc != 3)
    {
        printf("Insufficient arguments.\n");
        return -1;
    }

    fd1 = open(argv[1], O_RDONLY);
    fd2 = open(argv[2], O_RDONLY);

    if(fd1 == -1 || fd2 == -1)
    {
        printf("Unable to open file.\n");
        return -1;
    }

    stat(argv[1], &sobj1);
    stat(argv[2], &sobj2);

    if(sobj1.st_size != sobj2.st_size)
    {
        printf("Files are different.\n");
        return -1;  
    }

    while(ret = read(fd1, Buffer1, sizeof(Buffer1)) != 0)
    {
        ret = read(fd2, Buffer2, sizeof(Buffer2));
        if(memcmp(Buffer1, Buffer2, ret) != 0)
        {
            break;
        }
    }

    if(ret == 0)
    {
        printf("Both files are identical.\n");
    }
    else 
    {
        printf("Both files are separate\n");
    }

    close(fd1);
    close(fd2);
    
    return 0;
}