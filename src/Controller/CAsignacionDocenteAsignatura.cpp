#include "header/CAsignacionDocenteAsignatura.h"
#include "../Handlers/header/ManejadorPerfil.h"

CAsignacionDocenteAsignatura::CAsignacionDocenteAsignatura(){}
CAsignacionDocenteAsignatura::~CAsignacionDocenteAsignatura(){}

bool CAsignacionDocenteAsignatura::controlRol(DtInstanciaClase* tipoClases)
{
    switch (this -> rol)
    {
        case TEORICO:
            if (tipoClases -> getTeorico()) return true;

        break;
        
        case PRACTICO:
            if (tipoClases -> getPractico()) return true;

        break;
        
        case MONITOREO:
            if (tipoClases -> getMonitoreo()) return true;

        break;
    }
    return false;
}

//Listar todas las asignaturas
std::list<std::string> CAsignacionDocenteAsignatura::listarAsignaturas()
{
    return ManejadorAsignatura::getInstancia() -> listarAsignatura();
}

std::list<std::string> CAsignacionDocenteAsignatura::docentesSinLaAsignatura(std::string codigo)
{
    this -> codigo = codigo;

    std::list<std::string> lista;
    std::list<Perfil*> perfiles = ManejadorPerfil::getInstancia() -> listarPerfiles();
    std::list<Perfil*>::iterator it;

    for(it = perfiles.begin(); it != perfiles.end(); it++)
    {
        Docente * doc = dynamic_cast<Docente*>((*it));
        
        if(doc != NULL && !doc -> dictaAsignatura(codigo))
        {
            lista.push_back((*it) -> getEmail());
        }
    }

    return lista;
}

void CAsignacionDocenteAsignatura::selectDocente(std::string email, tipoRol rol)
{
    this -> email = email;
    this -> rol = rol;
}

void CAsignacionDocenteAsignatura::asignarDocente()
{
    Perfil * p = ManejadorPerfil::getInstancia() -> buscarPerfil(this -> email);
    Docente * doc = dynamic_cast<Docente*>(p);
    Asignatura * asig = ManejadorAsignatura::getInstancia() -> buscarAsignatura(this -> codigo);

    if(controlRol(asig -> getTipoClases()))
    {
        Rol * rol = new Rol(this -> rol, asig);
        doc -> addRol(rol);
    }
    else
    {
        throw std::invalid_argument("El rol del docente no corresponde con el de la asignatura...");
    }
}

void CAsignacionDocenteAsignatura::cancelar(){}
