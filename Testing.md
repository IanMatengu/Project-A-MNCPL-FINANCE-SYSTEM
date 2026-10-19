# 1. Employee Management Module #
## Test 1: Add, Display and Search Employees ##
## Objective ##
To verify that calculateSalary() returns basic + housing + transport, and that addEmployee(), displayEmployees() and searchEmployee() store, list and find employees correctly.

## Test Command ##
``gcc main.c employees.c -o employeestest
./employeestest``

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
<img width="1366" height="768" alt="Screenshot_2026-10-19_15-59-52" src="https://github.com/user-attachments/assets/2eace123-b579-4748-82fd-f8cedbe84f7d" />
<img width="1366" height="768" alt="Screenshot_2026-10-19_16-00-09" src="https://github.com/user-attachments/assets/c2af58ef-005c-4888-8a7e-7e0fa2963dd0" />

<img width="1366" height="768" alt="Screenshot_2026-10-19_16-00-19" src="https://github.com/user-attachments/assets/eb4a2411-9e93-469f-a621-dd9317fe87fe" />

## Test 2: Search is Case sensitive ##
## Objective ##
To check whether searchAssetByName() finds an asset when the name is typed in a different letter case. 

## Expected Output ##
Search should not care whether the use of uppercase or lowercase letters when looking for an asset and should find them regardless.

## Result ##
FAIL: laptop and TRUCK are not found. Names must be typed exactly as entered. search makes use of strcmp.

## Evidence ##

<img width="1366" height="768" alt="Screenshot_2026-10-19_16-14-47" src="https://github.com/user-attachments/assets/eeb34456-ad65-4c05-9067-307e7321b26b" />
<img width="1366" height="768" alt="Screenshot_2026-10-19_16-14-52" src="https://github.com/user-attachments/assets/a041da04-66eb-4114-bf54-a89ff7f763e2" />

## Test 3: Text longer than the field size ##
## Objective ##

To verify what happens when an asset name is longer than the 50 words/characters

## Expected Result ##
Name should be cut at the limit and the other fields should stay correct

## Result ##

Fail: The name is not cut or doesnt appear to be, and the leftover characters become the Asset Type and every later field moves one place, so the purchase value is 0.00 

## Evidence ##
<img width="1366" height="768" alt="Screenshot_2026-10-19_16-27-16" src="https://github.com/user-attachments/assets/86107a37-1df8-4d21-9be5-22fc37d7ddb4" />

# 3. Budget Module #

## Test 1: Add a budget that is within budget ##

## Objective ##

To verify hat addBudget() stores a department budget, stores department budget, and that displayBudget(), checkExceed() and calculateBudgetBalance() report it correctly.

## Test Command ##
`` gcc main.c budget.c -o budgettest
./budgettest``

## Expected Result ##
Remaining is N$ 20000.00, the status is WITHIN BUDGET , checkExceddd() prints NONE - all within budget and the balance is N$ 20000.00
## Result ##
PASS
## Evidence ## 
<img width="1366" height="768" alt="Screenshot_2026-10-19_16-43-48" src="https://github.com/user-attachments/assets/75113390-ea19-46a3-b160-3af3551cdf4e" />

## Test 2: Add a budget that has been exceedeed ##

## Objective ##

To verify that a department whose expenditure is higher than the its allocation is flagged as exceeded.

## Expected Result ##

Remaining Balance is -5000.50, the status is EXCEEDED BUDGET, checkExceed() lists Roads as over by 5000.50 and the balance is -5000.50

## Result ## 
PASS

## Evidence ##
<img width="1366" height="768" alt="Screenshot_2026-10-19_16-52-30" src="https://github.com/user-attachments/assets/2b9cceb5-e9cc-4562-8ca5-39108edae9cf" />

## Test 3: Negative allocated budget is rejected ##

## Objective ##
To verify that addbudget() refuses a negative allocated budget and does not save the record

## Expected Result ## 
System should display Error: Negative budget not accepted and 'No budget items to display. System should dsiplay Department ID 1 not found!. 
## Result ##
PASS
##Evidence ## 
<img width="1366" height="768" alt="Screenshot_2026-10-19_17-01-10" src="https://github.com/user-attachments/assets/cc0f2624-cc35-486d-b616-f6aab353efac" />


## Test 4: Empty department name is rejected ##

## Objective ## 

To verify that addBudget() refuses to accept an empty department name

## Expected result ##
System displays 'Error: Department Name cannot be empty.'

## Result ## 

PASS

## Evidence ## 
<img width="1366" height="768" alt="Screenshot_2026-10-19_17-05-58" src="https://github.com/user-attachments/assets/5d96df94-c71b-4fc8-8dcc-3c63d95fab2b" />
# 4. Supplier Module #

