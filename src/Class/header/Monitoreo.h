#ifndef MONITOREO_H
#define MONITOREO_H

#include "Clase.h"
#include "Estudiante.h"

#include <list>

class Monitoreo: public Clase
{
    private:
        std::list<Estudiante*> habilitados;
    public:
        Monitoreo();
        Monitoreo(std::string, DtTimeStamp, DtTimeStamp*, std::string, std::list<Estudiante*>);
        ~Monitoreo();

        std::list<Estudiante*> getHabilitados();

        DtInfoClase* getDtInfoClase();
};

#endif