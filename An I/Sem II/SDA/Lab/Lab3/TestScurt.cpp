#include "TestScurt.h"

#include <assert.h>
#include <exception>


#include "Lista.h"
#include "IteratorLP.h"
#include <iostream>



using namespace std;

void testAll() {

    Lista lista = Lista();
    assert(lista.dim() == 0);
    assert(lista.vida());

    lista.adaugaSfarsit(1);
    assert(lista.dim() == 1);
    assert(!lista.vida());

    IteratorLP it = lista.cauta(1);
    assert(it.valid());
    assert(it.element() == 1);
    it.urmator();
    assert(!it.valid());
    it.prim();
    assert(it.valid());
    assert(it.element() == 1);

    assert(lista.sterge(it) == 1);
    assert(lista.dim() == 0);
    assert(lista.vida());

    lista.adaugaInceput(1);
    assert(lista.dim() == 1);
    assert(!lista.vida());


    //teste functionalitate noua
    Lista lista2 = Lista();
    lista2.adaugaSfarsit(1);
    lista2.adaugaSfarsit(2);
    lista2.adaugaSfarsit(3);
    assert(lista2.dim() == 3);
    IteratorLP it2 = lista2.cauta(2);
    it2.elimina();
    assert(lista2.dim() == 2);
    assert(it2.element() == 3);
    it2.prim();
    assert(it2.element() == 1);
}

