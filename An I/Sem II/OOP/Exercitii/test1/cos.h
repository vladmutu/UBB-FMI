//
// Created by vladm on 6/19/2024.
//

#ifndef TEST1_COS_H
#define TEST1_COS_H

#include <string>
#include <vector>
using namespace std;

template<typename TElem>

class Cos{
private:
    vector<TElem> elemente;
public:
    Cos() = default;
    Cos& operator+(const TElem& elem)
    {
        elemente.push_back(elem);
        return *this;
    }

    Cos& undo()
    {
        if(!elemente.empty())
            elemente.pop_back();
        return *this;
    }

    Cos& operator=(const Cos& c)
    {
        this->elemente = c.elemente;
        return *this;
    }

    void tipareste(ostream& out)
    {
        for(const auto& el : this->elemente)
            out << el << ' ';
    }
};

#endif //TEST1_COS_H
