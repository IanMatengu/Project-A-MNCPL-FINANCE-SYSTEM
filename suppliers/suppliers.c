#include <stdio.h>
#include <string.h>
#include "suppliers.h"

Supplier suppliers[MAX_SUPPLIERS];
int supplierCount = 0;

void addSupplier()
{
    if (supplierCount >= MAX_SUPPLIERS)
    {
        printf("Supplier list is full.\n");
        return;
    }

    printf("\n--- ADD SUPPLIER ---\n");

    printf("Enter Supplier ID: ");
    fgets(suppliers[supplierCount].supplierID,
          sizeof(suppliers[supplierCount].supplierID), stdin);
    suppliers[supplierCount].supplierID[
        strcspn(suppliers[supplierCount].supplierID, "\n")] = '\0';

    printf("Enter Supplier Name: ");
    fgets(suppliers[supplierCount].supplierName,
          sizeof(suppliers[supplierCount].supplierName), stdin);
    suppliers[supplierCount].supplierName[
        strcspn(suppliers[supplierCount].supplierName, "\n")] = '\0';

    printf("Enter Email: ");
    fgets(suppliers[supplierCount].email,
          sizeof(suppliers[supplierCount].email), stdin);
    suppliers[supplierCount].email[
        strcspn(suppliers[supplierCount].email, "\n")] = '\0';

    printf("Enter Telephone Number: ");
    fgets(suppliers[supplierCount].telephone,
          sizeof(suppliers[supplierCount].telephone), stdin);
    suppliers[supplierCount].telephone[
        strcspn(suppliers[supplierCount].telephone, "\n")] = '\0';

    printf("Enter Town/Location: ");
    fgets(suppliers[supplierCount].town,
          sizeof(suppliers[supplierCount].town), stdin);
    suppliers[supplierCount].town[
        strcspn(suppliers[supplierCount].town, "\n")] = '\0';

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
    printf("Enter supplier name: ");

    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0';

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

    printf("Enter first supplier name: ");
    fgets(firstName, sizeof(firstName), stdin);
    firstName[strcspn(firstName, "\n")] = '\0';

    printf("Enter second supplier name: ");
    fgets(secondName, sizeof(secondName), stdin);
    secondName[strcspn(secondName, "\n")] = '\0';

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