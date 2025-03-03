#include "Tabla.h"
#include <string>

class Joc : public Tabla{
private:
    int id;
    Tabla tabla;
    char jucator; //X/O
    int stare; //1 = neinceput  2 = in derulare 3 = terminat
public:
    [[nodiscard]] int get_id() const;
    [[nodiscard]] char get_jucator() const;
    [[nodiscard]] int get_stare() const;
    [[nodiscard]] std::string get_pozitii() const;
    Joc(int id, int dim, std::string pozitii, char jucator, int stare) : id{id}, jucator{jucator}, stare{stare} {
        this->tabla = Tabla(dim, std::move(pozitii));
    };
    Joc& operator=(const Joc& joc) = default;
    Joc(const Joc& j) : id{j.id}, jucator{j.jucator}, stare{j.stare} {
        this->tabla = Tabla(j.tabla.get_dim(), j.tabla.get_pozitii());
    };

    [[nodiscard]] int validator() const;

    ~Joc() = default;
};