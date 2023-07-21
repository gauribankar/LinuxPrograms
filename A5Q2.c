//5.2 Read structure from file
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

    if(argc != 2)
    {
        printf("Insufficient Arguments ! \n");
        return -1;
    }   

    fd = open(argv[1],O_RDONLY);

    read(fd, &sobj, sizeof(sobj));

    printf("Roll number : %d \n",sobj.Rollno);
    printf("Name : %s\n",sobj.Name);
    printf("Marks : %f\n",sobj.Marks);
    printf("Age : %d\n",sobj.Age);

    close(fd);

    return 0;
}
