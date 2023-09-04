#include <stdio.h>
#include <string.h>

void sort_capital_letters(char *str)
{
    int n = strlen(str);
    char temp[n];
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            temp[j++] = str[i];
        }
    }
    for (int i = 0; i < j - 1; i++)
    {
        for (int k = i + 1; k < j; k++)
        {
            if (temp[i] > temp[k])
            {
                char t = temp[i];
                temp[i] = temp[k];
                temp[k] = t;
            }
        }
    }
    j = 0;
    for (int i = 0; i < n; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = temp[j++];
        }
    }
}

int main()
{
    char str[]={0}; 
    scanf("%s", &str);
    printf("Original string: %s\n", str);
    sort_capital_letters(str);
    printf("Sorted string: %s\n", str);
    return 0;
}
