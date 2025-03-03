#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <stdio.h>
#include "medicament.h"
#include "myList.h"
#include "service.h"
#include "ui.h"
#include "teste.h"
void updateMed(Farmacie* list)
{
    printf("Introduceti Id-ul:\n");
    int id;
    scanf_s("%d", &id);
    printf("Introduceti noua concentratie:\n");
    float concentratie;
    scanf_s("%f", &concentratie);
    printf("Introducceti noul nume:\n");
    char nume[30];
    scanf_s("%s", &nume, 30);
    if (!updateEnt(list, id, nume, concentratie))
        printf("Modificarea a avut loc cu succes!\n");
    else
        printf("Medicamentul cu id-ul dat nu exista!\n");

}
void readMed(Farmacie* list)
{
    printf("Introduceti id:\n");
    int id = -1;
    scanf_s("%d", &id);
    if (!checkId(list, id))
    {
        printf("Introduceti nume:\n");
        char nume[30];
        scanf_s("%s", &nume, 30);
        printf("Introduceti concentratie:\n");
        float concentratie;
        scanf_s("%f", &concentratie);
        printf("Introduceti stoc:\n");
        int stoc;
        scanf_s("%d", &stoc);

        if (addEnt(list, id, nume, concentratie, stoc))
            printf("Produsul a fost adaugat cu succes!\n");
        else
            printf("Medicament invalid!\n");
    }
    else
    {
        addStoc(list, id);
        printf("Stocul a fost actualizat cu succes!\n");
    }


}

void printFarmacie(Farmacie* list)
{
    for (int i = 0; i < list->lista->dimensiune; i++)
    {
        Medicament* m = get(list->lista, i);
        printf("Id: %d; Nume: %s; Concentratie: %f; Stoc: %d\n", m->id, m->nume, m->concentratie, m->stoc);
    }
}

void deleteMed(Farmacie* list)
{
    printf("Id-ul medicamentului pe care doriti sa il stergeti:\n");
    int id;
    scanf_s("%d", &id);
    if (!deleteEnt(list, id))
        printf("Acest medicament nu exista!\n");
    else
        printf("Medicament sters cu succes!\n");
}
void destroy(Farmacie* list)
{
    destroyAll(list);

}

void sortNumeCresc(Farmacie* list)
{
    printf("\n1. Bubble sort:\n");
    printf("\n2. Insertion sort:\n");
    int cmd;
    scanf_s("%d", &cmd);
    if (cmd == 1)
	{
		List* f = sortareNume(list);
		for (int i = 0; i < f->dimensiune; i++)
		{
			Medicament* m = get(f, i);
			printf("Id: %d; Nume: %s; Concentratie: %f; Stoc: %d\n", m->id, m->nume, m->concentratie, m->stoc);
		}

		destroyList(f);
	}
	else if (cmd == 2)
	{
		List* f = sortareNumeInsertionSort(list);
		for (int i = 0; i < f->dimensiune; i++)
		{
			Medicament* m = get(f, i);
			printf("Id: %d; Nume: %s; Concentratie: %f; Stoc: %d\n", m->id, m->nume, m->concentratie, m->stoc);
		}

		destroyList(f);
	}
	else
		printf("Comanda invalida!\n");

}

void sortNumeDesc(Farmacie* list)
{
    printf("\n1. Bubble sort:\n");
    printf("\n2. Insertion sort:\n");
    int cmd;
    scanf_s("%d", &cmd);
    if (cmd == 1)
    {
        List* f = sortareNume(list);
		for (int i = f->dimensiune - 1; i >= 0; i--)
		{
			Medicament* m = get(f, i);
			printf("Id: %d; Nume: %s; Concentratie: %f; Stoc: %d\n", m->id, m->nume, m->concentratie, m->stoc);
		}
		destroyList(f);
	}
	else if (cmd == 2)
	{
		List* f = sortareNumeInsertionSort(list);
		for (int i = f->dimensiune - 1; i >= 0; i--)
		{
			Medicament* m = get(f, i);
			printf("Id: %d; Nume: %s; Concentratie: %f; Stoc: %d\n", m->id, m->nume, m->concentratie, m->stoc);
		}
		destroyList(f);
	}
	else
		printf("Comanda invalida!\n");

}

void sortStocCresc(Farmacie* list)
{
    printf("\n1. Bubble sort:\n");
    printf("\n2. Insertion sort:\n");
	int cmd;
	scanf_s("%d", &cmd);
	if (cmd == 1)
	{
		List* f = sortareStoc(list);
		for (int i = 0; i < f->dimensiune; i++)
		{
			Medicament* m = get(f, i);
			printf("Id: %d; Nume: %s; Concentratie: %f; Stoc: %d\n", m->id, m->nume, m->concentratie, m->stoc);
		}
		destroyList(f);
	}
	else if (cmd == 2)
	{
		List* f = sortareStocInsertionSort(list);
		for (int i = 0; i < f->dimensiune; i++)
		{
			Medicament* m = get(f, i);
			printf("Id: %d; Nume: %s; Concentratie: %f; Stoc: %d\n", m->id, m->nume, m->concentratie, m->stoc);
		}
		destroyList(f);
	}
	else
		printf("Comanda invalida!\n");
}

