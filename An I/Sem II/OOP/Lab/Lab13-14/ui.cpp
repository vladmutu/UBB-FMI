//
// Created by vladm on 4/2/2024.
//
#include "ui.h"
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <QtWidgets>
using std::cin;
using std::cout;
using std::string;


void UI::citireAdaugareMasina() {
    string nr_inmatriculare;
    string producator;
    string model;
    string tip;
    cout << "\nIntroduceti numarul de inmatriculare:\n";
    cin >> nr_inmatriculare;
    cout << "\nIntroduceti producatorul:\n";
    cin >> producator;
    cout << "\nIntroduceti modelul:\n";
    cin >> model;
    cout << "\nIntroduceti tipul:\n";
    cin >> tip;
    try {
        service.adaugaMasinaService(nr_inmatriculare, producator, model, tip);
    }
    catch (MasinaException& e) {
        cout << e.get_msg() << "\n";
    }
}

void UI::citireStergereMasina() {
    string nr_inmatriculare;
    cout << "Introduceti numarul de inmatriculare:\n";
    cin >> nr_inmatriculare;
    try {
        service.stergeMasinaService(nr_inmatriculare);
    }
    catch (MasinaException& e) {
        cout << e.get_msg() << "\n";
    }
}

void UI::run() {
    int optiune = -1;
    while (true) {
        menu();
        cout << "Introduceti optiunea:\n";
        cin >> optiune;
        switch (optiune) {
            case 1:
                citireAdaugareMasina();
                break;
            case 2:
                citireStergereMasina();
                break;
            case 3:
                citireModificareMasina();
                break;
            case 4:
                afisareMasini();
                break;
            case 5:
                citireFiltrareProducator();
                break;
            case 6:
                citireFiltrareTip();
                break;
            case 7:
                sortare();
                break;
            case 8:
                menuSpalatorie();
                int cmd2;
                cin >> cmd2;
                switch (cmd2)
                {
                    case 1:
                        citireAdaugaSpalatorie();
                        break;
                    case 2:
                        generateRandomSpalatorieUI();
                        break;
                    case 3:
                        clearAllSpalatorie();
                        break;
                    case 4:
                        printAllSpalatorie();
                        break;
                    case 5:
                        saveToFileSpalatorie();
                        break;
                    case 0:
                        break;
                    default:
                        cout << "\nComanda invalida!";
                        break;
                }
                break;
            case 9:
                raportWithMapUI();
                break;
            case 10:
                undoUI();
                break;
            case 0:
                return;
            default:
                cout << "Optiune invalida!\n";
                break;
        }
    }
}

void UI::menu() {
    cout << "1. Adaugare masina\n";
    cout << "2. Stergere masina\n";
    cout << "3. Modificare masina\n";
    cout << "4. Afisare masini\n";
    cout << "5. Filtrare masini dupa producator\n";
    cout << "6. Filtrare masini dupa tip\n";
    cout << "7. Sortare\n";
    cout << "8. Spalatorie\n";
    cout << "9. Raport\n";
    cout << "10. Undo\n";
    cout << "0. Exit\n";
}

void UI::afisareMasini() {
    vector<Masina> masini = service.getAllMasiniService();
    for (auto& masina : masini) {
        cout << "Numar de inmatriculare: " << masina.get_nr_inmatriculare() << " Producator: " << masina.get_producator() << " Model: " << masina.get_model() << " Tip: " << masina.get_tip() << "\n";
    }
}

void UI::citireModificareMasina() {
    string nr_inmatriculare;
    string producator;
    string model;
    string tip;
    cout << "\nIntroduceti numarul de inmatriculare:\n";
    cin >> nr_inmatriculare;
    cout << "\nIntroduceti producatorul:\n";
    cin >> producator;
    cout << "\nIntroduceti modelul:\n";
    cin >> model;
    cout << "\nIntroduceti tipul:\n";
    cin >> tip;
    try {
        service.modificaMasinaService(nr_inmatriculare, producator, model, tip);
    }
    catch (MasinaException& e) {
        cout << e.get_msg() << "\n";
    }
}

void UI::citireFiltrareProducator() {
    string producator;
    cout << "Introduceti producatorul:\n";
    cin >> producator;
    vector<Masina> masini = service.filterMasiniProducer(producator);
    if (masini.size() == 0) {
        cout << "Nu exista masini cu acest producator!\n";
        return;
    }
    else
        for (auto& masina : masini) {
            cout << "Numar de inmatriculare: " << masina.get_nr_inmatriculare() << " Producator: " << masina.get_producator() << " Model: " << masina.get_model() << " Tip: " << masina.get_tip() << "\n";
        }
}

