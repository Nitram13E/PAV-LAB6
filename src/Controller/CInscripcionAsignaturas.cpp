#include "header/CInscripcionAsignaturas.h"
#include "../Handlers/header/ManejadorAsignatura.h"
#include "../Handlers/header/ManejadorPerfil.h"

CInscripcionAsignaturas::CInscripcionAsignaturas(){}

CInscripcionAsignaturas::~CInscripcionAsignaturas(){}
//lista las asignaturas en las que el usuario no esta inscripto.
std::list<std::string> CInscripcionAsignaturas::asignaturasNoInscriptos()
{
    ManejadorAsignatura * asignaturas = ManejadorAsignatura::getInstancia();

    // Creo la lista de asignaturas a devolver
    std::list<std::string> result;

    // Traigo todas las asignaturas existentes
    std::map<std::string,Asignatura*> listaAsignaturas = asignaturas -> listarMapAsignatura();

    ManejadorPerfil *  usuarios = ManejadorPerfil::getInstancia();
    Sesion * sesion = sesion -> getInstancia();

    // Obtengo estudiante con asignaturas de sesion
    Estudiante * estudiante = dynamic_cast<Estudiante*>(sesion -> getPerfil());

    if(estudiante == NULL)  throw std::invalid_argument("Usuario no encontrado\n");

    // Traigo las asignaturas en las cuales el estudiante esta inscripto
    std::list<Asignatura*> asignaturasEstudiante = estudiante -> getAsignaturas();

    // Creo el iterador para recorrer las listas de asignatura
    std::map<std::string,Asignatura*>::iterator iteradorAsig;

    std::list<Asignatura*>::iterator iteradorAsigestudiante;

    // Algoritmo de busqueda

    for (iteradorAsigestudiante = asignaturasEstudiante.begin(); iteradorAsigestudiante != asignaturasEstudiante.end(); iteradorAsigestudiante++)
    {
        iteradorAsig = listaAsignaturas.find((*iteradorAsigestudiante) -> getCodigo());

        if(iteradorAsig != listaAsignaturas.end())  listaAsignaturas.erase(iteradorAsig);
    }

    // Copiar lo que quedo del mapa a una lista de strings
    
    for(iteradorAsig = listaAsignaturas.begin(); iteradorAsig != listaAsignaturas.end(); iteradorAsig++)
    {
        result.push_back(iteradorAsig -> first);
    }
    
    return result;
}
//selecciona una asignatura y la setea en el Controlador.
void CInscripcionAsignaturas::selectAsignatura(std::string asignatura)
{
    this -> codigo = asignatura;
}

void CInscripcionAsignaturas::inscribir()
{
    ManejadorAsignatura * asignaturas = ManejadorAsignatura::getInstancia();
    Sesion * sesion = Sesion::getInstancia();

    Asignatura * asignaturaAIncribir = asignaturas -> buscarAsignatura(this -> codigo);

    // Busco si existe un estudiante con ese mail
    ManejadorPerfil *  usuarios = ManejadorPerfil::getInstancia();

    Estudiante * estudiante = dynamic_cast<Estudiante*>(sesion -> getPerfil());

    if(estudiante == NULL)  std::cout<<"Usuario no encontrado\n"<<std::endl;

    // Lo inscribo a esa asignatura
    estudiante -> addAsignaturas(asignaturaAIncribir);
}

// En cancelar no se borra nada, ya que no se creo ninguna instancia de ningun objeto porque no paso por la funcion inscribir()
void CInscripcionAsignaturas::cancelar(){}

bool CInscripcionAsignaturas::esEstudiante()
{   
    ManejadorPerfil *  usuarios = ManejadorPerfil::getInstancia();
    Sesion * sesion = sesion -> getInstancia();
    Estudiante * estudiante = dynamic_cast<Estudiante*>(sesion -> getPerfil());
    if (estudiante!=NULL)
        return true;
    else return false;
}

void CInscripcionAsignaturas::cargarDatos()
{
    ManejadorAsignatura * ma = ManejadorAsignatura::getInstancia();
    ManejadorPerfil * mp = ManejadorPerfil::getInstancia();
    Estudiante * estudiante;

    estudiante = dynamic_cast<Estudiante*>(mp -> buscarPerfil("mail-e1"));
    estudiante -> addAsignaturas(ma -> buscarAsignatura("1"));
    estudiante -> addAsignaturas(ma -> buscarAsignatura("2"));
    estudiante -> addAsignaturas(ma -> buscarAsignatura("3"));
    estudiante -> addAsignaturas(ma -> buscarAsignatura("4"));
    estudiante -> addAsignaturas(ma -> buscarAsignatura("5"));

    estudiante = dynamic_cast<Estudiante*>(mp -> buscarPerfil("mail-e2"));
    estudiante -> addAsignaturas(ma -> buscarAsignatura("1"));
    estudiante -> addAsignaturas(ma -> buscarAsignatura("2"));
    estudiante -> addAsignaturas(ma -> buscarAsignatura("3"));
    estudiante -> addAsignaturas(ma -> buscarAsignatura("4"));

    estudiante = dynamic_cast<Estudiante*>(mp -> buscarPerfil("mail-e3"));
    estudiante -> addAsignaturas(ma -> buscarAsignatura("1"));
    estudiante -> addAsignaturas(ma -> buscarAsignatura("2"));
    estudiante -> addAsignaturas(ma -> buscarAsignatura("3"));

    estudiante = dynamic_cast<Estudiante*>(mp -> buscarPerfil("mail-e4"));
    estudiante -> addAsignaturas(ma -> buscarAsignatura("1"));
    estudiante -> addAsignaturas(ma -> buscarAsignatura("4"));

    estudiante = dynamic_cast<Estudiante*>(mp -> buscarPerfil("mail-e5"));
    estudiante -> addAsignaturas(ma -> buscarAsignatura("1"));
}