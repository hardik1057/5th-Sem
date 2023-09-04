#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
int binarySearch(int arr[], int l, int r, int x)
{
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (arr[m] == x)
            return m;
        if (arr[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
int main()
{
    int n,key;
    printf("Enter Size- ");
    scanf("%d", &n);
    int unsorted[n];
    for (int i = 0; i < n; i++)
    {
        int num = rand() % 100;
        unsorted[i] = num;
    }
    insertionSort(unsorted, n);
    clock_t t1,t2,t3;
    key=unsorted[0];
    t1=clock();
    binarySearch(unsorted,0,n-1,key);
    t1=clock()-t1;
    printf("Time taken for searching first- %lf", (double)(t1) / CLOCKS_PER_SEC);
    key = unsorted[n-1];
    t2 = clock();
    binarySearch(unsorted, 0, n - 1, key);
    t2 = clock() - t2;
    printf("\nTime taken for searching last element- %lf", (double)(t2) / CLOCKS_PER_SEC);
    key = unsorted[rand()%n];
    t3 = clock();
    binarySearch(unsorted, 0, n - 1, key);
    t3 = clock() - t3;
    printf("\nTime taken for searching random element- %lf", (double)(t3) / CLOCKS_PER_SEC);
    return 0;
}