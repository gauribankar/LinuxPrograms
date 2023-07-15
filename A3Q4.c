// 3.4) Accept dir name and delete empty file
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
    char name[40] = {'\0'};
    struct stat sobj;
    
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

    while((entry = readdir(dp)) != NULL)
    {
        sprintf(name,"%s/%s",argv[1],entry->d_name);
        stat(name,&sobj);
        if(S_ISREG(sobj.st_mode))
        {
            if(sobj.st_size == 0)
            {
                printf("Deleting file : %s\n",entry->d_name);
                remove(name);
            }
        }
    }

    closedir(dp);

    return 0;
}