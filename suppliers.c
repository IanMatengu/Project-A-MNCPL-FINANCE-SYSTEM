#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "suppliers.h"

Supplier suppliers[MAX_SUPPLIERS];
int supplierCount = 0;

static int readNonEmptyInput(const char *prompt, char *buffer, size_t size)
{
    printf("%s", prompt);

    if (fgets(buffer, size, stdin) == NULL)
    {
        return 0;
    }

    buffer[strcspn(buffer, "\n")] = '\0';

    for (size_t i = 0; buffer[i] != '\0'; i++)
    {
        if (!isspace((unsigned char)buffer[i]))
        {
            return 1;
        }
    }

    return 0;
}

void addSupplier()
{
    if (supplierCount >= MAX_SUPPLIERS)
    {
        printf("Supplier list is full.\n");
        return;
    }

    printf("\n--- ADD SUPPLIER ---\n");

    if (!readNonEmptyInput("Enter Supplier ID: ",
                           suppliers[supplierCount].supplierID,
                           sizeof(suppliers[supplierCount].supplierID)))
    {
        printf("Supplier ID cannot be empty.\n");
        return;
    }

    if (!readNonEmptyInput("Enter Supplier Name: ",
                           suppliers[supplierCount].supplierName,
                           sizeof(suppliers[supplierCount].supplierName)))
    {
        printf("Supplier Name cannot be empty.\n");
        return;
    }

    if (!readNonEmptyInput("Enter Email: ",
                           suppliers[supplierCount].email,
                           sizeof(suppliers[supplierCount].email)))
    {
        printf("Email cannot be empty.\n");
        return;
    }

    if (!readNonEmptyInput("Enter Telephone Number: ",
                           suppliers[supplierCount].telephone,
                           sizeof(suppliers[supplierCount].telephone)))
    {
        printf("Telephone Number cannot be empty.\n");
        return;
    }

    if (!readNonEmptyInput("Enter Town/Location: ",
                           suppliers[supplierCount].town,
                           sizeof(suppliers[supplierCount].town)))
    {
        printf("Town/Location cannot be empty.\n");
        return;
    }

    supplierCount++;

    printf("\nSupplier added successfully!\n");
}

void displaySuppliers()
{
    if (supplierCount == 0)
    {
        printf("\nNo suppliers available.\n");
        return;
    }

    printf("\n========== SUPPLIER LIST ==========\n");

    for (int i = 0; i < supplierCount; i++)
    {
        printf("\nSupplier %d\n", i + 1);
        printf("Supplier ID: %s\n", suppliers[i].supplierID);
        printf("Supplier Name: %s\n", suppliers[i].supplierName);
        printf("Email: %s\n", suppliers[i].email);
        printf("Telephone: %s\n", suppliers[i].telephone);
        printf("Town/Location: %s\n", suppliers[i].town);
    }

    printf("\n===================================\n");
}

void searchSupplier()
{
    char searchName[100];

    printf("\n--- SEARCH SUPPLIER ---\n");

    if (!readNonEmptyInput("Enter supplier name: ",
                           searchName,
                           sizeof(searchName)))
    {
        printf("Supplier name cannot be empty.\n");
        return;
    }

    for (int i = 0; i < supplierCount; i++)
    {
        if (strcmp(suppliers[i].supplierName, searchName) == 0)
        {
            printf("\nSupplier found!\n");
            printf("Supplier ID: %s\n", suppliers[i].supplierID);
            printf("Supplier Name: %s\n", suppliers[i].supplierName);
            printf("Email: %s\n", suppliers[i].email);
            printf("Telephone: %s\n", suppliers[i].telephone);
            printf("Town/Location: %s\n", suppliers[i].town);
            return;
        }
    }

    printf("\nSupplier not found.\n");
}

void compareSuppliers()
{
    char firstName[100];
    char secondName[100];

    printf("\n--- COMPARE SUPPLIERS ---\n");

    if (!readNonEmptyInput("Enter first supplier name: ",
                           firstName,
                           sizeof(firstName)))
    {
        printf("First supplier name cannot be empty.\n");
        return;
    }

    if (!readNonEmptyInput("Enter second supplier name: ",
                           secondName,
                           sizeof(secondName)))
    {
        printf("Second supplier name cannot be empty.\n");
        return;
    }

    int firstFound = -1;
    int secondFound = -1;

    for (int i = 0; i < supplierCount; i++)
    {
        if (strcmp(suppliers[i].supplierName, firstName) == 0)
        {
            firstFound = i;
        }

        if (strcmp(suppliers[i].supplierName, secondName) == 0)
        {
            secondFound = i;
        }
    }

    if (firstFound == -1 || secondFound == -1)
    {
        printf("\nOne or both suppliers were not found.\n");
        return;
    }

    printf("\n--- SUPPLIER COMPARISON ---\n");

    printf("\nSupplier 1:\n");
    printf("ID: %s\n", suppliers[firstFound].supplierID);
    printf("Name: %s\n", suppliers[firstFound].supplierName);
    printf("Email: %s\n", suppliers[firstFound].email);
    printf("Telephone: %s\n", suppliers[firstFound].telephone);
    printf("Town: %s\n", suppliers[firstFound].town);

    printf("\nSupplier 2:\n");
    printf("ID: %s\n", suppliers[secondFound].supplierID);
    printf("Name: %s\n", suppliers[secondFound].supplierName);
    printf("Email: %s\n", suppliers[secondFound].email);
    printf("Telephone: %s\n", suppliers[secondFound].telephone);
    printf("Town: %s\n", suppliers[secondFound].town);
}
