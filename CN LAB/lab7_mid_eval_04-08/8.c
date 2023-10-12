// wap in c to print all the byes of a number 
#include<stdio.h>
int main ()
{
    unsigned int no;
    unsigned int byte[4];
    printf("Enter a number-");
    scanf("%x", &no);
    for(int i=0;i<4;i++)
    {
        byte[i]=(no & 0xFF);
        no=no>>8;
    }
    for(int i=3;i>=0;i--)
    {
        printf("%x ", byte[i]);
    }
    return 0;
}