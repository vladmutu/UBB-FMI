#include "Dictionar.h"
#include <iostream>
#include "IteratorDictionar.h"


//Complexitate Teta(m)
Dictionar::Dictionar() {
	/* de adaugat */
    this->dimensiune = 0;
    this->m = 10;
    this->prim = nullptr;
    this->tabela = new Nod*[m];
    for(int i = 0; i < m; i++)
        this->tabela[i] = nullptr;
}

Dictionar::~Dictionar() {
	/* de adaugat */
    delete[] tabela;
}

//Complexitate:
//BestCase: Teta(1) cand dictionarul este gol
//WorstCase: Teta(m) se cheia nu exista in dictionar
//Complexitate finala: O(m)
TValoare Dictionar::adauga(TCheie c, TValoare v){
    /* de adaugat */
    int poz = hash(c);
    Nod* p = tabela[poz];
    while(p != nullptr){
        if(p->elem.first == c){
            TValoare val = p->elem.second;
            p->elem.second = v;
            return val;
        }
        p = p->urm;
    }
    Nod* nou = new Nod;
    nou->elem.first = c;
    nou->elem.second = v;
    nou->urm = tabela[poz];
    tabela[poz] = nou;
    dimensiune++;
    return NULL_TVALOARE;
}



//Complexitate:
//BestCase: Teta(1) cand dictionarul este gol
//WorstCase: Teta(m) cand cheia nu exista in dictionar
//Complexitate finala: O(m)
TValoare Dictionar::cauta(TCheie c) const{
    /* de adaugat */
    int poz = hash(c);
    Nod* p = tabela[poz];
    while(p != nullptr){
        if(p->elem.first == c)
            return p->elem.second;
        p = p->urm;
    }
    return NULL_TVALOARE;
}

//Complexitate:
//BestCase: Teta(1) cand nu exista nicio cheie la pozitia la care suntem trimisi de functia de dispersie
//WorstCase: Teta(n) cand cheia nu exista in dictionar/dictionarul contine doar cheia de sters
//Complexitate finala: O(n)
TValoare Dictionar::sterge(TCheie c){
    /* de adaugat */
    int poz = hash(c);
    Nod* p = tabela[poz];
    Nod* ant = nullptr;
    while(p != nullptr){
        if(p->elem.first == c){
            if(ant == nullptr)
                tabela[poz] = p->urm;
            else
                ant->urm = p->urm;
            TValoare val = p->elem.second;
            delete p;
            dimensiune--;
            return val;
        }
        ant = p;
        p = p->urm;
    }
    return NULL_TVALOARE;
}

//Complexitate Teta(1)
int Dictionar::dim() const {
	/* de adaugat */
    return dimensiune;
}

//Complexitate Teta(1)
bool Dictionar::vid() const{
    /* de adaugat */
    return dimensiune == 0;
}


IteratorDictionar Dictionar::iterator() const {
    /* de adaugat */
    return IteratorDictionar(*this);
}


//Pseudocod:
//subalg cea...(d)
//1. frecventa = new int[m]
//2. pentru i<-0, i<m
//3.      frecventa[i] = 0
//4. sf_pentru
//5. pentru i<-0, i<m
//6.     Nod| p = d.tabela[i]
//7.     cat_timp p != NIL
//8.        frecventa[p->elem.second]++
//9.        p = [p].urm
//10.    sf_cat_timp
//11. sf_pentru
//12. max = 0
//13. pentru i<-0, i<m
//14.     daca frecventa[i] > frecventa[max]
//15.         max = i
//16. sf_pentru
//17. delete[] frecventa
//18. returneaza max
//Complexitate:
//BestCase: Teta(m+n) cand la fiecare nod* al tabelei de dispersie se afla o singura cheie
//WorsCase: Teta(m+n) cand toate cheile se afla la aceeasi pozitie in tabela de dispersie(pozitie aleasa de functia de dispersie)
//(n este numarul de chei de la acea pozitie)
//Complexitate finala: Teta(m+n)
TValoare Dictionar::ceaMaiFrecventaValoare() const {
    int* frecventa = new int[1000];
    for(int i = 0; i < 1000; i++)
        frecventa[i] = 0;
    for(int i = 0; i < m; i++){
        Nod* p = tabela[i];
        while(p != nullptr){
            frecventa[p->elem.second]++;
            p = p->urm;
        }
    }
    int max = 0;
    for(int i = 0; i < 1000; i++)
        if(frecventa[i] > frecventa[max])
            max = i;
    delete[] frecventa;
    return max;
}


