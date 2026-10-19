# 1. Employee Management Module #
## Test 1: Add, Display and Search Employees ##
## Objective ##
To verify that calculateSalary() returns basic + housing + transport, and that addEmployee(), displayEmployees() and searchEmployee() store, list and find employees correctly.

## Test Command ##
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


<img width="1366" height="768" alt="Screenshot_2026-10-19_15-23-39" src="https://github.com/user-attachments/assets/d406a238-75b0-4b33-95e3-9b5d8e25bd27" />


## Test 4: Non-numeric salary input ##

## objective ## 

To check how addEmployee() behave when letters are typed where a number is expecrted. 

## Expected Result ##
The system should ask for a letter and ask for a number again.

## Resullt## 
FAIL: The letters are not rejected. The salary and allowance are stored as 0.00 and the employee is added.

## Evidence ##
<img width="1366" height="768" alt="Screenshot_2026-10-19_15-34-23" src="https://github.com/user-attachments/assets/4aae41dc-f450-42c7-83d0-f7a13c4f34af" />
<img width="1366" height="768" alt="Screenshot_2026-10-19_15-34-30" src="https://github.com/user-attachments/assets/792b40e5-1b50-4581-b5cc-0f7f23968c66" />


# 2. Asset Management Module# 
## Test 1: Add, display and search Assets ##
## Objective ##
To verify that addAsset() stores asset details, displaysALLAssets() lists them, and searchAssetBYName() finds an existing asset and reports one that does not exist.

## Test command ## 
``gcc main.c assets.c -o assettest 
./assettest``


## Expected Result ## 
Both assets are listed with values to 2 decimal places. Searching Laptop shows the asset. Searching Lorry shows asset not found.

## Result ##

Pass

## evidence ##
<img width="1366" height="768" alt="Screenshot_2026-10-19_15-59-52" src="https://github.com/user-attachments/assets/2eace123-b579-4748-82fd-f8cedbe84f7d" /><img width="1366" height="768" alt="Screenshot_2026-10-19_16-00-19" src="https://github.com/user-attachments/assets/eb4a2411-9e93-469f-a621-dd9317fe87fe" />
<img width="1366" height="768" alt="Screenshot_2026-10-19_16-00-09" src="https://github.com/user-attachments/assets/c2af58ef-005c-4888-8a7e-7e0fa2963dd0" />



