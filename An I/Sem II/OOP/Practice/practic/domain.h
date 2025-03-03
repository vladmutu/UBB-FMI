//
// Created by vladm on 5/22/2024.
//

#ifndef PRACTIC_DOMAIN_H
#define PRACTIC_DOMAIN_H
#include <cstring>
#include <string>
#include <utility>
using namespace std;
class Log{
private:
    string id;
    string content;
    int pid;
    string level;
public:
    Log(string  id, string  content, const int& pid, string  level) : id {std::move(id)}, content{std::move(content)}, pid{pid}, level{std::move(level)}{

    }
    Log(const Log& l) = default;
    ~Log() = default;
    [[nodiscard]] string get_id() const;
    [[nodiscard]] string get_content()const;
    [[nodiscard]] int get_pid()const;
    [[nodiscard]] string get_level() const;
    int validateLog();
};

#endif //PRACTIC_DOMAIN_H
