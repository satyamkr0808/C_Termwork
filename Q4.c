#include <stdio.h>

int main()
{
    int n, i;
    int sum = 0;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        if (i % 2 != 0)
            sum = sum + (i * i);
        else
            sum = sum - (i * i);
    }

    printf("Sum of series = %d\n", sum);

    return 0;
}