#1. Employee Management Module #
## Test 1: Add, Display and Search Employees ##
## Objective ##
To verify that calculateSalary() returns basic + housing + transport, and that addEmployee(), displayEmployees() and searchEmployee() store, list and find employees correctly.

Test Command
gcc main.c employees.c -o employeestest
./employeestest

## Expected Result ## 

The driver line prints N$20000.00. The gross salaries are N$13000.00 and N$10000.00. Both employees are listed and the search finds Ian Matengu.

## Result ##
PASS

## Evidence ##
<img width="1366" height="768" alt="Screenshot_2026-10-04_14-08-32" src="https://github.com/user-attachments/assets/e3603110-66b9-4a8f-927b-69e194f0648b" />
<img width="1366" height="768" alt="Screenshot_2026-10-04_14-08-53" src="https://github.com/user-attachments/assets/92794a1e-05a6-4411-8fd6-7a618fb141d0" />

## Test 2: Negative Salary and allowance Validation ##
## Objective ## 

To verify that addEmployee() rejects negative salary and allowance values and asks for them again.

## Result ##
PASS

## Evidence ##
<img width="1366" height="768" alt="Screenshot_2026-10-19_15-06-22" src="https://github.com/user-attachments/assets/54af1772-9e7e-4e74-8623-2080174429ef" />
<img width="1366" height="768" alt="Screenshot_2026-10-19_15-13-09" src="https://github.com/user-attachments/assets/126bb3c2-f42b-4a23-b7dc-b31cab208cc7" />

<img width="1366" height="768" alt="Screenshot_2026-10-19_15-13-35" src="https://github.com/user-attachments/assets/14d17057-0397-4781-987c-5465fff67fde" />

## Test 3: Search for an Employee that does not exist ##
## Objective ## 

To see that searchEmployee() reports correctly when the name entered is not in the list.

## Expected result ##

The system should display: Employee not found 

## Result ##

## Evidence ##
<img width="1366" height="768" alt="Screenshot_2026-10-19_15-23-31" src="https://github.com/user-attachments/assets/f6b9c41f-2579-465b-9b0a-8e0912a5cbc2" />




