#include "MasinaService.h"
#include <assert.h>
/**
 * Functie care adauga o masina in lista de masini.
 * @param numar_inmatriculare
 * @param model
 * @param categorie
 */
void MasinaService::add_masina(string numar_inmatriculare,string model, string categorie){
    Masina m{numar_inmatriculare,model,categorie};
    //undo.push_back(repo.get_all());
    repo.store(m);
}
/**
 * Functie care actualizeaza o masina din lista de masini.
 * @param numar_inmatriculare
 * @param model
 * @param categorie
 */
void MasinaService::actualizare_masina(string numar_inmatriculare, string model, string categorie){
    Masina m{numar_inmatriculare,model,categorie};
    //undo.push_back(repo.get_all());
    repo.actualizare(m);
}
/**
 * Functie care sterge o masina din lista de masini.
 * @param numar_inmatriculare
 */
void MasinaService::stergere_masina(string numar_inmatriculare){
    //undo.push_back(repo.get_all());
    repo.stergere(numar_inmatriculare);
}
void testAdd(){
    MasinaRepo repo;
    MasinaService serv{repo};
    serv.add_masina("B123ABC", "Dacia", "mini");
    const auto& masini = serv.get_all();
    assert(masini.size() == 1);
    assert(masini[0].get_numar_inmatriculare() == "B123ABC");
    assert(masini[0].get_model() == "Dacia");
    assert(masini[0].get_categorie() == "mini");
    try {
        serv.add_masina("B123ABC", "Dacia", "mini");
        assert(true);
    } catch (RepoException& e) {
        assert(e.getMessage() == "Masina exista deja!\n");
    }
}
void testActualizare(){
    MasinaRepo repo;
    MasinaService serv{repo};
    serv.add_masina("B123ABC", "Dacia", "mini");
    serv.actualizare_masina("B123ABC", "Dacia", "mica");
    const auto& masini = serv.get_all();
    assert(masini.size() == 1);
    assert(masini[0].get_numar_inmatriculare() == "B123ABC");
    assert(masini[0].get_model() == "Dacia");
    assert(masini[0].get_categorie() == "mica");
    try{
        serv.actualizare_masina("CJ23ABC", "Dacia", "mica");
        assert(true);
    } catch (RepoException& e) {
        assert(e.getMessage() == "Masina nu exista!\n");

    }
}

void testStergere(){
    MasinaRepo repo;
    MasinaService serv{repo};
    serv.add_masina("B123ABC", "Dacia", "mini");
    serv.stergere_masina("B123ABC");
    const auto& masini = serv.get_all();
    assert(masini.size() == 0);
    try {
        serv.stergere_masina("B123ABC");
        assert(true);
    } catch (RepoException& e) {
        assert(e.getMessage() == "Masina nu exista!\n");
    }

}

void testAll()
{
    RepoTestAll();
    testAdd();
    testActualizare();
    testStergere();
}