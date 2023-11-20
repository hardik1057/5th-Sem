#include <stdio.h>
#include <time.h>
#include <math.h>
int partition(int *A, int p, int r)
{
    int i = -1;
    int x = A[r];
    for (int j = 0; j < r - 1; j++)
    {
        if (A[j] <= x)
        {
            i++;
            int temp = A[j];
            A[j] = A[i];
            A[i] = temp;
        }
    }
    if (i != -1)
    {
        i++;
        int temp = x;
        x = A[i];
        A[i] = temp;
    }
    return i;
}
void quickSort(int *A, int p, int r)
{
    if (p < r)
    {
        int q = partition(A, p, r);
        if (q == -1)
        {
            quickSort(A, p, r - 1);
        }
        else
        {
            quickSort(A, p, q - 1);
            quickSort(A, q + 1, r);
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
    quickSort(unsorted, 0, n - 1);
    t1 = clock() - t1;
    printf("\nTime taken for sorting unsorted- %lf", (double)(t1) / CLOCKS_PER_SEC);
    for (int i = 0; i < n; i++)
    {
        sorted[i] = unsorted[i];
    }
    t2 = clock();
    quickSort(sorted, 0, n - 1);
    t2 = clock() - t2;
    printf("\nTime taken for sorting sorted array- %lf", (double)(t2) / CLOCKS_PER_SEC);
    for (int j = n - 1, i = 0; j >= 0; j--, i++)
    {
        rev_sort[i] = sorted[j];
    }
    t3 = clock();
    quickSort(rev_sort, 0, n - 1);
    t3 = clock() - t3;
    printf("\nTime taken for sorting reversesorted array- %lf\n", (double)(t3) / CLOCKS_PER_SEC);
    return 0;
}
