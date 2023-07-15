// 3.2) Accept dir and file from user and check if file is present in dir
#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<dirent.h>

int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    struct dirent * entry = NULL;
    
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

    while((entry = readdir(dp)) != NULL)
    {
        if(strcmp(entry->d_name,argv[2]) == 0)
        {
            printf("File %s is present in %s directory.\n", argv[2], argv[1]);
            closedir(dp);
            return 0;
        }
    }

    printf("File %s not found in %s directory.\n", argv[2], argv[1]);

    closedir(dp);

    return 0;
}