#include <stdio.h>
#include <string.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

void findLCS(char *str1, char *str2, int n1, int n2)
{
    int L[n1 + 1][n2 + 1];
    char direction[n1 + 1][n2 + 1];
    for (int i = 0; i <= n1; i++)
    {
        for (int j = 0; j <= n2; j++)
        {
            if (i == 0 || j == 0) L[i][j] = 0;
            else if (str1[i - 1] == str2[j - 1])
            {
                L[i][j] = 1 + L[i - 1][j - 1];
                direction[i][j] = '/';
            }
            else
            {
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
                if (L[i][j] == L[i - 1][j])
                {
                    direction[i][j] = '|';
                }
                else
                {
                    direction[i][j] = '<';
                }
            }
        }
    }
    int length = L[n1][n2];
    char lcs[length + 1];
    lcs[length] = '\0';
    int i = n1, j = n2;
    while (i > 0 && j > 0)
    {
        if (str1[i - 1] == str2[j - 1])
        {
            lcs[length - 1] = str1[i - 1];
            i--;
            j--;
            length--;
        }
        else if (direction[i][j] == '|')
            i--;
        else
            j--;
    }
    printf("Longest Common Subsequence: %s\n", lcs);
}
int main()
{
    char str1[100], str2[100];
    printf("Enter the first string: ");
    scanf(" %[^\n]", str1);
    printf("Enter the second string: ");
    scanf(" %[^\n]", str2);
    int n1 = strlen(str1);
    int n2= strlen(str2);
    findLCS(str1, str2, n1, n2);
    return 0;
}
