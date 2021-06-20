#ifndef I_ASIGNACIONDOCENTEASIGNATURA
#define I_ASIGNACIONDOCENTEASIGNATURA

#include "../DataTypes/header/tipoRol.h"

#include <iostream>
#include <list>

class IAsignacionDocenteAsignatura
{
    public:
        virtual std::list<std::string> listarAsignaturas() = 0;

        virtual std::list<std::string> docentesSinLaAsignatura(std::string) = 0;

        virtual void selectDocente(std::string, tipoRol) = 0;

        virtual void asignarDocente() = 0;

        virtual void cancelar() = 0;

        virtual void cargarDatos() = 0;
};

#endif