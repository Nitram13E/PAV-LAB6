#include "header/Sesion.h"
Sesion* Sesion::instancia = NULL;
Sesion::Sesion(){}
Sesion* Sesion::getInstancia(){
    if(instancia == NULL){
        instancia = new Sesion();
    }
    return instancia;
}
void Sesion::setPerfil(Perfil* perfil,tipoPerfil tp){
    this->p = perfil;
    this->tipoDePerfil = tp;
}
Perfil* Sesion::getPerfil(){return this->p;}
tipoPerfil Sesion::getTipoPerfil(){return this->tipoDePerfil;}
<<<<<<< HEAD
Sesion::~Sesion(){}
=======
Sesion::~Sesion(){}
>>>>>>> e599c3b0f9ea9de4626693d4117509ee8ec5b6db
