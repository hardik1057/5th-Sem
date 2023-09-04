#include <stdio.h>
#include <string.h>

void sortVowels(char *str)
{
    int n = strlen(str);
    char temp1[n];
    char temp2[n];
    char res[n];
    int j = 0, k = 0;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
        {
            temp1[j++] = str[i];
        }
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
        {
            temp2[k++] = str[i];
        }
    }
    for (int i = 0; i < j - 1; i++)
    {
        for (int k = i + 1; k < j; k++)
        {
            if (temp1[i] > temp1[k])
            {
                char t = temp1[i];
                temp1[i] = temp1[k];
                temp1[k] = t;
            }
        }
    }
    for (int i = 0; i < k - 1; i++)
    {
        for (int z = i + 1; z < k; z++)
        {
            if (temp2[i] > temp2[z])
            {
                char t = temp2[i];
                temp2[i] = temp2[z];
                temp2[z] = t;
            }
        }
    }
    int j1 = 0, k1 = 0, i = 0;
    while (j1 < j && k1 < k)
    {
        int d = (int)temp2[k1] - (int)temp1[j1];
        if (d <= 32)
        {
            res[i++] = temp2[k1++];
        }
        else
        {
            res[i++] = temp1[j1++];
        }
    }
    while (j1 < j)
    {
        res[i++] = temp1[j1++];
    }
    while (k1 < k)
    {
        res[i++] = temp2[k1++];
    }
    j = 0;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U' || str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
        {
            str[i] = res[j++];
        }
    }
}

int main()
{
    char str[] = {};
    scanf("%s", str);
    printf("Original string: %s\n", str);
    sortVowels(str);
    printf("Sorted string: %s\n", str);
    return 0;
}   
