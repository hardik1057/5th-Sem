/*Write a program to store random numbers into an array of n integers, where the array must contains some duplicates. Do the following:
a)Find out the total number of duplicate elements.
b)Find out the most repeating element in the array.
Hints: Write the random generation function in such a way that it must generate some duplicate numbers. As for example if you generate 10 random numbers within a range say 11 to 15, then atleast 5 numbers will be duplicate.
Input
Enter how many random numbers: 15
The content of the array with  random input are as follows:
10, 40, 35, 47, 68, 22, 40, 10, 98, 10, 50, 35, 68, 40, 10
Output
Total number of duplicates =  4
The most repeating element in the array = 10
*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, s, e;
    printf("enter n:");
    scanf("%d", &n);
    int arr[n];
    printf("Enter start and range:");
    scanf("%d%d", &s, &e);
    int count[e + 1];
    for (int i = 0; i <= e; i++)
    {
        count[i] = 0;
    }
    printf("Elements present in the array:");
    for (int i = 0; i < n; i++)
    {
        arr[i] = s + (rand() % e);
        printf("%d ", arr[i]);
        count[arr[i] - s]++;
    }
    int c = 0, maxduplicate = 0, maxelement = 0;
    for (int i = 0; i <= e; i++)
    {
        if (count[i] > 1)
        {
            c++;
            if (maxduplicate < count[i])
            {
                maxduplicate = count[i];
                maxelement = (s + i);
            }
        }
    }
    printf("\nNumber of elements repeated %d\n", c);
    printf("Element repeated the most %d\n", maxelement);
    return 0;
}
