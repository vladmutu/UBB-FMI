//
// Created by vladm on 5/21/2024.
//

#ifndef UNTITLED2_SERVICE_H
#define UNTITLED2_SERVICE_H

#include "repository.h"
#include <string>
#include <utility>

class ServiceException : public std::exception{
private:
    string msg;
public:
    explicit ServiceException(string message) : msg{std::move(message)}{

    }
    [[nodiscard]] string get_msg() const{
        return msg;
    }
};

class EleviService{
private:
    RepoElevi& repo;
public:
    explicit EleviService(RepoElevi& repo) : repo { repo } {

    }
    ~EleviService() = default;

    void adaugaElevService(int nr_matricol, const string& nume, const string& scoala);

    void modificaMasinaService(int nr_matricol, const string&nume, const string& scoala);

    void stergeMasinaService(int nr_matricol);

    vector<Elev>& getAllEleviService();
};

#endif //UNTITLED2_SERVICE_H
