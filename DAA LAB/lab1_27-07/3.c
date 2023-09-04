/*Write a program to display an array of n integers (n>1), where at every index of the array should contain the product of all elements in the array except
 the element at the given index. Solve this problem by taking single loop and without an additional array.
Input Array  : 3  4  5  1  2
Output Array :40  30  24  120  60*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    printf("ENter size- ");
    scanf("%d", &n);
    int arr[n], mul = 1;
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 10;
        mul *= arr[i];
    }
    printf("\nElements present in the array are:");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
        arr[i] = mul / arr[i];
    }
    printf("\nUpdated array:");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
