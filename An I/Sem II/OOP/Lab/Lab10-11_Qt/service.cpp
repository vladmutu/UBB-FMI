//
// Created by vladm on 4/2/2024.
//
#include "service.h"
#include <random>
std::mt19937 mt{ std::random_device{}() };

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <unordered_map>
using std::unordered_map;


void ServiceMasina::adaugaMasinaService(string& nr_inmatriculare, string& producator, string& model, string& tip) {
    Masina m(nr_inmatriculare, producator, model, tip);
    switch (Masina::validateMasina(m)) {
    case 1:
        throw MasinaException("Numar de inmatriculare invalid!");
    case 2:
        throw MasinaException("Producator invalid!");
    case 3:
        throw MasinaException("Model invalid!");
    case 4:
        throw MasinaException("Tip invalid!");
    default:
        try {
            repo.adaugaMasina(m);
            undoActions.push_back(std::make_unique<UndoAdauga>(repo, m));
        }
        catch (RepoException& e) { throw MasinaException(e.get_msg()); }
        break;
    }
}

void ServiceMasina::stergeMasinaService(const string& nr_inmatriculare) {
    try {
        vector<Masina>masini = repo.getAllMasini();
        for (auto& masina : masini)
            if (masina.get_nr_inmatriculare() == nr_inmatriculare)
                undoActions.push_back(std::make_unique<UndoSterge>(repo, masina));
        repo.stergeMasina(nr_inmatriculare);
    }
    catch (RepoException& e) { throw MasinaException(e.get_msg()); }
}

void ServiceMasina::modificaMasinaService(string& nr_inmatriculare, string& producator, string& model, string& tip) {
    Masina m(nr_inmatriculare, producator, model, tip);
    switch (Masina::validateMasina(m)) {
    case 1:
        throw MasinaException("Numar de inmatriculare invalid!");
    case 2:
        throw MasinaException("Producator invalid!");
    case 3:
        throw MasinaException("Model invalid!");
    case 4:
        throw MasinaException("Tip invalid!");
    default:
        try {
            Masina masinaVeche;
            for (auto& masina : repo.getAllMasini())
                if (masina.get_nr_inmatriculare() == nr_inmatriculare)
                    masinaVeche = masina;
            repo.modificaMasina(m);
            undoActions.push_back(std::make_unique<UndoModifica>(repo, masinaVeche, m));
        }
        catch (RepoException& e) { throw MasinaException(e.get_msg()); }
        break;
    }
}

vector<Masina> ServiceMasina::getAllMasiniService() {
    return repo.getAllMasini();
}

vector<Masina> ServiceMasina::filterMasiniProducer(string& producator) {
    vector<Masina> masini;
    masini = repo.getAllMasini();
    vector<Masina> rez;
    auto filtFunction = [&producator](const Masina& masina) {return masina.get_producator() == producator; };
    std::copy_if(masini.begin(), masini.end(), std::back_inserter(rez), filtFunction);
    return rez;
}

vector<Masina> ServiceMasina::filterMasiniType(string& tip)
{
    vector<Masina> masini;
    masini = repo.getAllMasini();
    vector<Masina> rez;
    auto filtFunction = [&tip](const Masina& masina) {return masina.get_tip() == tip; };
    std::copy_if(masini.begin(), masini.end(), std::back_inserter(rez), filtFunction);
    return rez;
}

vector<Masina> ServiceMasina::sortMasini(Sort functieSortare)
{
    vector<Masina> masini = repo.getAllMasini();
    sort(masini.begin(), masini.end(), functieSortare);
    return masini;
}

vector<Masina>& ServiceMasina::getAllSpalatorie()
{
    return spalatorie.getAllMasiniSpalatorie();
}

void ServiceMasina::generateRandom(int n)
{
    vector<Masina> masini = repo.getAllMasini();
    for (int i = 0; i < n; i++)
    {
        std::uniform_int_distribution<int> dist(0, masini.size() - 1);
        int index = dist(mt);
        spalatorie.adaugaMasinaSpalatorie(masini[index]);
    }
}

void ServiceMasina::clearAllSpalatorie()
{
    spalatorie.clearAllMasiniSpalatorie();
}

void ServiceMasina::addMasinaSpalatorie(const string& nr_inmatriculare)
{
    for (auto& masina : repo.getAllMasini())
        if (masina.get_nr_inmatriculare() == nr_inmatriculare)
        {
            spalatorie.adaugaMasinaSpalatorie(masina);
        }
}



void ServiceMasina::filterWithMap(unordered_map<string, int>& u)
{
    vector<Masina>masini = repo.getAllMasini();
    for (auto& masina : masini)
    {
        u[masina.get_tip()]++;
    }
}


void ServiceMasina::undo()
{
    if (undoActions.empty())
        throw ServiceException("Nu mai exista operatii de undo!");
    else
    {
        undoActions.back()->doUndo();
        undoActions.pop_back();
    }
}


/*
functie service de salvare in fisier a masinilor
*/
void ServiceMasina::saveToFile(const string& file_name)
{
    ofstream fout;
    fout.open(file_name);
    const auto& masini = repo.getAllMasini();
    for (auto& masina : masini)
        fout << masina.get_nr_inmatriculare() << '\n' << masina.get_producator() << '\n' << masina.get_model() << '\n' << masina.get_tip() << '\n';
}

