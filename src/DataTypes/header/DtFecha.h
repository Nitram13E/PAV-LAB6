#ifndef DTFECHA
#define DTFECHA

#include <iostream>

class DtFecha
{
    private:
        int dia;
        int mes;
        int anio;

    public:

        DtFecha();
        DtFecha(int, int, int);

        int getDia();

        int getMes();

        int getAnio();

        ~DtFecha();

        bool checkFecha(int dia, int mes, int anio);
        
        friend std::ostream& operator << (std::ostream&, const DtFecha);

        friend bool operator == (DtFecha, DtFecha);
        
        friend bool operator < (DtFecha, DtFecha);
        
};

#endif