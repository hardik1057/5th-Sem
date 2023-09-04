/*Write a function to ROTATE_RIGHT(p1, p2 ) right an array for first p2 elements by 1 position using EXCHANGE(p, q) function that swaps/exchanges the
numbers p & q. Parameter p1 be the starting address of the array and p2 be the number of elements to be rotated.  */
#include <stdio.h>
void exchange(int *p, int *q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
}

void rotate_right(int arr[], int k)
{
    for (int i = k - 1; i > 0; i--)
    {
        exchange(arr + i, arr + (i - 1));
    }
}
int main()
{
    int size;
    scanf("%d", &size);
    int array[size] ;
    for(int i=0;i<size;i++)
    {
        scanf("%d", &array[i]);
    }
    int p2;
    scanf("%d",&p2);
    rotate_right(array, p2);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    return 0;
}