#ifndef BUDGET_H
#define BUDGET_H

#define MAX_BUDGETS 100
#define MAX_NAME_LEN 50

typedef struct {
    int departmentId;
    char departmentName[MAX_NAME_LEN];
    float allocatedBudget;
    float expenditure;
} Budget;

void addBudget();
void displayBudget();
float calculateBudgetBalance(int departmentId);
void checkExceed();

#endif
