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
