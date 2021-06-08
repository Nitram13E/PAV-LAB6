#ifndef C_INSCRIPCIONASIGNATURAS
#define C_INSCRIPCIONASIGNATURAS

#include "../../Interfaces/IInscripcionAsignaturas.h"
#include "../../Class/header/Sesion.h"

#include <iostream>
#include <list>
#include <iterator>

class CInscripcionAsignaturas : public IInscripcionesAsignaturas
{
    private:
        std::string codigo;

    public:
        CInscripcionAsignaturas();
        ~CInscripcionAsignaturas();

        std::list<std::string> asignaturasNoInscriptos();

        void selectAsignatura(std::string);

        void inscribir();

        void cancelar();
};

#endif