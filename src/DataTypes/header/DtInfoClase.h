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
        virtual ~DtInfoClase();

        int getId();
        std::string getNombre();
        std::list<std::string> getDocentes();

        friend std::ostream& operator << (std::ostream&, const DtInfoClase&);
};

#endif