//
// Created by vladm on 3/12/2024.
//Source file pentru UI
#include "electronic.h"
#include "electronicservice.h"
#include "ui.h"
#include "electronicrepository.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void readElectronic(ListManager* manager)
{
    int ID;
    printf("Introduceti ID-ul:");
    scanf_s("%d", &ID);
    bool exista = false;
    int i;
    for (i = 0; i < manager->Electronics->lg; i++)
    {
        Electronic* elem = get(manager->Electronics, i);
        if (elem->ID == ID)
		{
			exista = true;
			break;
		}
    }
        
    if (exista)
    {
        printf("\nActualizati cantitatea produsului cu ID-ul %d\n", ID);
        printf("\nIntroduceti cantitatea:");
        int quantity;
        scanf_s("%d", &quantity);
        updateQuantity(manager, ID, quantity);
        printf("\nCantitate actualizata!\n");
    }
    else
    {
        char type[30];
        char producer[30];
        char model[30];
        int price;
        int quantity;
        printf("\nIntroduceti tipul:");
        scanf_s("%s", &type, 30);
        printf("\nIntroduceti producatorul:");
        scanf_s("%s", &producer, 30);
        printf("\nIntroduceti modelul:");
        scanf_s("%s", &model, 30);
        printf("\nIntroduceti pretul:");
        scanf_s("%d", &price);
        printf("\nIntroduceti cantitatea:");
        scanf_s("%d", &quantity);
        int error = addElectronicService(manager, ID, type, producer, model, price, quantity);
        if (error != 0)
            printf("\nElectrocasnic invalid!\n");
        else
            printf("\nElectrocasnic adaugat\n");
    }
}

void readElectronicForUpdate(ListManager* manager)
{
    int ID;
    printf("\nIntroduceti ID-ul:");
    scanf_s("%d", &ID);
    bool exista = false;
    for (int i = 0; i < size(manager->Electronics); i++)
    {
		Electronic* elem = get(manager->Electronics, i);
		if (elem->ID == ID)
		{
			exista = true;
			break;
		}
	}
    if (exista)
    {
        int price, quantity;
        printf("\nIntroduceti pretul (Introduceti -1 daca vreti sa ramana neactualizat):");
        scanf_s("%d", &price);
        printf("\nIntroduceti cantitatea (Introduceti -1 daca vreti sa ramana neactualizata):");
        scanf_s("%d", &quantity);
        int error = updateElectronicService(manager, ID, price, quantity);
        if (error == 0)
            printf("\nDate actualizate!\n");
    }
    else printf("\nProdus inexistent!\n");
}

void readElectronicForDeletion(ListManager* manager)
{
    int ID;
    printf("\nIntroduceti ID-ul:\n");
    scanf_s("%d", &ID);
    bool exista = false;
    for (int i = 0; i < manager->Electronics->lg; i++)
	{
		Electronic* elem = get(manager->Electronics, i);
		if (elem->ID == ID)
		{
			exista = true;
			break;
		}
	}
    if (!exista)
        printf("\nProdus inexistent!\n");
    else
    {
        int error = deleteElectronicService(manager, ID);
        if (!error)
            printf("\nProdus sters cu succes!\n");
        else
            printf("\nEroare!\n");
    }
}

void printAllElectronics(MyList* Electronics)
{
    for (int i = 0; i < Electronics->lg; i++)
    {
		Electronic* elem = get(Electronics, i);
		printf("\nID: %d", elem->ID);
        printf(" Tip: %s", elem->type);
        printf(" Producator: %s", elem->producer);
        printf(" Model: %s", elem->model);
        printf(" Pret: %d", elem->price);
        printf(" Cantitate: %d\n", elem->quantity);
    }
}

void printAllSortedByPrice(ListManager* manager)
{
    int choice;
    printf("\n1. Ordonate crescator\n2. Ordonate descrescator\n");
    scanf_s("%d", &choice);
    if (choice == 1)
    {
        MyList* sorted = sortElectronicsPriceAscending(manager->Electronics);
        printAllElectronics(sorted);
        destroy(sorted);
    }
	else if(choice == 2)
	{
        MyList* sorted = sortElectronicsPriceDescending(manager->Electronics);
		printAllElectronics(sorted);
		destroy(sorted);
	}
	else
	{
		printf("Comanda inexistenta!\n");
	}
            
}

void printAllSortedByQuantity(ListManager* manager)
{
    int choice;
    printf("\n1. Ordonate crescator\n2. Ordonate descrescator\n");
    scanf_s("%d", &choice);
    if (choice == 1)
    {
        MyList* sorted = sortElectronicsQuantityAscending(manager->Electronics);
        printAllElectronics(sorted);
        destroy(sorted);
    }
    else if (choice == 2)
    {
        MyList* sorted = sortElectronicsQuantityDescending(manager->Electronics);
		printAllElectronics(sorted);
		destroy(sorted);
    }
    else
    {
        printf("Comanda inexistenta!\n");
    }

}

void printAllFiltered(ListManager* manager)
{
    int choice;
    printf("\n1. Filtrare dupa producator\n2. Filtrare dupa pret\n3. Filtrare dupa cantitate\n");
    scanf_s("%d", &choice);
    if (choice == 1)
    {
		char producer[30];
		printf("\nIntroduceti producatorul:\n");
		scanf_s("%s", &producer, 30);
        producer[strlen(producer)] = '\0';
		MyList* filtered = filterElectronicsByProducer(manager->Electronics, producer);
        printAllElectronics(filtered);
        destroy(filtered);
    }
    else if (choice == 2)
    {
		int price;
		printf("\nIntroduceti pretul:\n");
		scanf_s("%d", &price);
		MyList* filtered = filterElectronicsByPrice(manager->Electronics, price);
        printAllElectronics(filtered);
        destroy(filtered);

    }
    else if(choice == 3)
	{
        int quantity;
        printf("\nIntroduceti cantitatea:\n");
		scanf_s("%d", &quantity);
		MyList* filtered = filterElectronicsByQuantity(manager->Electronics, quantity);
        printAllElectronics(filtered);
        destroy(filtered);
	}
	else
	{
		printf("Comanda inexistenta!\n");
	}
}

void undo(ListManager* manager)
{
	int error = undoService(manager);
	if (error == 0)
		printf("\nUndo efectuat!\n");
	else
		printf("\nEroare!\n");
}

void run()
{
    ListManager manager = createListManager();
    int ruleaza = 1;
    while (ruleaza)
    {
        printf("\n1.Adauga electrocasnic\n2.Actualizeaza electrocasnic\n3.Sterge electrocasnic\n4.Afiseaza electrocasnice\n5.Vizualizare produse ordonate dupa pret\n6.Vizualizare produse ordonate dupa cantitate\n7.Vizualizare produse filtrate dupa un criteriu\n8.Undo\n0.Iesire\n");
        int cmd = 0;
        scanf_s("%d", &cmd);
        switch (cmd)
        {
            case 1:
                readElectronic(&manager);
                break;
            case 2:
                readElectronicForUpdate(&manager);
                break;
            case 3:
                readElectronicForDeletion(&manager);
                break;
            case 4:
                printAllElectronics(manager.Electronics);
                break;
            case 5:
				printAllSortedByPrice(&manager);
			    break;
            case 6:
                printAllSortedByQuantity(&manager);
                break;
            case 7:
                printAllFiltered(&manager);
			    break;
            case 8:
                undo(&manager);
                break;
            case 0:
                ruleaza = 0;
                destroyListManager(&manager);
                break;
            default:
                printf("Comanda inexistenta!\n");
        }
    }
}