//
// Created by vladm on 4/2/2024.
//
#include "repository.h"
#include <fstream>
#include <iostream>
using namespace std;

void RepoAbstract::adaugaMasina(const Masina& masina) {
    for (auto& masina1 : masini) {
        if (masina1.get_nr_inmatriculare() == masina.get_nr_inmatriculare()) {
            throw RepoException("Masina exista deja!");
        }
    }
    masini.push_back(masina);
}

void RepoAbstract::stergeMasina(const string& nr_inmatriculare) {
    //random();
    bool ok = false;
    int poz = 0;
    for (auto& masina : RepoAbstract::masini) {
        if (masina.get_nr_inmatriculare() == nr_inmatriculare) {
            masini.erase(masini.begin() + poz);
            ok = true;
        }
        poz++;
    }
    if (!ok)
        throw RepoException("Masina nu exista!");
}

void RepoAbstract::modificaMasina(const Masina& masina) {
    for (auto& masina1 : masini) {
        if (masina1.get_nr_inmatriculare() == masina.get_nr_inmatriculare()) {
            masina1 = masina;
            return;
        }
    }
    throw RepoException("Masina nu exista!");
}

const vector<Masina>& RepoAbstract::getAllMasini() {
    return masini;
}

void RepoFisier::loadFromFile() {
    ifstream fin{ file_name };
    while (!fin.eof()) {
        string nr_inmatriculare;
        string producator;
        string model;
        string tip;
        fin >> nr_inmatriculare >> producator >> model >> tip;
        if (nr_inmatriculare.empty()) {
            break;
        }
        Masina m{ nr_inmatriculare, producator, model, tip };
        adaugaMasina(m);
    }
    fin.close();
}

void RepoFisier::saveToFile() {
    ofstream fout{ file_name };
    std::ofstream ofs;
    ofs.open(file_name, std::ofstream::out | std::ofstream::trunc);
    ofs.close();
    for (const auto& masina : getAllMasini()) {
        fout << masina.get_nr_inmatriculare() << ' ' << masina.get_producator() << ' ' << masina.get_model() << ' ' << masina.get_tip() << '\n';
    }
    fout.close();
}

void MasinaRepo::adaugaMasina(const Masina& masina)
{
    //random();
    for (auto& masina1 : getAllMasini()) {
        if (masina1.get_nr_inmatriculare() == masina.get_nr_inmatriculare()) {
            throw RepoException("Masina exista deja!");
        }
    }
    masini_dict.insert(pair<string, Masina>(masina.get_nr_inmatriculare(), masina));
}

void MasinaRepo::stergeMasina(const string& nr_inmatriculare)
{
    //random();
    for (auto& masina1 : getAllMasini())
    {
        if (masina1.get_nr_inmatriculare() == nr_inmatriculare) {
            masini_dict.erase(nr_inmatriculare);
            return;
        }
    }
    throw RepoException("Masina nu exista!");
}

void MasinaRepo::modificaMasina(const Masina& masina)
{
    //random();
    bool ok = false;
    for (auto& masina1 : MasinaRepo::masini_dict) {
        if (masina1.first == masina.get_nr_inmatriculare()) {
            masina1.second = masina;
            ok = true;
        }
    }
    if (!ok)
        throw RepoException("Masina nu exista!");
}


const vector<Masina>& MasinaRepo::getAllMasini()
{
    masini1.clear();
    for (auto& masina : this->masini_dict) {
        masini1.emplace(masini1.begin(), masina.second);
    }
    return masini1;
}
