#include<string.h>
#include "service.h"
#include "medicament.h"
#include "myList.h"

Farmacie createFarmacie()
{
    Farmacie listaMeds;
    listaMeds.lista = createList(destroyMedicament);
    listaMeds.undoList = createList(destroyList);
    //aici pui cv de genul listaMeds.undoList = createList()
    return listaMeds;
}

void destroyFarmacie(Farmacie* f)
{
    destroyList(f->lista);
    destroyList(f->undoList);
}

/*Adauga  un medicament in lista.
 * Pre: list- de tip Farmacie*, id-int, nume - char*, concentratie-float
 * Post: 0 daca entitatea exista deja in lista, 1 altfel
 */
int addEnt(Farmacie* list, int id, char* nume, float concentratie, int stoc)
{
    Medicament* e = createMedicament(id, nume, concentratie, stoc);
    if (valideazaMedicament(e) == 1)
    {
        List* toUndo = copyFarmacie(list->lista, copyMedicament);
        addEntitate(list->lista, e);
        addEntitate(list->undoList, toUndo);
        return 1;
    }
    destroyMedicament(e);
    return 0;
}
/*Functie care sterge o entitate
 *Pre:list de tip Farmacie*, id de tip int
 * Post: 1 daca id-ul este in lista si a fost sters, 0 altfel
 */
int deleteEnt(Farmacie* list, int id)
{
    if (checkId(list, id))
    {
        for(int i = 0; i < list->lista->dimensiune; i++)
            if (getId(get(list->lista, i)) == id)
            {
                List* toUndo = copyFarmacie(list->lista, copyMedicament);
                Entitate elem = deleteEntitate(list->lista, i);
                destroyMedicament(elem);
                addEntitate(list->undoList, toUndo);
            }   
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
    for (int i = 0; i < list->lista->dimensiune; i++)
    {
        if (getId(get(list->lista, i)) == id)
        {
            List* toUndo = copyFarmacie(list->lista, copyMedicament);
            Entitate e = get(list->lista, i);
            updateMedicament(list->lista, e);
            addEntitate(list->undoList, toUndo);
            return 0;
        }

    }
    return -1;
}

/*Cauta daca un id este in lista*/
int checkId(Farmacie* list, int id)
{
    if (cauta(list->lista, id) != -1)
        return 1;
    return 0;
}

/*Adauga un singur produs pe stoc*/
void addStoc(Farmacie* list, int id)
{
    List* toUndo = copyFarmacie(list->lista, copyMedicament);
    int poz = cauta(list->lista, id);
    Medicament* m = get(list->lista, poz);
    setStoc(m, m->stoc + 1);
    addEntitate(list->undoList, toUndo);

}

/*Dealoca tot*/
void destroyAll(Farmacie* list)
{
    destroyFarmacie(list);
}


/*Functie care sorteaza medicamentele crescator dupa stocul lor. Returneaza o farmacie cu medicamentele ordonate*/
List* sortareStoc(Farmacie* list)
{
    List* f = copyFarmacie(list->lista, copyMedicament);
    for (int i = 0; i < f->dimensiune - 1; i++)
        for (int j = i + 1; j < f->dimensiune; j++)
            if (getStoc(f->medicamente[i]) > getStoc(f->medicamente[j]))
            {
                Medicament* m1 = get(f, i);
                Medicament* m2 = get(f, j);
                set(f, i, m2);
                set(f, j, m1);
            }

    return f;
}

List* sortareStocInsertionSort(Farmacie* list)
{
    List* f = copyFarmacie(list->lista, copyMedicament);
    for (int i = 0; i < f->dimensiune; i++)
    {
        int p = i;
        while( p > 0 && getStoc(f->medicamente[p]) < getStoc(f->medicamente[p - 1]))
		{
			Medicament* m1 = get(f, p);
			Medicament* m2 = get(f, p - 1);
			set(f, p, m2);
			set(f, p - 1, m1);
			p--;
		}
    }
    return f;
}

/*Functie care sorteaza medicamentele alfabetic. Returneaza o farmacie cu medicamentele in ordine alfabetica.*/
List* sortareNume(Farmacie* list)
{
    List* f = copyFarmacie(list->lista, copyMedicament);
    for (int i = 0; i < f->dimensiune - 1; i++)
        for (int j = i + 1; j < f->dimensiune; j++)
            if (strcmp(getNume(f->medicamente[i]), getNume(f->medicamente[j])) > 0)
            {
                Medicament* m1 = get(f, i);
                Medicament* m2 = get(f, j);
                set(f, i, m2);
                set(f, j, m1);
            }
    return f;
}

List* sortareNumeInsertionSort(Farmacie* list)
{
    List* f = copyFarmacie(list->lista, copyMedicament);
    for (int i = 0; i < f->dimensiune; i++)
    {
        int p = i;
        while( p > 0 && strcmp(getNume(f->medicamente[p]), getNume(f->medicamente[p - 1])) < 0)
        {
            Medicament* m1 = get(f, p);
			Medicament* m2 = get(f, p - 1);
			set(f, p, m2);
			set(f, p - 1, m1);
			p--;
		}
    }
    return f;
}

List* filter(Farmacie* list, cmpFunction cmp, param el)
{
      List* f = createList(destroyMedicament);
      for (int i = 0; i < list->lista->dimensiune; i++)
      {
          Medicament* m = get(list->lista, i);
		  if (cmp(m, el) == 1)
			  addEntitate(f, copyMedicament(m));
      }
      return f;
}

bool cmpStoc(Entitate el1, param el)
{
    int val = *(int*)el;
	if(getStoc(el1) < val)
		return 1;
    return 0;
}

bool cmpNume(Entitate el1, param c)
{
    if (getNume(el1)[0] == (char*)c)
        return 1;
    return 0;
}

bool cmpConcentratie(Entitate el1, param el)
{
    float val = *(float*)el;
    if(getConcentratie(el1) < val)
		return 1;
}

int undoService(Farmacie* manager)
{
    if (manager->undoList->dimensiune == 0)
        return 1;
    else
    {
        List* list = deleteEntitate(manager->undoList, manager->undoList->dimensiune - 1);
        destroyList(manager->lista);
        manager->lista = list;
        return 0;
    }
}
