#include "header/CInicioClase.h"
#include "../Class/header/Sesion.h"
#include "../Class/header/Teorico.h"
#include "../Class/header/Practico.h"
#include "../Class/header/Monitoreo.h"
#include "../Handlers/header/ManejadorPerfil.h"
#include "../Handlers/header/ManejadorAsignatura.h"
#include "../Handlers/header/ManejadorClase.h"
#include "../DataTypes/header/DtIniciarMonitoreo.h"

CInicioClase::CInicioClase(){}
CInicioClase::~CInicioClase(){}

std::list<std::string> CInicioClase::asignaturasAsignadas()
{
    Perfil* p = Sesion::getInstancia() -> getPerfil();
    Docente * d = dynamic_cast<Docente*>(p);

    if(d == NULL) throw std::invalid_argument("El usuario logueado no es un docente");

    this -> doc = d;

    std::list<std::string> lista;

    if(this -> doc != NULL)
    {
        return this -> doc -> listarAsignaturas();
    }
    return lista;
}
//Selecciona una Asignatura pasandole un DtIniciarClase(con sus datos respectivos).
bool CInicioClase::selectAsignatura(DtIniciarClase inicio)
{
    this -> inicioClase = inicio;

    std::list<Rol*>:: iterator it = this -> doc -> getRoles().begin();

    while((*it) -> getCodigoAsignatura() != inicio.getCodigo()) it++;

    this -> rol = (*it) -> getTipoRol();

    return ((*it) -> getTipoRol() == MONITOREO);
}
//Devuelve una lista de los inscriptos a la Asignantura.
std::list<std::string> CInicioClase::inscriptosAsignatura()
{
    std::list<std::string> listaEstudiantes;
    std::list<Perfil*> perfiles = ManejadorPerfil::getInstancia() -> listarPerfiles();
    std::list<Perfil*>::iterator it;

    for(it = perfiles.begin(); it != perfiles.end(); it++)
    {
        Estudiante * est = dynamic_cast<Estudiante*>(*it);
    
        if(est != NULL && est -> tieneAsignatura(this -> inicioClase.getCodigo())) listaEstudiantes.push_back(est -> getEmail());
    }
    return listaEstudiantes;
}
//Agrega un estudiante(Email) a la lista de habilitados
void CInicioClase::habilitar(std::string email)
{
    Estudiante * est = dynamic_cast<Estudiante*>(ManejadorPerfil::getInstancia() -> buscarPerfil(email));
    if(est != NULL) this -> listaEstudiantes.push_back(est);

    this -> listaHabilitados.push_back(email);
}
//Setea los atributos ingresados anteriormente 
DtIniciarClaseFull* CInicioClase::datosIngresados()
{
    //si es de monitoreo
    if (!this -> listaHabilitados.empty())
    {
        this -> data = new DtIniciarMonitoreo(Clase::getIdActual(), this -> inicioClase.getCodigo(), this -> inicioClase.getNombre(), this -> inicioClase.getFechaHora(), this -> listaHabilitados);
        return this -> data;
    }
    this -> data = new DtIniciarClaseFull(Clase::getIdActual(), this -> inicioClase.getCodigo(), this -> inicioClase.getNombre(), this -> inicioClase.getFechaHora());
    return this -> data;
}

void CInicioClase::iniciarClase()
{
    Clase* clase;

    switch(this -> rol)
    {
        case TEORICO:
            clase = new Teorico(this -> data -> getNombre(), this -> data -> getFechaHora(), NULL, "");
            break;

        case PRACTICO:
            clase = new Practico(this -> data -> getNombre(), this -> data -> getFechaHora(), NULL, "");
            break;

        case MONITOREO:
            clase = new Monitoreo(this -> data -> getNombre(), this -> data -> getFechaHora(), NULL, "", this -> listaEstudiantes);
            break;
    }

    clase -> addDocentes(this -> doc);

    ManejadorClase::getInstancia() -> addClase(clase);

    Asignatura * asig = ManejadorAsignatura::getInstancia() -> buscarAsignatura(data -> getCodigo());
    asig -> addClases(clase);
}

void CInicioClase::cancelar()
{
    delete this -> doc;
    this -> listaHabilitados.clear();
}