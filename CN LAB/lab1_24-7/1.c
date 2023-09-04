// Write a C program to swap the content of 2 variables entered through the command line using function and pointer.
#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main(int argc, char *argv)
{
    int var1 = argv[0]-'0';
    int var2 = argv[1]-'0';
    printf("Before swapping: var1 = %d, var2 = %d\n", var1, var2);
    swap(&var1, &var2);
    printf("After swapping: var1 = %d, var2 = %d\n", var1, var2);
    return 0;
}