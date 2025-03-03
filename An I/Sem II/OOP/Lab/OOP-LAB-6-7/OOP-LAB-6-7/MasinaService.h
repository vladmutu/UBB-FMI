#pragma once
#include "repository.h"
#include "Masina.h"
#include <string>
using std::string;
class MasinaService {
private:
    MasinaRepo& repo;
    //vector<vector<Masina>> undo;
public:
    MasinaService(MasinaRepo& r): repo{r}{
    }
    MasinaService(const MasinaService& ot) = delete;

    MasinaService()=default;

    void add_masina(string numar_inmatriculare,string model, string categorie);

    void actualizare_masina(string numar_inmatriculare, string model, string categorie);

    void stergere_masina(string numar_inmatriculare);

    /**
     * Functie care returneaza toate masinile din lista de masini.
     * @return
     */
    vector<Masina> get_all(){
        return repo.get_all();
    }
};

void testAdd();

void testActualizare();

void testAll();
