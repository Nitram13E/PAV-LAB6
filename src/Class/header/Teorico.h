#ifndef TEORICO_H
#define TEORICO_H

#include "Clase.h"

class Teorico : public Clase
{
    private:
        int cantAsistentes;
        
    public:
        Teorico();
        Teorico(std::string, DtTimeStamp, DtTimeStamp*, std::string);
        ~Teorico();

        void calcularAsistentes();
        
        DtInfoClase* getDtInfoClase();
};

#endif