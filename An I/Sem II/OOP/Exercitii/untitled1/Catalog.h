//
// Created by vladm on 6/20/2024.
//

#ifndef UNTITLED1_CATALOG_H
#define UNTITLED1_CATALOG_H
#include <string>
#include <vector>
using namespace std;
template<typename TElem>

class Catalog{
private:
    string denumire;
    vector<TElem> note;
public:
    Catalog(string denumire) : denumire{denumire} {

    }
    Catalog& operator+(TElem val)
    {
        note.push_back(val);
        return *this;
    }
    Catalog& operator=(Catalog& c)
    {
        this->note = c.note;
        return *this;
    }

    typename vector<TElem>::iterator begin(){
        return note.begin();
    }
    typename vector<TElem>::iterator end(){
        return note.end();
    }
};


template<typename TKey, typename TValue>
class MultiDictionary{
private:
    vector<pair<TKey, TValue>> elem;
public:
    MultiDictionary& add(TKey key, TValue value){
        elem.push_back(make_pair(key, value));
        return *this;
    }
    void print(ostream& out){
        for(auto pair: elem)
            out<<pair.first<< " "<<pair.second<<'\n';
    }
    void erase(TKey key, TValue value)
    {
        int i = 0;
        for(auto pair=elem.begin(); pair !=  elem.end(); pair++ )
            if(*pair->first == key && *pair->second == value)
                this->elem.erase(pair), i = 2;
            else if(*pair.first == key)
                i = 1;
        if(i == 0)
            throw runtime_error("Key does not exist");
        if(i == 1)
            throw runtime_error("Given value does not exist for given key");
    }
    TValue& sizeForKey(TKey& key){
        TValue c = 0;
        for(auto pair: elem)
            if(pair.first == key)
                c++;
        return c;
    }
};

template<typename TElem>
class Person{
private:
    pair<TElem, TElem> atributes;
public:
    Person() = default;
    Person(TElem age, TElem name) : atributes{make_pair(age, name)}{

    }
    friend ostream& operator<<(ostream& out, Person& p){
        out<<p.age<< " "<<p.name<<'\n';
        return out;
    }
};
#endif //UNTITLED1_CATALOG_H

