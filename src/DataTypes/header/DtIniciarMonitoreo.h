#ifndef DTINICIARMONITOREO
#define DTINICIARMONITOREO

#define MAX_HABILITADOS 15

#include "DtIniciarClaseFull.h"

class DtIniciarMonitoreo : public DtIniciarClaseFull
{
    private:
        std::string habilitados[MAX_HABILITADOS];

    public:
        DtIniciarMonitoreo();
        DtIniciarMonitoreo(std::string codigo, std::string nombre, DtTimeStamp fechahora, std::string*);
        ~DtIniciarMonitoreo();

        std::string * getHabilitados();
    
};

#endif