

//
// Created by vladm on 4/2/2024.
//
#include "teste.h"
#include "repository.h"
#include "domain.h"
#include "service.h"
#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

void testAddRepo() {
    MasinaRepo repo;
    Masina m1("BH-04-VLD", "Skoda", "Octavia", "Sedan");
    Masina m2("BH-05-VLD", "Skoda", "Octavia", "Sedan");
    Masina m3("BH-06-VLD", "Skoda", "Octavia", "Sedan");
    Masina m4("BH-07-VLD", "Skoda", "Octavia", "Sedan");
    Masina m5("BH-08-VLD", "Skoda", "Octavia", "Sedan");

    repo.adaugaMasina(m1);
    repo.adaugaMasina(m2);
    repo.adaugaMasina(m3);
    repo.adaugaMasina(m4);
    repo.adaugaMasina(m5);

    assert(repo.getAllMasini().size() == 5);
    assert(repo.getAllMasini()[0].get_nr_inmatriculare() == "BH-04-VLD");
    assert(repo.getAllMasini()[1].get_producator() == "Skoda");
    assert(repo.getAllMasini()[2].get_model() == "Octavia");
    assert(repo.getAllMasini()[3].get_tip() == "Sedan");
    try {
        repo.adaugaMasina(m1);
    }
    catch (RepoException& except) {
        assert(except.get_msg() == "Masina exista deja!");

    }
}

void testValidateMasina()
{
    assert(Masina::validateMasina(Masina("BH-04-VLD", "Skoda", "Octavia", "Sedan")) == 0);
    assert(Masina::validateMasina(Masina("BH-04-VLD", "", "Octavia", "Sedan")) == 2);
    assert(Masina::validateMasina(Masina("BH-04-VLD", "Skoda", "", "Sedan")) == 3);
    assert(Masina::validateMasina(Masina("BH-04-VLD", "Skoda", "Octavia", "")) == 4);
    assert(Masina::validateMasina(Masina("BH-04-VL", "Skoda", "Octavia", "Sedan")) == 1);
}

void testStergeMasina()
{
    MasinaRepo repo;
    Masina m1("BH-04-VLD", "Skoda", "Octavia", "Sedan");
    Masina m2("BH-05-VLD", "Skoda", "Octavia", "Sedan");
    Masina m3("BH-06-VLD", "Skoda", "Octavia", "Sedan");
    repo.adaugaMasina(m1);
    repo.adaugaMasina(m2);
    repo.adaugaMasina(m3);
    repo.stergeMasina("BH-05-VLD");
    assert(repo.getAllMasini().size() == 2);
    assert(repo.getAllMasini()[0].get_nr_inmatriculare() == "BH-04-VLD");
    assert(repo.getAllMasini()[1].get_nr_inmatriculare() == "BH-06-VLD");
    try {
        repo.stergeMasina("BH-07-VLD");
        assert(false);
    }
    catch (RepoException& except) {
        assert(except.get_msg() == "Masina nu exista!");
    }
}

void testModificaMasina()
{
    MasinaRepo repo;
    Masina m1("BH-04-VLD", "Skoda", "Octavia", "Sedan");
    Masina m2("BH-05-VLD", "Skoda", "Octavia", "Sedan");
    Masina m3("BH-06-VLD", "Skoda", "Octavia", "Sedan");
    repo.adaugaMasina(m1);
    assert(m1.get_nr_inmatriculare() == "BH-04-VLD");
    assert(m1.get_producator() == "Skoda");
    assert(m1.get_model() == "Octavia");
    assert(m1.get_tip() == "Sedan");
    repo.adaugaMasina(m2);
    repo.adaugaMasina(m3);
    repo.modificaMasina(Masina("BH-05-VLD", "Skoda", "Octavia", "Combi"));
    assert(repo.getAllMasini()[1].get_tip() == "Combi");
    try {
        repo.modificaMasina(Masina("BH-07-VLD", "Skoda", "Octavia", "Combi"));
        assert(false);
    }
    catch (RepoException& except) {
        assert(except.get_msg() == "Masina nu exista!");
    }
}

