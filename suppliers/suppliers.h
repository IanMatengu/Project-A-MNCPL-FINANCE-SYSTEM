#ifndef SUPPLIERS_H
#define SUPPLIERS_H

#define MAX_SUPPLIERS 100

typedef struct {
    char supplierID[20];
    char supplierName[100];
    char email[100];
    char telephone[30];
    char town[50];
} Supplier;

void addSupplier();
void displaySuppliers();
void searchSupplier();
void compareSuppliers();

#endif