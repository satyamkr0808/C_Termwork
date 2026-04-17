#include <stdio.h>
#include <string.h>
struct Book
{
    int Book_ID;
    char Title[100];
    char Author[100];
    float Price;
};

int main()
{
    struct Book books[50], temp;
    int n, i, j;
    printf("Enter number of books: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("\nEnter details for Book %d:\n", i + 1);
        printf("Book ID: ");
        scanf("%d", &books[i].Book_ID);
        printf("Title: ");
        scanf(" %[^\n]", books[i].Title);
        printf("Author: ");
        scanf(" %[^\n]", books[i].Author);
        printf("Price: ");
        scanf("%f", &books[i].Price);
    }
    // Bubble sort in descending order of price 
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (books[j].Price < books[j + 1].Price)
            {
                temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
        }
    }
    printf("\n--- Books sorted by Price (Descending) ---\n");
    printf("%-10s %-30s %-25s %-10s\n", "Book ID", "Title", "Author", "Price");
    for (i = 0; i < n; i++)
    {
        printf("%-10d %-30s %-25s %-10.2f\n",
               books[i].Book_ID, books[i].Title, books[i].Author, books[i].Price);
    }

    return 0;
}