#include <stdio.h>
#include <math.h>

int main()
{
    float a, b, c, disc, r1, r2, r, real, imag;

    printf("Enter coefficients a, b and c: ");
    scanf("%f %f %f", &a, &b, &c);

    disc = b * b - 4 * a * c;

    if (disc > 0)
    {
        printf("Roots are real numbers\n");
        r1 = (-b + sqrt(disc)) / (2 * a);
        r2 = (-b - sqrt(disc)) / (2 * a);
        printf("Roots are: %.2f and %.2f\n", r1, r2);
    }
    else if (disc == 0)
    {
        printf("Roots are equal\n");
        r = -b / (2 * a);
        printf("Root is: %.2f\n", r);
    }
    else
    {
        printf("Roots are imaginary\n");
        real = -b / (2 * a);
        imag = sqrt(-disc) / (2 * a);
        printf("Root 1: %.2f + %.2fi\n", real, imag);
        printf("Root 2: %.2f - %.2fi\n", real, imag);
    }

    return 0;
}