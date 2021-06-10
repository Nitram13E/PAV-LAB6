#include "header/CAltaUsuario.h"
#include "../Handlers/header/ManejadorPerfil.h"
#include "../Class/header/Docente.h"
#include "../Class/header/Estudiante.h"

CAltaUsuario::CAltaUsuario(){}
CAltaUsuario::~CAltaUsuario(){}

void CAltaUsuario::ingresarDatosPerfil(DtPerfil perfil, tipoPerfil tipo)
{
    this -> datosUsuario = perfil;
    this -> tipo_perfil = tipo;
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

    if(this -> tipo_perfil == ESTUDIANTE)
    {
        Estudiante* e = new Estudiante(this -> datosUsuario.getNombre(), this -> datosUsuario.getImagenURL(), this -> datosUsuario.getEmail(), this -> datosUsuario.getPassword(), this -> cedula);
        mp -> addPerfil(e);
    }
    else if(this -> tipo_perfil == DOCENTE)
    {
        Docente* d = new Docente(this -> datosUsuario.getNombre(), this -> datosUsuario.getImagenURL(), this -> datosUsuario.getEmail(), this -> datosUsuario.getPassword(), this -> instituto);
        mp -> addPerfil(d);
    }
}

void CAltaUsuario::cancelar(){}