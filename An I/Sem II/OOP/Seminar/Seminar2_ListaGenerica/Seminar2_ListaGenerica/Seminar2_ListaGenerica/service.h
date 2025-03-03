#pragma once
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include "MyList.h"

typedef struct {
	MyList* allSongs;
	MyList* undoList;
}ManagerMelodii;

/*
* Creeaza o entitate de tip ManagerMelodii
* care contine o lista de melodii si o 
* lista pentru undo
* 
*/
ManagerMelodii createManagerMelodii();
/*
* Elibereaza memoria alocata pentru un ManagerMelodii
*/
void destroyManagerMelodii(ManagerMelodii* store);

/*
* Adauga o melodie
*
* @param store: ManagerMelodii in care se adauga (ManagerMelodii*)
* @param titlu: titlul melodiei care se adauga (char*)
* @param artist: artistul melodiei care se adauga (char*)
* @param durata: durata melodiei care se adauga (int)
*
* @return: 1 daca melodia a fost adaugata cu succes, 0 altfel (int)
* post: melodia cu datele date este adaugata in lista (daca este o melodie valida)
*/
int addMelodie(ManagerMelodii* store, char* titlu, char* artist, double durata);

/*
* Sterge o melodie
*
* @param store: ManagerMelodii din care se sterge (ManagerMelodii*)
* @param titlu: titlul melodiei care se sterge (char*)
* @param artist: artistul melodiei care se sterge (char*)
*
* @return: 1 daca melodia a fost stearsa cu succes, 0 altfel (int)
* post: melodia cu titlul titlu si artistul artist este stearsa din lista daca exista
*/
int deleteMelodie(ManagerMelodii* store, char* titlu, char* artist);

/*
* Modifica o melodie
*
* @param store: ManagerMelodii in care se modifica (ManagerMelodii*)
* @param titlu: titlul melodiei care se modifica (char*)
* @param artist: artistul melodiei care se modifica (char*)
* @param durata: noua durata a melodiei (int)
*
* @return: 1 daca melodia a fost modificata cu succes, 0 altfel (int)
* post: melodia cu titlul titlu si artistul artist are durataNoua (daca o astfel
*		de melodie exista)
*/
int modifyMelodie(ManagerMelodii* store, char* titlu, char* artist, int durataNoua);

/*
* Gaseste o melodie cu titlu si artist dat
*
* @param store: ManagerMelodii in care se cauta melodia (ManagerMelodii)
* @param titlu: titlul melodiei care se cauta (char*)
* @param artist: artistul melodiei care se cauta (char*)
*
* @return: pozitia din lista a melodiei cautate, -1 daca
			melodia nu exista in lista (int)
*/
int findMelodie(ManagerMelodii* store, char* titlu, char* artist);

/*
* Filtreaza lista de melodii dupa un artist dat
*
* @param store: ManagerMelodii cu toate melodiile
* @param artist: artistul dupa care se filtreaza lista (char*)

*
* @return: lista cu melodiile care au artistul artist (MyList*)
*		   daca artist="" se returneaza o copie a listei originale
*/
MyList* filterMelodii(ManagerMelodii* store, char* artist);

/*
* Returneaza o lista sortata de melodii
* Criteriu de sortare: durata (ascendent)
*
* @param store: ManagerMelodii cu melodiile care se sorteaza (ManagerMelodii*)
*
* @return: o lista sortata de melodii  (MyList*)
*/
MyList* sortMelodiiByDurata(ManagerMelodii* store);
/*
* Returneaza o lista sortata de melodii
* Criteriu de sortare: titlu (ascendent)
*
* @param store: ManagerMelodii cu melodiile care se sorteaza (ManagerMelodii*)
*
* @return: o lista sortata de melodii  (MyList*)
*/
MyList* sortMelodiiByTitle(ManagerMelodii* store);
/*
* Returneaza o lista sortata de melodii
* Criteriu de sortare: artist (ascendent)
*
* @param store: ManagerMelodii cu melodiile care se sorteaza (ManagerMelodii*)
*
* @return: o lista sortata de melodii  (MyList*)
*/
MyList* sortMelodiiByArtist(ManagerMelodii* store);
/*
* Returneaza o lista sortata de melodii
* Criterii de sortare: 
*		criteriu 1 - artist (ascendent)
*		criteriu 2 - titlu (ascendent)
*
* @param store: ManagerMelodii cu melodiile care se sorteaza (ManagerMelodii*)
*
* @return: o lista sortata de melodii  (MyList*)
*/
MyList* sortMelodiiByArtistTitle(ManagerMelodii* store);

/*
* Reface ultima operatie 
* 
* @return: 1 daca undo-ul a fost realizat, 0 altfel (int)
* post: lista de melodii este cea de dinaintea efectuarii
*		ultimei operatii care a modificat-o
*/
int undo(ManagerMelodii* store);

void testAddService();
void testFindService();
void testDeleteService();
void testModifyService();
void testFilterService();
void testSortDurataService();
void testSortArtistService();
void testSortTitluService();
void testSortArtistTitluService();
void testUndo();
