//
// Created by vladm on 6/21/2024.
//

#ifndef MELODIIQT_SERVICE_H
#define MELODIIQT_SERVICE_H
#include <exception>
#include <string>
#include <utility>
#include "domain.h"
#include "repository.h"

using namespace std;

class ServiceException : public std::exception{
private:
    string msg;
public:
    explicit ServiceException(string msg) : msg{std::move(msg)}{

    }
    string get_msg(){
        return msg;
    }
};

class ServiceMelodii{
private:
    RepoMelodii& repo;
public:
    explicit ServiceMelodii(RepoMelodii& repo) : repo{repo}{

    }

    void adauga_melodie_service(const int& id, const string& titlu, const string& artist, const int& rank);

    vector<Melodie>& get_all_service(){
        return repo.get_all();
    }

    ~ServiceMelodii() = default;
};

#endif //MELODIIQT_SERVICE_H
