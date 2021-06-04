#ifndef C_INSCRIPCIONASIGNATURAS
#define C_INSCRIPCIONASIGNATURAS

#include "../Interfaces/IInscripcionAsignaturas.h"

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

        std::list<std::string> asignaturasNoInscriptos(std::string);

        void selectAsignatura(std::string);

        void inscribir(std::string);

        void cancelar();
};

#endif