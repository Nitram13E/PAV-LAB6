#ifndef DTINFOMONITOREO
#define DTINFOMONITOREO

#include "DtInfoClase.h"

class DtInfoMonitoreo : public DtInfoClase
{
    private:
        std::list<std::string> estudiantes;

    public:
        DtInfoMonitoreo();
        DtInfoMonitoreo(int, std::string, std::list<std::string>, std::list<std::string>);
        ~DtInfoMonitoreo();

        std::list<std::string> getEstudiantes();
};

#endif