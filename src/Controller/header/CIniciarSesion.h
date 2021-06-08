<<<<<<< HEAD
#ifndef CINICIARSESION_H
#define CINICIARSESION_H
#include "../../Handlers/header/ManejadorPerfil.h"
#include <list>
#include "../../Class/header/Perfil.h"
#include "../../Class/header/Sesion.h"
#include "../../Class/header/Estudiante.h"
#include "../../Class/header/Docente.h"
#include <string>
#include "../../DataTypes/header/tipoPerfil.h"
class CIniciarSesion{
    private:
        std::string email;
    public:
        CIniciarSesion();
        void ingresarEmail(std::string email);
        bool validarContrasenia(std::string password);
        void inciarSesion();
        ~CIniciarSesion();
};

#endif
=======
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
        void inciarSesion();
        
};

#endif
>>>>>>> ac28f01d4db01cceb35c7643caae7107476c218b
