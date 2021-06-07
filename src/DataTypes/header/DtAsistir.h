#ifndef DTASISTIR
#define DTASISTIR

#include <iostream>

class DtAsistir
{
    private:
        std::string codigo;
        int id;

    public:
        DtAsistir();
        DtAsistir(std::string, int);
        ~DtAsistir();

        std::string getCodigo();
        int getId();

        friend std::ostream& operator <<(std::ostream&, DtAsistir);
};

#endif