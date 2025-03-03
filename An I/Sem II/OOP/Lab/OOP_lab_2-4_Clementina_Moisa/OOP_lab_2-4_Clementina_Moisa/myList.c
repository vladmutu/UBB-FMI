#include "myList.h"
#include <stdlib.h>
#include <stdio.h>

/*Adauga un produs nou in farmacie.*/
void addEntitate(List* f, Entitate e)
{
    if (f->dimensiune < f->capacitate)
    {
        f->medicamente[f->dimensiune] = e;
        f->dimensiune += 1;
    }
    else
    {
        asiguraCapacitate(f);
        addEntitate(f, e);
    }
    
}

/*Functie care mareste capacitatea farmaciei.*/
void asiguraCapacitate(List* f)
{
    int nCap = f->capacitate * 2;
    Entitate* capacitateNoua = malloc(sizeof(Entitate) * nCap);
    //copiaza elementele
    for (int i = 0; i < f->dimensiune; i++)
        capacitateNoua[i] = f->medicamente[i];

    //dealoca memoria
    free(f->medicamente);
    f->medicamente = capacitateNoua;
    f->capacitate = nCap;

}

/*Sterge o un produs din farmacie.*/
Entitate deleteEntitate(List* f, int poz)
{
    Entitate elemToDelete = f->medicamente[poz];
    for (int i = poz; i < f->dimensiune - 1; i++)
		f->medicamente[i] = f->medicamente[i + 1];
	f->dimensiune--;
	return elemToDelete;
}


/*Functie care creeaza o entitate List noua si returneaza pointerul la entitatea respectiva.*/
List* createList(destroyFunction fnc)
{

    List* f = malloc(sizeof(List));
    f->dimensiune = 0;
    f->capacitate = 2;
    f->medicamente = malloc(sizeof(Entitate) * f->capacitate);
    f->destroyfunction = fnc;
    return f;
}

/*Primeste un pointer la entitatea List si dealoca memoria ocupata de entitate.*/
void destroyList(List* f)
{
    for (int i = 0; i < f->dimensiune; i++)
        f->destroyfunction(f->medicamente[i]);
    free(f->medicamente);
    free(f);

}

/*Functie care face update la un medicament.
 Primeste un pointer la medicamentul cu caracteristicile actualizate, distruge medicamentul
 vechi si il pune pe cel actualizat.
*/
void updateMedicament(List* f, Medicament* m)
{
    m->stoc++;
}

/*Functie care primeste un int -id- si returneaza pozitia pe care se afla elementul sau -1 in caz contrar*/
int cauta(List* f, int id)
{

    for (int i = 0; i < f->dimensiune; i++)
    {
        Medicament* p = get(f, i);
        if (p->id == id)
            return i;

    }
    return -1;
}


/*Functie care returneaza elementul de pe o pozitie data*/
Entitate get(List* f, int i)
{
    return f->medicamente[i];
}

/*Functie care pune pe o pozitie data o entitate data si returneaza fostul element de pe pozitia data.*/
Entitate set(List* f, int poz, Entitate e)
{

    Entitate rez = f->medicamente[poz];
    f->medicamente[poz] = e;
    return rez;
}

List* copyFarmacie(List* p, copyFunction cpy)
{
    List* list_copy = createList(p->destroyfunction);
    for(int i = 0; i < p->dimensiune; i++)
	{
		addEntitate(list_copy, cpy(p->medicamente[i]));
	}
    return list_copy;
}