#include <stdio.h>
struct node
{
    double data;
    int index;
};
void merge(struct node arr[], long long l, long long m, long long r)
{
    long long i, j, k;
    long long n1 = m - l;
    long long n2 = r - m + 1;
    struct node L[n1], R[n2];
    for (i = 0; i < n1; i++)
    {
        L[i].data = arr[l + i].data;
        L[i].index = arr[l + i].index;
    }
    for (j = 0; j < n2; j++)
    {
        R[j].data = arr[m + j].data;
        R[j].index = arr[m + j].index;
    }
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i].data <= R[j].data)
        {
            arr[k].data = L[i].data;
            arr[k].index = L[i].index;
            i++;
        }
        else
        {
            arr[k].data = R[j].data;
            arr[k].index = R[j].index;
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k].data = L[i].data;
        arr[k].index = L[i].index;
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k].data = R[j].data;
        arr[k].index = R[j].index;
        j++;
        k++;
    }
}
void mergeSort(struct node arr[], long long l, long long r)
{
    if (l < r)
    {
        long long m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m + 1, r);
    }
}
int main()
{
    int size, capacity;
    printf("Enter number of items and capacity of knapsack- ");
    scanf("%d%d", &size, &capacity);
    struct node weight[size];
    struct node value[size];
    struct node profit[size];
    for (int i = 0; i < size; i++)
    {
        printf("\nEnter weight and value of item %d:", i + 1);
        weight[i].index = i;
        value[i].index = i;
        profit[i].index = i;
        scanf("%lf%lf", &weight[i].data, &value[i].data);
        profit[i].data = value[i].data / weight[i].data;
    }
    struct node original[size];
    for (int i = 0; i < size; i++)
    {
        original[i].data = weight[i].data;
        original[i].index = weight[i].index;
    }
    mergeSort(weight, 0, size - 1);
    double kval = 0, tmp = 0;
    int i = 0;
    while (tmp != capacity || i < size)
    {
        if (tmp + weight[i].data <= capacity)
        {
            kval += value[weight[i].index].data;
            tmp += weight[i].data;
        }
        else
        {
            kval += (double)(value[weight[i].index].data * (capacity - tmp)) / (double)weight[i].data;
            tmp += (capacity - tmp);
        }
        i++;
    }
    printf("\nValuable items present in knapsack according to weight will be %lf\n", kval);
    for (int i = 0; i < size; i++)
    {
        weight[i].data = original[i].data;
        weight[i].index = original[i].index;
    }
    for (int i = 0; i < size; i++)
    {
        original[i].data = value[i].data;
        original[i].index = value[i].index;
    }
    mergeSort(value, 0, size - 1);
    kval = 0;
    i = 0;
    tmp = 0;
    while (tmp < capacity && i < size)
    {
        if ((tmp + weight[value[size - 1 - i].index].data) <= capacity)
        {
            kval += value[size - 1 - i].data;
            tmp += weight[value[size - 1 - i].index].data;
        }
        else
        {
            kval += (value[size - 1 - i].data * (capacity - tmp)) / weight[(int)value[size - 1 - i].index].data;
            tmp += (capacity - tmp);
        }
        i++;
    }
    printf("Valuable items present in knapsack according to value will be %lf", kval);
    for (int i = 0; i < size; i++)
    {
        value[i].data = original[i].data;
        value[i].index = original[i].index;
    }
    mergeSort(profit, 0, size - 1);
    kval = 0;
    i = 0;
    tmp = 0;
    while (tmp < capacity && i < size)
    {
        if ((tmp + weight[profit[size - 1 - i].index].data) <= capacity)
        {
            kval += value[profit[size - 1 - i].index].data;
            tmp += weight[profit[size - 1 - i].index].data;
        }
        else
        {
            kval += (value[profit[size - 1 - i].index].data * (capacity - tmp)) / weight[profit[size - 1 - i].index].data;
            tmp += (capacity - tmp);
        }
        i++;
    }
    printf("\nValuable items present in knapsack according to weight by value will be %lf", kval);
    return 0;
}