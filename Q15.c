#include <stdio.h>
#include <ctype.h>

int isVowel(char ch)
{
    ch = tolower(ch);
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        return 1;
    return 0;
}

int main()
{
    FILE *fin, *fout;
    char ch;
    int vowelCount = 0, consonantCount = 0;
    fin = fopen("Input.txt", "r");
    if (fin == NULL)
    {
        printf("Error: Cannot open Input.txt\n");
        return 1;
    }
    fout = fopen("Output.txt", "w");
    if (fout == NULL)
    {
        printf("Error: Cannot create Output.txt\n");
        fclose(fin);
        return 1;
    }
    while ((ch = fgetc(fin)) != EOF)
    {
        if (isdigit(ch))
            continue;  // Skip digits

        fputc(ch, fout);  // Write non-digit characters

        if (isalpha(ch))
        {
            if (isVowel(ch))
                vowelCount++;
            else
                consonantCount++;
        }
    }
    // Append counts at the end of Output.txt 
    fprintf(fout, "\n\nTotal Vowels: %d\n", vowelCount);
    fprintf(fout, "Total Consonants: %d\n", consonantCount);

    fclose(fin);
    fclose(fout);

    printf("Output written to Output.txt\n");
    printf("Total Vowels: %d\n", vowelCount);
    printf("Total Consonants: %d\n", consonantCount);
    
    return 0;
}