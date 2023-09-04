#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void bubbleSort(int arr[], int n)
{
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++)
    {
        swapped = false;
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
}
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
}
int main()
{
    int n;
    printf("Enter Size- ");
    scanf("%d", &n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        int num=rand() % 100;
        arr[i]=num;
    }
    // printf("Before Sorting- ");
    // printArray(arr, n);
    clock_t t;
    t = clock();
    bubbleSort(arr, n);
    t = clock() - t;
    // printf("\nAfter Sorting- ");
    // printArray(arr, n);
    printf("\nTime taken- %lf\n", (double)(t) / CLOCKS_PER_SEC);
    return 0;
}