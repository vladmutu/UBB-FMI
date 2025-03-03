#pragma once
#include "medicament.h"
#include "myList.h"
#include <stdbool.h>

typedef struct {
    List* lista;
    List* undoList;
    //aici adaugi o lista de undo de tip List*
} Farmacie;

typedef List* (*filterFunction)(Farmacie*, ...);
typedef void* param;

typedef bool (*cmpFunction)(param, param);

/*Functie care creaza o lista ce contine o lista de medicamente*/
Farmacie createFarmacie();

/*Functie care dealoca lista ce cont    ine lista de medicamente*/
void destroyFarmacie(Farmacie*);

/*Functie care adauga o entitate in farmacie*/
int addEnt(Farmacie* list, int, char*, float, int);

/*Functie care sterge o entitate din store*/
int deleteEnt(Farmacie* list, int);

/*Functie care face update la un produs*/
int updateEnt(Farmacie*, int, char*, float);

/*Cauta un id in lista*/
int checkId(Farmacie* list, int);

/*Adauga in stocul unui produs deja existent*/
void addStoc(Farmacie* list, int);

/*Distruge tot*/
void destroyAll(Farmacie* list);

/*Sorteaza medicamentele dupa stoc folosind bubble sort.*/
List* sortareStoc(Farmacie* list);

/*Sorteaza medicamentele dupa stoc folosind insertion sort.*/
List* sortareStocInsertionSort(Farmacie* list);

/*Sorteaza medicamentele alfabetic folosind bubble sort*/
List* sortareNume(Farmacie* list);

/*Sorteaza medicamentele alfabetic folosind insertion sort*/
List* sortareNumeInsertionSort(Farmacie* list);

/*functie de filtrare dupa nume*/
List* filter(Farmacie* list, cmpFunction, param);

/*functie de comparae a stocului*/
bool cmpStoc(Entitate, param);

/*functie de comparare a numelui*/
bool cmpNume(Entitate, char* c);

/*functie de comparare a concentratiei*/
bool cmpConcentratie(Entitate, param);

int undoService(Farmacie* manager);

