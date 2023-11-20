#include <stdlib.h>
#include <time.h>
#include <stdio.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(int arr[], int n, int index)
{
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != index)
    {
        swap(&arr[index], &arr[largest]);
        heapify(arr, n, largest);
    }
}
void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int n;
    printf("Enter the size:");
    scanf("%d", &n);
    int random_numbers[n];
    for (int i = 0; i < n; i++)
    {
        random_numbers[i] = rand() % 100;
    }
    clock_t t;
    t = clock();
    heapSort(random_numbers, n);
    t = clock() - t;
    double time_taken = ((double)t) / CLOCKS_PER_SEC;

    int arr1[n];
    for (int i = 0; i < n; i++)
    {
        arr1[i] = random_numbers[i];
    }
    clock_t t1;
    t1 = clock();
    heapSort(arr1, n);
    t1 = clock() - t1;
    double time_taken1 = ((double)t1) / CLOCKS_PER_SEC;
    int arr2[n];
    int j = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        arr2[j] = arr1[i];
        j++;
    }
    clock_t t2;
    t2 = clock();
    heapSort(arr2, n);
    t2 = clock() - t1;
    double time_taken2 = ((double)t2) / CLOCKS_PER_SEC;
    printf("\nUnsorted function  took %lf seconds to execute", time_taken);
    printf("\nSorted function took %lf seconds to execute", time_taken1);
    printf("\nReverse function took %lf seconds to execute", time_taken2);
    return 0;
}
