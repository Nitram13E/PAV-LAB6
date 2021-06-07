#ifndef DTINICIARCLASEFULL
#define DTINICIARCLASEFULL

#include "DtIniciarClase.h"

class DtIniciarClaseFull : public DtIniciarClase
{
    private:
        int id;

    public:
        DtIniciarClaseFull();
        DtIniciarClaseFull(int, std::string codigo, std::string nombre, DtTimeStamp fechahora);
        ~DtIniciarClaseFull();

        int getId();
};

#endif