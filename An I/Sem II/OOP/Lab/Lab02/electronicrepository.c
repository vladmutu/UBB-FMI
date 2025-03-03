//
// Created by vladm on 3/12/2024.
//source file pentru repository-ul electrocasnicelor
#include "electronicrepository.h"
#include <stdlib.h>
#define INITIAL_CAPACITY 10

/*
 * creaza o lista
 * post lista sa fie goala, lg = 0
 *
 */
MyList* createEmpty()
{
    MyList* list = (MyList*)malloc(sizeof(MyList));
    list -> elems = (Electronic*)malloc(INITIAL_CAPACITY* sizeof(Electronic));
    list -> capacity = INITIAL_CAPACITY;
    list -> lg = 0;
    return list;
}

/*
 * distruge o lista
 */
void destroy(MyList *list)
{
    free(list->elems);
    free(list);
}

/*
 * functie de marire a capacitatii listei dinamice
 * newCapacity = 2 * oldCapacity
 */
void resize(MyList* list)
{
    int nCap = 2*list->capacity;
    Electronic * nElems=malloc(nCap*sizeof(Electronic));
    int i;
    for (i = 0; i < list->lg; i++) {
        nElems[i] = list->elems[i];
    }
    free(list->elems);
    list->elems = nElems;
    list->capacity = nCap;
}

/*
 * functie de adaugare a unui element in lista
 * post lgNew = lgOld+1
 */
void add(MyList* list, Electronic elem)
{
    if(list->lg == list->capacity)
        resize(list);
    list->elems[list->lg] = elem;
    list->lg++;
}


/*
 * returneaza elementul din lista de la pozitia poz
 * poz este luat ca fiind o pozitie valida in lista
 */

/*
 * functie de stergere a unui electrocasnic din lista de electrocasnice
 */
int delete(MyList* list, int index)
{
    for (int i = index; i < list->lg - 1; i++) {
        list->elems[i] = list->elems[i + 1];
    }
    list->lg--;
    return 0;
}
