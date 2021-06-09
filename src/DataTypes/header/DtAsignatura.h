#ifndef DTASIGNATURA
#define DTASIGNATURA

#include <iostream>
#include "DtInstanciaClase.h"

class DtAsignatura
{
    private:
        std::string codigo;
        std::string nombre;
        DtInstanciaClase* tipoClases;

    public:
        DtAsignatura();
        DtAsignatura(std::string, std::string, DtInstanciaClase*);
        ~DtAsignatura();
        std::string getCodigo();
        std::string getNombre();
        DtInstanciaClase* getTipoClases();
};

#endif