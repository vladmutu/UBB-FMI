#include "IteratorMDO.h"
#include "MDO.h"

/*Complexitate: O(1)*/
IteratorMDO::IteratorMDO(const MDO& d) : dict(d){
	/* de adaugat */
    this->pozitie = 0;
    this->curent = this->dict.prim;
    this->ultim = this->dict.ultim;

}

/*Complexitate: O(1)*/
void IteratorMDO::prim(){
	/* de adaugat */
    this->curent = this->dict.prim;
    this->ultim = this->dict.ultim;
    this->pozitie = 0;
}

/*Complexitate: O(1)*/
void IteratorMDO::urmator(){
	/* de adaugat */
    if (this->valid())
    {
        this->curent = this->curent->urm;
        this->pozitie++;
    }
    else
    {
        throw exception();
    }
}

/*Complexitate: O(1)*/
bool IteratorMDO::valid() const{
    return this->curent != nullptr;
}

/*Complexitate: O(1)*/
TElem IteratorMDO::element() const{
    /* de adaugat */
    if (this->valid())
    {
        return TElem(this->curent->cheie, this->curent->valoare);
    }
    else
    {
        throw exception();
    }
}


