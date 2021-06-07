#ifndef I_INICIOCLASE
#define I_INICIOCLASE

#include "../DataTypes/header/DtIniciarClaseFull.h"

class IinicioClase
{
    public:
        virtual std::list<std::string> asignaturasAsignadas() = 0;
        virtual bool selectAsignatura(DtIniciarClase) = 0 ;
        virtual std::list<std::string> inscriptosAsignatura() = 0;
        virtual void habilitar(std::string) = 0;
        virtual DtIniciarClaseFull* datosIngresados() = 0;

        virtual void iniciarClase() = 0;
        virtual void cancelar() = 0;
};

#endif