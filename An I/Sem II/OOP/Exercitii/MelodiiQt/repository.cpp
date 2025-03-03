//
// Created by vladm on 6/21/2024.
//
#include "repository.h"
#include <fstream>

using namespace std;

void RepoMelodii::load_from_file() {
    ifstream fin(file_name);
    while(!fin.eof())
    {
        string id_aux;
        string titlu;
        string artist;
        string rank_aux;
        getline(fin, id_aux, ',');
        getline(fin, titlu, ',');
        getline(fin, artist, ',');
        getline(fin, rank_aux, '\n');
        if(id_aux.empty())
            break;
        int id = stoi(id_aux);
        int rank = stoi(rank_aux);
        Melodie m(id, titlu, artist, rank);
        adauga_melodie(m);
    }
}

void RepoMelodii::save_to_file() {
    ofstream fout(file_name);
    for(auto& melodie : melodii)
        fout << melodie.get_id() << "," << melodie.get_titlu() << "," << melodie.get_artist() << "," << melodie.get_rank() << '\n';
}

