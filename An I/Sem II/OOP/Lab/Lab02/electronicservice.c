//
// Created by vladm on 3/12/2024.
//Source file service pentru electrocasnice
#include <stdio.h>
#include "electronicservice.h"

/*
 * functie service de adaugare a unui electrocasnic in lista de electrocasnice
 */
int addElectronicService(MyList* Electronics, int ID, char type[], char producer[], char model[], int price, int quantity)
{
    Electronic elem = createElectronic(ID, type, producer, model, price, quantity);
    int error = validateElectronic(elem);
    if(error == 1)
        return 1;
    else
    {
        add(Electronics, elem);
        return 0;
    }
}

/*
 * functie service de actualizare a pretului sau cantitatii unui electrocasnic
 */
int updateElectronicService(MyList* Electronics, int ID, int price, int quantity)
{
    if(price == -1)
    {
        if(quantity != -1)
            for(int i = 0; i < Electronics->lg; i++)
                if(Electronics->elems[i].ID == ID)
                    Electronics->elems[i].quantity = quantity;
    } else if(quantity == -1)
    {
        for(int i = 0; i < Electronics->lg; i++)
            if(Electronics->elems[i].ID == ID)
                Electronics->elems[i].price = price;
    } else {
        for(int i = 0; i < Electronics->lg; i++)
            if(Electronics->elems[i].ID == ID) {
                Electronics->elems[i].price = price;
                Electronics->elems[i].quantity = quantity;
            }
    }
    return 0;
}

/*
 * functie service se stergere a unui electrocasnic
 */
int deleteElectronicService(MyList* Electronics, int ID)
{
    int poz;
    for(int i = 0; i < Electronics->lg; i++)
        if( Electronics->elems[i].ID == ID)
            poz = i;
    int error = delete(Electronics, poz);
    return 0;
}

/*
 * functie de actualizare a cantitatii
 */
int updateQuantity(MyList* Electronics, int ID, int quantity)
{
    for(int i = 0; i < Electronics->lg; i++)
        if(Electronics->elems[i].ID == ID)
        {
            Electronics->elems[i].quantity += quantity;
        }
    return 0;
}