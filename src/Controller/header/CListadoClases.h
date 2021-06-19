#ifndef C_LISTADOCLASES
#define C_LISTADOCLASES

#include "../../Interfaces/IListadoClase.h"

#include <list>

class CListadoClases : public IListadoClases
{
    public:
        CListadoClases();
        ~CListadoClases();

        std::list<std::string> asignaturasAsignadas();
        std::list<DtInfoClase*> selectAsignatura(std::string);
        
};

#endif