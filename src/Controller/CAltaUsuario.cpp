#include "CAltaUsuario.h"
#include "ManejadorPerfil.cpp"
#include "../../Class/header/Estudiante.h"
#include "../../Class/header/Docente.h"

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
        Estudiante* e = new Estudiante(this->datosUsuario.getNombre(), this -> datosUsuario.getImagenURL(), this -> datosUsuario.getEmail(), this -> datosUsuario.getPassword(), this -> cedula);
        mp->addPerfil(e);

    } else if (this->tipo_perfil==DOCENTE)
    {
        Docente* d = new Docente(this -> datosUsuario.getNombre(), this -> datosUsuario.getImagenURL(), this -> datosUsuario.getEmail(), this -> datosUsuario.getPassword(), this -> instituto);
        mp->addPerfil(d);
    }
    
}

void CAltaUsuario::setTipoPerfil(tipoPerfil perfil)
{
    this -> tipo_perfil = perfil;
    
}

void cancelar() {}

/*void CAltaUsuario::cargarDatos(){
    //estudiantes
    //Estudiante* e = new Estudiante("Don Pepito", "IMG", "donpepito@gmail.com","edqw3r4q23","2352523");
    DtPerfil aux = DtPerfil("Don Pepito", "IMG", "donpepito@gmail.com","edqw3r4q23");

    ingresarDatosPerfil(aux);
    //docentes
    ingresarDatosPerfil("Dross Rotzank", "sobreroDeCuero", "vlogsdedross@gmail.com","3w52345rrw","Youtube");
    ingresarDatosPerfil("Bill Gates", "Microsoft", "billgate@hotmail.com", "wewewe323", "Harvard");
}*/