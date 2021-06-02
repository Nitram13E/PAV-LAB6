#ifndef DTINFOCLASE
#define DTINFOCLASE

#include <iostream>

#include <list>
#include <iterator>

class DtInfoClase
{
    private:
        
        int id;
        std::string nombre;
        std::list<std::string> docentes;

    public:
        DtInfoClase();
        DtInfoClase(int, std::string, std::list<std::string>);
        ~DtInfoClase();

        int getId();

        std::string getNombre();

        std::list<std::string> getDocentes();
};

#endif