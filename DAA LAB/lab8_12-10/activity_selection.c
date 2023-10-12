#include <stdio.h>
typedef struct
{
    int start;
    int end;
    int number;
} Activity;
void swap(Activity *xp, Activity *yp)
{
    Activity temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void SelectionSort(Activity arr[], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (arr[i].end > arr[j].end)
            {
                swap(&arr[j], &arr[i]);
            }
        }
    }
}
int main()
{
    int no, i;
    printf("Enter the number of activities: ");
    scanf("%d", &no);

    Activity activity[no];

    for (i = 0; i < no; i++)
    {
        printf("Enter start and end time for activity %d: ", i + 1);
        scanf("%d %d", &activity[i].start, &activity[i].end);
        activity[i].number = (i + 1);
    }
    SelectionSort(activity, no);
    int num = 0;
    printf("%d ", activity[num].number);
    for (int j = 1; j < no; j++)
    {
        if (activity[j].start >= activity[num].end)
        {
            printf("%d ", activity[j].number);
            num = j;
        }
    }
    return 0;
}
