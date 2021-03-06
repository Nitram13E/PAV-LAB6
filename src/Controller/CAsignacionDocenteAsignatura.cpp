#include "header/CAsignacionDocenteAsignatura.h"
#include "../Handlers/header/ManejadorPerfil.h"

CAsignacionDocenteAsignatura::CAsignacionDocenteAsignatura(){}
CAsignacionDocenteAsignatura::~CAsignacionDocenteAsignatura(){}

//Controla que el rol selecc. corresponda con la instancia de clase de la asignatura 
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

//Lista los docentes no asignados a la asignatura
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

//Crea un objeto rol con la asignatura y el tipoRol selecc. y lo agrega al docente
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
        throw std::invalid_argument("El rol del docente no corresponde con el de la asignatura.");
    }
}

void CAsignacionDocenteAsignatura::cancelar(){}

void CAsignacionDocenteAsignatura::cargarDatos()
{
    docentesSinLaAsignatura("1");
    selectDocente("mail-d1", TEORICO);
    asignarDocente();

    docentesSinLaAsignatura("1");
    selectDocente("mail-d2", PRACTICO);
    asignarDocente();

    docentesSinLaAsignatura("2");
    selectDocente("mail-d3", TEORICO);
    asignarDocente();

    docentesSinLaAsignatura("3");
    selectDocente("mail-d4", PRACTICO);
    asignarDocente();

    docentesSinLaAsignatura("4");
    selectDocente("mail-d3", TEORICO);
    asignarDocente();

    docentesSinLaAsignatura("4");
    selectDocente("mail-d1", PRACTICO);
    asignarDocente();

    docentesSinLaAsignatura("5");
    selectDocente("mail-d2", TEORICO);
    asignarDocente();

    docentesSinLaAsignatura("5");
    selectDocente("mail-d1", MONITOREO);
    asignarDocente();

    docentesSinLaAsignatura("6");
    selectDocente("mail-d3", PRACTICO);
    asignarDocente();
}