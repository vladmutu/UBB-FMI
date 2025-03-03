//
// Created by vladm on 5/22/2024.
//
#include "domain.h"

string Log::get_id() const {
    return id;
}

string Log::get_content() const {
    return content;
}

int Log::get_pid() const {
    return pid;
}

string Log::get_level() const {
    return level;
}

int Log::validateLog() {
    if(id.size() < 4)
        return 1;
    if(content.empty())
        return 2;
    if(pid < 0)
        return 3;
    if(level != "info" && level != "warning" && level != "error" && level != "critical")
        return 4;
    return 0;
}

