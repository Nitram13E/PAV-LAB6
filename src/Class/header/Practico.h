#ifndef PRACTICO_H
#define PRACTICO_H

#include "Clase.h"

class Practico: public Clase
{
    public:
        Practico();
        Practico(std::string, DtTimeStamp, DtTimeStamp*, std::string);
        ~Practico();
        DtInfoClase getDtInfoClase();
};

#endif