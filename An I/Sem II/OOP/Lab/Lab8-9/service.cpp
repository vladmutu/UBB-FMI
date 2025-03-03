//
// Created by vladm on 4/2/2024.
//
#include "service.h"


void ServiceMasina::adaugaMasinaService(string& nr_inmatriculare, string& producator, string& model, string& tip) {
    Masina m(nr_inmatriculare, producator, model, tip);
    switch (Masina::validateMasina(m)) {
        case 1:
            throw MasinaException("Numar de inmatriculare invalid!");
        case 2:
            throw MasinaException("Producator invalid!");
        case 3:
            throw MasinaException("Model invalid!");
        case 4:
            throw MasinaException("Tip invalid!");
        default:
            try{
                repo.adaugaMasina(m);
            } catch (RepoException& e) {
                throw MasinaException(e.get_msg());
            }
            break;
    }
}

void ServiceMasina::stergeMasinaService(const string &nr_inmatriculare) {
    try {
        repo.stergeMasina(nr_inmatriculare);
    } catch (RepoException& e) {
        throw MasinaException(e.get_msg());
    }
}

void ServiceMasina::modificaMasinaService(string& nr_inmatriculare, string& producator, string& model, string& tip) {
    Masina m(nr_inmatriculare, producator, model, tip);
    switch (Masina::validateMasina(m)) {
        case 1:
            throw MasinaException("Numar de inmatriculare invalid!");
        case 2:
            throw MasinaException("Producator invalid!");
        case 3:
            throw MasinaException("Model invalid!");
        case 4:
            throw MasinaException("Tip invalid!");
        default:
            try{
                repo.modificaMasina(m);
            }catch (RepoException& e) {
                throw MasinaException(e.get_msg());
            }
            break;
    }
}

vector<Masina> ServiceMasina::getAllMasiniService() {
    return repo.getAllMasini();
}

vector<Masina> ServiceMasina::filterMasiniProducer(string& producator) {
    vector<Masina> masini;
    masini = repo.getAllMasini();
    vector<Masina> rez;
    for(const auto & i : masini)
        if(i.get_producator() == producator)
            rez.push_back(i);
    return rez;
}

vector<Masina> ServiceMasina::filterMasiniType(string& tip)
{
    vector<Masina> masini;
    masini = repo.getAllMasini();
    vector<Masina> rez;
    for(const auto & i : masini)
        if(i.get_tip() == tip)
            rez.push_back(i);
    return rez;
}

vector<Masina> ServiceMasina::sortMasini(Sort functieSortare)
{
    vector<Masina> masini = repo.getAllMasini();
    for(int i = 0; i < masini.size() - 1; i++)
        for(int j = i + 1; j < masini.size(); j++)
            if(functieSortare(masini[i], masini[j]) > 0) {
                Masina aux = masini[i];
                masini[i] = masini[j];
                masini[j] = aux;
            }
    vector<Masina> aux;
    aux = masini;
    return aux;
}

int sortNrInmatriculare(const Masina& m1, const Masina& m2) {
    return m1.get_nr_inmatriculare().compare(m2.get_nr_inmatriculare());
}

int sortTip(const Masina& m1, const Masina& m2) {
    return m1.get_tip().compare(m2.get_tip());
}

int sortProducatorModel(const Masina& m1, const Masina& m2) {
    if (m1.get_producator().compare(m2.get_producator()) > 0){
        return (m1.get_producator().compare(m2.get_producator()));
    } else
        return m1.get_model().compare(m2.get_model());
}

int sortProducator(const Masina& m1, const Masina& m2) {
    return m1.get_producator().compare(m2.get_producator());
}

int sortModel(const Masina& m1, const Masina& m2) {
    return m1.get_model().compare(m2.get_model());
}
