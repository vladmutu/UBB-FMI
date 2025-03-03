#include "repository.h"
#include <assert.h>
/**
 * Adauga o masina in lista de masini
 * @param m
 */
void MasinaRepo::store(const Masina& m){
    for (const Masina& M: masini) {
        if (M.get_numar_inmatriculare() == m.get_numar_inmatriculare()) {
            throw RepoException("Masina exista deja!\n");
        }
    }
    masini.push_back(m);
}
/**
 * Actualizeaza o masina din lista de masini
 * @param m
 */
void MasinaRepo::actualizare(const Masina& m){
    for (auto& M: masini) {
        if (M.get_numar_inmatriculare() == m.get_numar_inmatriculare()) {
            M = m;
            return;
        }
    }
    throw RepoException("Masina nu exista!\n");
}
/**
 * Sterge o masina din lista de masini
 * @param numar_inmatriculare
 */
void MasinaRepo::stergere(const string& numar_inmatriculare){
    for (int i=0;i<masini.size();i++){
        if (masini[i].get_numar_inmatriculare() == numar_inmatriculare){
            masini.erase(masini.begin()+i);
            return;
        }
    }
    throw RepoException("Masina nu exista!\n");
}

void testRepo(){
    MasinaRepo repo;
    Masina m1("B123ABC", "Dacia", "mini");
    repo.store(m1);
    const auto& masini = repo.get_all();
    assert(masini.size() == 1);
    assert(masini[0].get_numar_inmatriculare() == "B123ABC");
    assert(masini[0].get_model() == "Dacia");
    assert(masini[0].get_categorie() == "mini");

    try {
        repo.store(m1);
        assert(true);
    } catch (RepoException& e) {
        assert(e.getMessage() == "Masina exista deja!\n");
    }
    repo.store({"CJ12ABC", "Dacia", "mini" });
    repo.store({"BN12ABC", "Dacia", "mini" });
    repo.store({"AB12ABC", "Dacia", "mini" });

    assert(masini.size() == 4);
}

void testRepoActualizare(){
    MasinaRepo repo;
    Masina m1("B123ABC", "Dacia", "mini");
    repo.store(m1);
    repo.actualizare(m1);
    const auto& masini = repo.get_all();
    assert(masini.size() == 1);
    assert(masini[0].get_numar_inmatriculare() == "B123ABC");
    assert(masini[0].get_model() == "Dacia");
    assert(masini[0].get_categorie() == "mini");
    repo.store({"CJ12ABC", "Dacia", "mini" });
    repo.store({"BN23ABC", "Dacia", "mini" });
    repo.store({"AB23ABC", "Dacia", "mini" });
    assert(masini.size() == 4);
    try {
        repo.actualizare({"CJ123ABC", "Dacia", "mini" });
        assert(false);
    } catch (RepoException& e) {
        assert(e.getMessage() == "Masina nu exista!\n");}
}

void testRepoStergere(){
    MasinaRepo repo;
    Masina m1("B123ABC", "Dacia", "mini");
    repo.store(m1);
    repo.stergere("B123ABC");
    const auto& masini = repo.get_all();
    assert(masini.size() == 0);
    try {
        repo.stergere("B123ABC");
        assert(true);
    } catch (RepoException& e) {
        assert(e.getMessage() == "Masina nu exista!\n");
    }
    repo.store({"CJ12ABC", "Dacia", "mini" });
    repo.store({"BN23ABC", "Dacia", "mini" });
    repo.store({"AB23ABC", "Dacia", "mini" });

    assert(masini.size() == 3);
}
void RepoTestAll(){
    testRepo();
    testRepoActualizare();
    testRepoStergere();
}