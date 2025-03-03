#include "service.h"

void ServiceMelodii::adauga_melodie_service(const int &id, const string &titlu, const string &artist, const int &rank) {
    Melodie m(id, titlu, artist, rank);
    try{
        int c = m.validate();
        try{
            repo.adauga_melodie(m);
        }catch(RepoException& e)
        {
            throw ServiceException(e.get_msg());
        }
    }catch(MelodieException& e) {
        throw ServiceException(e.get_msg());
    }
}
