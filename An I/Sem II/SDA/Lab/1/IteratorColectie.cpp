#include "IteratorColectie.h"
#include "Colectie.h"

#include <iostream>

IteratorColectie::IteratorColectie(const Colectie& c): col(c) {
    pozitie = 0;
    frecventa = 1;
}

/*
 * Complexitate: Tetha(1)
 */
TElem IteratorColectie::element() const {
    if(validUrmator())
        return col.elemente[pozitie].element;
    throw std::exception();
}

/*
 * Complexitate: Tetha(1)
 */
bool IteratorColectie::validUrmator() const {
    return pozitie < col.lungime;
}

bool IteratorColectie::validAnterior() const {
    return pozitie > 0;
}

/*
 * Complexitate: O(1)
 */
void IteratorColectie::urmator() {
    if(validUrmator())
    {
        if( frecventa < col.elemente[pozitie].frecventa )
            frecventa++;
        else {
            pozitie++;
            frecventa = 1;
        }
    }
    else
        throw std::exception();

}

/*
 * Complexitate: O(1)
 * BestCase = WorstCase = O(1)
 */
/*Complexitate: Tetha(1)
 * Pseudocod:
 * algoritm
 * daca iteratorul e valid atunci
 *      daca frecventa > 1 atunci
 *          frecventa<- frecventa - 1
 *      altfel
 *          pozitie <- pozitie - 1
 *          frecventa <- elemente[pozitie].frecventa
 *      sf_daca
 * altfel
 *      arunca exceptie
 * sf_daca
 * sf_algoritm
 */
void IteratorColectie::anterior()
{
    if( validAnterior() )
    {
        if( frecventa > 1)
            frecventa--;
        else
        {
            pozitie--;
            frecventa = col.elemente[pozitie].frecventa;
        }
    }
    else
        throw std::exception();
}

/*
 * Complexitate: Tetha(1)
 */
void IteratorColectie::prim() {
    pozitie = 0;
    frecventa = 1;
}

/*
 * Complexitate: Tetha(1)
 */
void IteratorColectie::ultim()
{
    this->pozitie = col.lungime - 1;
    this->frecventa = col.elemente[pozitie].frecventa;
}
