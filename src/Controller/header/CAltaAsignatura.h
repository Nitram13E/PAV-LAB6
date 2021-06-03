#ifndef C_ALTAASIGNATURA
#define C_ALTAASIGNATURA

#include "../DataTypes/header/DtAsignatura.h"

class CAltaAsignatura
{
    private:
        DtAsignatura* datosAsignatura;

    public:
        CAltaAsignatura();
        ~CAltaAsignatura();
        
        DtAsignatura ingresar(DtAsignatura);
        void altaAsignatura();
        void cancelar();
};

#endif