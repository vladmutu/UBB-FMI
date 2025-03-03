//
// Created by vladm on 6/21/2024.
//

#ifndef MELODIIQT_DOMAIN_H
#define MELODIIQT_DOMAIN_H
#include <string>
#include <utility>

using namespace std;

class MelodieException : public std::exception{
private:
    string msg;
public:
    explicit MelodieException(string msg) : msg{std::move(msg)}{

    }
    string get_msg(){
        return msg;
    }
};

class Melodie{
private:
    int id;
    string titlu;
    string artist;
    int rank;
public:
    Melodie(int i, string t, string a, int r) : id{i}, titlu{std::move(t)}, artist{std::move(a)}, rank{r} {

    }
    Melodie() = default;
    Melodie(const Melodie& ot)
    {
        id = ot.id;
        titlu = ot.titlu;
        artist = ot.artist;
        rank = ot.rank;
    }

    Melodie& operator=(const Melodie& ot)
    {
        this->id = ot.id;
        this->titlu = ot.titlu;
        this->artist = ot.artist;
        this->rank = ot.rank;
        return *this;
    }

    ~Melodie() = default;
public:
    [[nodiscard]] int get_id() const;
    [[nodiscard]] string get_titlu() const;
    [[nodiscard]] string get_artist() const;
    [[nodiscard]] int get_rank() const;
    int validate();

};

#endif //MELODIIQT_DOMAIN_H