void sortStocDesc(Farmacie* list)
{
    printf("\n1. Bubble sort:\n");
    printf("\n2. Insertion sort:\n");
    int cmd;
    scanf_s("%d", &cmd);
    if (cmd == 1)
    {
	    List* f = sortareStoc(list);
	    for (int i = f->dimensiune - 1; i >= 0; i--)
	    {
		    Medicament* m = get(f, i);
		    printf("Id: %d; Nume: %s; Concentratie: %f; Stoc: %d\n", m->id, m->nume, m->concentratie, m->stoc);
	    }
	    destroyList(f);
    }
    else if (cmd == 2)
    {
	    List* f = sortareStocInsertionSort(list);
	    for (int i = f->dimensiune - 1; i >= 0; i--)
	    {
		    Medicament* m = get(f, i);
		    printf("Id: %d; Nume: %s; Concentratie: %f; Stoc: %d\n", m->id, m->nume, m->concentratie, m->stoc);
	    }
	    destroyList(f);
    }
    else
	    printf("Comanda invalida!\n");
}

void filtrareStoc(Farmacie* list)
{
    printf("Dati o valoare intrega, pozitiva, nenula:\n");
    int val;
    scanf_s("%d", &val);
    List* f = filter(list, cmpStoc, &val);
    for (int i = 0; i < f->dimensiune; i++)
    {
        Medicament* m = get(f, i);
        printf("Id: %d; Nume: %s; Concentratie: %f; Stoc: %d\n", m->id, m->nume, m->concentratie, m->stoc);
    }

    destroyList(f);

}

void filtrareNume(Farmacie* list)
{
    printf("Dati o litera:");
    char litera[2];
    scanf_s("%s", &litera, 2);
    List* f = filter(list, cmpNume, litera[0]);
    for (int i = 0; i < f->dimensiune; i++)
    {
        Medicament* m = get(f, i);
        printf("Id: %d; Nume: %s; Concentratie: %f; Stoc: %d\n", m->id, m->nume, m->concentratie, m->stoc);
    }

    destroyList(f);
}

void uiFilterConcentratie(Farmacie* list)
{
	printf("Dati o valoare reala, pozitiva, nenula:\n");
	float val;
	scanf_s("%f", &val);
	List* f = filter(list, cmpConcentratie, &val);
	for (int i = 0; i < f->dimensiune; i++)
	{
		Medicament* m = get(f, i);
		printf("Id: %d; Nume: %s; Concentratie: %f; Stoc: %d\n", m->id, m->nume, m->concentratie, m->stoc);
	}
	destroyList(f);
}

void undo(Farmacie* list)
{
    int error = undoService(list);
    if(error == 1)
		printf("Nu se mai poate face undo!\n");
	else
		printf("Undo efectuat cu succes!\n");
}

void run()
{
    Farmacie list = createFarmacie();

    while (1)
    {
        int cmd;
        printf("0. Exit;\n1. Adaugare;\n2. Modificare;\n3. Stergere;\n4.Afisare farmacie;\n"
            "5. Sortare nume crescator;\n6. Sortare nume descrescator;\n7. Sortare stoc crescator;\n"
            "8. Sortare stoc descrescator;\n9. Filtrare stoc;\n10. Filtrare nume;\n11. Filtrare concentratie;\n12. Undo\n");
        scanf_s("%d", &cmd);
        if (cmd == 1)
            readMed(&list);
        else if (cmd == 2)
            updateMed(&list);
        else if (cmd == 3)
            deleteMed(&list);
        else if (cmd == 4)
            printFarmacie(&list);
        else if (cmd == 5)
            sortNumeCresc(&list);
        else if (cmd == 6)
            sortNumeDesc(&list);
        else if (cmd == 7)
            sortStocCresc(&list);
        else if (cmd == 8)
            sortStocDesc(&list);
        else if (cmd == 9)
            filtrareStoc(&list);
        else if (cmd == 10)
            filtrareNume(&list);
        else if (cmd == 11)
			uiFilterConcentratie(&list);
        else if (cmd == 12)
			undo(&list);
        else if (cmd == 0)
        {
            break;
        }
    }
    destroyFarmacie(&list);

}

int main()
{
    runAllTests();
    //run();
    _CrtDumpMemoryLeaks();
    return 0;
}
