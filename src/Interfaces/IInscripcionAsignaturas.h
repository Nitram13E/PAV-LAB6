#ifndef IINSCRIPCIONASIGNATURAS
#define IINSCRIPCIONASIGNATURAS

#include <iostream>
#include <list>

class IInscripcionesAsignaturas
{
    public:
        virtual std::list<std::string> asignaturasNoInscriptos(std::string) = 0;
        virtual void selectAsignatura(std::string) = 0;
        virtual void inscribir(std::string) = 0;
        virtual void cancelar() = 0;
};

#endif