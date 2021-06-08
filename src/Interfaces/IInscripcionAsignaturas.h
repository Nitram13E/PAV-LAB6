#ifndef IINSCRIPCIONASIGNATURAS
#define IINSCRIPCIONASIGNATURAS

#include <iostream>
#include <list>
class IInscripcionesAsignaturas
{
    public:
        virtual std::list<std::string> asignaturasNoInscriptos() = 0;
        virtual void selectAsignatura(std::string) = 0;
        virtual void inscribir() = 0;
        virtual void cancelar() = 0;
};

#endif