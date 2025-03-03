//
// Created by vladm on 5/22/2024.
//
#include "service.h"
#include <cstring>
#include <string>
#include <iostream>
using namespace std;

void ServiceLogs::adaugaLogService(const string& id, const string& content, int pid, const string& level) {
    Log log(id, content, pid, level);
    switch(log.validateLog())
    {
        case 0:
            try{
                repo.adaugaLog(log);
            }catch(RepoException& e){
                throw ServiceException(e.get_msg());
            }
            break;
        case 1:
            throw ServiceException("ID invalid!");
            break;
        case 2:
            throw ServiceException("Content invalid!");
            break;
        case 3:
            throw ServiceException("PID invalid!");
            break;
        case 4:
            throw ServiceException("Level invalid!");
            break;
    }
}

void ServiceLogs::modificaLogService(const string &id, const string &content, int pid, const string &level) {
    Log log(id, content, pid, level);
    switch(log.validateLog())
    {
        case 0:
            try{
                repo.modificaLog(log);
            }catch(RepoException& e){
                throw ServiceException(e.get_msg());
            }
            break;
        case 1:
            throw ServiceException("ID invalid!");
            break;
        case 2:
            throw ServiceException("Content invalid!");
            break;
        case 3:
            throw ServiceException("PID invalid!");
            break;
        case 4:
            throw ServiceException("Level invalid!");
            break;
    }
}

void ServiceLogs::stergeLogService(const string &id) {
    try{
        repo.stergeLog(id);
    }catch(RepoException& e){
        throw ServiceException(e.get_msg());
    }
}

vector<Log> ServiceLogs::getAllLogsService() {
    return repo.getAllLogs();
}


