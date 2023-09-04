/* Write a program to find out the second smallest and second largest element stored in an array of n integers. */
#include <stdio.h>
int main()
{
    int arr[] = {12, 45, 2, 41, 31, 10, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int smallest = arr[0];
    int second_smallest = arr[0];
    int largest = arr[0];
    int second_largest = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < smallest)
        {
            second_smallest = smallest;
            smallest = arr[i];
        }
        else if (arr[i] < second_smallest)
        {
            second_smallest = arr[i];
        }

        if (arr[i] > largest)
        {
            second_largest = largest;
            largest = arr[i];
        }
        else if (arr[i] > second_largest)
        {
            second_largest = arr[i];
        }
    }

    printf("Second Smallest: %d\n", second_smallest);
    printf("Second Largest: %d\n", second_largest);

    return 0;
}
