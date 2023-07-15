// 2.4) Accept directory name from user and print files and its type
#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<dirent.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    struct dirent * entry = NULL;
    
    if(argc != 2)
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

    printf("List of Files from %s : ", argv[1]);

    while((entry = readdir(dp)) != NULL)
    {
        if(entry->d_type == 4)
        {
            printf("Directory : %s\n", entry->d_name);
        }
        else if(entry->d_type == 8)
        {
            printf("File : %s\n", entry->d_name);
        }
        
    }

    closedir(dp);

    return 0;
}