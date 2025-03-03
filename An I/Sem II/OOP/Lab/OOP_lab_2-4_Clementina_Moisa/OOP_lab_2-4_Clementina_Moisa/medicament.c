#include "medicament.h"
#include <stdlib.h>
#include <string.h>

Medicament* createMedicament(int id, char* nume, float concentratie, int stoc)
{
    Medicament* p = malloc(sizeof(Medicament));
    p->id = id;
    int nr = (int)strlen(nume) + 1;
    p->nume = malloc(sizeof(char) * nr);
    strcpy_s(p->nume, nr, nume);
    p->concentratie = concentratie;
    p->stoc = stoc;
    return p;
}

Medicament* copyMedicament(Medicament* m)
{
    Medicament* p = malloc(sizeof(Medicament));
    p->id = m->id;
    p->nume = (char*)malloc(sizeof(char) * (strlen(m->nume) + 1));
    strcpy_s(p->nume, strlen(m->nume)+1, m->nume);
    p->concentratie = m->concentratie;
    p->stoc = m->stoc;
    return p;
}


void destroyMedicament(Medicament* p)
{
    p->id = -1;
    free(p->nume);
    free(p);
}


int getId(Medicament* p)
{
    return p->id;
}

float getConcentratie(Medicament* p)
{
    return p->concentratie;
}

/*
char* getNume(Medicament* p)
{
    return p->nume;
}
*/
int getStoc(Medicament* p)
{
    return p->stoc;
}

/*
float getConcentratie(Medicament* p)
{
    return p->concentratie;
}
*/
void setStoc(Medicament* p, int stoc)
{
    p->stoc = stoc;
}

int valideazaMedicament(Medicament* m)
{
    if (m->id <= 0)
        return -1;
    if (m->stoc <= 0)
        return -1;
    if (strlen(m->nume) < 2)
        return -1;
    if (m->concentratie <= 0)
        return -1;

    return 1;
}

char* getNume(Medicament* m)
{
    return m->nume;
}
