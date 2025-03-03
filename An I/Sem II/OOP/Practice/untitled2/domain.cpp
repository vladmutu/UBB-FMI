//
// Created by vladm on 5/21/2024.
//
#include "domain.h"
#include <cstring>
#include <utility>
int Elev::get_nr_matricol() const {
    return this->nr_matricol;
}

string Elev::get_nume() const{
    return this->nume;
}

string Elev::get_scoala() const{
    return this->scoala;
}

int Elev::validateElev() const {
    if(this->get_nr_matricol() < 1)
        return 1;
    if(get_nume().empty())
        return 2;
    if(get_scoala().empty())
        return 3;
    return 0;
}

vector<string> Elev::get_ateliere() const {
    return ateliere;
}

void Elev::set_ateliere(vector<string> a) const {

}


