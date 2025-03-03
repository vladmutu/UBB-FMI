//
// Created by vladm on 3/12/2024.
//source file pentru domain unde se defineste TAD electrocasnice
#include "electronic.h"
#include <string.h>
#include <stdlib.h>

/*
 * functie de creare a unui electrocasnic
 */
Electronic createElectronic(int ID, char* type, char* producer, char* model, int price, int quantity)
{
    Electronic elem;
    elem.ID = ID;
    int nr_caracters = (int)strlen(type) + 1;
    elem.type = (char*)malloc(nr_caracters * sizeof(char));
    strcpy_s(elem.type, nr_caracters, type);
    nr_caracters = (int) strlen(producer) + 1;
    elem.producer = (char*)malloc(nr_caracters * sizeof(char));
    strcpy_s(elem.producer, nr_caracters, producer);
    nr_caracters = (int) strlen(model) + 1;
    elem.model = (char*)malloc(nr_caracters * sizeof(char));
    strcpy_s(elem.model, nr_caracters, model);
    elem.price = price;
    elem.quantity = quantity;
    return elem;
}

/*
 * functie de validare a unui electrocasnic
 */
int validateElectronic(Electronic elem)
{
    if(elem.ID < 0)
        return 1;
    if(strlen(elem.type) == 0)
        return 1;
    if(strlen(elem.producer) == 0)
        return 1;
    if(strlen(elem.model) == 0)
        return 1;
    if(elem.price < 0)
        return 1;
    if(elem.quantity < 0)
        return 1;
    return 0;
}