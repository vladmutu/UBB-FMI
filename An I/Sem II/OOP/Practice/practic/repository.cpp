//
// Created by vladm on 5/22/2024.
//
#include "repository.h"
#include "domain.h"
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

void RepoLogs::loadFromFile() {
    ifstream fin(file_name);
    if(!fin.is_open())
        throw RepoException("Nu s-a putut deschide fisierul");
    while(!fin.eof())
    {
        string id;
        string content;
        string pid_aux;
        string level;
        getline(fin, id, ',');
        getline(fin, content, ',');
        getline(fin, pid_aux, ',');
        getline(fin, level, '\n');
        if(id.empty())
            break;
        int pid = stoi(pid_aux);
        Log log(id, content, pid, level);
        adaugaLog(log);
    }
}

void RepoLogs::writeToFile() {
    ofstream fout(file_name);
    if(!fout.is_open())
        throw RepoException("Nu s-a putut deschide fisierul!");
    for(auto& log : logs)
    {
        fout<<log.get_id()<<','<<log.get_content()<<','<<log.get_pid()<<','<<log.get_level()<<'\n';
    }
}

void RepoLogs::adaugaLog(const Log &log) {
    for(auto& l : logs)
    {
        if(l.get_id() == log.get_id())
            throw RepoException("Log cu acest id deja existent!");
    }
    logs.push_back(log);
}

void RepoLogs::modificaLog(const Log &log) {
    for(auto& l : logs)
    {
        if(l.get_id() == log.get_id()){
            l = log;
            return;
        }
    }
    throw RepoException("Nu exista un log cu acest id!");
}

void RepoLogs::stergeLog(const string &id) {
    int poz = 0;
    bool ok = false;
    for(auto& l : logs)
    {
        if(l.get_id() == id) {
            ok = true;
            logs.erase(logs.begin() + poz);
        }
        poz++;
    }
    if(!ok)
        throw RepoException("Nu exista un log cu acest id!");
}

vector<Log> RepoLogs::getAllLogs() {
    return logs;
}

