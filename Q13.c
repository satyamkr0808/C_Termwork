#include <stdio.h>
struct Employee
{
    int Employee_ID;
    char Name[100];
    char Department[50];
    float Salary;
};

void displayAboveSalary(struct Employee emp[], int n, float threshold)
{
    int i, found = 0;
    printf("\nEmployees with salary above %.2f:\n", threshold);
    for (i = 0; i < n; i++)
    {
        if (emp[i].Salary > threshold)
        {
            printf("ID: %d | Name: %s | Dept: %s | Salary: %.2f\n",
                   emp[i].Employee_ID, emp[i].Name, emp[i].Department, emp[i].Salary);
            found = 1;
        }
    }
    if (!found)
        printf("No employee found above given salary.\n");
}
void searchByID(struct Employee emp[], int n, int id)
{
    int i, found = 0;
    for (i = 0; i < n; i++)
    {
        if (emp[i].Employee_ID == id)
        {
            printf("\nEmployee Found:\n");
            printf("ID: %d | Name: %s | Dept: %s | Salary: %.2f\n",
                   emp[i].Employee_ID, emp[i].Name, emp[i].Department, emp[i].Salary);
            found = 1;
            break;
        }
    }
    if (!found)
        printf("Employee not found.\n");
}

int main()
{
    struct Employee emp[50];
    int n, i, searchID;
    float threshold;

    printf("Enter number of employees: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("\nEnter details for Employee %d:\n", i + 1);
        printf("Employee ID: ");
        scanf("%d", &emp[i].Employee_ID);
        printf("Name: ");
        scanf(" %[^\n]", emp[i].Name);
        printf("Department: ");
        scanf(" %[^\n]", emp[i].Department);
        printf("Salary: ");
        scanf("%f", &emp[i].Salary);
    }

    printf("\nEnter salary threshold: ");
    scanf("%f", &threshold);
    displayAboveSalary(emp, n, threshold);

    printf("\nEnter Employee ID to search: ");
    scanf("%d", &searchID);
    searchByID(emp, n, searchID);

    return 0;
}