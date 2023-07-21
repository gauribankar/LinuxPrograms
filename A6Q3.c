//6.3 Accept file and dir, create file in that dir
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<dirent.h>

int main(int argc, char *argv[])
{
    int fd = 0;

    if(argc != 3)
    {
        printf("Insufficient Arguments ! \n");
        return -1;
    }   

    DIR *dp = NULL;
    struct dirent * entry = NULL;
    char name[40];
    
    if(argc != 3)
    {
        printf("Please provide all arguments!\n");
        return -1;
    }

    dp = opendir(argv[1]);
    
    if(dp == NULL)
    {
        printf("Unable to open directory!\n");
        return -1;
    }

    sprintf(name,"%s/%s",argv[1], argv[2]);
    fd = creat(name,0777);

    close(fd);

    return 0;
}