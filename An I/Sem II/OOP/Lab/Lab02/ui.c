//
// Created by vladm on 3/12/2024.
//Source file pentru UI

#include "electronic.h"
#include "electronicservice.h"
#include "ui.h"
#include "electronicrepository.h"
#include <stdio.h>
#include <stdbool.h>


/*
 * functie de citire a parametrilor unui electronic
 * pre Electronics = lista dinamica
 * post s-au citit parametrii unui posibil electrocasnic
 */
void readElectronic(MyList* Electronics)
{
    int ID;
    printf("Introduceti ID-ul:");
    scanf_s("%d", &ID);
    bool exista = false;
    int i;
    for(i = 0; i < Electronics->lg; i++)
        if(Electronics->elems[i].ID == ID)
            exista = true;
    if(exista)
    {
        int quantity;
        printf("\nID existent! Actualizati cantitatea produsului!");
        scanf_s("%d", &quantity);
        int error = updateQuantity(Electronics, ID, quantity);
        if(error == 0)
            printf("\nCantitate actualizata!\n");
        else
            printf("\nEroare!\n");
    }
    else
    {
        char type[30];
        char producer[30];
        char model[30];
        int price;
        int quantity;
        printf("\nIntroduceti tipul:");
        scanf_s("%s", &type);
        printf("\nIntroduceti producatorul:");
        scanf_s("%s", &producer);
        printf("\nIntroduceti modelul:");
        scanf_s("%s", &model);
        printf("\nIntroduceti pretul:");
        scanf_s("%d", &price);
        printf("\nIntroduceti cantitatea:");
        scanf_s("%d", &quantity);
        int error = addElectronicService(Electronics, ID, type, producer, model, price, quantity);
        if (error != 0)
            printf("\nElectrocasnic invalid!\n");
        else
            printf("\nElectrocasnic adaugat\n");
    }
}

/*
 * functi de citire a parametrilor pret si cantitate ai unui electronic pentru update
 * pre Electronics = lista dinamica
 * post s-au citit parametrii unui electrocasnic
 */
void readElectronicForUpdate(MyList* Electronics)
{
    int ID;
    printf("\nIntroduceti ID-ul:");
    scanf_s("%d", &ID);
    bool exista = false;
    for(int i=0; i < Electronics->lg; i++)
        if(Electronics->elems[i].ID==ID)
            exista = true;
    if(exista)
    {
        int price, quantity;
        printf("\nIntroduceti pretul (Introduceti -1 daca vreti sa ramana neactualizat):");
        scanf_s("%d", &price);
        printf("\nIntroduceti cantitatea (Introduceti -1 daca vreti sa ramana neactualizata):");
        scanf_s("%d", &quantity);
        int error = updateElectronicService(Electronics, ID, price, quantity);
        if(error == 0)
            printf("\nDate actualizate!\n");
    } else printf("\nProdus inexistent!\n");
}

/*
 * functie de citire a parametrilor unui electronic pentru stergere
 * pre Electronics = lista dinamica
 * post s-a citit ID-ul unui electrocasnic destinat stergerii
 */
void readElectronicForDeletion(MyList* Electronics)
{
    int ID;
    printf("\nIntroduceti ID-ul:\n");
    scanf_s("%d", &ID);
    bool exista = false;
    for(int i=0; i < Electronics->lg; i++)
        if(Electronics->elems[i].ID==ID)
            exista = true;
    if(!exista)
        printf("\nProdus inexistent!\n");
    else
    {
        int error = deleteElectronicService(Electronics, ID);
        if(!error)
            printf("\nProdus sters cu succes!\n");
        else
            printf("\nEroare!\n");
    }
}

/*
 * functie de afisare a tuturor electronicelor
 * post s-au afisat toate electrocasnicele din lista dinamica
 */
void printAllElectronics(MyList* Electronics)
{
    for(int i = 0; i < Electronics->lg; i++)
    {
        printf("%d.  ", Electronics->elems[i].ID);
        printf("Tip: %s  ", Electronics->elems[i].type);
        printf("Producator: %s  ", Electronics->elems[i].producer);
        printf("Model: %s  ", Electronics->elems[i].model);
        printf("Pret: %d  ", Electronics->elems[i].price);
        printf("Cantitate: %d\n", Electronics->elems[i].quantity);
    }
}

/*
 * functie de pornire a programului
 */
void run()
{
    MyList* Electronics = createEmpty();
    int ruleaza = 1;
    while(ruleaza)
    {
        printf("\n1.Adauga electrocasnic\n2.Actualizeaza electrocasnic\n3.Sterge electrocasnic\n4.Afiseaza electrocasnice\n0.Iesire\n");
        int cmd = 0;
        scanf_s("%d", &cmd);
        switch (cmd)
        {
            case 1:
                readElectronic(Electronics);
                break;
            case 2:
                readElectronicForUpdate(Electronics);
                break;
            case 3:
                readElectronicForDeletion(Electronics);
                break;
            case 4:
                printAllElectronics(Electronics);
                break;
            case 0:
                ruleaza = 0;
                break;
            default:
                printf("Comanda inexistenta!\n");
        }
    }
    destroy(Electronics);
}