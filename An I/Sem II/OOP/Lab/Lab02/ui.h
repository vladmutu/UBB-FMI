//
// Created by vladm on 3/12/2024.
//header file pentru UI
#pragma once
#include "electronicservice.h"
#include "electronicrepository.h"
#include "electronic.h"
#ifndef LAB02_UI_H
#define LAB02_UI_H

#endif //LAB02_UI_H

/*
 * functie de citire a parametrilor unui electronic
 */
void readElectronic(MyList* Electronics);

/*
 * functi de citire a parametrilor pret si cantitate ai unui electronic pentru update
 */
void readElectronicForUpdate(MyList* Electronics);

/*
 * functie de citire a parametrilor unui electronic pentru stergere
 */
void readElectronicForDeletion(MyList* Electronics);

/*
 * functie de afisare a tuturor electronicelor
 */
void printAllElectronics(MyList* Electronics);

/*
 * functie de pornire a programului
 */
void run();