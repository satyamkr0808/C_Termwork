#include <stdio.h>
struct Product
{
    char Product_name[100];
    int Product_ID;
    int Quantity;
    float Price;
};

int main()
{
    struct Product p[50];
    int n, i;
    float totalCost;
    FILE *fproduct, *fexpensive;

    printf("Enter number of products: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("\nProduct %d:\n", i + 1);
        printf("Product Name: ");
        scanf(" %[^\n]", p[i].Product_name);
        printf("Product ID: ");
        scanf("%d", &p[i].Product_ID);
        printf("Quantity: ");
        scanf("%d", &p[i].Quantity);
        printf("Price: ");
        scanf("%f", &p[i].Price);
    }
    // All records to product.txt
    fproduct = fopen("product.txt", "w");
    if (fproduct == NULL)
    {
        printf("Error: Cannot create product.txt\n");
        return 1;
    }
    // Expensive records to expensive.txt
    fexpensive = fopen("expensive.txt", "w");
    if (fexpensive == NULL)
    {
        printf("Error: Cannot create expensive.txt\n");
        fclose(fproduct);
        return 1;
    }
    fprintf(fproduct, "%-20s %-12s %-10s %-10s %-12s\n",
            "Product Name", "Product ID", "Quantity", "Price", "Total Cost");

    fprintf(fexpensive, "%-20s %-12s %-10s %-10s %-12s\n",
            "Product Name", "Product ID", "Quantity", "Price", "Total Cost");

    for (i = 0; i < n; i++)
    {
        totalCost = p[i].Quantity * p[i].Price;
        fprintf(fproduct, "%-20s %-12d %-10d %-10.2f %-12.2f\n",
                p[i].Product_name, p[i].Product_ID, p[i].Quantity, p[i].Price, totalCost);

        if (totalCost > 10000)
        {
            fprintf(fexpensive, "%-20s %-12d %-10d %-10.2f %-12.2f\n",
                    p[i].Product_name, p[i].Product_ID, p[i].Quantity, p[i].Price, totalCost);
        }
    }
    fclose(fproduct);
    fclose(fexpensive);
    printf("\nAll records saved to product.txt\n");
    printf("Expensive records (total cost > 10000) saved to expensive.txt\n");
    // Display all records 
    fproduct = fopen("product.txt", "r");
    char line[200];
    printf("\n--- All Products ---\n");
    while (fgets(line, sizeof(line), fproduct))
        printf("%s", line);
    fclose(fproduct);
    // Display expensive records
    fexpensive = fopen("expensive.txt", "r");
    printf("\n--- Expensive Products (Total Cost > 10000) ---\n");
    while (fgets(line, sizeof(line), fexpensive))
        printf("%s", line);
    fclose(fexpensive);

    return 0;
}