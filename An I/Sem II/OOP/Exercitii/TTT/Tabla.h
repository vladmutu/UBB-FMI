#include <string>

class Tabla {
private:
    int dim;
    std::string pozitii;
public:
    Tabla(int dim, std::string pozitii) : dim{dim}, pozitii{std::move(pozitii)} {

    }
    Tabla() = default;
    Tabla& operator=(const Tabla& tabla) = default;
    Tabla(const Tabla& t) : dim{t.dim}, pozitii{t.pozitii} {

    }
    [[nodiscard]] int get_dim() const {
        return dim;
    }
    [[nodiscard]] std::string get_pozitii() const{
        return pozitii;
    }
};