#include "IteratorMDO.h"
#include "MDO.h"
#include <iostream>
#include <vector>

#include <exception>
using namespace std;

/*
 * Complexitate: O(1)
 * Constructor
 */
MDO::MDO(Relatie r) {
    this->rel = r;
    this->ultim = nullptr;
    this->prim = nullptr;
    this->dimensiune = 0;
}

/*Complexitate: O(n)
 * Best Case: Tetha(1) // dictionarul nu contine nicio cheie
 * Worst Case: Tetha(n) // adaugam la finalul dictionarului
 * T(n)=O(n)
 */
void MDO::adauga(TCheie c, TValoare v) {
    Nod* nod = new Nod();
    nod->cheie = c;
    nod->valoare = v;
    nod->urm = nullptr;
    nod->prec = nullptr;
    if(this->prim == nullptr) {
        this->prim = nod;
        this->ultim = nod;
    } else {
        Nod* nodCurent = this->prim;
        Nod* nodAnterior = nullptr;
        while(nodCurent != nullptr && this->rel(nodCurent->cheie, c)) {
            nodAnterior = nodCurent;
            nodCurent = nodCurent->urm;
        }
        if(nodAnterior == nullptr) {
            nod->urm = this->prim;
            this->prim->prec = nod;
            this->prim = nod;
        } else if(nodCurent == nullptr) {
            nod->prec = this->ultim;
            this->ultim->urm = nod;
            this->ultim = nod;
        } else {
            nod->urm = nodCurent;
            nod->prec = nodCurent->prec;
            nodCurent->prec->urm = nod;
            nodCurent->prec = nod;
        }
    }
    dimensiune++;
}

/*
 * Complexitate: O(n)
 * Best Case: Tetha(1) // dictionar gol
 * Worst Case: O(n) // dictionarul nu contine cheia
 * T(n)=O(n)
 */
vector<TValoare> MDO::cauta(TCheie c) const {
    vector<TValoare> v;
    for(Nod* nod = this->prim; nod != nullptr; nod = nod->urm) {
        if(nod->cheie == c) {
            v.push_back(nod->valoare);
        }
    }
    return v;
}

/*
 * Complexitate: O(n)
 * Best Case: Tetha(1) // dictionarul este gol
 * Worst Case: O(n) // dictionarul nu contine cheia si valoarea
 * T(n)=O(n)
 */
bool MDO::sterge(TCheie c, TValoare v) {
    for(Nod* nod = this->prim; nod != nullptr; nod = nod->urm) {
        if(nod->cheie == c && nod->valoare == v) {
            if(nod->prec != nullptr) {
                nod->prec->urm = nod->urm;
            }
            if(nod->urm != nullptr) {
                nod->urm->prec = nod->prec;
            }
            if(nod == this->prim) {
                this->prim = nod->urm;
            }
            if(nod == this->ultim) {
                this->ultim = nod->prec;
            }
            delete nod;
            dimensiune--;
            return true;
        }
    }
    return false;
}

/*
 * Complexitate: Tetha(1)
 * Best Case: Tetha(1)
 * Worst Case: Tetha(1)
 * T(n)=Tetha(1)
 */
int MDO::dim() const {
    return this->dimensiune;
}

/*
 * Complexitate: Tetha(1)
 * Best Case: Tetha(1)
 * Worst Case: Tetha(1)
 * T(n)=Tetha(1)
 */
bool MDO::vid() const {
    return this->dimensiune == 0;
}


/*
 * fie m nr de noduri din mdo si n nr de noduri din this n<m
 * Best Case: O(m^2) // daca dictionarele sunt identice
 * Worst Case: O(m^2*n) // daca dictionarele nu au chei si valori comune
 * T(n)=O(m^3*n)
 */
/*
 * Pseudocod(curent, mdo):
 * nrAdaugari <- 0
 * pentru fiecare nod din mdo executa
 *      daca cauta(curent, nod.cheie) = 0 sau cauta(curent, nod.cheie) != cauta(mdo, nod.cheie) atunci
 *          pentru fiecare val1 din cauta(mdo, nod.cheie) executa
 *              v <- cauta(curent, nod.cheie)
 *              exista <- fals
 *              pentru fiecare val2 din v executa
 *                  daca val1 = val2 atunci
 *                      exista <- adevarat
 *                  sf daca
 *              sf pentru
 *              daca exista = fals atunci
 *                  adauga(curent, nod.cheie, val1)
 *                  nrAdaugari <- nrAdaugari + 1
 *              sf daca
 *          sf pentru
 *      sf daca
 * sf pentru
 * returneaza nrAdaugari
 */
int MDO::adaugaInexistente(MDO &mdo) {
    int nrAdaugari = 0;
    for(Nod* nod = mdo.prim; nod != nullptr; nod = nod->urm) {//O(m)
        if (this->cauta(nod->cheie).size() == 0 or this->cauta(nod->cheie).size() != mdo.cauta(nod->cheie).size()) //O(m)
            for (TValoare val1: mdo.cauta(nod->cheie)) {//O(m)
                vector<TValoare> v = this->cauta(nod->cheie);//O(n)
                bool exista = false;
                for(TValoare val2: v) {//O(n)
                    if(val1 == val2) {
                        exista = true;
                    }
                }
                if(!exista) {
                    this->adauga(nod->cheie, val1);//O(n)
                    nrAdaugari++;
                }
            }
    }
    return nrAdaugari;
}

IteratorMDO MDO::iterator() const {
	return IteratorMDO(*this);
}

/*
 * Complexitate: O(n)
 * Best Case: Tetha(1)
 * Worst Case: O(n)
 * T(n)=O(n)
 */
MDO::~MDO() {
    Nod* nod = this->prim;
    while(nod != nullptr) {
        Nod* urm = nod->urm;
        delete nod;
        nod = urm;
    }
}
