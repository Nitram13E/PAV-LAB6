#ifndef C_ASIGNACIONDOCENTEASIGNATURA
#define C_ASIGNACIONDOCENTEASIGNATURA

#include "../../Interfaces/IAsignacionDocenteAsignatura.h"
#include "../../Handlers/header/ManejadorAsignatura.h"

class CAsignacionDocenteAsignatura : public IAsignacionDocenteAsignatura
{
    private:
        std::string codigo;
        std::string email;
        tipoRol rol;
        
        bool controlRol(DtInstanciaClase*); //Controla si el docente a asignar corresponde con el tipo de clase.

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