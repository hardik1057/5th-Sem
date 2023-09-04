/*Write a C Program to enter a number and store the number across the
following structure and print the content of each member of the structure.
Then aggregate each member of the structure to form the original number and
print the same.
struct pkt{
char ch1;
char ch2[2];
char ch3;
};
*/ 
#include<stdio.h>

struct pkt
{
    char ch1;
    char ch2[2];
    char ch3;
};
int main()
{
    struct pkt data;
    unsigned int num;
    printf("Enter a number- ");
    scanf("%u", &num);
    char byte1 = num & 0xFF;
    char byte2 = (num >> 8) & 0xFF;
    char byte3 = (num >> 16) & 0xFF;
    char byte4 = (num >> 24) & 0xFF;
    data.ch1 = byte1;
    data.ch2[0] = byte2;
    data.ch2[1] = byte3;
    data.ch3 = byte4;
    printf("\nContent of the structure- \n");
    printf("ch1-  %u\n", data.ch1);
    printf("ch2[0]-  %u\n", data.ch2[0]);
    printf("ch2[1]-  %u\n", data.ch2[1]);
    printf("ch3-  %u\n", data.ch3);
    int num1 = data.ch1;
    int num2 = data.ch2[0] << 8;
    int num3 = data.ch2[1] << 16;
    int num4 = data.ch3 << 24;
    int originalNumber = num1 + num2 + num3 + num4;
    printf("\nOriginal number- %d\n", originalNumber);
    return 0;
}
