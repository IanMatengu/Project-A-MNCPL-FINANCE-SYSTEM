#ifndef EMPLOYEES_H
#define EMPLOYEES_H

#define MAX_EMPLOYEES 50

extern int employeeCount;
extern int employeeIDs[MAX_EMPLOYEES];
extern char employeeNames[MAX_EMPLOYEES][50];
extern char employeeDepartments[MAX_EMPLOYEES][50];
extern double basicSalaries[MAX_EMPLOYEES];
extern double housingAllowances[MAX_EMPLOYEES];
extern double transportAllowances[MAX_EMPLOYEES];
extern double grossSalaries[MAX_EMPLOYEES];


void addEmployee();
void displayEmployees();
void searchEmployee();
double calculateSalary(double basic, double housing, double transport);

#endif
