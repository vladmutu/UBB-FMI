//
// Created by vladm on 3/12/2024.
//header file service pentru electrocasnice
#pragma once
#include "electronicrepository.h"
#include <stdbool.h>

typedef struct {
	MyList* Electronics;
	MyList* UndoList;
} ListManager;

/*
functie de creare al unui manager de liste generice
*/
ListManager createListManager();

/*
* functie destroy pentru un ListManager
*/
void destroyListManager(ListManager* manager);

/*
 * functie service pentru adaugarea unui electrocasnic in lista
 */
int addElectronicService(ListManager* manager, int ID, char* type, char* producer, char* model, int price, int quantity);

/*
 * functie service de update pentru un electrocasnic din lista
 */
int updateElectronicService(ListManager* manager, int ID, int price, int quantity);

/*
 * functie service de stergere a unui electrocasnic din lista
 */
int deleteElectronicService(ListManager* manager, int ID);

/*
 * functie de actualizare a cantitatii unui electrocasnic de pe stoc
 */
void updateQuantity(ListManager* manager, int ID, int quantity);

/*
 * functie de sortare a electrocasnicelor dupa pret crescator
 */
MyList* sortElectronicsPriceAscending(MyList* Electronics);

/*
 * functie de sortare a electrocasnicelor dupa pret descrescator
 */
MyList* sortElectronicsPriceDescending(MyList* Electronics);

/*
 * functie de sortare a electrocasnicelor dupa cantitate crescator
 */
MyList* sortElectronicsQuantityAscending(MyList* Electronics);

/*
 * functie de sortare a electrocasnicelor dupa cantitate descrescator
 */
MyList* sortElectronicsQuantityDescending(MyList* Electronics);

/*
* functie de filtrare a electrocasnicelor dupa un anumit producator
*/
MyList* filterElectronicsByProducer(MyList* Electronics, char* producer);

/*
* functie de filtrare a electrocasnicelor dupa un anumit pret
*/
MyList* filterElectronicsByPrice(MyList* Electronics, int price);

/*
 * functie de filtrare a electrocasnicelor dupa o anumita cantitate
 */
MyList* filterElectronicsByQuantity(MyList* Electronics, int quantity);

/*
* functie de comparare a preturilor a doua electrocasnice
*/
bool cmpPriceAscending(Electronic* elem1, Electronic* elem2);

/*
* functie de comparare a preturilor a doua electrocasnice
*/
bool cmpPriceDescending(Electronic* elem1, Electronic* elem2);

/*
* functie de comparare a cantitatilor a doua electrocasnice
*/
bool cmpQuantityAscending(Electronic* elem1, Electronic* elem2);

/*
* functie de comparare a cantitatilor a doua electrocasnice
*/
bool cmpQuantityDescending(Electronic* elem1, Electronic* elem2);

/*
* functie service de undo
*/
int undoService(ListManager* manager);
