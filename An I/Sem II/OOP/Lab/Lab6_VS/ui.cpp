//
// Created by vladm on 4/2/2024.
//
#include "ui.h"
#include "service.h"
#include <iostream>
#include <string>
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
    cout << "7. Sortare masini dupa nr_inmatriculare\n";
    cout << "8. Sortare masini dupa tip\n";
    cout << "9. Sortare masini dupa producator si model\n";
    cout << "0. Exit\n";
}

void UI::afisareMasini() {
    VectorDinamic<Masina> masini = service.getAllMasiniService();
    for (int i = 0; i < masini.size(); i++) {
        cout << "Numar de inmatriculare: " << masini.get(i).get_nr_inmatriculare() << " Producator: " << masini.get(
            i).get_producator() << " Model: " << masini.get(
                i).get_model() << " Tip: " << masini.get(
                    i).get_tip() << "\n";
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
    VectorDinamic<Masina> masini = service.filterMasiniProducer(producator);
    if (masini.size() == 0) {
        cout << "Nu exista masini cu acest producator!\n";
        return;
    }
    else
        for (int i = 0; i < masini.size(); i++)
            cout << "Numar de inmatriculare: " << masini.get(i).get_nr_inmatriculare() << " Producator: " << masini.get(
                i).get_producator() << " Model: " << masini.get(
                    i).get_model() << " Tip: " << masini.get(
                        i).get_tip() << "\n";
}

void UI::citireFiltrareTip() {
    string tip;
    cout << "Introduceti tipul:\n";
    cin >> tip;
    VectorDinamic<Masina> masini = service.filterMasiniType(tip);
    if (masini.size() == 0) {
        cout << "Nu exista masini de acest tip!\n";
        return;
    }
    else
        for (int i = 0; i < masini.size(); i++)
            cout << "Numar de inmatriculare: " << masini.get(i).get_nr_inmatriculare() << " Producator: " << masini.get(
                i).get_producator() << " Model: " << masini.get(
                    i).get_model() << " Tip: " << masini.get(
                        i).get_tip() << "\n";
}


void UI::sortare() {
    cout << "SORTARE" << endl;
    cout << "1. Numar de inmatriculare \n 2. Tip \n 3. Producator si model" << endl;
    string optiune;
    cout << ">>> ";
    cin >> optiune;
    if (optiune == "1") {
        VectorDinamic<Masina> lista_sortata = service.sortMasini(sortNrInmatriculare);
        for (int i = 0; i < lista_sortata.size(); i++) {
            cout << "Numar de inmatriculare: " << lista_sortata.get(i).get_nr_inmatriculare() << " Producator: " << lista_sortata.get(
                i).get_producator() << " Model: " << lista_sortata.get(
                    i).get_model() << " Tip: " << lista_sortata.get(
                        i).get_tip() << "\n";
        }
    }
    else if (optiune == "2") {
        VectorDinamic<Masina> lista_sortata = service.sortMasini(sortTip);
        for (int i = 0; i < lista_sortata.size(); i++) {
            cout << "Numar de inmatriculare: " << lista_sortata.get(i).get_nr_inmatriculare() << " Producator: " << lista_sortata.get(
                i).get_producator() << " Model: " << lista_sortata.get(
                    i).get_model() << " Tip: " << lista_sortata.get(
                        i).get_tip() << "\n";
        }
    }
    else if (optiune == "3") {
        VectorDinamic<Masina> lista_sortata = service.sortMasini(sortProducatorModel);
        for (int i = 0; i < lista_sortata.size(); i++) {
            cout << "Numar de inmatriculare: " << lista_sortata.get(i).get_nr_inmatriculare() << " Producator: " << lista_sortata.get(
                i).get_producator() << " Model: " << lista_sortata.get(
                    i).get_model() << " Tip: " << lista_sortata.get(
                        i).get_tip() << "\n";
        }
    }
}
