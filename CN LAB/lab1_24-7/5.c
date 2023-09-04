/*Write a C program to check whether the Host machine is in Little Endian or
Big Endian. Enter a number, print the content of each byte location and
Convert the Endianness of the same i.e. Little to Big Endian and vice-versa.
*/ 
#include<stdio.h>
int main()
{
    unsigned int num;
    printf("Enter a number: ");
    scanf("%u", &num);
    char byte1 = num & 0xFF;
    char byte2 = (num >> 8) & 0xFF;
    char byte3 = (num >> 16) & 0xFF;
    char byte4 = (num >> 24) & 0xFF;
    int n1, n2, n3, n4, converted_number;
    char *p = &num;
    char b1 = *(p);
    int i = 0;
    printf("Extracted byte from the LSB of the Number=%d\n", byte1);
    printf("Extracted byte from the MSB of the Number=%d\n", byte4);
    printf("Memory representation of the Number\n");
    printf("Memory Address  ->\tValue\n");
    while (i < 4)
    {
        printf("%d\t\t->\t%d\n", p, b1);
        p++;
        b1 = *(p);
        i++;
    }
    p = &num;
    b1 = *(p);
    if (b1 == byte1)
    {
        printf("The LSB of the number is stored at the lowest memory address\nHence, the host machine is in Little Endian\n");
        printf("\nThe Number is converted to Big Endian now\nMemory representation of the number\n");
        n1 = byte1 << 24;
        n2 = byte2 << 16;
        n3 = byte3 << 8;
        n4 = byte4;
        converted_number = n1 + n2 + n3 + n4;
        char *p1 = &converted_number;
        char b2 = *(p1);
        i = 0;
        while (i < 4)
        {
            printf("%d\t\t->\t%d\n", p1, b2);
            p1++;
            b2 = *(p1);
            i++;
        }
        printf("The number in Big Endian format is %d", converted_number);
    }
    else if (b1 == byte4)
    {
        printf("The LSB of the number is stored at the highest memory address\nHence, the host machine is in Big Endian\n");
        printf("\nThe Number is converted to Little Endian now\nMemory representation of the number\n");
        n1 = byte1 << 24;
        n2 = byte2 << 16;
        n3 = byte3 << 8;
        n4 = byte4;
        converted_number = n1 + n2 + n3 + n4;
        char *p1 = &converted_number;
        char b2 = *(p1);
        i = 0;
        while (i < 4)
        {
            printf("%d\t\t->\t%d\n", p1, b2);
            p1++;
            b2 = *(p1);
            i++;
        }
        printf("The number in Little Endian format is %d", converted_number);
    }
    return 0;
}
