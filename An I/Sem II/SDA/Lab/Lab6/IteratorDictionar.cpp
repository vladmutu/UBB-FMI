#include "IteratorDictionar.h"
#include "Dictionar.h"

using namespace std;


//Complextitate:
//BestCase: Teta(1) cand dictionarul este gol
//WorstCAse: T(m) cand toate elementele sunt la aceeasi cheie si functia de dispersie le situeaza
//pe ultima pozitie in tabela
//Complexitate finala: O(m)
IteratorDictionar::IteratorDictionar(const Dictionar& d) : dict(d){
	/* de adaugat */
    this->curent = 0;
    while(curent < dict.m && dict.tabela[curent] == nullptr)
        curent++;
    if(curent < dict.m)
        nodCurent = dict.tabela[curent];
    else
        nodCurent = nullptr;

}


//Complexitate:
//BestCase: Teta(1) cand dictionarul este gol
//WorstCase: Teta(m) cand toate elementele sunt la aceeasi cheie si functia de dispersie le situeaza
//pe ultima pozitie in tabela
//Complexitate finala: O(m)
void IteratorDictionar::prim() {
    /* de adaugat */
    this->curent = 0;
    while(curent < dict.m && dict.tabela[curent] == nullptr)
        curent++;
    if(curent < dict.m)
        nodCurent = dict.tabela[curent];
    else
        nodCurent = nullptr;
}

//Complexitate:
//BestCase: Teta(1) cand iteratorul nu este valid sau urmatorul nod al tabelei contine chei
//WorstCase: Teta(m) cand urmatoarea cheie se afla pe ultimul nod
//Complexitate finala: O(m)
void IteratorDictionar::urmator() {
	/* de adaugat */
    if(valid()){
        nodCurent = nodCurent->urm;
        if(nodCurent == nullptr){
            curent++;
            while(curent < dict.m && dict.tabela[curent] == nullptr)
                curent++;
            if(curent < dict.m)
                nodCurent = dict.tabela[curent];
            else
                nodCurent = nullptr;
        }
    }
}

//Complexitate:
//Teta(1)
TElem IteratorDictionar::element() const{
	/* de adaugat */
    if(valid())
        return nodCurent->elem;
	return pair <TCheie, TValoare>  (-1, -1);
}

//Complexitate: Teta(1)
bool IteratorDictionar::valid() const {
	/* de adaugat */
    return nodCurent != nullptr;
}

