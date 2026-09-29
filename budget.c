#include <stdio.h>
#include <string.h>
#include "budget.h"

char departments[100][50];
float allocated[100];
float expenditure[100];
int count = 0;

void budgetMenu() {
    int choice;
    do {
        printf("\n BUDGET MANAGEMENT \n");
        printf("1. Enter departmental budget\n");
        printf("2. Enter expenditure\n");
        printf("3. Display budget information\n");
        printf("4. Identify exceeded budgets\n");
        printf("0. Back\n");
        printf("Choice: ");
        scanf("%d", &choice);

        if(choice == 1) enterBudget();
        else if(choice == 2) enterExpenditure();
        else if(choice == 3) displayBudget();
        else if(choice == 4) checkExceeded();

    } while(choice!= 0);
}

void enterBudget() {
    printf("Department: ");
    scanf("%s", departments[count]);
    printf("Allocated Budget: N$");
    scanf("%f", &allocated[count]);
    expenditure[count] = 0;
    count++;
    printf("Budget added!\n");
}

void enterExpenditure() {
    char dept[50];
    printf("Department: ");
    scanf("%s", dept);
    for(int i=0; i<count; i++) {
        if(strcmp(departments[i], dept) == 0) {
            printf("Expenditure: N$");
            float exp;
            scanf("%f", &exp);
            expenditure[i] += exp;
            printf("Expenditure added!\n");
            return;
        }
    }
    printf("Department not found!\n");
}

void displayBudget() {
    for(int i=0; i<count; i++) {
        float remaining = allocated[i] - expenditure[i];
        printf("\nDepartment: %s\n", departments[i]);
        printf("Allocated Budget: N$%.2f\n", allocated[i]);
        printf("Expenditure: N$%.2f\n", expenditure[i]);
        printf("Remaining Budget: N$%.2f\n", remaining);
        if(expenditure[i] <= allocated[i]) {
            printf("Status: WITHIN BUDGET\n");
        } else {
            printf("Status: EXCEEDED BUDGET\n");
        }
    }
}

void checkExceeded() {
    printf("\n Departments that EXCEEDED budget \n");
    int found = 0;
    for(int i=0; i<count; i++) {
        if(expenditure[i] > allocated[i]) {
            printf("%s - Allocated: N$%.2f, Spent: N$%.2f\n", departments[i], allocated[i], expenditure[i]);
            found = 1;
        }
    }
    if(found == 0) printf("None - All within budget\n");
}