void testAdaugaMasinaService()
{
    MasinaRepo repo;
    Spalatorie spalatorie;
    ServiceMasina service(repo, spalatorie);
    string nr_inmatriculare = "BH-04-VLD";
    string producator = "Skoda";
    string model = "Octavia";
    string tip = "Sedan";
    service.adaugaMasinaService(nr_inmatriculare, producator, model, tip);
    assert(service.getAllMasiniService().size() == 1);
    try {
        service.adaugaMasinaService(nr_inmatriculare, producator, model, tip);
        assert(false);
    }
    catch (MasinaException& except) {
        assert(except.get_msg() == "Masina exista deja!");
    }
    nr_inmatriculare = "BH-05-VL";
    try {
        service.adaugaMasinaService(nr_inmatriculare, producator, model, tip);
        assert(false);
    }
    catch (MasinaException& except) {
        assert(except.get_msg() == "Numar de inmatriculare invalid!");
    }
    nr_inmatriculare = "BH-05-VLD";
    producator = "";
    try {
        service.adaugaMasinaService(nr_inmatriculare, producator, model, tip);
        assert(false);
    }
    catch (MasinaException& except) {
        assert(except.get_msg() == "Producator invalid!");
    }
    producator = "Skoda";
    model = "";
    try {
        service.adaugaMasinaService(nr_inmatriculare, producator, model, tip);
        assert(false);
    }
    catch (MasinaException& except) {
        assert(except.get_msg() == "Model invalid!");
    }
    model = "Octavia";
    tip = "";
    try {
        service.adaugaMasinaService(nr_inmatriculare, producator, model, tip);
        assert(false);
    }
    catch (MasinaException& except) {
        assert(except.get_msg() == "Tip invalid!");
    }
}

void testStergeMasinaService()
{
    MasinaRepo repo;
    Spalatorie spalatorie;
    ServiceMasina service(repo, spalatorie);
    string nr_inmatriculare = "BH-04-VLD";
    string producator = "Skoda";
    string model = "Octavia";
    string tip = "Sedan";
    service.adaugaMasinaService(nr_inmatriculare, producator, model, tip);
    nr_inmatriculare = "BH-05-VLD";
    try {
        service.stergeMasinaService(nr_inmatriculare);
        assert(false);
    }
    catch (MasinaException& except) {
        assert(except.get_msg() == "Masina nu exista!");
        nr_inmatriculare = "BH-04-VLD";
        service.stergeMasinaService(nr_inmatriculare);
        assert(service.getAllMasiniService().size() == 0);
    }
}

void testModificaMasinaService()
{
    MasinaRepo repo;
    Spalatorie spalatorie;
    ServiceMasina service(repo, spalatorie);
    string nr_inmatriculare = "BH-04-VLD";
    string producator = "Skoda";
    string model = "Octavia";
    string tip = "Sedan";
    service.adaugaMasinaService(nr_inmatriculare, producator, model, tip);
    nr_inmatriculare = "BH-04-VLD";
    producator = "Skoda";
    model = "Octavia";
    tip = "Combi";
    service.modificaMasinaService(nr_inmatriculare, producator, model, tip);
    assert(service.getAllMasiniService()[0].get_tip() == "Combi");
    nr_inmatriculare = "BH-05-VLD";
    try {
        service.modificaMasinaService(nr_inmatriculare, producator, model, tip);
        assert(false);
    }
    catch (MasinaException& except) {
        assert(except.get_msg() == "Masina nu exista!");
        nr_inmatriculare = "BH-05-VL";
        try {
            service.modificaMasinaService(nr_inmatriculare, producator, model, tip);
            assert(false);
        }
        catch (MasinaException& except) {
            assert(except.get_msg() == "Numar de inmatriculare invalid!");
        }
        nr_inmatriculare = "BH-04-VLD";
        producator = "";
        try {
            service.modificaMasinaService(nr_inmatriculare, producator, model, tip);
            assert(false);
        }
        catch (MasinaException& except) {
            assert(except.get_msg() == "Producator invalid!");
        }
        producator = "Skoda";
        model = "";
        try {
            service.modificaMasinaService(nr_inmatriculare, producator, model, tip);
            assert(false);
        }
        catch (MasinaException& except) {
            assert(except.get_msg() == "Model invalid!");
        }
        model = "Octavia";
        tip = "";
        try {
            service.modificaMasinaService(nr_inmatriculare, producator, model, tip);
            assert(false);
        }
        catch (MasinaException& except) {
            assert(except.get_msg() == "Tip invalid!");
        }
    }
}
void testRepoExceptionMsg()
{
    try {
        throw RepoException("Mesaj");
    }
    catch (RepoException& except) {
        assert(except.get_msg() == "Mesaj");
    }
}

