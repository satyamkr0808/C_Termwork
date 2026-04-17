#include <stdio.h>

int main()
{
    int i, j, val;
    char ch = 'A';

    /* Pattern (a) */
    printf("Pattern (a):\n");
    for (i = 1; i <= 5; i++)
    {
        for (j = 1; j <= i; j++)
        {
            printf("%c ", ch);
            ch++;
        }
        printf("\n");
    }

    printf("\n");

    /* Pattern (b) */
    printf("Pattern (b):\n");
    for (i = 1; i <= 5; i++)
    {
        
        if (i % 2 != 0)
            val = 1;
        else
            val = 0;

        for (j = 1; j <= i; j++)
        {
            printf("%d ", val);
            val = 1 - val;  
        }
        printf("\n");
    }

    return 0;
}