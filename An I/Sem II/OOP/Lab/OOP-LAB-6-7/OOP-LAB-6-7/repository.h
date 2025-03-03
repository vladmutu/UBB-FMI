#pragma once
#include <vector>
#include <stdexcept>
#include <cassert>
#include "Masina.h"
using std::vector;

class RepoException{
    string msg;
public:
    RepoException(string m): msg{m}{
    }
    string getMessage(){
        return msg;
    }
};

class MasinaRepo {
private:
    vector<Masina> masini;
public:
    MasinaRepo(const MasinaRepo& ot) = delete;
    MasinaRepo()=default;

    void store(const Masina& m);

    void actualizare(const Masina& m);

    void stergere(const string& numar_inmatriculare);

    const vector<Masina>& get_all(){
        return masini;
    }
};

void testRepo();

void testRepoActualizare();

void testRepoStergere();

void RepoTestAll();

