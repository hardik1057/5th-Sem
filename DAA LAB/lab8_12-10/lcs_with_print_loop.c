#include <stdio.h>
#include <string.h>
char direction[100][100];
int max(int a, int b)
{
    return (a > b) ? a : b;
}
void print(char *X, char *Y, int i, int j)
{
    if (i < 1 || j < 1)
    {
        return;
    }
    if (direction[i][j] == '/')
    {
        print(X, Y, i - 1, j - 1);
        printf("%c", Y[j - 1]);
    }
    else
    {
        if (direction[i][j] == '<')
        {                                   
            print(X, Y, i, j - 1);
        }
        else
        {
            print(X, Y, i - 1, j);
        }
    }
}
void findLCS(char *X, char *Y, int m, int n)
{
    int L[m + 1][n + 1];
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
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
    printf("Longest Common Subsequence:");
    print(X, Y, m, n);
}

int main()
{
    char X[100], Y[100];
    printf("Enter the first string: ");
    scanf(" %[^\n]", X);
    printf("Enter the second string: ");
    scanf(" %[^\n]", Y);

    int m = strlen(X);
    int n = strlen(Y);

    findLCS(X, Y, m, n);
    return 0;
}
