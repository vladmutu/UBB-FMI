#include<string.h>
#include "service.h"
#include "medicament.h"
#include "myList.h"

Farmacie createFarmacie()
{
    Farmacie listaMeds;
    listaMeds.lista = createList();
    //aici pui cv de genul listaMeds.undoList = createList()
    return listaMeds;
}

void destroyFarmacie(Farmacie* f)
{
    destroyList(f->lista);
}

/*Adauga  un medicament in lista.
 * Pre: list- de tip Farmacie*, id-int, nume - char*, concentratie-float
 * Post: 0 daca entitatea exista deja in lista, 1 altfel
 */
int addEnt(Farmacie* list, int id, char* nume, float concentratie, int stoc)
{
    Medicament* e = createMedicament(id, nume, concentratie, stoc);
    if(valideazaMedicament(e) == 1)
    {
        addEntitate(list->lista,e);
        return 1;
    }
    else
    {
        destroyMedicament(e);
        return 0;
    }
}
/*Functie care sterge o entitate
 *Pre:list de tip Farmacie*, id de tip int
 * Post: 1 daca id-ul este in lista si a fost sters, 0 altfel
 */
int deleteEnt(Farmacie* list, int id)
{
    if(checkId(list,id))
    {
        deleteEntitate(list->lista,id);
        return 1;
    }
    return 0;
}

/*Face update la un medicament.
 * Pre: list- de tip Farmacie*, id-int, nume - char*, concentratie-float
 * Post: 0 daca entitatea exista deja in lista si s-a facut modificarea, 1 altfel
 */
int updateEnt(Farmacie* list, int id, char* nume, float concentratie)
{
    for(int i=0;i<list->lista->dimensiune;i++)
    {
        if(getId(get(list->lista,i))==id)
        {
            int stoc = getStoc(get(list->lista,i));
            Entitate e = createMedicament(id,nume,concentratie,stoc);
            updateMedicament(list->lista,e);
            return 0;
        }

    }
    return -1;
}

/*Cauta daca un id este in lista*/
int checkId(Farmacie* list, int id)
{
    if(cauta(list->lista,id) != -1)
        return 1;
    return 0;
}

/*Adauga un singur produs pe stoc*/
void addStoc(Farmacie* list, int id)
{
    int poz = cauta(list->lista,id);
    Medicament* m = get(list->lista,poz);
    setStoc(m,m->stoc+1);

}

/*Dealoca tot*/
void destroyAll(Farmacie* list)
{
    destroyFarmacie(list);
}


/*Functie care sorteaza medicamentele crescator dupa stocul lor. Returneaza o farmacie cu medicamentele ordonate*/
List* sortareStoc(Farmacie* list)
{
    List* f = copyFarmacie(list->lista);
    for(int i=0; i<f->dimensiune-1;i++)
        for(int j=i+1; j<f->dimensiune;j++)
            if(getStoc(f->medicamente[i])> getStoc(f->medicamente[j]))
            {
                Medicament* m1 = get(f,i);
                Medicament* m2 = get(f,j);
                set(f,i,m2);
                set(f,j,m1);
            }

    return f;
}

/*Functie care sorteaza medicamentele alfabetic. Returneaza o farmacie cu medicamentele in ordine alfabetica.*/
List* sortareNume(Farmacie* list)
{
    List* f = copyFarmacie(list->lista);
    for(int i=0;i<f->dimensiune-1;i++)
        for(int j=i+1;j<f->dimensiune;j++)
            if(strcmp(getNume(f->medicamente[i]),getNume(f->medicamente[j]))>0)
            {
                Medicament* m1 = get(f,i);
                Medicament* m2 = get(f,j);
                set(f,i,m2);
                set(f,j,m1);
            }
    return f;
}

/*Functie care filtreaza farmacia. Returneaza o farmacie doar cu medicamentele care au stocul mai mic decat o valoare data*/
List* filterStoc(Farmacie* list, int val)
{
    List* f = copyFarmacie(list->lista);

    for(int i=0; i<f->dimensiune;i++)
    {
        Medicament* m = get(f,i);
        if(m->stoc>=val)
            deleteEntitate(f,m->id), i--;
    }

    return f;
}

/*Functie care filtreaza farmacia. Returneaza o farmacie doar cu medicamentele care incep cu litera data*/
List* filterNume(Farmacie* list, char litera)
{
    List* f = copyFarmacie(list->lista);

    for(int i=0; i<f->dimensiune;i++)
    {
        Medicament* m = get(f,i);
        if(m->nume[0] != litera)
            deleteEntitate(f,m->id), i--;
    }

    return f;
}
