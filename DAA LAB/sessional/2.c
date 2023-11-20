#include <stdio.h>
struct pair
{
    int min;
    int max;
};
struct pair getMinMax(int arr[], int n)
{
    struct pair minmax;
    int i;
    if (n == 1)
    {
        minmax.max = arr[0];
        minmax.min = arr[0];
        return minmax;
    }
    if (arr[0] > arr[1])
    {
        minmax.max = arr[0];
        minmax.min = arr[1];
    }
    else
    {
        minmax.max = arr[1];
        minmax.min = arr[0];
    }
    for (i = 2; i < n; i++)
    {
        if (arr[i] > minmax.max)
        {
            minmax.max = arr[i];
        }

        else if (arr[i] < minmax.min)
        {
            minmax.min = arr[i];
        }
    }
    return minmax;
}
int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    struct pair minmax = getMinMax(arr, n);
    printf("nMinimum element is %d", minmax.min);
    printf("nMaximum element is %d", minmax.max);
    return 0;
}
