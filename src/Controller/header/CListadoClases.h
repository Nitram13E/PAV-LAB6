#ifndef C_LISTADOCLASES
#define C_LISTADOCLASES

#include "../DataTypes/header/DtInfoClase.h"

#include <list>

class CListadoClases
{
    private:
        
    public:
        CListadoClases();
        ~CListadoClases();

        std::list<std::string> asignaturasAsignadas();
        std::list<DtInfoClase> selectAsignatura(std::string);
};

#endif