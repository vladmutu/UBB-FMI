//
// Created by vladm on 4/2/2024.
//
#pragma once

#include <random>
#include <chrono>
#include "domain.h"
#include "VectorDinamic.h"
#include <unordered_map>
#include <utility>
#include <vector>
using std::vector;
#include <string>
using std::string;
using namespace std;

/*
    Clasa de exceptii pentru repo
*/
class RepoException : public std::exception {
    string msg;
public:
    explicit RepoException(string m) : msg{ std::move(m) } {

    }

    string get_msg() {
        return msg;
    }
};




/*
clasa abstracta de repo
*/
class RepoAbstract {
private:
    vector<Masina> masini;
public:
    RepoAbstract() = default;
    ~RepoAbstract() = default;

    virtual void adaugaMasina(const Masina& masina) = 0;
    virtual void stergeMasina(const string& nr_inmatriculare) = 0;
    virtual void modificaMasina(const Masina& masina) = 0;
    virtual const vector<Masina>& getAllMasini() = 0;
};




/*
 * Clasa de repository pentru masini
 * vector dinamic
 */
class MasinaRepo : public RepoAbstract {
private:
    unordered_map<string, Masina> masini_dict;
    double probabilitate;
public:
    MasinaRepo() {
        auto seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::mt19937 gen(seed);
        std::uniform_real_distribution<double> dis(0.0, 1.0);
        probabilitate = dis(gen);
    }
    ~MasinaRepo() = default;
    /*
     * Adauga o masina in lista de masini
     * Date de intrare: masina - Masina
     * Date de iesire: -
     * pre: masina este valida si lista de masini nu contine masina cu acelasi nr_inmatriculare
     * post: masina este adaugata in lista de masini
     * post: lungimea listei de masini este cu 1 mai mare
     * exceptie: daca masina cu nr_inmatriculare exista deja
     */
    void adaugaMasina(const Masina& masina) override;

    /*
     * Sterge o masina din lista de masini
     * Date de intrare: nr_inmatriculare - string
     * Date de iesire: -
     * pre: nr_inmatriculare este valid
     * post: masina cu nr_inmatriculare este stearsa din lista de masini
     * post: lungimea listei de masini este cu 1 mai mica
     * exceptie: daca masina cu nr_inmatriculare nu exista
     */
    void stergeMasina(const string& nr_inmatriculare) override;

    /*
     * Modifica o masina din lista de masini
     * Date de intrare: masina - Masina
     * Date de iesire: -
     * pre: masina este valida si lista de masini contine masina cu acelasi nr_inmatriculare
     * post: masina cu nr_inmatriculare este modificata in lista de masini
     * exceptie: daca masina cu nr_inmatriculare nu exista
     */
    void modificaMasina(const Masina& masina) override;

    /*
     * Returneaza toate masinile din lista de masini
     * Date de intrare: -
     * Date de iesire: vector<Masina>
     * pre: -
     * post: se returneaza toate masinile din lista de masini
     */
    const vector<Masina>& getAllMasini() override;

    void random() const {
        double random = ((double)rand() / (RAND_MAX));
        if (random > probabilitate) {
            random *= 100;
            cout << "Probabilitatea: " << random << '\n';
            throw(RepoException("Nu se poate executa aceasta functie!"));
        }
    }
};






class RepoFisier : public RepoAbstract {
private:
	string file_name="masini.txt";
    void loadFromFile();
    void saveToFile();
public:
    RepoFisier(string filename) : file_name{ filename } {
		loadFromFile();
	}
	~RepoFisier() = default;

    void setFileName(string filename) {
		this->file_name = filename;
	}

    string getFileName() {
		return file_name;
	}

    void adaugaMasina(const Masina& masina) override {
        RepoAbstract::adaugaMasina(masina);
        saveToFile();
    }

    void stergeMasina(const string& nr_inmatriculare) override {
	    RepoAbstract::stergeMasina(nr_inmatriculare);
		saveToFile();
	}

    void modificaMasina(const Masina& masina) override {
		RepoAbstract::modificaMasina(masina);
		saveToFile();
	}

    const vector<Masina>& getAllMasini() override {
		return RepoAbstract::getAllMasini();
	}
};