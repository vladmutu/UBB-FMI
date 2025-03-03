#pragma once


#define NULL_TVALOARE -1
typedef int TCheie;
typedef int TValoare;

class IteratorDictionar;

#include <utility>
typedef std::pair<TCheie,TValoare> TElem;
#include <cmath>
//dictionar cu tabela de dispersie cu coliziuni rezolvate prin liste independente
class Dictionar {
	friend class IteratorDictionar;

	private:
	/* aici e reprezentarea */
    struct Nod{
        TElem elem;
        Nod* urm;
    };
    Nod** tabela;
    int m;
    int dimensiune;
    Nod* prim;
    int hash(TCheie c) const
    {
        return abs(c) % m;
    }

	public:

	// constructorul implicit al dictionarului
	Dictionar();

	// adauga o pereche (cheie, valoare) in dictionar	
	//daca exista deja cheia in dictionar, inlocuieste valoarea asociata cheii si returneaza vechea valoare
	// daca nu exista cheia, adauga perechea si returneaza null: NULL_TVALOARE
	TValoare adauga(TCheie c, TValoare v);

	//cauta o cheie si returneaza valoarea asociata (daca dictionarul contine cheia) sau null: NULL_TVALOARE
	TValoare cauta(TCheie c) const;

	//sterge o cheie si returneaza valoarea asociata (daca exista) sau null: NULL_TVALOARE
	TValoare sterge(TCheie c);

	//returneaza numarul de perechi (cheie, valoare) din dictionar 
	int dim() const;

	//verifica daca dictionarul e vid 
	bool vid() const;

    TValoare ceaMaiFrecventaValoare() const;

	// se returneaza iterator pe dictionar
	IteratorDictionar iterator() const;


	// destructorul dictionarului	
	~Dictionar();

};


