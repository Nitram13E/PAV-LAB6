#include "header/CIniciarSesion.h"
#include "../Handlers/header/ManejadorPerfil.h"
#include "../Class/header/Perfil.h"
#include "../Class/header/Sesion.h"
#include "../Class/header/Estudiante.h"
#include "../Class/header/Docente.h"

#include <list>

CIniciarSesion::CIniciarSesion(){}

void CIniciarSesion::ingresarEmail(std::string email)
{
    this -> email = email;
}

bool CIniciarSesion::validarContrasenia(std::string password)
{
    ManejadorPerfil* mp = ManejadorPerfil::getInstancia();
    
    Perfil* p = mp -> buscarPerfil(this -> email);
    
    if(p != NULL && p -> getPassword() == password) return true;
    
    return false;
}

void CIniciarSesion::inciarSesion()
{
    ManejadorPerfil* mp = ManejadorPerfil::getInstancia();
    
    Sesion* session = Sesion::getInstancia();

    Perfil* p = mp -> buscarPerfil(this -> email);

    if(p != NULL)
    {
        Estudiante * e = dynamic_cast<Estudiante*>(p);
        if(e != NULL)
        {
            session -> setPerfil((p),ESTUDIANTE);
        }
        else
        {
            Docente *d = dynamic_cast<Docente*>(p);

            if(d != NULL)
            {
                session -> setPerfil((p),DOCENTE);
            }
        }
    }
}

CIniciarSesion::~CIniciarSesion(){}
