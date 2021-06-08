#ifndef IALTAUSUARIO
#define IALTAUSUARIO

#include "../DataTypes/header/DtPerfil.h"
#include "../DataTypes/header/tipoPerfil.h"

class IAltaUsuario
{
    public:
        virtual void ingresarDatosPerfil(DtPerfil) = 0;
        virtual void ingresarEstudiante(std::string) = 0;
        virtual void ingresarDocente(std::string) = 0;
        virtual void altaUsuario() = 0;
        virtual void setTipoPerfil(tipoPerfil) = 0;
        virtual void cancelar() = 0;
};

#endif