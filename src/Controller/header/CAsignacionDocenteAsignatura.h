#ifndef C_ASIGNACIONDOCENTEASIGNATURA
#define C_ASIGNACIONDOCENTEASIGNATURA

#include <iostream>
#include <list>

#include "../../DataTypes/header/tipoRol.h"

class CAsignacionDocenteAsignatura
{
    private:
        std::string codigo;
        std::string email;
        tipoRol rol;

    public:
        CAsignacionDocenteAsignatura();
        ~CAsignacionDocenteAsignatura();

        std::list<std::string> listarAsignaturas();

        std::list<std::string> docentesSinLaAsignatura(std::string);

        void selectDocente(std::string, tipoRol);

        void asignarDocente();

        void cancelar();
};

#endif