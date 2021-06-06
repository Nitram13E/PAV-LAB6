#include "header/CIniciarSesion.h"
#include "../Handlers/header/ManejadorPerfil.h"
#include <list>
#include "../Class/header/Perfil.h"
#include "../Class/header/Sesion.h"
#include "../Class/header/Estudiante.h"
#include "../Class/header/Docente.h"


CIniciarSesion::CIniciarSesion(){}
void CIniciarSesion::ingresarEmail(std::string email){
    this->email = email;
}
bool CIniciarSesion::validarContrasenia(std::string password){
    ManejadorPerfil* mp = ManejadorPerfil::getInstancia();
    std::list<Perfil*> list = mp->listarPerfiles();
    std::list<Perfil*>::iterator it = list.begin();
    while((it != list.end()) && ((*it)->getPassword() != password)){
        it++; //Puede tirar error porque it es en list.begin() y no hago ++it antes de empezar el while
    }
    if(it == list.end()){
        return false;
    }else{

        return true;
    }
}
void CIniciarSesion::inciarSesion(){
    ManejadorPerfil* mp = ManejadorPerfil::getInstancia();
    Sesion* session = Sesion::getInstancia();
    std::list<Perfil*> list = mp->listarPerfiles();
    std::list<Perfil*>::iterator it = list.begin();
    while((it != list.end()) && (this->email != (*it)->getEmail())){
        it++;
    };
    if(it != list.end()){
        Estudiante * e = dynamic_cast<Estudiante*>(*it);
        if(e != NULL){
            session->setPerfil((*it),ESTUDIANTE);
        }else{
            Docente *d = dynamic_cast<Docente*>(*it);
            if(d != NULL){
            session->setPerfil((*it),DOCENTE);
            }
        }
    }
    //Poner un else de if(it!=list.end()){}else{cout << "No se pudo Iniciar sesion" << endl}  ???
}
CIniciarSesion::~CIniciarSesion(){}