void testMasinaExceptionMsg()
{
    try {
        throw MasinaException("Mesaj");
    }
    catch (MasinaException& except) {
        assert(except.get_msg() == "Mesaj");
    }
}

void testOperator()
{
    Masina m1("BH-04-VLD", "Skoda", "Octavia", "Sedan");

    const Masina& m2(m1);
    assert(m2.get_nr_inmatriculare() == m1.get_nr_inmatriculare());
    assert(m2.get_producator() == m1.get_producator());
    assert(m2.get_model() == m1.get_model());
    assert(m2.get_tip() == m1.get_tip());

    Masina m3 = m1;
    assert(m3.get_nr_inmatriculare() == m1.get_nr_inmatriculare());
    assert(m3.get_producator() == m1.get_producator());
    assert(m3.get_model() == m1.get_model());
    assert(m3.get_tip() == m1.get_tip());

    m3 = Masina("BH-04-VLD", "Skoda", "Octavia", "Combi");
    assert(m1.get_tip() != m3.get_tip());
}

void testFilterProducator()
{
    MasinaRepo repo;
    Spalatorie spalatorie;
    ServiceMasina service(repo, spalatorie);
    string nr_inmatriculare = "BH-04-VLD";
    string producator = "Skoda";
    string model = "Octavia";
    string tip = "Sedan";
    service.adaugaMasinaService(nr_inmatriculare, producator, model, tip);
    nr_inmatriculare = "BH-05-VLD";
    producator = "Dacia";
    service.adaugaMasinaService(nr_inmatriculare, producator, model, tip);
    string cond = "Skoda";
    vector<Masina>masini = service.filterMasiniProducer(cond);
    assert(masini.size() == 1);
}

void testFilterTip()
{
    MasinaRepo repo;
    Spalatorie spalatorie;
    ServiceMasina service(repo, spalatorie);
    string nr_inmatriculare = "BH-04-VLD";
    string producator = "Skoda";
    string model = "Octavia";
    string tip = "Sedan";
    service.adaugaMasinaService(nr_inmatriculare, producator, model, tip);
    nr_inmatriculare = "BH-05-VLD";
    tip = "Combi";
    service.adaugaMasinaService(nr_inmatriculare, producator, model, tip);
    string cond = "Sedan";
    vector<Masina>masini = service.filterMasiniType(cond);
    assert(masini.size() == 1);
}

