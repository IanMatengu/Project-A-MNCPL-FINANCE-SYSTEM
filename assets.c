#include <stdio.h>
#include <string.h>

int assetID[50];
char assetName[50][50];
char assetType[50][50];
double purchaseValue[50];
char assetDepartment[50][50];
char assetCondition[50][50];
int assetCount = 0;

void addAsset() {
    printf("Enter Asset ID: ");
    scanf("%d", &assetID[assetCount]);
    while (getchar() != '\n');

    printf("Enter Asset Name: ");
    fgets(assetName[assetCount], sizeof(assetName[assetCount]), stdin);
    assetName[assetCount][strcspn(assetName[assetCount], "\n")] = '\0';

    printf("Enter Asset Type: ");
    fgets(assetType[assetCount], sizeof(assetName[assetCount]), stdin);
    assetType[assetCount][strcspn(assetType[assetCount], "\n")] = '\0';

    printf("Enter Purchase Value: ");
    scanf("%lf", &purchaseValue[assetCount]);
    while(getchar() != '\n');

    printf("Enter Department: ");
    fgets(assetDepartment[assetCount], sizeof(assetDepartment[assetCount]), stdin);
    assetDepartment[assetCount][strcspn(assetDepartment[assetCount], "\n")] = '\0';

    printf("Enter Condition: ");
    fgets(assetCondition[assetCount], sizeof(assetCondition[assetCount]), stdin);
    assetCondition[assetCount][strcspn(assetCondition[assetCount], "\n")] = '\0';

    assetCount++;
    printf("Asset added successfully!\n");
}

void displayALLAssets() {
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

void searchAssetByName() {
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


