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

const int val5 = 5;
const int val6 = 6;
const int val7 = 7;
const int val8 = 8;


void UI::citireAdaugareMasina() {
    string nr_inmatriculare;
    string producator;
    string model;
    string tip;
    cout<<"\nIntroduceti numarul de inmatriculare:\n";
    cin>>nr_inmatriculare;
    cout<<"\nIntroduceti producatorul:\n";
    cin>>producator;
    cout<<"\nIntroduceti modelul:\n";
    cin>>model;
    cout<<"\nIntroduceti tipul:\n";
    cin>>tip;
    try{
        service.adaugaMasinaService(nr_inmatriculare, producator, model, tip);
    } catch(MasinaException& e) {
        cout<<e.get_msg()<<"\n";
    }
}

void UI::citireStergereMasina() {
    string nr_inmatriculare;
    cout<<"Introduceti numarul de inmatriculare:\n";
    cin>>nr_inmatriculare;
    try {
        service.stergeMasinaService(nr_inmatriculare);
    } catch(MasinaException& e) {
        cout<<e.get_msg()<<"\n";
    }
}

void UI::run() {
    int optiune = -1;
    while(true) {
        menu();
        cout<<"Introduceti optiunea:\n";
        cin>>optiune;
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
            case val5:
                citireFiltrareProducator();
                break;
            case val6:
                citireFiltrareTip();
                break;
            case val7:
                sortare();
                break;
            case val8:

                break;
            case 0:
                return;
            default:
                cout<<"Optiune invalida!\n";
                break;
        }
    }
}

void UI::menu() {
    cout<<"1. Adaugare masina\n";
    cout<<"2. Stergere masina\n";
    cout<<"3. Modificare masina\n";
    cout<<"4. Afisare masini\n";
    cout<<"5. Filtrare masini dupa producator\n";
    cout<<"6. Filtrare masini dupa tip\n";
    cout<<"7. Sortare masini\n";
    cout<<"8. Creare lista de
    cout<<"0. Exit\n";
}

void UI::afisareMasini() {
    vector<Masina> masini = service.getAllMasiniService();
    for(const auto & i : masini) {
        cout << "Numar de inmatriculare: " << i.get_nr_inmatriculare() << " Producator: " << i.get_producator() << " Model: " << i.get_model() << " Tip: " << i.get_tip() << "\n";
    }
}

void UI::citireModificareMasina() {
    string nr_inmatriculare;
    string producator;
    string model;
    string tip;
    cout<<"\nIntroduceti numarul de inmatriculare:\n";
    cin>>nr_inmatriculare;
    cout<<"\nIntroduceti producatorul:\n";
    cin>>producator;
    cout<<"\nIntroduceti modelul:\n";
    cin>>model;
    cout<<"\nIntroduceti tipul:\n";
    cin>>tip;
    try {
        service.modificaMasinaService(nr_inmatriculare, producator, model, tip);
    } catch(MasinaException& e) {
        cout<<e.get_msg()<<"\n";
    }
}

void UI::citireFiltrareProducator() {
    string producator;
    cout<<"Introduceti producatorul:\n";
    cin>>producator;
    vector<Masina> masini = service.filterMasiniProducer(producator);
    if(masini.empty()) {
        cout<<"Nu exista masini cu acest producator!\n";
        return;
    }
    else
        for(const auto & i : masini)
            cout << "Numar de inmatriculare: " << i.get_nr_inmatriculare() << " Producator: " << i.get_producator() << " Model: " << i.get_model() << " Tip: " << i.get_tip() << "\n";
}

void UI::citireFiltrareTip() {
    string tip;
    cout<<"Introduceti tipul:\n";
    cin>>tip;
    vector<Masina> masini = service.filterMasiniType(tip);
    if(masini.empty()) {
        cout<<"Nu exista masini de acest tip!\n";
        return;
    }
    else
        for(const auto & i : masini)
            cout << "Numar de inmatriculare: " << i.get_nr_inmatriculare() << " Producator: " << i.get_producator() << " Model: " << i.get_model() << " Tip: " << i.get_tip() << "\n";
}


void UI::sortare() {
    cout<<"SORTARE"<<endl;
    cout<<"1. Numar de inmatriculare \n 2. Tip \n 3. Producator si model"<<endl;
    string optiune;
    cout<<">>> ";
    cin>>optiune;
    if (optiune == "1") {
        vector<Masina> lista_sortata = service.sortMasini(sortNrInmatriculare);
        for(const auto & i : lista_sortata) {
            cout << "Numar de inmatriculare: " << i.get_nr_inmatriculare() << " Producator: " << i.get_producator() << " Model: " << i.get_model() << " Tip: " << i.get_tip() << "\n";
        }
    } else if(optiune == "2") {
        vector<Masina> lista_sortata = service.sortMasini(sortTip);
        for(const auto & i : lista_sortata) {
            cout << "Numar de inmatriculare: " << i.get_nr_inmatriculare() << " Producator: " << i.get_producator() << " Model: " << i.get_model() << " Tip: " << i.get_tip() << "\n";
        }
    } else if(optiune == "3") {
        vector<Masina> lista_sortata = service.sortMasini(sortProducatorModel);
        for(const auto & i : lista_sortata) {
            cout << "Numar de inmatriculare: " << i.get_nr_inmatriculare() << " Producator: " << i.get_producator() << " Model: " << i.get_model() << " Tip: " << i.get_tip() << "\n";
        }
    }
}

