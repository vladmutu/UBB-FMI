#include "teste.h"
#include "medicament.h"
#include "myList.h"
#include "service.h"
#include <assert.h>
#include <string.h>
#include <stdio.h>

void testValideazaMedicament()
{
    int idRau = -1;
    char* numeRau = "";
    float concentratieRea = -1.0;
    int stocRau = 0;
    Medicament* o = createMedicament(19, numeRau, 9, 10);
    assert(valideazaMedicament(o) == -1);

    Medicament* i = createMedicament(19, "ksdjn", -9, 10);
    assert(valideazaMedicament(i) == -1);

    Medicament* d = createMedicament(19, "sdkhb", 9, -10);
    assert(valideazaMedicament(d) == -1);


    Medicament* m = createMedicament(idRau, numeRau, concentratieRea, stocRau);
    assert(valideazaMedicament(m) == -1);

    int idBun = 19;
    char* numeBun = "nurofen";
    float concentratieBuna = 0.88;
    int stocBun = 7;
    Medicament* p = createMedicament(idBun, numeBun, concentratieBuna, stocBun);
    assert(valideazaMedicament(p) == 1);

    destroyMedicament(m);
    destroyMedicament(p);
    destroyMedicament(o);
    destroyMedicament(i);
    destroyMedicament(d);

}

void testUpdate()
{
    Farmacie list = createFarmacie();
    List* f = list.lista;
    Medicament* m = createMedicament(19, "nurofen", 3, 10);
    setStoc(m, 10);
    addEntitate(f, m);

    assert(updateEnt(&list, 20, "newname", 9) == -1);
    assert(updateEnt(&list, 19, "newname", 10) == 0);

    destroyAll(&list);

}
void testCauta()
{
    Farmacie list = createFarmacie();
    List* f = list.lista;
    Medicament* m = createMedicament(19, "nurofen", 3, 10);
    addEntitate(f, m);
    assert(checkId(&list, 19) == 1);
    assert(checkId(&list, 30) == 0);

    destroyAll(&list);
}

void testAddEntitate()
{
    Farmacie list = createFarmacie();

    addEnt(&list, 19, "nurofen", 3, 10);
    addEnt(&list, 20, "paracetamol", 4, 10);
    addEnt(&list, 10, "ceva", 10, 2);
    assert(list.lista->dimensiune == 3);
    Medicament* p = get(list.lista, 0);

    assert(19 == p->id);
    assert(10 == p->stoc);
    assert(3 == p->concentratie);

    assert(addEnt(&list, -12, "a", -1, 0) == 0);

    destroyAll(&list);

}

void testDeleteEntitate()
{
    Farmacie list = createFarmacie();
    Medicament* elem1 = createMedicament(19, "nurofen", 3, 10);
    Medicament* elem2 = createMedicament(20, "paracetamol", 4, 10);
    Medicament* elem3 = createMedicament(10, "ceva", 10, 2);
    addEntitate(list.lista, elem1);
    addEntitate(list.lista, elem2);
    addEntitate(list.lista, elem3);
    assert(deleteEnt(&list, 19) == 1);
    assert(deleteEnt(&list, 21) == 0);
    destroyFarmacie(&list);
}

void testAsiguraCapacitate()
{
    List* f = createList(destroyMedicament);
    Medicament* m = createMedicament(19, "nurofen", 3, 10);
    Medicament* m1 = createMedicament(20, "ceva", 8, 100);
    Medicament* m2 = createMedicament(21, "altceva", 1, 19);
    addEntitate(f, m);
    addEntitate(f, m1);
    assert(f->capacitate == 2);
    addEntitate(f, m2);
    assert(f->capacitate == 4);
    assert(f->dimensiune == 3);
    destroyList(f);

}

void testAddStoc()
{
    Farmacie list = createFarmacie();

    addEnt(&list, 19, "nurofen", 9, 10);
    addStoc(&list, 19);
    Medicament* m = get(list.lista, 0);
    assert(getStoc(m) == 11);

    destroyAll(&list);

}

void testSortareStoc()
{
    Farmacie list = createFarmacie();

    addEnt(&list, 19, "nurofen", 3, 10);
    addEnt(&list, 21, "ceva", 8, 100);
    addEnt(&list, 22, "ceva", 8, 1);
    addEnt(&list, 26, "ceva", 8, 3);
    addEnt(&list, 23, "ceva", 8, 9);

    List* f1 = sortareStoc(&list);

    assert(f1->dimensiune == 5);

    for (int i = 0; i < f1->dimensiune - 1; i++)
    {
        Medicament* m1 = get(f1, i);
        Medicament* m2 = get(f1, i + 1);
        assert(m1->stoc <= m2->stoc);

    }

    destroyList(f1);
    destroyAll(&list);
}

void testSortareNume()
{
    Farmacie list = createFarmacie();

    addEnt(&list, 19, "nurofen", 3, 10);
    addEnt(&list, 21, "ceva", 8, 100);
    addEnt(&list, 22, "aaa", 8, 1);
    addEnt(&list, 26, "cea", 8, 3);
    addEnt(&list, 23, "eva", 8, 9);

    List* f1 = sortareNume(&list);

    assert(f1->dimensiune == 5);

    for (int i = 0; i < f1->dimensiune - 1; i++)
    {
        Medicament* m1 = get(f1, i);
        Medicament* m2 = get(f1, i + 1);
        assert((int)strcmp(m1->nume, m2->nume) < 0);

    }

    destroyList(f1);
    destroyAll(&list);
}



