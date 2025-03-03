#pragma once
#include "medicament.h"

/*Creeaza o entitate*/
typedef void* Entitate;

typedef void (*destroyFunction)(Entitate);
typedef Entitate (*copyFunction)(Entitate);

typedef struct {
    Entitate* medicamente;
    int dimensiune;
    int capacitate;
    destroyFunction destroyfunction;
} List;

/* Adauga o entitate in lista */
void addEntitate(List*, Entitate);

/* Sterge o entitate cu id-ul dat din lista */
Entitate deleteEntitate(List*, int);

/*Dubleaza capacitatea vectorului*/
void asiguraCapacitate(List*);

/* Creeaza o lista Noua */
List* createList(destroyFunction fnc);

/* Sterge lista */
void destroyList(List*);

/* Modifica un medicament */
void updateMedicament(List*, Medicament*);

/* Returneaza entitatea de pe o pozitie data */
Entitate get(List*, int);

/* Pune pe o pozitie data Entitatea data.*/
Entitate set(List*, int, Entitate);

/*Cauta un medicament cu un id dat*/
int cauta(List*, int);

/*Creeaza o copie la farmacia data*/
List* copyFarmacie(List*, copyFunction cpy);