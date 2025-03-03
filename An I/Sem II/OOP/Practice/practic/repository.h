//
// Created by vladm on 5/22/2024.
//

#ifndef PRACTIC_REPOSITORY_H
#define PRACTIC_REPOSITORY_H

#include <fstream>
#include <string>
#include <cstring>
#include <utility>
#include <vector>
#include "domain.h"

using namespace std;

class RepoException : public exception{
private:
    string msg;
public:
    explicit RepoException(string  message) : msg{std::move(message)}{

    }
    string get_msg(){
        return msg;
    }

};

class RepoLogs{
private:
    vector<Log> logs;
    string file_name;
    void loadFromFile();
    void writeToFile();
public:
    explicit RepoLogs(string file_name) : file_name{std::move(file_name)}{
        loadFromFile();
    }
    ~RepoLogs() = default;

    void adaugaLog(const Log& log);

    void modificaLog(const Log& log);

    void stergeLog(const string& id);

    vector<Log> getAllLogs();
};


#endif //PRACTIC_REPOSITORY_H
