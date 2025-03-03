//
// Created by vladm on 3/12/2024.
//header file pentru UI
#pragma once
#include "electronicservice.h"
#include "electronicrepository.h"
#include "electronic.h"

/*
 * functie de citire a parametrilor unui electronic
 */
void readElectronic(ListManager* manager);

/*
 * functi de citire a parametrilor pret si cantitate ai unui electronic pentru update
 */
void readElectronicForUpdate(ListManager* manager);

/*
 * functie de citire a parametrilor unui electronic pentru stergere
 */
void readElectronicForDeletion(ListManager* manager);

/*
 * functie de afisare a tuturor electronicelor
 */
void printAllElectronics(MyList* Electronics);

/*
* functie de afisare a tuturor electronicelor sortate dupa pret
*/
void printAllSortedByPrice(ListManager* manager);

/*
* functie de afisare a tuturor electronicelor sortate dupa cantitate
*/
void printAllSortedByQuantity(ListManager* manager);

/*
* functie de afisare a tuturor electronicelor filtrate
*/
void printAllFiltered(ListManager* manager);

/*
* functie ui de undo
*/
void undo(ListManager* manager);

/*
 * functie de pornire a programului
 */
void run();
