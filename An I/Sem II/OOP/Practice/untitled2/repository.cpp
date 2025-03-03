//
// Created by vladm on 5/21/2024.
//
#include "repository.h"
#include <fstream>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

void RepoElevi::adaugaElev(const Elev& elev) {
    for(auto& e : elevi)
        if(e.get_nr_matricol() == elev.get_nr_matricol())
            throw RepoException("Elevul exista deja!");
    elevi.push_back(elev);
}

void RepoElevi::modificaElev(const Elev &elev) {
    for(auto& e : elevi)
        if(e.get_nr_matricol() == elev.get_nr_matricol()){
            e = elev;
            return;
        }

    throw RepoException("Elevul cu acest numar matricol nu exista!");
}

void RepoElevi::stergeElev(int nr_matricol) {
    int poz = 0;
    for(auto& e : elevi) {
        if (e.get_nr_matricol() == nr_matricol) {
            elevi.erase(elevi.begin() + poz);
        }
    }
    throw RepoException("Elevul cu acest numar matricol nu exista!");
}

const vector<Elev> &RepoElevi::getAllElevi() {
    return elevi;
}

void RepoElevi::loadFromFile() {
    ifstream fin{file_name};
    if(!fin.is_open())
        throw RepoException("Fisierul nu s-a putut deschide!");
    while(!fin.eof())
    {
        string nr_matricol1;
        string nume;
        string scoala;
        getline(fin, nr_matricol1, ',');
        getline(fin, nume, ',');
        getline(fin, scoala, '\n');
        if(nr_matricol1.empty())
            break;
        int nr_matricol = stoi(nr_matricol1);
        Elev elev(nr_matricol, nume, scoala);
        adaugaElev(elev);
    }
}

void RepoElevi::writeToFile() {
    ofstream fout{file_name};
    if(!fout.is_open())
        throw RepoException("Fisierul nu s-a putut deschide!");
    for(auto& elev:elevi)
        fout<<elev.get_nr_matricol()<<","<<elev.get_nume()<<","<<elev.get_scoala()<<'\n';
    fout.close();
}




