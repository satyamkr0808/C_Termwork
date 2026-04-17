#include <stdio.h>
#include <string.h>

int main()
{
    char s1[100], s2[100];
    int freq[256] = {0};
    int i, flag = 0;

    printf("Enter first string: ");
    scanf("%s", s1);
    printf("Enter second string: ");
    scanf("%s", s2);

    if (strlen(s1) != strlen(s2))
    {
        printf("Not Anagram\n");
        return 0;
    }

    for (i = 0; s1[i] != '\0'; i++)
        freq[(int)s1[i]]++;

    for (i = 0; s2[i] != '\0'; i++)
        freq[(int)s2[i]]--;

    for (i = 0; i < 256; i++)
    {
        if (freq[i] != 0)
        {
            flag = 1;
            break;
        }
    }

    if (flag == 0)
        printf("It is an  Anagram\n");
    else
        printf("Not an Anagram\n");

    return 0;
}