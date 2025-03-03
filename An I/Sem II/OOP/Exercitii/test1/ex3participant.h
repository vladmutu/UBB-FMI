#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Participant{
protected:
    bool voluntar = true;
public:
    virtual void tipareste() = 0;
    bool eVoluntar()
    {
        return this->voluntar;
    }
    virtual ~Participant() = default;
};

class Personal : public Participant{
private:
    string nume;
public:
    explicit Personal(string nume) : nume{std::move(nume)}{

    }
    void tipareste()
    {
        cout << nume << " ";
    }
    virtual ~Personal() = default;
};

class Administrator : public Personal{
public:
    Administrator(string n) : Personal(n) {

    }
    void tipareste() override{
        Personal::tipareste();
        cout << "Administrator" << " ";
    }
    ~Administrator() = default;
};

class Director : public Personal{
public:
    Director(string n) : Personal(n) {

    }

    void tipareste() override{
        Personal::tipareste();
        cout << "Director" << " ";
    }
    ~Director() = default;
};

class Angajat : public Participant{
private:
    Participant* p;
public:
    Angajat(Participant* pp) : p{pp}{
        voluntar = false;
    }

    bool eVoluntar(){
        return voluntar;
    }

    void tipareste() override{
        p->tipareste();
        cout << "Angajat" << " ";
    }

    ~Angajat(){
        delete p;
    }
};

class ONG{
private:
    vector<Participant*>participanti;
public:
    ONG() = default;
    void add(Participant* p){
        participanti.push_back(p);
    }
    vector<Participant*> getAll(bool Voluntari)
    {
        vector<Participant*> rez;
        for(const auto p : participanti)
            if(p->eVoluntar() == Voluntari)
                rez.push_back(p);
        return rez;
    }
};
