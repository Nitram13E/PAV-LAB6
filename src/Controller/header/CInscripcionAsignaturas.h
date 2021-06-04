#ifndef C_INSCRIPCIONASIGNATURAS
#define C_INSCRIPCIONASIGNATURAS

#include <iostream>
#include <list>

class CInscripcionAsignaturas
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