// 3.3) Accept two dir names and move files
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
    char oldName[40] = {'\0'};
    char newName[40] = {'\0'};
    struct stat sobj;
    
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
        sprintf(oldName,"%s/%s",argv[1],entry->d_name);
        sprintf(newName,"%s/%s",argv[2],entry->d_name);
        rename(oldName, newName);
    }

    closedir(dp);

    return 0;
}