void UI::citireFiltrareTip() {
    string tip;
    cout << "Introduceti tipul:\n";
    cin >> tip;
    vector<Masina> masini = service.filterMasiniType(tip);
    if (masini.size() == 0) {
        cout << "Nu exista masini de acest tip!\n";
        return;
    }
    else
        for (auto& masina : masini) {
            cout << "Numar de inmatriculare: " << masina.get_nr_inmatriculare() << " Producator: " << masina.get_producator() << " Model: " << masina.get_model() << " Tip: " << masina.get_tip() << "\n";
        }
}


void UI::sortare() {
    cout << "SORTARE" << endl;
    cout << "1. Numar de inmatriculare \n 2. Tip \n 3. Producator si model" << endl;
    string optiune;
    cout << ">>> ";
    cin >> optiune;
    if (optiune == "1") {
        vector<Masina> lista_sortata = service.sortMasini(sortNrInmatriculare);
        for (auto& masina : lista_sortata) {
            cout << "Numar de inmatriculare: " << masina.get_nr_inmatriculare() << " Producator: " << masina.get_producator() << " Model: " << masina.get_model() << " Tip: " << masina.get_tip() << "\n";
        }
    }
    else if (optiune == "2") {
        vector<Masina> lista_sortata = service.sortMasini(sortTip);
        for (auto& masina : lista_sortata) {
            cout << "Numar de inmatriculare: " << masina.get_nr_inmatriculare() << " Producator: " << masina.get_producator() << " Model: " << masina.get_model() << " Tip: " << masina.get_tip() << "\n";
        }
    }
    else if (optiune == "3") {
        vector<Masina> lista_sortata = service.sortMasini(sortProducatorModel);
        for (auto& masina : lista_sortata) {
            cout << "Numar de inmatriculare: " << masina.get_nr_inmatriculare() << " Producator: " << masina.get_producator() << " Model: " << masina.get_model() << " Tip: " << masina.get_tip() << "\n";
        }
    }
}

void UI::menuSpalatorie()
{
    cout << "1. Adauga masina\n";
    cout << "2. Genereaza random\n";
    cout << "3. Goleste lista\n";
    cout << "4. Afiseaza lista\n";
    cout << "5. Salveaza in fisier\n";
    cout << "0. Inapoi\n";
}

void UI::citireAdaugaSpalatorie()
{
    string nr_inmatriculare;
    cout << "Introduceti numarul de inmatriculare:\n";
    cin >> nr_inmatriculare;
    try {
        service.addMasinaSpalatorie(nr_inmatriculare);
    }
    catch (MasinaException& e) {
        cout << e.get_msg() << "\n";
    }
    cout << "\n" << service.getAllSpalatorie().size() << "\n";
}

void UI::raportWithMapUI()
{
    unordered_map<string, int> raport;
    service.filterWithMap(raport);
    auto printKeyValue = [](const auto& key, const auto& value) { cout << "Tip:" << key << " Numar de masini:" << value << "\n"; };
    for (auto& pair : raport)
        printKeyValue(pair.first, pair.second);
}

void UI::clearAllSpalatorie()
{
    service.clearAllSpalatorie();
    cout << "\n" << service.getAllSpalatorie().size() << "\n";
}


void UI::generateRandomSpalatorieUI()
{
    int n;
    cout << "Introduceti numarul de masini:\n";
    cin >> n;
    try
    {
        service.generateRandom(n);
    }
    catch (MasinaException& e)
    {
        cout << e.get_msg();
    }
    cout << "\n" << service.getAllSpalatorie().size() << "\n";
}

void UI::saveToFileSpalatorie()
{
    string filename;
    cout << "Introduceti numele fisierului:\n";
    cin >> filename;
    service.saveToFileSpalatorie(filename);
}


void UI::undoUI()
{
    try {
        service.undo();
    }
    catch (ServiceException& e) {
        cout << e.get_msg() << "\n";
    }
}


void UI::printAllSpalatorie() {
    vector<Masina>& manager = service.getAllSpalatorie();
    for (auto& masina : manager) {
        cout << "Numar de inmatriculare: " << masina.get_nr_inmatriculare() << " Producator: " << masina.get_producator() << " Model: " << masina.get_model() << " Tip: " << masina.get_tip() << "\n";
    }
    cout << "\n" << manager.size() << "\n";
}

