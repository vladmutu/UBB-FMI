//
// Created by vladm on 3/12/2024.
//header file pentru repository-ul electrocasnicelor
#pragma once
#include "electronic.h"

typedef void* ElemType;

typedef void (*DestroyElemFunction)(ElemType);
typedef ElemType (*CopyElemFunction)(ElemType);

/*
 * definirea listei
 */
typedef struct {
    ElemType* elems;
    int lg;
    int capacity;
    DestroyElemFunction destroyElemFunction;
}MyList;


/*
 * creaza o lista goala
 * post lista sa fie goala, lg = 0
 */
MyList* createEmpty(DestroyElemFunction f);


/*
 * distruge o lista
 */
void destroy(MyList* list);


/*
 * adauga un element in lista
 * post: elementul este adaugat la finalul listei
 */
void add(MyList* l, ElemType elem);

/*
* functie getter pentru un element din lista
*/
ElemType get(MyList* l, int poz);

/*
* functie de obtinere a dimensiunii listei
*/
int size(MyList* l);


/*
 * marire a spatiului utilizat de catre lista pe heap
 */
void resize(MyList* l);

/*
 * functie de setare a unui element din lista
 */
ElemType set(MyList* l, int poz, ElemType elem);

/*
 *functie de stergere din lista a unui element dupa pozitia lui
 */
ElemType delete(MyList* Electronics, int poz);

/*
 * functie de copiere a unei liste
 */
MyList* CopyList(MyList* l, CopyElemFunction copyFunction);