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

void CAltaUsuario::cargarDatos()
{
    ingresarDatosPerfil(DtPerfil("EST1", "IMG1", "mail-e1", "123abc"), ESTUDIANTE);
    ingresarEstudiante("342342");
    altaUsuario();

    ingresarDatosPerfil(DtPerfil("EST2", "IMG2", "mail-e2", "123abc"), ESTUDIANTE);
    ingresarEstudiante("3878424");
    altaUsuario();

    ingresarDatosPerfil(DtPerfil("EST3", "IMG3", "mail-e3", "123abc"), ESTUDIANTE);
    ingresarEstudiante("6565624");
    altaUsuario(); 

    ingresarDatosPerfil(DtPerfil("EST4", "IMG4", "mail-e4", "123abc"), ESTUDIANTE);
    ingresarEstudiante("342342");
    altaUsuario();

    ingresarDatosPerfil(DtPerfil("EST5", "IMG5", "mail-e5", "123abc"), ESTUDIANTE);
    ingresarEstudiante("3878424");
    altaUsuario();

    ingresarDatosPerfil(DtPerfil("EST6", "IMG6", "mail-e6", "123abc"), ESTUDIANTE);
    ingresarEstudiante("6565624");
    altaUsuario();


    ingresarDatosPerfil(DtPerfil("DOC1", "IMG1", "mail-d1", "123abc"), DOCENTE);
    ingresarDocente("ins1");
    altaUsuario();

    ingresarDatosPerfil(DtPerfil("DOC2", "IMG2", "mail-d2", "123abc"), DOCENTE);
    ingresarDocente("ins2");
    altaUsuario();

    ingresarDatosPerfil(DtPerfil("DOC3", "IMG3", "mail-d3", "123abc"), DOCENTE);
    ingresarDocente("ins1");
    altaUsuario();

    ingresarDatosPerfil(DtPerfil("DOC4", "IMG4", "mail-d4", "123abc"), DOCENTE);
    ingresarDocente("ins2");
    altaUsuario();
}