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

//Lista las asignaturas a las que esta asignado el docente
std::list<std::string> CInicioClase::asignaturasAsignadas()
{
    Perfil* p = Sesion::getInstancia() -> getPerfil();
    Docente * d = dynamic_cast<Docente*>(p);

    if(d == NULL) throw std::invalid_argument("El usuario no es un docente.");

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

    std::list<Rol*> roles = this -> doc -> getRoles();

    std::list<Rol*>:: iterator it = roles.begin();

    while(it != roles.end() && (*it) -> getCodigoAsignatura() != inicio.getCodigo()) it++;

    if(it == roles.end()) throw std::invalid_argument("Asignatura no encontrada en lista de roles. ");

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

    if(listaEstudiantes.empty()) throw std::invalid_argument("La asignatura no tiene estudiantes inscriptos.");

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
    this -> doc = NULL;
    this -> listaHabilitados.clear();
}
//Carga Datos Predefinidos al Programa.
void CInicioClase::cargarDatos()
{
    ManejadorPerfil* mp = ManejadorPerfil::getInstancia();

    this -> doc = dynamic_cast<Docente*>(mp -> buscarPerfil("mail-d2"));
    selectAsignatura(DtIniciarClase("1", "PAV practico 20-6-21", DtTimeStamp(DtFecha(20,6,2021), 10, 0, 0)));
    datosIngresados();
    iniciarClase();

    this -> doc = dynamic_cast<Docente*>(mp -> buscarPerfil("mail-d3"));
    selectAsignatura(DtIniciarClase("2", "COE teorico 20-6-21", DtTimeStamp(DtFecha(20,6,2021), 11, 0, 0)));
    datosIngresados();
    iniciarClase();

    this -> doc = dynamic_cast<Docente*>(mp -> buscarPerfil("mail-d4"));
    selectAsignatura(DtIniciarClase("3", "RC monitoreo 20-6-21", DtTimeStamp(DtFecha(20,6,2021), 12, 0, 0)));
    datosIngresados();
    iniciarClase();
}