#ifndef MONITOREO
#define MONITOREO 

#include "Clase.h"
#include "Estudiante.h"

#include <list>

class Monitoreo: public Clase
{
    private:
        std::list<Estudiante*> habilitados;
    public:
        Monitoreo();
        Monitoreo(std::string, DtTimeStamp, DtTimeStamp, std::string);
        ~Monitoreo();

        std::list<Estudiante*> getHabilitados();
};

#endif