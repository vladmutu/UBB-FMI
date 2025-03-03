//
// Created by vladm on 5/21/2024.
//

#ifndef UNTITLED2_DOMAIN_H
#define UNTITLED2_DOMAIN_H
#include <string>
#include <utility>
#include <exception>
#include <vector>
using namespace std;

class ElevException{
private:
    string msg;
public:
    explicit ElevException(string msg) : msg{std::move(msg)}{

    }
    [[nodiscard]] string get_msg() const{
        return msg;
    }
};

class Elev{
private:
    int nr_matricol;
    string nume;
    string scoala;
    vector<string> ateliere;
public:
    [[nodiscard]] int get_nr_matricol() const;
    [[nodiscard]] string get_nume() const;
    [[nodiscard]] string get_scoala() const;
    void set_ateliere(vector<string> a) const;
    [[nodiscard]] vector<string> get_ateliere() const;
    Elev() = default;
    Elev(int nr_matricol, string nume, string scoala) : nr_matricol{ nr_matricol }, nume{ std::move(nume) }, scoala{ std::move(scoala) }{

    }
    Elev(const Elev& elev) = default;

    ~Elev() = default;

    int validateElev() const;
};

#endif //UNTITLED2_DOMAIN_H
