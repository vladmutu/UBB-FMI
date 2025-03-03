#pragma once
#include "Colectie.h"

class Colectie;
typedef int TElem;

class IteratorColectie
{
	friend class Colectie;

private:
    //constructorul primeste o referinta catre Container
	//iteratorul va referi primul element din container
   IteratorColectie(const Colectie& c);

    //contine o referinta catre containerul pe care il itereaza
	const Colectie& col;
	/* aici e reprezentarea  spcifica a iteratorului*/
    int pozitie;
    int frecventa;

public:

		//reseteaza pozitia iterator-ului la inceputul container-ului
		void prim();

		//muta iteratorul in container
		// arunca exceptie daca iteratorul nu e valid
		void urmator();

        //muta iteratorul in container
        // arunca exceptie daca iteratorul nu e valid
        void anterior();

		//verifica daca iteratorul e valid pentru elementul urmator(indica un element al containerului)
		bool validUrmator() const;

        //verifica daca iteratorul e valid pentru elementul anterior(indica un element al containerului)
        bool validAnterior() const;

        //seteaza pozitia iteratorului la ultimul element din container
        void ultim();


		//returneaza valoarea elementului din container referit de iterator
		//arunca exceptie daca iteratorul nu e valid
		TElem element() const;
};

