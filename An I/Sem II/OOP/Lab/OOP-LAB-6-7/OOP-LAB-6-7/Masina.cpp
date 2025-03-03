#include "Masina.h"

/**
 * Functie care returneaza numarul de inmatriculare al unei masini.
 * @return
 */
string Masina::get_numar_inmatriculare() const{
    return numar_inmatriculare;
}
/**
 * Functie care returneaza modelul unei masini.
 * @return
 */
string Masina::get_model() const{
    return model;
}
/**
 * Functie care returneaza categoria unei masini.
 * @return
 */
string Masina::get_categorie() const{
    return categorie;
}