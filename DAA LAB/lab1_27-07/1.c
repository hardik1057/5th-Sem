/*Write a program to store random numbers into an array of n integers and then find out the smallest and largest number stored in it.
Input
Enter how many random numbers : 10
The content of the array with  random input are as follows:
10, 40, 35, 47, 68, 22, 40, 46, 98, 10
Output
The smallest number is 10
The largest number is 98
*/
#include <stdio.h>
#include<stdlib.h>
int main()
{
    int size;
    printf("Enter size- ");
    scanf("%d", &size);
    int arr[size];
    for(int i=0;i<size;i++)
    {
        int num=rand() % 10;
        arr[i]=num;
    }
    for (int i=0;i<size;i++)
    {
        printf("%d ", arr[i]);
    }
    int max=arr[0];
    int min=arr[0];
    for(int i=0; i<size; i++)
    {
        if(min<arr[i])
        {
	        min=arr[i];   
        }
		if(max>arr[i])
        {
             max=arr[i];       
        }
    }
    printf("\nMax- %d, Min- %d", max,min);
    return 0;
}