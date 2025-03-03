#include "IteratorLP.h"
#include "Lista.h"
#include <exception>

//Complexitate Teta(1)
IteratorLP::IteratorLP(Lista& l):lista(l) {
    curent = l.primul;
}

//Complexitate Teta(1)
void IteratorLP::prim(){
    curent = lista.primul;
}

//Complexitate Teta(1)
void IteratorLP::urmator(){
    if(curent == -1)
        throw std::exception();

    curent = lista.urmator[curent];
}

//Complexitate Teta(1)
bool IteratorLP::valid() const{
    if(curent == -1)
        return false;
    return true;
}

//Complexitate Teta(1)
TElem IteratorLP::element() const{
    if(!valid())
        throw std::exception();

    return lista.elems[curent];
}


//Complexitate:
//Teta(1) - cazul in care iteratorul nu este valid(Best case)
//Teta(n) - cazul in care iteratorul se afla pe ultima pozitie(Worst case)(Din cauza lista.sterge())
//Complexitate finala: O(n)
//PSeudocod:
// daca iteratorul nu este valid
//      arunca exceptie
// TElem to_delete = lista.elems[curent]
// sterge(lista, |this)
// urmator()
// returneaza to_delete
TElem IteratorLP::elimina() {
    if(!valid())
        throw std::exception();
    TElem to_delete = lista.elems[curent];
    lista.sterge(*this);
    return to_delete;
}


