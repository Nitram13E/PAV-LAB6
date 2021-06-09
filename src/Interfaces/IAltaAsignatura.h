#ifndef I_ALTAASIGNATURA
#define I_ALTAASIGNATURA

#include "../DataTypes/header/DtAsignatura.h"
#include "../DataTypes/header/DtInstanciaClase.h"

class IAltaAsignatura
{
    public:
        virtual DtAsignatura* ingresar(DtAsignatura* datosAsignatura) = 0;
        virtual void altaAsignatura() = 0;
        virtual void cancelar() = 0;
};

#endif