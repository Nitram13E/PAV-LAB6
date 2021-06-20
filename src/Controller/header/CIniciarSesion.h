#ifndef CINICIARSESION_H
#define CINICIARSESION_H

#include "../../Interfaces/IiniciarSesion.h"

#include "../../Class/header/Sesion.h"
#include "../../Handlers/header/ManejadorPerfil.h"
#include "../../Class/header/Estudiante.h"
#include "../../Class/header/Docente.h"

class CIniciarSesion : public IiniciarSesion
{
    private:
        std::string email;

    public:
        CIniciarSesion();
        ~CIniciarSesion();
        void ingresarEmail(std::string email);
        bool validarContrasenia(std::string password);
        void iniciarSesion();
        
};

#endif
