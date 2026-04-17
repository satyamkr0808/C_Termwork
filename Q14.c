#include <stdio.h>
#include <math.h>

int isPrime(int n)
{
    int i;
    if (n <= 1)
        return 0;
    for (i = 2; i <= (int)sqrt((double)n); i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int main()
{
    FILE *fin, *fprime, *fnonprime;
    int num;

    fin = fopen("numbers.txt", "r");
    if (fin == NULL)
    {
        printf("Error: Cannot open numbers.txt\n");
        return 1;
    }

    fprime = fopen("prime.txt", "w");
    fnonprime = fopen("non_prime.txt", "w");

    if (fprime == NULL || fnonprime == NULL)
    {
        printf("Error: Cannot create output files.\n");
        fclose(fin);
        return 1;
    }

    while (fscanf(fin, "%d", &num) != EOF)
    {
        if (isPrime(num))
            fprintf(fprime, "%d\n", num);
        else
            fprintf(fnonprime, "%d\n", num);
    }

    fclose(fin);
    fclose(fprime);
    fclose(fnonprime);

    printf("Done! Check prime.txt and non_prime.txt\n");
    return 0;
}