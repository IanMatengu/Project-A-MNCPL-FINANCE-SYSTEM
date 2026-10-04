#include <stdio.h>
#include <string.h>
#include <assests.h>

int assetID[50];
char assetName[50][50];
char assetType[50][50];
double purchaseValue[50];
char assetDepartment[50][50];
char assetCondition[50][50];
int assetCount = 0;

void addAsset() {
    if (assetCount >= 50) {
    printf("Error: Cannot add more than 50 assets.\n");
    return;
    }
    
    printf("Enter Asset ID: ");
    scanf("%d", &assetID[assetCount]);
    
    while (getchar() != '\n');
    do{
    printf("Enter Asset Name: ");
    fgets(assetName[assetCount], sizeof(assetName[assetCount]), stdin);
    assetName[assetCount][strcspn(assetName[assetCount], "\n")] = '\0';

    if (strlen(assetName[assetCount]) == 0) {
    printf("Asset Name cannot be left blank. Please try again.\n");
        }
    }

    while (strlen(assetName[assetCount]) == 0);
    do {
    printf("Enter Asset Type: ");
    fgets(assetType[assetCount], sizeof(assetName[assetCount]), stdin);
    assetType[assetCount][strcspn(assetType[assetCount], "\n")] = '\0';

    if (strlen(assetType[assetCount]) == 0) {
    printf("Asset Type cannot be left blank. Please try again.\n");
        }
    } 
    
    while (strlen(assetType[assetCount]) == 0);
    do {
    printf("Enter Purchase Value: ");
    scanf("%lf", &purchaseValue[assetCount]);
    
    while(getchar() != '\n');
     if (purchaseValue[assetCount] < 0) {
    printf("Validation Error: Purchase Value cannot be negative. Try again.\n");
        }
    }
        
    while (purchaseValue[assetCount] < 0);
    do {
    printf("Enter Department: ");
    fgets(assetDepartment[assetCount], sizeof(assetDepartment[assetCount]), stdin);
    assetDepartment[assetCount][strcspn(assetDepartment[assetCount], "\n")] = '\0';

    if (strlen(assetDepartment[assetCount]) == 0) {
    printf("Department cannot be left blank. Please try again.\n");
        }
    }
        
    while (strlen(assetDepartment[assetCount]) == 0);
    do {
    printf("Enter Condition: ");
    fgets(assetCondition[assetCount], sizeof(assetCondition[assetCount]), stdin);
    assetCondition[assetCount][strcspn(assetCondition[assetCount], "\n")] = '\0';

    if (strlen(assetCondition[assetCount]) == 0) {
    printf("Condition cannot be left blank. Please try again.\n");

        }
    } while (strlen(assetCondition[assetCount]) == 0);
        
    assetCount++;
    printf("Asset added successfully!\n");
}

void displayAssets() {
    if (assetCount == 0) {
        printf("No assets registered yet. \n");
        return;
    }

    printf("\n--- MUNICIPAL ASSET REPORT ---\n");
    for (int i = 0; i < assetCount; i++) {
        
        printf("Asset ID: %d\n", assetID[i]);
        printf("Name: %s\n", assetName[i]);
        printf("Type: %s\n", assetType[i]);
        printf("Purchase Value: N$ %.2f\n", purchaseValue[i]);
        printf("Department: %s\n", assetDepartment[i]),
        printf("Condition: %s\n", assetCondition[i]),
        printf("-------------------------\n");
    }
}

void searchAsset() {
    char searchName[50];
    int found = 0;

    printf("Enter asset name to search: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0';

    for (int i = 0; i < assetCount; i++) {
        if (strcmp(assetName[i], searchName) == 0) {
            printf("\nAsset Found!\n");
            printf("Asset ID: %d\n", assetID[i]);
            printf("Name: %s\n", assetName[i]);
            printf("Type: %s\n", assetType[i]);
            printf("Purchase Value: N$ %.2f\n", purchaseValue[i]);
            printf("Department: %s\n", assetDepartment[i]);
            printf("Condition: %s\n", assetCondition[i]);
            found = 1;
        }
    }

    if (found == 0) {
        printf("Asset not found in the system.\n");
    }
}
