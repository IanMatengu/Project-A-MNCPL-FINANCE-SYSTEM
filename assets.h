#ifndef ASSETS_H
#define ASSETS_H

#define MAX_ASSETS 50
#define MAX_ASSET_NAME 50
#define MAX_ASSET_TYPE 50
#define MAX_DEPARTMENT 50
#define MAX_CONDITION 50

extern int assetID[MAX_ASSETS];
extern char assetName[MAX_ASSETS][MAX_ASSET_NAME];
extern char assetType[MAX_ASSETS][MAX_ASSET_TYPE];
extern double purchaseValue[MAX_ASSETS];
extern char assetDepartment[MAX_ASSETS][MAX_DEPARTMENT];
extern char assetCondition[MAX_ASSETS][MAX_CONDITION];
extern int assetCount;

void addAsset();
void displayAssets();
void searchAsset();

#endif
