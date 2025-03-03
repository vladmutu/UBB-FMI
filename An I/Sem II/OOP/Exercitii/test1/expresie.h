//
// Created by vladm on 6/19/2024.
//

#ifndef TEST1_EXPRESIE_H
#define TEST1_EXPRESIE_H
#include <vector>
template<typename TElem>

class Expresie {
private:
    std::vector<std::pair<TElem,int>> operatii;
public:
    Expresie(TElem elem) {
        operatii.push_back(std::make_pair(elem, 1));
    }

    Expresie& operator+(const TElem& elem)
    {
        operatii.push_back(std::make_pair(elem, 1));
        return *this;
    }

    Expresie& operator-(const TElem& elem)
    {
        operatii.push_back(std::make_pair(elem, -1));
        return *this;
    }

    TElem valoare()
    {
        TElem rez = 0;
        for(const auto& el : operatii)
            rez += el.first*el.second;
        return rez;
    }

    Expresie& undo()
    {
        if(!operatii.empty())
            operatii.pop_back();
        return *this;
    }
};

#endif //TEST1_EXPRESIE_H
