//5.1 Write structure in file
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>


#pragma pack(1)
struct Student
{
    int Rollno;
    char Name[20];
    float Marks;
    int Age;
};

int main(int argc, char *argv[])
{
    struct Student sobj;
    char Fname[20];
    int fd = 0;

    sobj.Rollno = 11;
    sobj.Marks = 89;
    sobj.Age = 25;
    strcpy(sobj.Name,"Gauri");

    if(argc != 2)
    {
        printf("Insufficient Arguments ! \n");
        return -1;
    }   

    fd = creat(argv[1],0777);

    write(fd, &sobj, sizeof(sobj)); 

    

    return 0;
}