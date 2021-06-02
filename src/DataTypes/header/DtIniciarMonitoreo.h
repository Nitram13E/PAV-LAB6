#ifndef DTINICIARMONITOREO
#define DTINICIARMONITOREO

#include "DtIniciarClaseFull.h"

#include <list>

class DtIniciarMonitoreo : public DtIniciarClaseFull
{
    private:
        std::list<std::string> habilitados;

    public:
        DtIniciarMonitoreo();
        DtIniciarMonitoreo(int id, std::string codigo, std::string nombre, DtTimeStamp fechahora, std::list<std::string>);
        ~DtIniciarMonitoreo();

        std::list<std::string> getHabilitados();
    
};

#endif