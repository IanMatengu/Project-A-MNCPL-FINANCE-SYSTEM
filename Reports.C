#include <stdio.h>

int employeeCount = 3;
char employeeNames[50][50] = {"John", "Maria", "Peter"};
double grossSalaries[50] = {1300.00, 2500.00, 1800.00};

int assetCount = 2;
char assetName[50][50] = {"Chair", "Desk"};
double purchaseValue[50] = {500.00, 1500.00};

void displayBudget()
{
    printf("\nDepartment: Finance (ID:1)\n");
    printf("Allocated: 50000.00\n");
    printf("Expenditure: 42000.00\n");
    printf("Remaining: 8000.00\n");
    printf("Status: WITHIN BUDGET\n");
}

void checkExceed()
{
    printf("\nDepartments that EXCEEDED budget\n");
    printf("None - All within budget\n");
}

void displaySuppliers()
{
    printf("\n========== SUPPLIER LIST ==========\n");
    printf("\nSupplier 1\n");
    printf("Supplier ID: S1\n");
    printf("Supplier Name: Acme\n");
    printf("Email: acme@mail.com\n");
    printf("Telephone: 061123456\n");
    printf("Town/Location: Windhoek\n");
    printf("\n===================================\n");
}

#ifndef REPORTS_H
#define REPORTS_H

void displayReports(void);
void employeeReport(void);
void budgetReport(void);
void supplierReport(void);
void assetReport(void);
double calculateAverage(double salaries[], int total);
int findHighest(double salaries[], int total);
int findLowest(double salaries[], int total);

#endif

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

void employeeReport(void)
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

void budgetReport(void)
{
    printf("\n========================================\n");
    printf("BUDGET REPORT\n");
    printf("========================================\n");

    displayBudget();
    checkExceed();
}

void supplierReport(void)
{
    printf("\n========================================\n");
    printf("SUPPLIER REPORT\n");
    printf("========================================\n");

    displaySuppliers();
}

void assetReport(void)
{
    int high;
    int low;
    int i;
    double total = 0;

    printf("\n========================================\n");
    printf("ASSET REPORT\n");
    printf("========================================\n");

    if (assetCount == 0)
    {
        printf("No assets have been added yet.\n");
        return;
    }

    for (i = 0; i < assetCount; i++)
    {
        total = total + purchaseValue[i];
    }

    high = findHighest(purchaseValue, assetCount);
    low = findLowest(purchaseValue, assetCount);

    printf("Total Assets   : %d\n", assetCount);
    printf("Total Value    : N$%.2f\n", total);
    printf("Average Value  : N$%.2f\n", calculateAverage(purchaseValue, assetCount));
    printf("Highest Value  : N$%.2f (%s)\n", purchaseValue[high], assetName[high]);
    printf("Lowest Value   : N$%.2f (%s)\n", purchaseValue[low], assetName[low]);
}

void displayReports(void)
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
        printf("4. Back to Main Menu\n");
        printf("Enter your choice: ");

        result = scanf("%d", &choice);

        if (result == EOF)
        {
            choice = 4;
        }
        else if (result != 1)
        {
            printf("\nInvalid input. Please enter a number from 1 to 4.\n");
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
                    printf("\nReturning to main menu...\n");
                    break;
                default:
                    printf("\nInvalid choice. Please enter a number from 1 to 4.\n");
            }
        }
    } while (choice != 4);
}

int main()
{
    employeeReport();
    budgetReport();
    supplierReport();
    assetReport();

    printf("\nAll reports displayed.\n");
    return 0;
}
