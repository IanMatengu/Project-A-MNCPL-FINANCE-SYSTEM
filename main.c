#include <stdio.h>
#include "employees.h"
#include "budget.h"
#include "suppliers.h"


int getInteger()
{
    int number;
    int result;

    while (1)
    {
        result = scanf("%d", &number);

        if (result == 1)
        {
            return number;
        }

        printf("Invalid input. Please enter a number: ");

        while (getchar() != '\n');
    }
}


int getMenuChoice(int min, int max)
{
    int choice;

    while (1)
    {
        choice = getInteger();

        if (choice >= min && choice <= max)
        {
            return choice;
        }

        printf("Invalid choice. Please enter a number between %d and %d: ",
               min, max);
    }
}


void employeeMenu()
{
    int choice;

    do
    {
        printf("\n");
        printf("========================================\n");
        printf("        EMPLOYEE MANAGEMENT\n");
        printf("========================================\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Search Employee\n");
        printf("4. Back to Main Menu\n");
        printf("========================================\n");

        printf("Enter your choice: ");
        choice = getMenuChoice(1, 4);

        switch (choice)
        {
            case 1:
                addEmployee();
                break;

            case 2:
                displayEmployees();
                break;

            case 3:
                searchEmployee();
                break;

            case 4:
                printf("\nReturning to main menu...\n");
                break;
        }

    } while (choice != 4);
}


void budgetMenu()
{
    int choice;

    do
    {
        printf("\n");
        printf("========================================\n");
        printf("          BUDGET MANAGEMENT\n");
        printf("========================================\n");
        printf("1. Add Budget\n");
        printf("2. Display Budget\n");
        printf("3. Calculate Budget Balance\n");
        printf("4. Check Exceeded Budget\n");
        printf("5. Back to Main Menu\n");
        printf("========================================\n");

        printf("Enter your choice: ");
        choice = getMenuChoice(1, 5);

        switch (choice)
        {
            case 1:
                addBudget();
                break;

            case 2:
                displayBudget();
                break;

            case 3:
            {
                int departmentId;

                printf("Enter Department ID: ");
                departmentId = getInteger();

                calculateBudgetBalance(departmentId);
                break;
            }

            case 4:
                checkExceed();
                break;

            case 5:
                printf("\nReturning to main menu...\n");
                break;
        }

    } while (choice != 5);
}


void supplierMenu()
{
    int choice;

    do
    {
        printf("\n");
        printf("========================================\n");
        printf("         SUPPLIER MANAGEMENT\n");
        printf("========================================\n");
        printf("1. Add Supplier\n");
        printf("2. Display Suppliers\n");
        printf("3. Search Supplier\n");
        printf("4. Compare Suppliers\n");
        printf("5. Back to Main Menu\n");
        printf("========================================\n");

        printf("Enter your choice: ");
        choice = getMenuChoice(1, 5);

        switch (choice)
        {
            case 1:
                addSupplier();
                break;

            case 2:
                displaySuppliers();
                break;

            case 3:
                searchSupplier();
                break;

            case 4:
                compareSuppliers();
                break;

            case 5:
                printf("\nReturning to main menu...\n");
                break;
        }

    } while (choice != 5);
}



void displayMenu()
{
    printf("\n");
    printf("=========================================\n");
    printf("   MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printf("=========================================\n");
    printf("1. Employee Management\n");
    printf("2. Budget Management\n");
    printf("3. Supplier Management\n");
    printf("4. Asset Management\n");
    printf("5. Reports\n");
    printf("6. Exit\n");
    printf("=========================================\n");
}



int main()
{
    int choice;

    do
    {
        displayMenu();

        printf("Enter your choice: ");
        choice = getMenuChoice(1, 6);

        switch (choice)
        {
            case 1:
                employeeMenu();
                break;

            case 2:
                budgetMenu();
                break;

            case 3:
                supplierMenu();
                break;

            case 4:
                /* Asset Management will be added */
                printf("\nAsset Management module coming soon.\n");
                break;

            case 5:
                /* Reports module will be added */
                printf("\nReports module coming soon.\n");
                break;

            case 6:
                printf("\nThank you for using the Municipal Financial Management System.\n");
                break;
        }

    } while (choice != 6);

    return 0;
}
