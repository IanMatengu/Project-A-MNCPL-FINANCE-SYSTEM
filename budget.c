#include <stdio.h>
#include "budget.h"

char categories[100][50];
float amounts[100];
int count = 0;

void addBudget() {
    printf("Enter Category: ");
    scanf("%s", categories[count]);
    printf("Enter Amount: ");
    scanf("%f", &amounts[count]);
    count++;
    printf("Budget Added!\n");
}

void viewBudgets() {
    int i;
    if (count == 0) {
        printf("No budgets yet!\n");
        return;
    }
    for (i = 0; i < count; i++) {
        printf("%d. %s - %.2f\n", i+1, categories[i], amounts[i]);
    }
}

void budgetMenu() {
    int choice;
    while (1) {
        printf("\n Budget Menu \n");
        printf("1. Add Budget\n");
        printf("2. View Budgets\n");
        printf("3. Exit\n");
        printf("Choose: ");
        scanf("%d", &choice);
        if (choice == 1) addBudget();
        else if (choice == 2) viewBudgets();
        else if (choice == 3) break;
    }
}