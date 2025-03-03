#include "TestScurt.h"
#include "Colectie.h"
#include "IteratorColectie.h"
#include <assert.h>

void testAll() {
	Colectie c;
	c.adauga(5);
	c.adauga(6);
	c.adauga(0);
	c.adauga(5);
	c.adauga(10);
	c.adauga(8);

	assert(c.dim() == 6);
	assert(c.nrAparitii(5) == 2);

	assert(c.sterge(5) == true);
	assert(c.dim() == 5);

	assert(c.cauta(6) == true);
	assert(c.vida() == false);

	IteratorColectie ic = c.iterator();
	assert(ic.validUrmator() == true);
	while (ic.validUrmator()) {
		ic.element();
		ic.urmator();
	}
	assert(ic.validUrmator() == false);
	ic.prim();
	assert(ic.validUrmator() == true);


    Colectie c2;
    c2.adauga(5);
    c2.adauga(6);
    c2.adauga(0);
    c2.adauga(5);
    c2.adauga(10);
    c2.adauga(8);

    IteratorColectie ic2 = c2.iterator();
    ic.ultim();
    while(ic2.validAnterior())
    {
        ic.element();
        ic.anterior();
    }
    assert(ic2.validAnterior() == false);
    ic2.ultim();
    assert(ic2.validAnterior() == true);
}
