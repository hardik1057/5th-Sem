/*Write a program to read ‘n’ integers from a disc file that must contain some duplicate values and store them into an array. Perform the following operations
 on the array.
a) Find out the total number of duplicate elements.
b) Find out the most repeating element in the array.
*/
#include <stdio.h>
int main()
{
    int n, i, j;
    printf("Enter number of elements:");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements into array should contain duplicate elements(max value of element can be 100):");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int count[101], max_element = 0, duplicates = 0, count_max = 0;
    for (i = 0; i < 101; i++)
    {
        count[i] = 0;
    }
    for (i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }
    for (i = 0; i < 101; i++)
    {
        if (count[i] > 1)
        {
            duplicates++;
            if (count[i] > count_max)
            {
                count_max = count[i];
                max_element = i;
            }
        }
    }
    printf("\nNumber of duplicate elements are %d and the most repeating element is %d", duplicates, max_element);
    return 0;
}
