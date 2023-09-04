/*WAP in C to find the ime taken by bubble sort to sort unsorted array, sorted array, reverse sorted array. Take note of time taken by the algoritm and plot a graph*/
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
    int unsorted[n];
    int sorted[n];
    int rev_sort[n];
    for (int i = 0; i < n; i++)
    {
        int num = rand() % 100;
        unsorted[i] = num;
    }
    clock_t t1, t2, t3;
    t1 = clock();
    bubbleSort(unsorted, n);
    t1 = clock() - t1;
    printf("Time taken for sorting unsorted- %lf", (double)(t1) / CLOCKS_PER_SEC);
    for (int i = 0; i < n; i++)
    {
        sorted[i] = unsorted[i];
    }
    t2 = clock();
    bubbleSort(sorted, n);
    t2 = clock() - t2;
    printf("\nTime taken for sorting sorted array- %lf", (double)(t2) / CLOCKS_PER_SEC);
    for (int j = n - 1, i = 0; j >= 0; j--, i++)
    {
        rev_sort[i] = sorted[j];
    }
    t3 = clock();
    bubbleSort(rev_sort, n);
    t3 = clock() - t3;
    printf("\nTime taken for sorting reversesorted array- %lf\n", (double)(t3) / CLOCKS_PER_SEC);
    return 0;
}