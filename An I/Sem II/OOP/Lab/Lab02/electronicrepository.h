//
// Created by vladm on 3/12/2024.
//header file pentru repository-ul electrocasnicelor
#pragma once
#include "electronic.h"
#ifndef LAB02_ELECTRONICREPOSITORY_H
#define LAB02_ELECTRONICREPOSITORY_H

#endif //LAB02_ELECTRONICREPOSITORY_H

/*
 * definirea listei
 */
typedef struct {
    Electronic*elems;
    int lg;
    int capacity;
}MyList;


/*
 * creaza o lista goala
 * post lista sa fie goala, lg = 0
 */
MyList* createEmpty();


/*
 * distruge o lista
 */
void destroy(MyList *list);


/*
 * adauga un element in lista
 * post: elementul este adaugat la finalul listei
 */
void add(MyList* l, Electronic elem);




/*
 * marire a spatiului utilizat de catre lista pe heap
 */
void resize(MyList* l);

/*
 *functie de stergere din lista a unui element dupa pozitia lui
 */
int delete(MyList* Electronics, int index);