//
// Created by vladm on 4/2/2024.
//
#pragma once
#include "repository.h"
#include "domain.h"
#include "VectorDinamic.h"
#include "undo.h"
#include <string>
#include <utility>
#include <memory>
#include <unordered_map>
#include "observer.h"
using std::string;


typedef int(*Sort)(const Masina&, const Masina&);

class ServiceException : public std::exception {
private:
    string message;
public:
    explicit ServiceException(string message) : message{ std::move(message) } {}

    [[nodiscard]] const string& get_msg() const {
        return message;
    }
};


class Spalatorie : public Subject {
private:
    vector<Masina> masini_spalatorie;
public:
    Spalatorie() = default;

    void adaugaMasinaSpalatorie(const Masina& m);

    vector<Masina>& getAllMasiniSpalatorie();

    void clearAllMasiniSpalatorie();

    void saveToFile(const string& file_name);

    void loadFromFile(const string& file_name);
};

/*
 * Clasa de service pentru masini
 */
class ServiceMasina {
private:
    RepoAbstract& repo;
    Spalatorie& spalatorie;
    vector<std::unique_ptr<ActiuneUndo>> undoActions;
public:
    /*
     * initializeaza un service pentru masini
     */
    explicit ServiceMasina(RepoAbstract& repo, Spalatorie& spalatorie) : repo{ repo }, spalatorie{ spalatorie } {}


    Spalatorie& getSpalatorie() {
        return spalatorie;
    }
    /*
     * Adauga o masina in lista de masini
     */
    void adaugaMasinaService(string& nr_inmatriculare, string& producator, string& model, string& tip);

    /*
     * Sterge o masina din lista de masini
     */
    void stergeMasinaService(const string& nr_inmatriculare);

    /*
     * Modifica o masina din lista de masini
     */
    void modificaMasinaService(string& nr_inmatriculare, string& producator, string& model, string& tip);

    /*
     * Returneaza toate masinile din lista de masini
     */
    vector<Masina> getAllMasiniService();

    /*
     * returneaza o lista filtrata dupa producator
     */
    vector<Masina> filterMasiniProducer(string& producator);

    /*
     * returneaza o lista filtrata dupa tip
     */
    vector<Masina> filterMasiniType(string& tip);

    /*
     * returneaza o lista sortate dupa o functie de sortare
     */
    vector<Masina> sortMasini(Sort functieSortare);

    /*
     * returneaza toate masinile din lista de manager
     */
    vector<Masina>& getAllSpalatorie();

    void generateRandom(int n);

    void clearAllSpalatorie();

    void addMasinaSpalatorie(const string& nr_inmatriculare);

    /*
    * functie de filtrare cu map
    */
    void filterWithMap(std::unordered_map<string, int>&);

    /*
    functie service de undo
    */
    void undo();

    void saveToFile(const string& file_name);

    void loadFromFile(const string& file_name);

    void saveToFileSpalatorie(const string& file_name);

    void loadFromFileSpalatorie(const string& file_name);



};

int sortNrInmatriculare(const Masina& m1, const Masina& m2);

int sortTip(const Masina& m1, const Masina& m2);

int sortProducatorModel(const Masina& m1, const Masina& m2);

int sortProducator(const Masina& m1, const Masina& m2);

int sortModel(const Masina& m1, const Masina& m2);



