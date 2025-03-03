//
// Created by vladm on 4/2/2024.
//
#include "repository.h"

void MasinaRepo::adaugaMasina(const Masina& masina) {
    bool exista = false;
    for (int i = 0; i < masini.size(); i++)
        if (masini.get(i).get_nr_inmatriculare() == masina.get_nr_inmatriculare())
            exista = true;
    if (exista) {
        throw RepoException("Masina cu acelasi numar de inmatriculare deja existenta!");
    }
    masini.add(masina);
}

void MasinaRepo::stergeMasina(const std::string& nr_inmatriculare) {
    int poz = -1;
    for (int i = 0; i < masini.size(); i++)
        if (masini.get(i).get_nr_inmatriculare() == nr_inmatriculare)
            poz = i;
    if (poz == -1)
        throw RepoException("Masina cu acest numar de inmatriculare nu exista!");
    masini.erase(poz);
}

void MasinaRepo::modificaMasina(const Masina& masina) {
    int poz = -1;
    for (int i = 0; i < masini.size(); i++)
        if (masini.get(i).get_nr_inmatriculare() == masina.get_nr_inmatriculare())
            poz = i;
    if (poz == -1)
        throw RepoException("Masina cu acest numar de inmatriculare nu exista!");
    masini.get(poz) = masina;
}



