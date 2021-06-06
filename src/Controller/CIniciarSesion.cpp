#include "header/CIniciarSesion.h"

CIniciarSesion::CIniciarSesion(){}

CIniciarSesion::~CIniciarSesion(){}

void CIniciarSesion::ingresarEmail(std::string email)
{
    this->email = email;
}

bool CIniciarSesion::validarContrasenia(std::string password)
{
    ManejadorPerfil* mp = ManejadorPerfil::getInstancia();
    
    Perfil* p = mp->buscarPerfil(this->email);
    
    if(p->getPassword() == password) return true;
    
    return false;
}

void CIniciarSesion::inciarSesion()
{
    ManejadorPerfil* mp = ManejadorPerfil::getInstancia();
    
    Sesion* session = Sesion::getInstancia();

    Perfil* p = mp->buscarPerfil(this->email);

    if(p != NULL){
        Estudiante * e = dynamic_cast<Estudiante*>(p);
        if(e != NULL){
            session->setPerfil((p),ESTUDIANTE);
        }else{
            Docente *d = dynamic_cast<Docente*>(p);
            if(d != NULL){
            session->setPerfil((p),DOCENTE);
            }
        }
    }
}

