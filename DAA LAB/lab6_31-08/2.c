#include <stdio.h>
void maxHeapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        maxHeapify(arr, n, largest);
    }
}
void convertToMaxHeap(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        maxHeapify(arr, n, i);
    }
}
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int n;
    printf("Enter number of elements in the bst:");
    scanf("%d", &n);
    int bstArray[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &bstArray[i]);
    }
    printf("Binary Search Tree Array: ");
    printArray(bstArray, n);
    convertToMaxHeap(bstArray, n);
    printf("Max-Heap Array: ");
    printArray(bstArray, n);
    return 0;
}
