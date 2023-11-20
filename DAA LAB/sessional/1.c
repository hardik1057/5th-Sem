#include <stdio.h>
int split(int arr[], int n)
{
   
    int leftSum = 0;
    for (int i = 0; i < n; i++)
        leftSum += arr[i];
    int rightSum = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        rightSum += arr[i];
        leftSum -= arr[i];

        if (rightSum == leftSum)
            return i;
    }
    return -1;
}
void printing(int arr[], int n)
{
    int splitPoint = split(arr, n);

    if (splitPoint == -1 || splitPoint == n)
    {
        printf("Not Possible\n");
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (splitPoint == i)
            printf("\n");
        printf("%d\n", arr[i]);
    }
}
int main()
{
    int n;
    printf("Enter size- ");
    scanf("%d", &n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);
    }
    printing(arr,n);
    return 0;
}
