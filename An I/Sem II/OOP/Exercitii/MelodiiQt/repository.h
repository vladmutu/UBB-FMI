//
// Created by vladm on 6/21/2024.
//

#ifndef MELODIIQT_REPOSITORY_H
#define MELODIIQT_REPOSITORY_H
#include <string>
#include <utility>
#include "domain.h"
#include <vector>
#include <algorithm>

using namespace std;

class RepoException : public std::exception{
private:
    string msg;
public:
    explicit RepoException(string  msg) : msg{std::move(msg)} {

    }
    string get_msg(){
        return this->msg;
    }
};

class RepoMelodii{
private:
    vector<Melodie> melodii;
    string file_name="melodii.txt";
    void load_from_file();
    void save_to_file();
public:
    RepoMelodii(){
        load_from_file();
    }

    void adauga_melodie(Melodie& m)
    {
        for(auto& melodie : melodii)
            if(melodie.get_id() == m.get_id())
                throw RepoException("Id deja existent!");
        melodii.push_back(m);
        sort(melodii.begin(), melodii.end(), [](Melodie& m1, Melodie& m2){
            return m1.get_id() < m2.get_id();
        });
    }

    vector<Melodie>& get_all()
    {
        return melodii;
    }

    ~RepoMelodii(){
        save_to_file();
    }
};

#endif //MELODIIQT_REPOSITORY_H
