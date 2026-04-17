#include <stdio.h>

int main()
{
    char ch;

    printf("Enter a character: ");
    scanf("%c", &ch);

    if (ch >= '0' && ch <= '9')
    {
        printf("%c is a number.\n", ch);
    }
    else if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
    {
        printf("%c is an alphabet.\n", ch);
    }
    else
    {
        printf("%c is a special symbol.\n", ch);
    }

    return 0;
}