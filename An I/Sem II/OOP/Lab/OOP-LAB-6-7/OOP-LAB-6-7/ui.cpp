#include "ui.h"
#include <iostream>
using std::cin;
using std::cout;
void ui::run(){
    while(true)
    {
        cout<<"1. Adauga masina\n2. Actualizare\n3. Sterge\n4. Print\n0. Exit\nComand:";
        int cmd=0;
        cin>>cmd;
        if (cmd==0){
            break;
        }
        if (cmd==1){
            string numar_inmatriculare;
            string model;
            string categorie;
            cout<<"Numar inmatriculare: ";
            cin>>numar_inmatriculare;
            cout<<"\nModel: ";
            cin>>model;
            cout<<"\nCategorie: ";
            cin>>categorie;
            try{
                serv.add_masina(numar_inmatriculare,model,categorie);
                cout<<"Masina adaugata cu succes\n";
            }
            catch (RepoException& ex){
                cout<<ex.getMessage();
            }

        }
        if (cmd==2)
        {
            string numar_inmatriculare;
            string new_model;
            string new_categorie;
            cout<<"Numar inmatriculare: ";
            cin>>numar_inmatriculare;
            cout<<"\nModel: ";
            cin>>new_model;
            cout<<"\nCategorie: ";
            cin>>new_categorie;
            try{
                serv.actualizare_masina(numar_inmatriculare,new_model,new_categorie);
                cout<<"Masina actualizata cu succes\n";
            }
            catch (RepoException& ex){
                cout<<ex.getMessage();
            }
        }
        if (cmd==3){
            string numar_inmatriculare;
            cout<<"Numar inmatriculare: ";
            cin>>numar_inmatriculare;
            try{
                serv.stergere_masina(numar_inmatriculare);
                cout<<"Masina stearsa cu succes\n";
            }
            catch (RepoException& ex){
                cout<<ex.getMessage();
            }
        }
        if (cmd==4)
        {
            auto masini = serv.get_all();
            if(masini.empty())
            {
                cout<<"Nu exista masini!\n";
            }
            else{
                for (const auto& masina: masini)
                {
                    cout<<masina.get_numar_inmatriculare()<<" "<<masina.get_model()<<" "<<masina.get_categorie()<<"\n";
                }
            }

        }
    }
}