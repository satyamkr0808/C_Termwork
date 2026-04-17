#include <stdio.h>
#include <ctype.h>
int main()
{
    static char stored_email[] = "admin@example.com";
    char user_email[100];
    char *p1, *p2;
    int flag = 0;

    printf("Enter your email ID: ");
    scanf("%s", user_email);

    p1 = stored_email;
    p2 = user_email;

    while (*p1 != '\0' && *p2 != '\0')
    {
        if (tolower(*p1) != tolower(*p2))
        {
            flag = 1;
            break;
        }
        p1++;
        p2++;
    }

    // Also check if both strings ended at same time (same length) 
    if (*p1 != '\0' || *p2 != '\0')
        flag = 1;

    if (flag == 0)
        printf("Valid Email\n");
    else
        printf("Invalid Email\n");

    return 0;
}