#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
void merge(int arr[], long long l, long long m, long long r)
{
    long long i, j, k;
    long long n1 = m - l;
    long long n2 = r - m + 1;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], long long l, long long r)
{
    if (l < r)
    {
        long long m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m + 1, r);
    }
}
int main()
{
    long long  n;
    printf("Enter Size- ");
    scanf("%lld", &n);
    int unsorted[n];
    int sorted[n];
    int rev_sort[n];
    for (long long  i = 0; i < n; i++)
    {
        int num = rand() % 100;
        unsorted[i] = num;
    }
    clock_t t1, t2, t3;
    t1 = clock();
    mergeSort(unsorted, 0, n);
    t1 = clock() - t1;
    printf("Time taken for sorting unsorted- %lf", (double)(t1) / CLOCKS_PER_SEC);
    for (long long i = 0; i < n; i++)
    {
        sorted[i] = unsorted[i];
    }
    t2 = clock();
    mergeSort(sorted, 0, n);
    t2 = clock() - t2;
    printf("\nTime taken for sorting sorted array- %lf", (double)(t2) / CLOCKS_PER_SEC);
    for (long long j = n - 1, i = 0; j >= 0; j--, i++)
    {
        rev_sort[i] = sorted[j];
    }
    t3 = clock();
    mergeSort(rev_sort, 0, n);
    t3 = clock() - t3;
    printf("\nTime taken for sorting reversesorted array- %lf\n", (double)(t3) / CLOCKS_PER_SEC);
    return 0;
}
