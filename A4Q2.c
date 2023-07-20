// 4.2) Accept directory name from user and create that directory
#include<stdio.h>
#include<dirent.h>

int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    if(argc != 2)
    {
        printf("Insufficient arguments.\n");
        return -1;
    }

    dp = mkdir(argv[1], 0777);
    if(dp == NULL)
    {
        printf("Unable to create directory %s\n", argv[1]);
        return -1;
    }

    printf("%s directory created successfully.\n", argv[1]);
    return 0;
}