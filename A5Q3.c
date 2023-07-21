//5.3 Accept dir name and write information of all regular files
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
    char DirName[20];
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    char name[30];
    struct stat sobj;

    printf("Name of directory : ");
    scanf("%s", DirName);

    dp = opendir(DirName);
    if(dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }

    while((entry = readdir(dp)) != NULL)
    {
        // printf("%s\n", entry->d_name);
        sprintf(name,"%s/%s",DirName, entry->d_name);
        printf("%s\n", name);
        stat(name, &sobj);
        if(S_ISREG(sobj.st_mode))
        {
            printf("File name : %s File size : %ld \n",name,sobj.st_size);
        }
    }

    closedir(dp);

    return 0;
}