#include <iostream>
#include <vector>
#include <exception>
#include <cassert>
#include <cstring>
#include "Catalog.h"
using namespace std;

class A{
private:
    int x;
public:
    A(int x) : x{x} {

    }
    void print(){
        cout << x << '\n';
    }
};

A f(A a)
{
    a.print();
    a = A{7};
    a.print();
    return a;
}



vector<int> f(int a)
{
    if(a < 0) {
        throw exception();
    }
    vector<int>rez;
    for(int i=1; i<=a; i++)
        if(a%i == 0)
            rez.push_back(i);
    return rez;
}
void function() {
    MultiDictionary<int, std::string> d1;
    d1.add(1, "a").add(2, "b").add(1, "c").add(3, "d");
    d1.print(std::cout); // prints 1 a c; 2 b; 3 d
    try {
        d1.erase(4, "w"); assert(false);
    }
    catch (std::runtime_error& e) {
        try {
            assert(strcmp(e.what(), "Key does not exist!") == 0);
            d1.erase(2, "w"); assert(false);
        }
        catch (std::runtime_error& e) {
            assert(strcmp(e.what(), "Given value does not exist for given key") == 0);
        }
    }

    d1.erase(1, "a"); d1.print(std::cout); // prints 1 c; 2 b; 3 d
    MultiDictionary<std::string, Person> d2;
    d2.add("p1", Person(23, "Mircea"));
    Person p2(20, "Ioana");
    d2.add("p1", p2);
    std::cout << d2.sizeForKey("p1") << " "; // prints 2
    d2.add("p2", Person(20, "Ioana"));
    d2.print(std::cout); // prints p1 Mircea is 23 years old Ioana is 20 years old p2 Ioana is 20 years old
    assert(d2.sizeForKey("p1") == 2);
    assert(d2.sizeForKey("b") == 0);
}
int main()
{
    /*try{
        f(-1);
    }
    catch (exception& e){
        cout << "Exception caught\n";
    }
    vector<int>rezz = f(0);
    assert(rezz.empty());
    vector<int>rez = f(6);
    assert(rez.size() == 4);
    assert(rez[0] == 1);
    assert(rez[1] == 2);
    assert(rez[2] == 3);
    assert(rez[3] == 6);
    A a{5};
    a.print();
    f(a);
//    a.print();*/
//    Catalog<int> cat{"OOP"};
//    cat+10;
//    cat = cat+8+6;
//    int sum = 0;
//    for(auto n :cat){
//        sum+=n;
//    }
//    cout<<"Suma note:"<<sum<<'\n';
    function();
    return 0;
}

