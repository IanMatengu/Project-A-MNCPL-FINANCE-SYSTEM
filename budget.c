#include <stdio.h>
#include <string.h>
#include "budget.h"

static Budget budgets[MAX_BUDGETS];
static int count = 0;

void addBudget() {
    if (count >= MAX_BUDGETS) {
        printf("Budget storage full!\n");
        return;
    }
    Budget b;
    printf("Enter Department ID: ");
    scanf("%d", &b.departmentId);
    getchar();
    printf("Enter Department Name: ");
    fgets(b.departmentName, MAX_NAME_LEN, stdin);
    b.departmentName[strcspn(b.departmentName, "\n")] = 0;
    if (strlen(b.departmentName) == 0) {
        printf("Error: Department name cannot be empty.\n");
        return;
    }
    printf("Enter Allocated Budget: ");
    scanf("%f", &b.allocatedBudget);
    if (b.allocatedBudget < 0) {
        printf("Error: Negative budget not accepted.\n");
        return;
    }
    printf("Enter Expenditure: ");
    scanf("%f", &b.expenditure);
    if (b.expenditure < 0) {
        printf("Error: Negative expenditure not accepted.\n");
        return;
    }
    budgets[count++] = b;
    printf("Budget added!\n");
}

void displayBudget() {
    int i;
    if (count == 0) {
        printf("No budgets to display.\n");
        return;
    }
    for ( i = 0; i < count; i++) {
        float remaining = budgets[i].allocatedBudget - budgets[i].expenditure;
        printf("\nDepartment: %s (ID:%d)\n", budgets[i].departmentName, budgets[i].departmentId);
        printf("Allocated: %.2f\n", budgets[i].allocatedBudget);
        printf("Expenditure: %.2f\n", budgets[i].expenditure);
        printf("Remaining: %.2f\n", remaining);
        if (budgets[i].expenditure <= budgets[i].allocatedBudget) {
            printf("Status: WITHIN BUDGET\n");
        } else {
            printf("Status: EXCEEDED BUDGET\n");
        }
    }
}

float calculateBudgetBalance(int departmentId) {
    int i;
    for ( i = 0; i < count; i++) {
        if (budgets[i].departmentId == departmentId) {
            float remaining = budgets[i].allocatedBudget - budgets[i].expenditure;
            printf("Department %s Remaining: %.2f\n", budgets[i].departmentName, remaining);
            return remaining;
        }
    }
    printf("Department ID %d not found!\n", departmentId);
    return 0;
}

void checkExceed() {
    printf("\nDepartments that EXCEEDED budget\n");
    int i;
    int found = 0;
    for ( i = 0; i < count; i++) {
        if (budgets[i].expenditure > budgets[i].allocatedBudget) {
            printf("%s (ID:%d) - Allocated: %.2f, Spent: %.2f, Over: %.2f\n",
                   budgets[i].departmentName, budgets[i].departmentId,
                   budgets[i].allocatedBudget, budgets[i].expenditure,
                   budgets[i].expenditure - budgets[i].allocatedBudget);
            found = 1;
        }
    }
    if (found == 0) printf("None - All within budget\n");
}
