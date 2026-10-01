#include <stdio.h>
#include <string.h>
#include "employees.h"

int employeeCount = 0;
int employeeIDs[MAX_EMPLOYEES];
char employeeNames[MAX_EMPLOYEES][50];
char employeeDepartments[MAX_EMPLOYEES][50];
double basicSalaries[MAX_EMPLOYEES];
double housingAllowances[MAX_EMPLOYEES];
double transportAllowances[MAX_EMPLOYEES];
double grossSalaries[MAX_EMPLOYEES];

double calculateSalary(double basic, double housing, double transport)
{
    double gross;

    gross = basic + housing + transport;
    return gross;
}

void addEmployee()
{
    int i = employeeCount;

    if (employeeCount >= MAX_EMPLOYEES)
    {
        printf("\nThe employee list is full.\n");
        return;
    }

    printf("\n--- ADD EMPLOYEE ---\n");

    printf("Enter employee ID: ");
    scanf("%d", &employeeIDs[i]);

    printf("Enter employee name: ");
    scanf(" %49[^\n]", employeeNames[i]);

    printf("Enter department: ");
    scanf(" %49[^\n]", employeeDepartments[i]);

    printf("Enter basic salary: N$");
    scanf("%lf", &basicSalaries[i]);
    while (basicSalaries[i] < 0)
    {
        printf("Salary cannot be negative. Enter again: N$");
        scanf("%lf", &basicSalaries[i]);
    }

    printf("Enter housing allowance: N$");
    scanf("%lf", &housingAllowances[i]);
    while (housingAllowances[i] < 0)
    {
        printf("Allowance cannot be negative. Enter again: N$");
        scanf("%lf", &housingAllowances[i]);
    }

    printf("Enter transport allowance: N$");
    scanf("%lf", &transportAllowances[i]);
    while (transportAllowances[i] < 0)
    {
        printf("Allowance cannot be negative. Enter again: N$");
        scanf("%lf", &transportAllowances[i]);
    }

    grossSalaries[i] = calculateSalary(basicSalaries[i], housingAllowances[i], transportAllowances[i]);

    employeeCount++;

    printf("\nEmployee added. Gross salary: N$%.2f\n", grossSalaries[i]);
}

void displayEmployees()
{
    printf("\n--- EMPLOYEE LIST ---\n");

    if (employeeCount == 0)
    {
        printf("No employees have been added yet.\n");
        return;
    }

    for (int i = 0; i < employeeCount; i++)
    {
        printf("\nEmployee %d\n", i + 1);
        printf("ID         : %d\n", employeeIDs[i]);
        printf("Name       : %s\n", employeeNames[i]);
        printf("Department : %s\n", employeeDepartments[i]);
        printf("Basic      : N$%.2f\n", basicSalaries[i]);
        printf("Housing    : N$%.2f\n", housingAllowances[i]);
        printf("Transport  : N$%.2f\n", transportAllowances[i]);
        printf("Gross      : N$%.2f\n", grossSalaries[i]);
    }
}

void searchEmployee()
{
    char searchName[50];
    int found = 0;

    printf("\n--- SEARCH EMPLOYEE ---\n");

    printf("Enter employee name to search: ");
    scanf(" %49[^\n]", searchName);

    for (int i = 0; i < employeeCount; i++)
    {
        if (strcmp(employeeNames[i], searchName) == 0)
        {
            found = 1;
            printf("\nEmployee found.\n");
            printf("ID         : %d\n", employeeIDs[i]);
            printf("Name       : %s\n", employeeNames[i]);
            printf("Department : %s\n", employeeDepartments[i]);
            printf("Gross      : N$%.2f\n", grossSalaries[i]);
        }
    }

    if (found == 0)
    {
        printf("Employee not found.\n");
    }
}

void employeeMenu()
{
    int choice;

    do
    {
        printf("\n========================================\n");
        printf("EMPLOYEE MANAGEMENT\n");
        printf("========================================\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Search Employee\n");
        printf("4. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

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
            default:
                printf("\nInvalid choice. Please enter 1 to 4.\n");
        }
    } while (choice != 4);

    return 0;
}

