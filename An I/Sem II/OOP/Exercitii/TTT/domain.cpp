#include "domain.h"
#include <string>

int Joc::get_id() const {
    return this->id;
}

char Joc::get_jucator() const {
    return this->jucator;
}

int Joc::get_stare() const {
    return this->stare;
}

int Joc::validator() const {
    if(this->id < 1)
        return 1;
    if(tabla.get_dim() < 3)
        return 2;
    if(this->jucator != 'X' && this->jucator != 'O')
        return 3;
    if(this->stare > 3 || this->stare < 1)
        return 4;
    if(this->tabla.get_pozitii().size() != tabla.get_dim() * tabla.get_dim())
        return 5;
    return 0;
}