void ServiceMasina::loadFromFile(const string& file_name)
{
    ifstream fin(file_name);
    while (!fin.eof())
    {
        string nr_inmatriculare;
        string producator;
        string model;
        string tip;
        getline(fin, nr_inmatriculare);
        getline(fin, producator);
        getline(fin, model);
        getline(fin, tip);
        if (nr_inmatriculare.empty())
            break;
        Masina m(nr_inmatriculare, producator, model, tip);
        repo.adaugaMasina(m);
    }
}

/*
functie service de salvare in fisier csv sau html a masinilor din spalatorie
*/
void ServiceMasina::saveToFileSpalatorie(const string& file_name)
{
    spalatorie.saveToFile(file_name);
}

/*
* functie service de incarcare din fisier a masinilor din spalatorie
*/
void ServiceMasina::loadFromFileSpalatorie(const string& file_name)
{
    spalatorie.loadFromFile(file_name);
}



void Spalatorie::adaugaMasinaSpalatorie(const Masina& m)
{
    masini_spalatorie.push_back(m);
}

vector<Masina>& Spalatorie::getAllMasiniSpalatorie()
{
    return masini_spalatorie;
}

void Spalatorie::clearAllMasiniSpalatorie()
{
    masini_spalatorie.clear();
}

void Spalatorie::saveToFile(const string& file_name)
{
    ofstream fout(file_name);
    if (file_name.find(".csv") == string::npos && file_name.find(".html") == string::npos)
        throw ServiceException("Fisierul trebuie sa fie de tip .csv sau .html!");
    if (file_name.find(".csv") != string::npos)
    {
        std::ofstream ofs;
        ofs.open(file_name, std::ofstream::out | std::ofstream::trunc);
        ofs.close();
        for (auto& masina : masini_spalatorie)
            fout << masina.get_nr_inmatriculare() << "," << masina.get_producator() << "," << masina.get_model() << "," << masina.get_tip() << '\n';
    }
    else
    {
        std::ofstream ofs;
        ofs.open(file_name, std::ofstream::out | std::ofstream::trunc);
        ofs.close();
        fout << "<!DOCTYPE html>\n";
        fout << "<html>\n";
        fout << "<head>\n";
        fout << "<title>Lista masini</title>\n";
        fout << "</head>\n";
        fout << "<body>\n";
        fout << "<table border=\"1\">\n";
        for (auto& masina : masini_spalatorie)
        {
            fout << "<tr>\n";
            fout << "<td>\n" << masina.get_nr_inmatriculare() << "\n</td>\n";
            fout << "<td>\n" << masina.get_producator() << "\n</td>\n";
            fout << "<td>\n" << masina.get_model() << "\n</td>\n";
            fout << "<td>\n" << masina.get_tip() << "\n</td>\n";
            fout << "</tr>\n";
        }
        fout << "</table>\n";
        fout << "</body>\n";
        fout << "</html>\n";
    }
}


/*
functie de incarcare a masinilor din spalatorie din fisier
*/
void Spalatorie::loadFromFile(const string& file_name)
{
    ifstream fin(file_name);
    if (file_name.find(".csv") != string::npos)
    {
        while (!fin.eof())
        {
            string nr_inmatriculare;
            string producator;
            string model;
            string tip;
            getline(fin, nr_inmatriculare, ',');
            getline(fin, producator, ',');
            getline(fin, model, ',');
            getline(fin, tip, '\n');
            if (nr_inmatriculare.empty())
                break;
            Masina m(nr_inmatriculare, producator, model, tip);
            masini_spalatorie.push_back(m);
        }
    }
    else
    {
        string line;
        getline(fin, line);
        while (!fin.eof())
        {
            if (line.find("<td>") != string::npos)
            {
                string nr_inmatriculare;
                string producator;
                string model;
                string tip;
                getline(fin, nr_inmatriculare);
                getline(fin, line);
                getline(fin, line);
                getline(fin, producator);
                getline(fin, line);
                getline(fin, line);
                getline(fin, model);
                getline(fin, line);
                getline(fin, line);
                getline(fin, tip);
                getline(fin, line);
                Masina m(nr_inmatriculare, producator, model, tip);
                masini_spalatorie.push_back(m);
            }
            else
            {
                getline(fin, line);
            }
        }
    }
}


int sortNrInmatriculare(const Masina& m1, const Masina& m2) {
    return m1.get_nr_inmatriculare() < m2.get_nr_inmatriculare();
}

int sortTip(const Masina& m1, const Masina& m2) {
    return m1.get_tip() < m2.get_tip();
}

int sortProducatorModel(const Masina& m1, const Masina& m2) {
    if (m1.get_producator() < m2.get_producator())
        return m1.get_producator() < m2.get_producator();
    else
        return m1.get_model() < m2.get_model();
}

int sortProducator(const Masina& m1, const Masina& m2) {
    return m1.get_producator() < m2.get_producator();
}

int sortModel(const Masina& m1, const Masina& m2) {
    return m1.get_model() < m2.get_model();
}