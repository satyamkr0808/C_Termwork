#include <stdio.h>

int main()
{
    int mat[10][10], m, n, i, j, k;
    int rowMin, colMax, found = 0;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &m, &n);

    printf("Enter matrix elements:\n");
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &mat[i][j]);

    printf("Matrix is:\n");
    for (i = 0; i < n; i++)
       { for (j = 0; j < n; j++)
            {
              printf("%d\t", mat[i][j]);
            
            }
            printf("\n");
        }

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            // Find minimum of row i 
            rowMin = mat[i][0];
            for (k = 1; k < n; k++)
                if (mat[i][k] < rowMin)
                    rowMin = mat[i][k];

            // Find maximum of column j 
            colMax = mat[0][j];
            for (k = 1; k < m; k++)
                if (mat[k][j] > colMax)
                    colMax = mat[k][j];

            // Check if current element is both row min and col max 
            if (mat[i][j] == rowMin && mat[i][j] == colMax)
            {
                printf("Saddle point found at (%d, %d) = %d\n", i, j, mat[i][j]);
                found = 1;
            }
        }
    }

    if (!found)
        printf("No Saddle Point\n");

    return 0;
}