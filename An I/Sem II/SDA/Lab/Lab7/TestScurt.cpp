#include "TestScurt.h"
#include <assert.h>
#include "Matrice.h"
#include <iostream>

using namespace std;

void testAll() { //apelam fiecare functie sa vedem daca exista
	Matrice m(4,4);
	assert(m.nrLinii() == 4);
	assert(m.nrColoane() == 4);
	//adaug niste elemente
	m.modifica(1,1,5);
	assert(m.element(1,1) == 5);
	m.modifica(1,1,6);
	assert(m.element(1,2) == NULL_TELEMENT);
    Matrice m2(4,4);
    assert(m2.nrLinii() == 4);
    assert(m2.nrColoane() == 4);
    m2.modifica(0,0,5);
    m2.modifica(0,1,6);
    m2.modifica(0,2,7);
    m2.modifica(0,3,8);
    m2.modifica(1,0,9);
    m2.modifica(1,1,20);
    m2.modifica(1,2,11);
    m2.modifica(1,3,12);
    m2.modifica(2,0,13);
    m2.modifica(2,1,14);
    m2.modifica(2,2,15);
    m2.modifica(2,3,16);
    m2.modifica(3,0,17);
    m2.modifica(3,1,18);
    m2.modifica(3,2,19);
    m2.modifica(3,3,5);
    assert(m2.valoareMaxima() == 20);


}
