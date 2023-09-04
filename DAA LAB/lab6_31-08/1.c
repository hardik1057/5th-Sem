#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void maxToMinHeap(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < n && arr[left] < arr[smallest])
            smallest = left;
        if (right < n && arr[right] < arr[smallest])
            smallest = right;
        if (smallest != i)
        {
            swap(&arr[i], &arr[smallest]);
            maxToMinHeap(arr, n);
        }
    }
}
void minToMaxHeap(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < n && arr[left] > arr[largest])
            largest = left;
        if (right < n && arr[right] > arr[largest])
            largest = right;
        if (largest != i)
        {
            swap(&arr[i], &arr[largest]);
            minToMaxHeap(arr, n);
        }
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
    int maxHeap[] = {9, 7, 6, 5, 3, 1};
    int minHeap[] = {1, 3, 2, 7, 5, 8};
    int n = sizeof(maxHeap) / sizeof(maxHeap[0]);
    printf("Max Heap:");
    printArray(maxHeap, n);
    maxToMinHeap(maxHeap, n);
    printf("Max Heap Converted to Min Heap: ");
    printArray(maxHeap, n);
    printf("\n");
    printf("Min Heap:");
    printArray(minHeap, n);
    minToMaxHeap(minHeap, n);
    printf("Min Heap Converted To Max Heap: ");
    printArray(minHeap, n);
    return 0;
}
