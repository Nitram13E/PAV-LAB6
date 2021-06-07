#ifndef C_ALTAASIGNATURA
#define C_ALTAASIGNATURA

#include "../../Interfaces/IAltaAsignatura.h"

class CAltaAsignatura : public IAltaAsignatura
{
    private:
        DtAsignatura* datosAsignatura;

    public:
        CAltaAsignatura();
        ~CAltaAsignatura();
        
        DtAsignatura* ingresar(DtAsignatura*);
        void altaAsignatura();
        void cancelar();
};

#endif