void testSortare()
{
    MasinaRepo repo;
    Spalatorie spalatorie;
    ServiceMasina service(repo, spalatorie);
    string nr_inmatriculare = "BH-05-VLD";
    string producator = "Skoda";
    string model = "Octavia";
    string tip = "Sedan";
    service.adaugaMasinaService(nr_inmatriculare, producator, model, tip);
    nr_inmatriculare = "BH-04-VLD";
    producator = "Dacia";
    model = "Logan";
    tip = "Combi";
    service.adaugaMasinaService(nr_inmatriculare, producator, model, tip);
    vector<Masina>masini = service.sortMasini(sortNrInmatriculare);
    assert(masini[0].get_nr_inmatriculare() == "BH-04-VLD");
    assert(masini[1].get_nr_inmatriculare() == "BH-05-VLD");
    masini.clear();
    masini = service.sortMasini(sortProducator);
    assert(masini[0].get_producator() == "Dacia");
    assert(masini[1].get_producator() == "Skoda");
    masini.clear();
    masini = service.sortMasini(sortModel);
    assert(masini[0].get_model() == "Logan");
    assert(masini[1].get_model() == "Octavia");
    masini.clear();
    masini = service.sortMasini(sortTip);
    assert(masini[0].get_tip() == "Combi");
    assert(masini[1].get_tip() == "Sedan");
    MasinaRepo repo2;
    Spalatorie spalatorie2;
    ServiceMasina service2(repo2, spalatorie2);
    nr_inmatriculare = "BH-05-VLD";
    producator = "Skoda";
    model = "Octavia";
    tip = "Sedan";
    service2.adaugaMasinaService(nr_inmatriculare, producator, model, tip);
    nr_inmatriculare = "BH-04-VLD";
    producator = "Skoda";
    model = "Logan";
    tip = "Combi";
    service2.adaugaMasinaService(nr_inmatriculare, producator, model, tip);
    masini.clear();
    masini = service2.sortMasini(sortProducatorModel);
    assert(masini[0].get_model() == "Logan");
    assert(masini[1].get_model() == "Octavia");
    MasinaRepo repo3;
    Spalatorie spalatorie3;
    ServiceMasina service3(repo3, spalatorie3);
    nr_inmatriculare = "BH-05-VLD";
    producator = "Skoda";
    model = "Octavia";
    tip = "Sedan";
    service3.adaugaMasinaService(nr_inmatriculare, producator, model, tip);
    nr_inmatriculare = "BH-04-VLD";
    producator = "Dacia";
    model = "Logan";
    tip = "Combi";
    service3.adaugaMasinaService(nr_inmatriculare, producator, model, tip);
    masini.clear();
    masini = service3.sortMasini(sortProducatorModel);
    assert(masini[0].get_producator() == "Dacia");
    assert(masini[1].get_producator() == "Skoda");
}

void testAssignmentOperator() {
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);

    // Test deep copy
    vector<int> v2 = v1;
    assert(v2.size() == v1.size());
    for (int i = 0; i < v1.size(); i++) {
        assert(v2[i] == v1[i]);
    }

    // Test original object remains unchanged
    v2.push_back(4);
    assert(v1.size() == 3);
    assert(v2.size() == 4);

    // Test self-assignment
    v2 = v2;
    assert(v2.size() == 4);
    assert(v2[3] == 4);
}


void testClearAllSpalatorie()
{
    MasinaRepo repo;
    Spalatorie spalatorie;
    ServiceMasina service(repo, spalatorie);
    string nr_inmatriculare = "BH-04-VLD";
    string producator = "Skoda";
    string model = "Octavia";
    string tip = "Sedan";
    service.adaugaMasinaService(nr_inmatriculare, producator, model, tip);
    service.addMasinaSpalatorie(nr_inmatriculare);
    assert(service.getAllSpalatorie().size() == 1);
    service.clearAllSpalatorie();
    assert(service.getAllSpalatorie().size() == 0);

}


void testGenerateRandom()
{
    MasinaRepo repo;
    Spalatorie spalatorie;
    ServiceMasina service(repo, spalatorie);
    repo.adaugaMasina(Masina("BH-04-VLD", "Skoda", "Octavia", "Sedan"));
    service.generateRandom(5);
    assert(service.getAllSpalatorie().size() == 5);
    assert(service.getAllSpalatorie()[0].get_nr_inmatriculare() == "BH-04-VLD");
    assert(service.getAllSpalatorie()[1].get_nr_inmatriculare() == "BH-04-VLD");
    assert(service.getAllSpalatorie()[2].get_nr_inmatriculare() == "BH-04-VLD");
    assert(service.getAllSpalatorie()[3].get_nr_inmatriculare() == "BH-04-VLD");
    assert(service.getAllSpalatorie()[4].get_nr_inmatriculare() == "BH-04-VLD");

}

