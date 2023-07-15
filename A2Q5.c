// 2.5) Accept directory name from user and print file with largest size
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
    char largestName[20] = {'\0'};
    int maxSize = 0;
    char name[30];
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
            if(maxSize < sobj.st_size)
            {
                maxSize = sobj.st_size;
                strcpy(largestName,entry->d_name);
            }
        } 
    }

    printf("Name of largest file : %s \nSize : %d bytes \n",largestName,maxSize); 

    closedir(dp);

    return 0;
}