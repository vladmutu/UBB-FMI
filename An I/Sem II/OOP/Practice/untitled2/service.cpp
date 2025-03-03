//
// Created by vladm on 5/21/2024.
//
#include "service.h"

void EleviService::adaugaElevService(int nr_matricol, const string& nume, const string& scoala) {
    Elev e(nr_matricol, nume, scoala);
    switch(e.validateElev())
    {
        case 0:
            try{
                repo.adaugaElev(e);
            }catch(RepoException& e){
                throw ServiceException(e.get_msg());
            }
            break;
        case 1:
            throw ServiceException("Nr matricol invalid!");
        case 2:
            throw ServiceException("Nume invalid!");
        case 3:
            throw ServiceException("Scoala invalida");
    }
}

void EleviService::modificaMasinaService(int nr_matricol, const string &nume, const string &scoala) {

}


void EleviService::stergeMasinaService(int nr_matricol) {

}


vector<Elev> &EleviService::getAllEleviService() {

}

