/*WAP in C to find the ime taken by selection sort to sort unsorted array, sorted array, reverse sorted array. Take note of time taken by the algoritm and plot a graph*/
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
void SelectionSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                swap(&arr[j], &arr[i]);
            }
        }
    }
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
    SelectionSort(unsorted, n);
    t1 = clock() - t1;
    printf("Time taken for sorting unsorted- %lf", (double)(t1) / CLOCKS_PER_SEC);
    for (int i = 0; i < n; i++)
    {
        sorted[i] = unsorted[i];
    }
    t2 = clock();
    SelectionSort(sorted, n);
    t2 = clock() - t2;
    printf("\nTime taken for sorting sorted array- %lf", (double)(t2) / CLOCKS_PER_SEC);
    for (int j = n - 1, i = 0; j >= 0; j--, i++)
    {
        rev_sort[i] = sorted[j];
    }
    t3 = clock();
    SelectionSort(rev_sort, n);
    t3 = clock() - t3;
    printf("\nTime taken for sorting reverse sorted array- %lf\n", (double)(t3) / CLOCKS_PER_SEC);
    return 0;
}
