#include <iostream>
#include <vector>
#include "expresie.h"
#include "cos.h"
#include "ex3participant.h"
using namespace std;

void operatii()
{
    Expresie<int> exp{3};
    exp = exp + 7 + 3;
    exp = exp - 8;
    cout << exp.valoare() << '\n';
    exp.undo();
    cout << exp.valoare() << '\n';
    exp.undo().undo();
    cout<< exp.valoare() << '\n';
}

void cumparaturi()
{
    Cos<string> cos;
    cos = cos + "Mere";
    cos.undo();
    cos + "Mere";
    cos = cos + "Paine" + "Lapte";
    cos.undo().undo();
    cos.tipareste(cout);
}

ONG functie()
{
    ONG o;
    o.add(new Administrator{"George"});
    o.add(new Angajat{new Administrator{"Ion"}});
    o.add(new Director{"Vasile"});
    o.add(new Angajat{new Director{"Mihai"}});
    return o;
}

int main()
{
    //operatii();
    //cumparaturi();
    ONG o = functie();
    vector<Participant*> voluntari = o.getAll(true);
    vector<Participant*> angajati = o.getAll(false);
    for(auto el : voluntari)
    {
        el->tipareste();
        cout<<endl;
        delete el;
    }
    for(auto el : angajati) {
        el->tipareste();
        cout << endl;
        delete el;
    }
    return 0;
}