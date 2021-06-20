#include "header/CEliminarAsignatura.h"
#include "../Handlers/header/ManejadorAsignatura.h"
#include "../Handlers/header/ManejadorPerfil.h"

CEliminarAsignatura::CEliminarAsignatura(){}
CEliminarAsignatura::~CEliminarAsignatura(){}

std::list<std::string> CEliminarAsignatura::listarAsignaturas()
{
    return ManejadorAsignatura::getInstancia() -> listarAsignatura();
}

void CEliminarAsignatura::selectAsignatura(std::string codigo)
{
    this -> codigo = codigo;
}

void CEliminarAsignatura::eliminarAsignatura()
{
    ManejadorAsignatura * ma = ManejadorAsignatura::getInstancia();
    Asignatura * asignatura = ma -> buscarAsignatura(this -> codigo);

    if(asignatura == NULL) return;
    std::list<Perfil*> perfiles = ManejadorPerfil::getInstancia() -> listarPerfiles();

    for(std::list<Perfil*>::iterator it = perfiles.begin(); it != perfiles.end(); it++)
    {
        (*it) -> desvincularAsignatura(this -> codigo);
    }
    
    ma -> removeAsignatura(this -> codigo);
}

void CEliminarAsignatura::cancelar(){}