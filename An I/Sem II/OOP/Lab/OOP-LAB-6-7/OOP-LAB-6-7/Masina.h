#pragma once
#include <string>

using std::string;
class  Masina {
private:
    string numar_inmatriculare;
    string model;
    string categorie;
public:
    string get_numar_inmatriculare() const;
    string get_model() const;
    string get_categorie() const;

    /**
     * Constructor pentru clasa Masina.
     * @param numar_inmatriculare
     * @param model
     * @param categorie
     */
    Masina(string numar_inmatriculare, string model, string categorie): numar_inmatriculare{numar_inmatriculare}, model{model}, categorie{categorie}{
    }

    /**
     * Constructor de copiere pentru clasa Masina.
     * @param ot
     */
    Masina(const Masina& ot):numar_inmatriculare{ot.numar_inmatriculare},model{ot.model},categorie{ot.categorie}{
    }

    Masina& operator=(const Masina& ot){
        numar_inmatriculare = ot.numar_inmatriculare;
        model = ot.model;
        categorie = ot.categorie;
        return *this;
    }
};


