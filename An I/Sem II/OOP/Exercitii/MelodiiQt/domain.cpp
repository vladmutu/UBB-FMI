
#include "domain.h"

int Melodie::get_id() const {
    return id;
}

string Melodie::get_titlu() const{
    return titlu;
}

string Melodie::get_artist() const{
    return artist;
}

int Melodie::get_rank() const {
    return rank;
}

int Melodie::validate() {
    if(id < 0)
        throw MelodieException("Id invalid");
    if(titlu.empty())
        throw MelodieException("titlu invalid");
    if(artist.empty())
        throw MelodieException("artist invalid");
    if(rank < 0 && rank > 10)
        throw MelodieException("rand invalid");
    return 0;
}
