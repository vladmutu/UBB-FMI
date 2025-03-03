//
// Created by vladm on 3/12/2024.
//header file pentru definirea TAD Electrocasnic
#pragma once
#ifndef LAB02_ELECTRONIC_H
#define LAB02_ELECTRONIC_H

#endif //LAB02_ELECTRONIC_H

/*
 * functie de definire a unui eletrocasnic
 */
typedef struct {
    char* type;
    char* producer;
    char* model;
    int ID;
    int price;
    int quantity;
}Electronic;

/*
 * functie de creare a unui electrocasnic
 */
Electronic* createElectronic(int ID, char* type, char* producer, char* model, int price, int quantity);

/*
 * functie de distrugere al unui eletrocasnic
 */
void destroyElectronic(Electronic* elem);

/*
 * functie de validare a electrocasnicelor
 */
int validateElectronic(Electronic* elem);

Electronic* copyElectronic(Electronic* elem);