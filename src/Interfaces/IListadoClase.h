#ifndef I_LISTADOCLASE
#define I_LISTADOCLASE

#include "../DataTypes/header/DtInfoClase.h"

class IListadoClases
{
    public:
        virtual std::list<std::string> asignaturasAsignadas() = 0;
        virtual std::list<DtInfoClase*> selectAsignatura(std::string) = 0;
};

#endif