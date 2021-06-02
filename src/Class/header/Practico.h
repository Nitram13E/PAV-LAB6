#ifndef PRACTICO
#define PRACTICO

#include "Clase.h"

class Practico: public Clase
{
    public:
        Practico();
        Practico(std::string, DtTimeStamp, DtTimeStamp, std::string);
        ~Practico();
};

#endif