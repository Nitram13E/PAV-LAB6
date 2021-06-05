#ifndef I_ALTAASIGNATURA
#define I_ALTAASIGNATURA

#include "../DataTypes/header/DtAsignatura.h"
#include "../DataTypes/header/DtInstanciaClase.h"

class IAltaAsignatura
{
    public:
        virtual DtAsignatura* ingresar(std::string, std::string, DtInstanciaClase) = 0;
        virtual void altaAsignatura() = 0;
        virtual void cancelar() = 0;
};

#endif