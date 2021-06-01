#ifndef INICIARCLASE
#define INICIARCLASE

#include "DtTimeStamp.h"

class DtIniciarClase
{
    private:
        std::string codigo;
        std::string nombre;
        DtTimeStamp fechaHora;

    public:
        DtIniciarClase();
        DtIniciarClase(std::string, std::string, DtTimeStamp);
        ~DtIniciarClase();

        std::string getCodigo();

        std::string getNombre();

        DtTimeStamp getFechaHora();
};

#endif