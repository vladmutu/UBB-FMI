//
// Created by vladm on 5/22/2024.
//

#ifndef PRACTIC_SERVICE_H
#define PRACTIC_SERVICE_H
#include <utility>

#include "repository.h"

class ServiceException : public exception{
private:
    string msg;
public:
    explicit ServiceException(string  message) : msg{std::move(message)}
    {

    }
    string get_msg(){
        return msg;
    }
};

class ServiceLogs{
private:
    RepoLogs& repo;
public:
    explicit ServiceLogs(RepoLogs& repo) : repo{repo}{

    };
    ~ServiceLogs() = default;
    void adaugaLogService(const string& id, const string& content, int pid, const string& level);

    void modificaLogService(const string& id, const string& content, int pid, const string& level);

    void stergeLogService(const string& id);

    vector<Log> getAllLogsService();
};

#endif //PRACTIC_SERVICE_H
