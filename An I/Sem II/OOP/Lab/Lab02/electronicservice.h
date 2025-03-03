//
// Created by vladm on 3/12/2024.
//header file service pentru electrocasnice
#pragma once
#include "electronicrepository.h"
#ifndef LAB02_ELECTRONICSERVICE_H
#define LAB02_ELECTRONICSERVICE_H

#endif //LAB02_ELECTRONICSERVICE_H

/*
 * functie service pentru adaugarea unui electrocasnic in lista
 */
int addElectronicService(MyList* Electronics, int ID, char type[], char producer[], char model[], int price, int quantity);

/*
 * functie service de update pentru un electrocasnic din lista
 */
int updateElectronicService(MyList* Electronics, int ID, int price, int quantity);

/*
 * functie service de stergere a unui electrocasnic din lista
 */
int deleteElectronicService(MyList* Electronics, int ID);

/*
 * functie de actualizare a cantitatii unui electrocasnic de pe stoc
 */
int updateQuantity(MyList* Electronics, int ID, int quantity);