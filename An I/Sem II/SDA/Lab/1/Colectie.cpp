#include "Colectie.h"
#include "IteratorColectie.h"
#include <iostream>

using namespace std;

bool rel(TElem e1, TElem e2) {
    return e1 <= e2;
}

Colectie::Colectie() {
    this->lungime = 0;
    this->capacitate = 1;
    this->elemente = new Pereche[this->capacitate];
}

/*
 * Complexitate: O(n)
 * Best Case: Tetha(1)
 * Worst Case: Tetha(n)
 * T(n)=O(n)
 */
void Colectie::adauga(TElem e) {
    if(lungime == 0)
    {
        Pereche p{};
        p.element = e;
        p.frecventa = 1;
        this->elemente[0] = p;
        lungime++;
        return;
    }
    bool gasit = false;
    int poz = cautareBinara(this->elemente, 0, this->lungime-1, e, gasit);
    if( gasit )
        this->elemente[poz].frecventa++;
    else
    {
        if(lungime == capacitate)
            resize();
        for(int i = lungime; i > poz; i--)
            this->elemente[i] = this->elemente[i-1];
        Pereche p;
        p.element = e;
        p.frecventa = 1;
        this->elemente[poz] = p;
        lungime++;
    }
}

/*
 * Complexitate: O(n)
 * Best Case: Tetha(1)
 * Worst Case: O(n)
 * T(n)=O(n)
 */
bool Colectie::sterge(TElem e) {
    bool gasit = false;
    int poz = cautareBinara(this->elemente, 0, this->lungime-1, e, gasit);
    if(gasit)
    {
        if(this->elemente[poz].frecventa > 1)
            this->elemente[poz].frecventa--;
        else
        {
            for(int i = poz; i < this->lungime-1; i++)
                this->elemente[i] = this->elemente[i+1];
            lungime--;
        }
        return true;
    }
	return false;
}

/*
 * Complexitate: O(n)
 * cautare secventiala
 * BestCase = O(1)
 * WorstCase = O(n)
 */
bool Colectie::cauta(TElem elem) const {
    for(int i = 0; i<this->lungime;i++)
        if(this->elemente[i].element == elem)
            return true;
	return false;
}

/*
 * Complexitate: T(n)=O(logn)
 * Best Case: O(1)
 * Worst Case: O(logn)
 */
int Colectie::nrAparitii(TElem elem) const {
    bool gasit = false;
    int poz = cautareBinara(this->elemente, 0, this->lungime-1, elem, gasit);
    if( gasit )
        return this->elemente[poz].frecventa;
	return 0;
}


/*
 * Complexitate: Tetha(n)
 * parcurgere secventiala
 */
int Colectie::dim() const {
    int nr = 0;
    for(int i = 0; i < this->lungime; i++)
        nr += this->elemente[i].frecventa;
    return nr;
}

/*
 * Complexitate: Tetha(1)
 * BestCase = WorstCase = Tetha(1)
 */
bool Colectie::vida() const {
    if(this->lungime == 0)
	    return true;
    return false;
}

//Complexitate: T(n) = Tetha(n)
//BestCase == WorstCase: Tetha(n)
//functie de redimensionare a colectiei
void Colectie::resize() {
    this->capacitate *= 2;
    Pereche* aux = new Pereche[this->capacitate];
    for(int i = 0; i < this->lungime; i++)
        aux[i] = elemente[i];
    delete[] elemente;
    elemente = aux;
}

//Complexitate: O(logn)
//BestCase: O(1)
//WorstCase: O(logn)
//T(n)=O(logn)
//cautare binara
int Colectie::cautareBinara(Pereche* elemente, int st, int dr, TElem e, bool &gasit) const{
    int mijloc = 0;
    while (st <= dr && !gasit) {
        mijloc = (st + dr) / 2;
        if (e == elemente[mijloc].element) {
            gasit = true;
        }
        else {
            if (rel(e, elemente[mijloc].element))
                dr = mijloc - 1;
            else
                st = mijloc + 1;
        }
    }
    if (rel(e, elemente[mijloc].element))
        return mijloc;
    return mijloc + 1;
}

IteratorColectie Colectie::iterator() const {
	return  IteratorColectie(*this);
}


Colectie::~Colectie() {
    delete[] elemente;
}
