#include <stdio.h>

void spiral(int a[100][100], int r, int c)
{
    int top = 0, bottom = r - 1;
    int left = 0, right = c - 1;
    int i;

    while (top <= bottom && left <= right)
    {
        for (i = left; i <= right; i++)
            printf("%d ", a[top][i]);
        top++;

        for (i = top; i <= bottom; i++)
            printf("%d ", a[i][right]);
        right--;

        if (top <= bottom)
        {
            for (i = right; i >= left; i--)
                printf("%d ", a[bottom][i]);
            bottom--;
        }

        if (left <= right)
        {
            for (i = bottom; i >= top; i--)
                printf("%d ", a[i][left]);
            left++;
        }
    }
}

int main()
{
    int r, c;
    int a[100][100];
    int i, j;

    scanf("%d %d", &r, &c);

    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            scanf("%d", &a[i][j]);

    spiral(a, r, c);

    return 0;
}

