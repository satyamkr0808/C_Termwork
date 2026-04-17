#include <stdio.h>
int main()
{
    int mat[10][10], n, i, j, flag = 0;

    printf("Enter size of square matrix: ");
    scanf("%d", &n);
    printf("Enter matrix elements:\n");
    for (i = 0; i < n; i++)
    {    for (j = 0; j < n; j++)
        {    
            scanf("%d", &mat[i][j]);
        }
    }
    printf("Matrix is:\n");
    for (i = 0; i < n; i++)
       { for (j = 0; j < n; j++)
            {
              printf("%d\t", mat[i][j]);
            
            }
            printf("\n");
        }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (mat[i][j] != mat[j][i])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
            break;
    }

    if (flag == 0)
        printf("Matrix is Symmetric\n");
    else
        printf("Matrix is Not Symmetric\n");

    return 0;
}