## Test 1: Add, Display, Search and Compare suppliers ##

## Objective ##
To verify that addSupplier() stores suppliers, displaySuppliers() list them, searchSupplier() finds one by name, and compareSuppliers() shows two suppliers comparatively.

## Test command ##
`` gcc main.c suppliers.c -o supplierstest
./supplierstest``

## Expected Result ## 

Both suppliers are listed. The search finds WHK suppliers. The comparison shows SWK suppliers as supplier 1 and WHK suppliers as supplier 2 

## Result ##
PASS

## Evidence ##
<img width="1366" height="768" alt="Screenshot_2026-10-19_19-12-18" src="https://github.com/user-attachments/assets/a1c9e154-e417-4516-8d1a-82f026052aa6" />

<img width="1366" height="768" alt="Screenshot_2026-10-19_19-12-30" src="https://github.com/user-attachments/assets/3951c0a1-d96c-453e-8420-6bd8ce337069" />

## Test 2: Search and compare with a supplier that does not exist

## Objective ## 
To verify that search Supplier() and compareSupliers() report correctlty when a supplier name is not found

## Expected Result ##

Search should print 'Supplier not Found' and the comparison prints 'One or both suppliers were not found'

## Result ## 
PASS

## Evidence ##



<img width="1366" height="768" alt="Screenshot_2026-10-19_19-26-35" src="https://github.com/user-attachments/assets/8cb26137-995e-46a9-a4a1-a56c724632b2" />

<img width="1366" height="768" alt="Screenshot_2026-10-19_19-26-42" src="https://github.com/user-attachments/assets/79b3dcb7-d27e-4d2d-be60-93352786131f" />


## Test 3: Empty field is rejected ##

## Objective ##

To see whether addSupplier() rejects an empty supplier name and does not save the record.

## Expected Result ##

First attempt should print Supplier name cannot be empty. Only the second supplier appears in the list.

## Result ##

PASS

## Evidence ##
<img width="1366" height="768" alt="Screenshot_2026-10-19_19-36-22" src="https://github.com/user-attachments/assets/661a1ab5-81cb-480c-b5b8-2d5b9bf5846d" />

# 5. Reports Module #

<!--## Test 1: Helper Functions : Average, highest and lowest ##

## Objective ##

To unit test calculateAverage() , findHighest() and findLowest() directly with known arrays, including single value, tied values and an empty array.

## Test Command ##

`` gcc main.c 

-->

## Test 2: Report Menu: All four reports ##

## Objective ##

To verify that displayReports() calls the employee, budget, supplier and asset reports correctly and returns when option 5 is chosen 
## Test Command ##

`` gcc main.c reports.c employees.c assets.c budget.c suppliers.c -o reporttest
./reporttest``

## Expected Result ##
Employee report: 2 employees , average N$ 11500.00, highest N$ 13000.00 (Nelisiwe),lowest N$10000.00 (Luvinga). Budget report: health exceeded by 10000.00. supplier and asset reports list their records. Option 5 prints Returning to main menu.

## Result ##
PASS

## Evidence ##
<img width="1366" height="768" alt="Screenshot_2026-10-19_20-09-41" src="https://github.com/user-attachments/assets/8e14d187-c5f7-4469-9cff-8f29081b7545" />
<img width="1366" height="768" alt="Screenshot_2026-10-19_20-10-47" src="https://github.com/user-attachments/assets/2c517d70-1945-40ba-b346-493dd1abd80e" />
<img width="1366" height="768" alt="Screenshot_2026-10-19_20-09-47" src="https://github.com/user-attachments/assets/b6314f22-4eb0-4c58-a2e0-8e214888dac3" />


<img width="1366" height="768" alt="Screenshot_2026-10-19_20-11-33" src="https://github.com/user-attachments/assets/6f1f777b-5b4b-4cee-b7ca-3b2dcae65fe8" />
<img width="1366" height="768" alt="Screenshot_2026-10-19_20-11-54" src="https://github.com/user-attachments/assets/b73b1100-df4d-4a43-806d-10bb653f2b8a" />

<img width="1366" height="768" alt="Screenshot_2026-10-19_20-12-03" src="https://github.com/user-attachments/assets/31824d34-4f6c-493e-a86c-74ac8f1a6ddc" />

## Test 3: Report Menu: Invalid Input ##

## Objective ##

To see that displayReports() handles letters and out of range numbers without crashing or looping 

## Expected result ## 

abc prints invalid input. Please enter a number from 1 to 5. pressing 9 gives output "invalid choice".
Menu should continue as normal

## Result ##
PASS

## Evidence ## 
<img width="1366" height="768" alt="Screenshot_2026-10-19_20-26-39" src="https://github.com/user-attachments/assets/99d14ca9-b6ee-4248-9f8c-b51c0fda1d17" />