void testRaport()
{
    MasinaRepo repo;
    Spalatorie spalatorie;
    ServiceMasina service(repo, spalatorie);
    string nr_inmatriculare = "BH-04-VLD";
    string producator = "Skoda";
    string model = "Octavia";
    string tip = "Sedan";
    service.adaugaMasinaService(nr_inmatriculare, producator, model, tip);
    nr_inmatriculare = "BH-05-VLD";
    producator = "Dacia";
    model = "Logan";
    tip = "Combi";
    service.adaugaMasinaService(nr_inmatriculare, producator, model, tip);
    unordered_map<string, int> raport;
    service.filterWithMap(raport);
    assert(raport["Sedan"] == 1);
    assert(raport["Combi"] == 1);
}

void testServiceExceptionMsg()
{
    try {
        throw ServiceException("Mesaj");
    }
    catch (ServiceException& except) {
        assert(except.get_msg() == "Mesaj");
    }
}

void testSaveToFileSpalatorieService()
{
    MasinaRepo repo;
    Spalatorie spalatorie;
    ServiceMasina service(repo, spalatorie);
    string nr_inmatriculare = "BH-04-VLD";
    string producator = "Skoda";
    string model = "Octavia";
    string tip = "Sedan";
    service.adaugaMasinaService(nr_inmatriculare, producator, model, tip);
    service.addMasinaSpalatorie(nr_inmatriculare);
    nr_inmatriculare = "BH-05-VLD";
    producator = "Dacia";
    model = "Logan";
    tip = "Combi";
    service.adaugaMasinaService(nr_inmatriculare, producator, model, tip);
    service.addMasinaSpalatorie(nr_inmatriculare);
    try {
        service.saveToFileSpalatorie("test.txt");
        assert(false);
    }
    catch (ServiceException& except) {
        assert(except.get_msg() == "Fisierul trebuie sa fie de tip .csv sau .html!");
    }
    service.saveToFileSpalatorie("test.csv");
    service.clearAllSpalatorie();
    service.loadFromFileSpalatorie("test.csv");
    assert(service.getAllSpalatorie().size() == 2);
    assert(service.getAllSpalatorie()[0].get_nr_inmatriculare() == "BH-04-VLD");
    assert(service.getAllSpalatorie()[1].get_nr_inmatriculare() == "BH-05-VLD");
    service.saveToFileSpalatorie("test.html");
    service.clearAllSpalatorie();
    service.loadFromFileSpalatorie("test.html");
    assert(service.getAllSpalatorie().size() == 2);
}


void testUndo()
{
    MasinaRepo repo;
    Spalatorie spalatorie;
    ServiceMasina service(repo, spalatorie);
    string nr_inmatriculare = "BH-04-VLD";
    string producator = "Skoda";
    string model = "Octavia";
    string tip = "Sedan";
    try {
        service.undo();
        assert(false);
    }
    catch (ServiceException& except) {
        assert(except.get_msg() == "Nu mai exista operatii de undo!");
    }
    service.adaugaMasinaService(nr_inmatriculare, producator, model, tip);
    service.undo();
    assert(service.getAllMasiniService().size() == 0);
    service.adaugaMasinaService(nr_inmatriculare, producator, model, tip);
    nr_inmatriculare = "BH-05-VLD";
    service.adaugaMasinaService(nr_inmatriculare, producator, model, tip);
    service.stergeMasinaService(nr_inmatriculare);
    service.undo();
    assert(service.getAllMasiniService().size() == 2);
    producator = "Dacia";
    service.modificaMasinaService(nr_inmatriculare, producator, model, tip);
    service.undo();
    assert(service.getAllMasiniService()[1].get_producator() == "Skoda");
}

