//
// Created by vladm on 4/2/2024.
//
#include "repository.h"
void MasinaRepo::adaugaMasina(const Masina& masina) {
    bool exista = false;
    for(const auto & i : masini)
        if(i.get_nr_inmatriculare() == masina.get_nr_inmatriculare())
            exista = true;
    if(exista) {
        throw RepoException("Masina cu acelasi numar de inmatriculare deja existenta!");
    }
    masini.push_back(masina);
}

void MasinaRepo::stergeMasina(const std::string &nr_inmatriculare) {
    int poz = -1;
    int k = 0;
    for(const auto & i : masini)
    {
        if(i.get_nr_inmatriculare() == nr_inmatriculare)
            poz = k;
        k++;
    }
    if(poz == -1)
        throw RepoException("Masina cu acest numar de inmatriculare nu exista!");
    masini.erase(masini.begin() + poz);
}

void MasinaRepo::modificaMasina(const Masina& masina) {
    int poz = -1;
    int k = 0;
    for(const auto & i : masini)
    {
        if(i.get_nr_inmatriculare() == masina.get_nr_inmatriculare())
            poz = k;
        k++;
    }
    if(poz == -1)
        throw RepoException("Masina cu acest numar de inmatriculare nu exista!");
    masini[poz] = masina;
}

vector<Masina>& MasinaRepo::getAllMasini() {
    return masini;
}





