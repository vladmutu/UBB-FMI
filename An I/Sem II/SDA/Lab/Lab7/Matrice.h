#pragma once

typedef int TElem;


#define NULL_TELEMENT 0
//TAD Matrice reprezentarea sub forma unei matrice rare(triplete de forma (i,j,valoare)) memorate folosind un
//arbore binar de cautare reprezentat inlantuit, cu inlantuiri
//reprezentate pe tablou
class Matrice {

private:
	/* aici e reprezentarea */
    struct Nod{
        int linie, coloana;
        TElem valoare;
        Nod* stanga;
        Nod* dreapta;
    };
    Nod** matrice;
    int nrLiniiMatrice;
    int nrColoaneMatrice;
    Nod* creeazaNod(int linie, int coloana, TElem valoare);
    TElem cautaNod(Nod* nod, int linie, int coloana) const;
    Nod* radacina;
public:

	//constructor
	//se arunca exceptie daca nrLinii<=0 sau nrColoane<=0
	Matrice(int nrLinii, int nrColoane);


	//destructor
	~Matrice(){};

	//returnare element de pe o linie si o coloana
	//se arunca exceptie daca (i,j) nu e pozitie valida in Matrice
	//indicii se considera incepand de la 0
	TElem element(int i, int j) const;

    int valoareMaxima() const;

	// returnare numar linii
	int nrLinii() const;

	// returnare numar coloane
	int nrColoane() const;


	// modificare element de pe o linie si o coloana si returnarea vechii valori
	// se arunca exceptie daca (i,j) nu e o pozitie valida in Matrice
	TElem modifica(int i, int j, TElem);

};







