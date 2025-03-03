#include "Matrice.h"

#include <exception>

using namespace std;

//Complexitate: Tetha(n*m)
Matrice::Matrice(int m, int n) {
    nrLiniiMatrice = m;
    nrColoaneMatrice = n;
    // creez matricea
    matrice = new Nod*[nrLiniiMatrice];
    radacina = new Nod();
    for(int i = 0; i < nrLiniiMatrice; i++)
    {
        matrice[i] = new Nod[nrColoaneMatrice];
        for(int j = 0; j < nrColoaneMatrice; j++)
        {
            matrice[i][j].stanga = nullptr;
            matrice[i][j].dreapta = nullptr;
            matrice[i][j].linie = -1;
            matrice[i][j].coloana = -1;
            matrice[i][j].valoare = NULL_TELEMENT;
        }
    }
}


//Complexitate Teta(1)
int Matrice::nrLinii() const{
	/* de adaugat */
	return nrLiniiMatrice;
}

//Complexitate Teta(1)
int Matrice::nrColoane() const{
	/* de adaugat */
	return nrColoaneMatrice;
}

//Complexitate:
//BestCase Teta(1) cand nu se da o pozitie valida in matrice sau cand nodul cautat se afla in radacina
//WorstCase Teta(h) (log n*m)cand nodul cautat se afla pe o frunza a arborelui aflata la adancimea maxima a arborelui
//Final - O(h) (log n*m)
TElem Matrice::element(int i, int j) const{
    /* de adaugat */
    if(i < 0 || i > nrLiniiMatrice || j < 0 || j > nrColoaneMatrice)
        throw exception();
    return cautaNod(radacina, i, j);
}


//Complexitate:
//BestCase - cand nu se da o pozitie valida in matrice Teta(1) sau cand se modifica un element care se afla in radacina
//WorstCase - Teta(h) (log n*m)cand se modifica un element care se afla pe o frunza a arborelui aflata la adancimea maxima a arborelui
//Final - O(h) (log n*m)
TElem Matrice::modifica(int i, int j, TElem e) {
    if(i < 0 || i > nrLiniiMatrice || j < 0 || j > nrColoaneMatrice)
        throw exception();
    TElem valoare = cautaNod(radacina, i, j);
    if(valoare == NULL_TELEMENT)
    {
        Nod* nod = creeazaNod(i, j, e);
        Nod* nodCurent = radacina;
        while(true)
        {
            if(nodCurent->linie > i || (nodCurent->linie == i && nodCurent->coloana > j))
            {
                if(nodCurent->stanga == nullptr)
                {
                    nodCurent->stanga = nod;
                    break;
                }
                nodCurent = nodCurent->stanga;
            }
            else
            {
                if(nodCurent->dreapta == nullptr)
                {
                    nodCurent->dreapta = nod;
                    break;
                }
                nodCurent = nodCurent->dreapta;
            }
        }
    }
    else
    {
        Nod* nodCurent = radacina;
        while(true)
        {
            if(nodCurent->linie == i && nodCurent->coloana == j)
            {
                nodCurent->valoare = e;
                break;
            }
            if(nodCurent->linie > i || (nodCurent->linie == i && nodCurent->coloana > j))
                nodCurent = nodCurent->stanga;
            else
                nodCurent = nodCurent->dreapta;
        }
    }
    return valoare;
}


//Complexitate: Teta(1)
Matrice::Nod* Matrice::creeazaNod(int linie, int coloana, TElem valoare) {
    Nod* nod = new Nod();
    nod->linie = linie;
    nod->coloana = coloana;
    nod->valoare = valoare;
    nod->stanga = nullptr;
    nod->dreapta = nullptr;
    return nod;
}

//Complexitate:
//BestCase - Cand elementul se afla in radacina sau arborele nu are elemente Teta(1)
//WorstCase - cand elementul se afla pe o frunza a arborelui aflata la adancimea maxima a arborelui Teta(h)(log n*m)
//Final - O(h)(log n*m)
TElem Matrice::cautaNod(Matrice::Nod *nod, int linie, int coloana) const {
    if(nod == nullptr)
        return NULL_TELEMENT;
    if(nod->linie == linie && nod->coloana == coloana)
        return nod->valoare;
    if(nod->linie > linie || (nod->linie == linie && nod->coloana > coloana))
        return cautaNod(nod->stanga, linie, coloana);
    return cautaNod(nod->dreapta, linie, coloana);
}

//Complexitate: O(nrLinii*nrColoane*h) (n*m*log n*m)
//Best Case - Teta(n*m) cand arborele nu are elemente
//Worst Case - Teta(nrLinii*nrColoane*h)(n*m*log n*m) cand arborele are elemente

//Pseudocod
//subalgoritm_valoareMaxima(matrice, max)
//    max <- -1
//    pentru i <- 0, nrLiniiMatrice executa
//        pentru j <- 0, nrColoaneMatrice executa
//          daca element(matrice,i,j) > max atunci
//              max <- element(matrice,i,j)
//          sf_daca
//        sf_pentru
//    sf_pentru
//    daca max == -1 atunci
//        returneaza NULL_TELEMENT
//    sf_daca
//    returneaza max
int Matrice::valoareMaxima() const {
    int max = -1;
    for(int i = 0; i < nrLiniiMatrice; i++)
        for(int j = 0; j < nrColoaneMatrice; j++)
            if(element(i,j) > max)
                max = element(i,j);
    if(max == -1)
        return NULL_TELEMENT;
    return max;
}