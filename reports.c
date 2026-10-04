#include <stdio.h>
#include "reports.h"
#include "employees.h"
#include "budget.h"
#include "suppliers.h"
#include "assets.h"

double calculateAverage(double salaries[], int total)
{
    double sum = 0;
    int i;

    if (total == 0)
    {
        return 0;
    }

    for (i = 0; i < total; i++)
    {
        sum = sum + salaries[i];
    }

    return sum / total;
}

int findHighest(double salaries[], int total)
{
    int highest = 0;
    int i;

    for (i = 1; i < total; i++)
    {
        if (salaries[i] > salaries[highest])
        {
            highest = i;
        }
    }

    return highest;
}

int findLowest(double salaries[], int total)
{
    int lowest = 0;
    int i;

    for (i = 1; i < total; i++)
    {
        if (salaries[i] < salaries[lowest])
        {
            lowest = i;
        }
    }

    return lowest;
}

void employeeReport()
{
    int high;
    int low;

    printf("\n========================================\n");
    printf("EMPLOYEE REPORT\n");
    printf("========================================\n");

    if (employeeCount == 0)
    {
        printf("No employees have been added yet.\n");
        return;
    }

    high = findHighest(grossSalaries, employeeCount);
    low = findLowest(grossSalaries, employeeCount);

    printf("Total Employees : %d\n", employeeCount);
    printf("Average Salary  : N$%.2f\n", calculateAverage(grossSalaries, employeeCount));
    printf("Highest Salary  : N$%.2f (%s)\n", grossSalaries[high], employeeNames[high]);
    printf("Lowest Salary   : N$%.2f (%s)\n", grossSalaries[low], employeeNames[low]);
}

void budgetReport()
{
    printf("\n========================================\n");
    printf("BUDGET REPORT\n");
    printf("========================================\n");

    displayBudget();
    checkExceed();
}

void supplierReport()
{
    printf("\n========================================\n");
    printf("SUPPLIER REPORT\n");
    printf("========================================\n");

    displaySuppliers();
}

void assetReport()
{
    printf("\n========================================\n");
    printf("ASSET REPORT\n");
    printf("========================================\n");

    displayALLAssets();
}

void displayReports()
{
    int choice;
    int result;
    int c;

    do
    {
        printf("\n========================================\n");
        printf("REPORTS\n");
        printf("========================================\n");
        printf("1. Employee Report\n");
        printf("2. Budget Report\n");
        printf("3. Supplier Report\n");
        printf("4. Asset Report\n");
        printf("5. Back to Main Menu\n");
        printf("Enter your choice: ");

        result = scanf("%d", &choice);

        if (result != 1)
        {
            printf("\nInvalid input. Please enter a number from 1 to 5.\n");
            c = getchar();
            while (c != '\n' && c != EOF)
            {
                c = getchar();
            }
            choice = 0;
        }
        else
        {
            switch (choice)
            {
                case 1:
                    employeeReport();
                    break;
                case 2:
                    budgetReport();
                    break;
                case 3:
                    supplierReport();
                    break;
                case 4:
                    assetReport();
                    break;
                case 5:
                    printf("\nReturning to main menu...\n");
                    break;
                default:
                    printf("\nInvalid choice. Please enter a number from 1 to 5.\n");
            }
        }
    } while (choice != 5);
}
