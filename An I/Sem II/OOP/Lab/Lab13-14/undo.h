#include "domain.h"
#include "repository.h"


class ActiuneUndo {
public:
    virtual void doUndo() = 0;

    virtual ~ActiuneUndo() = default;
};

class UndoAdauga : public ActiuneUndo {
    Masina masinaAdaugata;
    RepoAbstract& repo;
public:
    UndoAdauga(RepoAbstract& repo, Masina& masina) : repo{ repo }, masinaAdaugata{ masina } {}

    void doUndo() override {
        repo.stergeMasina(masinaAdaugata.get_nr_inmatriculare());
    }
};


class UndoModifica : public ActiuneUndo {
    Masina masinaVeche, masinaNoua;
    RepoAbstract& Repo;
public:
    UndoModifica(RepoAbstract& repo, Masina& masinaVeche, Masina& masinaNoua) : Repo{ repo }, masinaVeche{ masinaVeche },
                                                                                masinaNoua{ masinaNoua } {}

    void doUndo() override {
        Repo.stergeMasina(masinaNoua.get_nr_inmatriculare());
        Repo.adaugaMasina(masinaVeche);
    }
};

class UndoSterge : public ActiuneUndo {
    Masina masinaStearsa;
    RepoAbstract& Repo;
public:
    UndoSterge(RepoAbstract& repo, Masina& masinaStearsa) : Repo{ repo }, masinaStearsa{ masinaStearsa } {}

    void doUndo() override {
        Repo.adaugaMasina(masinaStearsa);
    }
};