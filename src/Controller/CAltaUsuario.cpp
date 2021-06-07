#include "CAltaUsuario.h"
#include "ManejadorPerfil.cpp"

CAltaUsuario::CAltaUsuario(){}
CAltaUsuario::~CAltaUsuario(){}

void CAltaUsuario::ingresarDatosPerfil(DtPerfil perfil)
{
    this -> datosUsuario = perfil;
}

void CAltaUsuario::ingresarEstudiante(std::string ci)
{
    this -> cedula = ci;
}

void CAltaUsuario::ingresarDocente(std::string ins)
{
    this -> instituto = ins;
}


void CAltaUsuario::altaUsuario()
{
    ManejadorPerfil* mp = ManejadorPerfil::getInstancia();
    

    if (this->tipo_perfil==ESTUDIANTE)
    {
        Estudiante* e = new Estudiante(this -> datosUsuarios -> getNombre(), this -> datosUsuarios ->  getImagenURL(), this -> datosUsuarios -> getEmail(), this -> datosUsuarios -> getPassword(), this -> documento);
        mp->addPerfil(e);

    } else if (this->tipo_perfil==DOCENTE)
    {
        Docente* d = new Docente(this -> datosUsuarios -> getNombre(), this -> datosUsuarios ->  getImagenURL(), this -> datosUsuarios -> getEmail(), this -> datosUsuarios -> getPassword(), this -> instituto);
        mp->addPerfil(d);
    }
    
}

void setTipoPerfil(tipoPerfil perfil)
{
    this -> tipo_perfil = perfil;
    
}

void cancelar() {}