void testRepoFisier()
{
    std::ofstream ofs;
    ofs.open("test.txt", std::ofstream::out | std::ofstream::trunc);
    ofs << "BH-04-VLD" << '\n';
    ofs << "Skoda" << '\n';
    ofs << "Octavia" << '\n';
    ofs << "Sedan" << '\n';
    ofs.close();
    RepoFisier repo("test.txt");
    Spalatorie spalatorie;
    ServiceMasina service(repo, spalatorie);
    string nr_inmatriculare = "BH-04-VLD";
    string producator = "Skoda";
    string model = "Octavia";
    string tip = "Sedan";
    try {
        service.adaugaMasinaService(nr_inmatriculare, producator, model, tip);
        assert(false);
    }
    catch (MasinaException& except)
    {
        assert(except.get_msg() == "Masina exista deja!");
    }
    assert(service.getAllMasiniService().size() == 1);
    nr_inmatriculare = "BH-05-VLD";
    producator = "Dacia";
    model = "Logan";
    tip = "Combi";
    service.adaugaMasinaService(nr_inmatriculare, producator, model, tip);
    model = "Sandero";
    service.modificaMasinaService(nr_inmatriculare, producator, model, tip);
    assert(service.getAllMasiniService()[1].get_model() == "Sandero");
    service.stergeMasinaService(nr_inmatriculare);
    assert(service.getAllMasiniService().size() == 1);
    service.undo();
    assert(service.getAllMasiniService().size() == 2);
    service.saveToFile("test.txt");
    for (auto& masina : service.getAllMasiniService())
    {
        service.stergeMasinaService(masina.get_nr_inmatriculare());
    }
    nr_inmatriculare = "BH-06-VLD";
    try {
        service.stergeMasinaService(nr_inmatriculare);
        assert(false);
    }
    catch (MasinaException& except)
    {
        assert(except.get_msg() == "Masina nu exista!");
    }
    try {
        service.modificaMasinaService(nr_inmatriculare, producator, model, tip);
        assert(false);
    }
    catch (MasinaException& except)
    {
        assert(except.get_msg() == "Masina nu exista!");
    }
}


void testSaveToFileService()
{
    MasinaRepo repo;
    Spalatorie spalatorie;
    ServiceMasina service(repo, spalatorie);
    string nr_inmatriculare = "BH-04-VLD";
    string producator = "Skoda";
    string model = "Octavia";
    string tip = "Sedan";
    service.adaugaMasinaService(nr_inmatriculare, producator, model, tip);
    nr_inmatriculare = "BH-05-VLD";
    producator = "Dacia";
    model = "Logan";
    tip = "Combi";
    service.adaugaMasinaService(nr_inmatriculare, producator, model, tip);
    service.saveToFile("test.txt");
    for (auto masina : service.getAllMasiniService())
    {
        service.stergeMasinaService(masina.get_nr_inmatriculare());
    }
    service.loadFromFile("test.txt");
    assert(service.getAllMasiniService().size() == 2);
    assert(service.getAllMasiniService()[0].get_nr_inmatriculare() == "BH-04-VLD");
    assert(service.getAllMasiniService()[1].get_nr_inmatriculare() == "BH-05-VLD");

}


void allTests() {
    cout << "Teste incepute..." << endl;
    testAddRepo();
    testValidateMasina();
    testStergeMasina();
    testModificaMasina();
    testAdaugaMasinaService();
    testStergeMasinaService();
    testModificaMasinaService();
    testRepoExceptionMsg();
    testMasinaExceptionMsg();
    testOperator();
    testFilterProducator();
    testFilterTip();
    testSortare();
    testAssignmentOperator();
    testGenerateRandom();
    testRaport();
    testServiceExceptionMsg();
    testUndo();
    testClearAllSpalatorie();
    testSaveToFileSpalatorieService();
    testSaveToFileService();
    testRepoFisier();
    cout << "Teste finalizate!" << endl;
}