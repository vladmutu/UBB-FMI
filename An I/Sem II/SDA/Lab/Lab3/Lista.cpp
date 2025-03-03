#include <exception>
#include "Lista.h"
#include "IteratorLP.h"

/*
 * Complexitate totala: Teta(MAX_SIZE)
 */
Lista::Lista() {
    dimensiune = 0;
    primul = -1;
    for(int i = 0; i < MAX_SIZE; i++)
    {
        urmator[i] = i + 1;
        elems[i] = 0;
    }
    urmator[MAX_SIZE - 1] = -1;
    primLiber = 0;
}

//Complexitate Teta(1)
int Lista::dim() const {
    return dimensiune;
}

//Complexitate Teta(1)
bool Lista::vida() const {
    if(dimensiune == 0)
        return true;
    return false;
}

//Complexitate Teta(1)
IteratorLP Lista::prim(){
    return IteratorLP(*this);
}

//Complexitate Teta(1)
TElem Lista::element(IteratorLP poz) const {
    return poz.element();
}

//Complexitate:
//Teta(1) - cazul in care lista e vida(Best Case)
//Teta(n) - cazul in care se sterge de pe ultima pozitie(Worst Case)
//Teta(n) - cazul general
//Complexitate finala: O(n)
TElem Lista::sterge(IteratorLP& poz) {
    if(!poz.valid())
        throw std::exception();
    IteratorLP it(*this);
    int poz_anterior = it.curent;
    TElem to_delete = poz.element();

    while(it.curent != poz.curent)
    {
        poz_anterior = it.curent;
        it.urmator();
    }
    urmator[poz_anterior] = urmator[poz.curent];
    int toDealoc = poz.curent;
    poz.curent = urmator[poz.curent];
    dealoca(toDealoc);
    dimensiune--;
    return to_delete;
}

//Complexitate:
//Teta(1) - cazul in care lista e vida
//Teta(n) - cazul general
//Best Case: Teta(1) - cand elementul e pe prima pozitie
//Worst Case: Teta(n) - cand elementul nu exista in lista
//Complexitate finala: O(n)
IteratorLP Lista::cauta(TElem e){
    IteratorLP it(*this);
    while(it.valid())
    {
        if(it.element() == e)
            break;
        it.urmator();
    }
    return it;
}

//Complexitate:
//Teta(1) - cazul in care lista e vida
//Teta(1) - cazul general(Best Case = Worst Case)
//Complexitate finala: Teta(1)
TElem Lista::modifica(IteratorLP poz, TElem e) {
    if(!poz.valid())
        throw std::exception();
    TElem to_return = poz.element();
    elems[poz.curent] = e;
    return to_return;
}

//Complexitate:
//Teta(1) - cazul in care lista e vida(Best Case)
//Teta(n) - cazul in care se adauga la final(Worst Case)
//Caz general: O(n)
//Complexitate finala: O(n)
void Lista::adauga(IteratorLP& poz, TElem e) {
    if(!poz.valid())
        throw std::exception();

    if(dimensiune == 0)
        adaugaInceput(e);

    int i = creeazaNod(e);

    if(i!=-1)
    {
        IteratorLP it(*this);
        int poz_anterior = it.curent;

        while(it.curent != poz.curent)
        {
            poz_anterior = it.curent;
            it.urmator();
        }

        urmator[poz_anterior] = i;
        urmator[i] = it.curent;
        poz.curent = i;
        dimensiune++;
    }
}

//Complexitate:
//Teta(1) in orice caz(Best Case = Worst Case)
//Complexitate finala: Teta(1)
void Lista::adaugaInceput(TElem e) {
    int i = creeazaNod(e);

    if (i != -1)
    {
        urmator[i] = primul;
        primul = i;
        dimensiune++;
    }
}

//Complexitate:
//Teta(1) - cazul in care lista e vida(Best Case)
//Teta(n) - cand se adauga la final(Worst Case)(Orice caz in afara de Best Case)
//Complexitate finala: O(n)
void Lista::adaugaSfarsit(TElem e) {
    if (dimensiune == 0)
    {
        adaugaInceput(e);
        return;
    }

    int i = creeazaNod(e);
    if (i != -1)
    {
        int poz = primul;
        while (urmator[poz] != -1)
        {
            poz = urmator[poz];
        }
        urmator[poz] = i;
        dimensiune++;
    }
}

//Complexitate Teta(1)
void Lista::dealoca(int i) {
    urmator[i] = primLiber;
    primLiber = i;
}

//Complexitate Teta(1)
int Lista::aloca() {
    int i = primLiber;
    primLiber = urmator[primLiber];
    return i;
}

//Complexitate Teta(1)
int Lista::creeazaNod(TElem e) {
    int i = aloca();
    if (i != -1) {
        elems[i] = e;
        urmator[i] = -1;
    }
    return i;
}

Lista::~Lista() {
}