void testSet()
{
    List* f = createList(destroyMedicament);
    Medicament* m = createMedicament(19, "nurofen", 3, 10);
	Medicament* m1 = createMedicament(20, "ceva", 8, 100);
	Medicament* m2 = createMedicament(21, "altceva", 1, 19);
	addEntitate(f, m);
	addEntitate(f, m1);
	addEntitate(f, m2);
	Medicament* temp = createMedicament(10, "nurofen", 3, 10);
    Medicament* aux = set(f, 0, temp);
    assert(aux->id == 19);
    assert(getId(f->medicamente[0]) == 10);
    destroyMedicament(aux);
	destroyList(f);
}

void testGetConcentratie()
{
    Medicament* m = createMedicament(19, "nurofen", 3, 10);
	assert(getConcentratie(m) == 3);
	destroyMedicament(m);
}

void testGetNume()
{
    Medicament* m = createMedicament(19, "nurofen", 3, 10);
	assert(strcmp(getNume(m), "nurofen") == 0);
	destroyMedicament(m);
}

void testGetStoc()
{
    Medicament* m = createMedicament(19, "nurofen", 3, 10);
	assert(getStoc(m) == 10);
	destroyMedicament(m);
}



void testUndo()
{
    Farmacie list = createFarmacie();
	addEnt(&list, 19, "nurofen", 3, 10);
	addEnt(&list, 21, "ceva", 10, 100);
	addEnt(&list, 22, "aaa", 15, 1);
	addEnt(&list, 26, "cea", 5, 3);
	addEnt(&list, 23, "eva", 8, 9);
	int error = undoService(&list);
    assert(error == 0);
    error = undoService(&list);
	assert(error == 0);
    error = undoService(&list);
	assert(error == 0);
    error = undoService(&list);
	assert(error == 0);
    error = undoService(&list);
	assert(error == 0);
    error = undoService(&list);
	assert(error == 1);
	destroyFarmacie(&list);
}

void testSortareNumeInsertionSort()
{
	Farmacie list = createFarmacie();
	addEnt(&list, 19, "nurofen", 3, 10);
	addEnt(&list, 21, "ceva", 8, 100);
	addEnt(&list, 22, "aaa", 8, 1);
	addEnt(&list, 26, "cea", 8, 3);
	addEnt(&list, 23, "eva", 8, 9);
	List* f1 = sortareNumeInsertionSort(&list);
	assert(f1->dimensiune == 5);
	for (int i = 0; i < f1->dimensiune - 1; i++)
	{
		Medicament* m1 = get(f1, i);
		Medicament* m2 = get(f1, i + 1);
		assert((int)strcmp(m1->nume, m2->nume) < 0);
	}
	destroyList(f1);
	destroyAll(&list);
}

void testSortareStocInsertionSort()
{
	Farmacie list = createFarmacie();
	addEnt(&list, 19, "nurofen", 3, 10);
	addEnt(&list, 21, "ceva", 8, 100);
	addEnt(&list, 22, "aaa", 8, 1);
	addEnt(&list, 26, "cea", 8, 3);
	addEnt(&list, 23, "eva", 8, 9);
	List* f1 = sortareStocInsertionSort(&list);
	assert(f1->dimensiune == 5);
	for (int i = 0; i < f1->dimensiune - 1; i++)
	{
		Medicament* m1 = get(f1, i);
		Medicament* m2 = get(f1, i + 1);
		assert(m1->stoc <= m2->stoc);
	}
	destroyList(f1);
	destroyAll(&list);
}

void testFilter()
{
    Farmacie list = createFarmacie();
    addEnt(&list, 19, "nurofen", 3, 10);
    addEnt(&list, 21, "ceva", 10, 100);
    addEnt(&list, 22, "aaa", 15, 1);
    addEnt(&list, 26, "cea", 5, 3);
    addEnt(&list, 23, "eva", 8, 9);
    int val1 = 10;
    param el1 = &val1;
    List* f1 = filter(&list, cmpStoc, el1);
    assert(f1->dimensiune == 3);
    assert(getId(f1->medicamente[0]) == 22);
    assert(getId(f1->medicamente[1]) == 26);
    assert(getId(f1->medicamente[2]) == 23);
    destroyList(f1);
    float val2 = 8.00;
    param el2 = &val2;
    List* f2 = filter(&list, cmpConcentratie, el2);
    assert(f2->dimensiune == 2);
    assert(getId(f2->medicamente[0]) == 19);
    assert(getId(f2->medicamente[1]) == 26);
    destroyList(f2);
    List* f3 = filter(&list, cmpNume, 'c');
	assert(f3->dimensiune == 2);
	assert(getId(f3->medicamente[0]) == 21);
	assert(getId(f3->medicamente[1]) == 26);
	destroyList(f3);
	destroyAll(&list);
}

void runAllTests()
{
    testValideazaMedicament();
    testCauta();
    testAddEntitate();
    testDeleteEntitate();
    testUpdate();
    testSet();
    testAsiguraCapacitate();
    testAddStoc();
    testSortareNume();
    testSortareStoc();
    testGetConcentratie();
    testGetStoc();
    testGetNume();
    testSortareNumeInsertionSort();
    testSortareStocInsertionSort();
    testFilter();
    testUndo();
}


