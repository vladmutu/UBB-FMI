//
// Created by vladm on 5/21/2024.
//

#ifndef UNTITLED2_REPOSITORY_H
#define UNTITLED2_REPOSITORY_H
#include "domain.h"
#include <utility>
#include <vector>
#include <exception>

using namespace std;

class RepoException : public exception {
private:
    string msg;
public:
    explicit RepoException(string  msg) : msg {std::move( msg)} {

    }
    [[nodiscard]] string get_msg() const {
        return msg;
    }
};

class RepoElevi{
private:
    string file_name;
    vector<Elev> elevi;
    void loadFromFile();
    void writeToFile();
public:
    explicit RepoElevi(string file_name) : file_name{file_name}{
        loadFromFile();
    }
    ~RepoElevi() = default;

    void adaugaElev(const Elev& elev);
    void modificaElev(const Elev& elev);
    void stergeElev(int nr_matricol);
    const vector<Elev>& getAllElevi();
};

#endif //UNTITLED2_REPOSITORY_H
