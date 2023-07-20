// 4.1) Program to show IO redirection
#include<stdio.h>

int main(int argc, char *argv[])
{
    char input[30];

    scanf("%s", input);

    printf("Hello, %s. This program is to demonstrate IO redirection!\n", input);

    return 0;
}

// To execute:
// ./Myexe < input_file > output_file