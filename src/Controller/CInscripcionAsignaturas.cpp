#include "header/CInscripcionAsignaturas.h"
#include "../Handlers/header/ManejadorAsignatura.h"
#include "../Handlers/header/ManejadorPerfil.h"


CInscripcionAsignaturas::CInscripcionAsignaturas(){}

CInscripcionAsignaturas::~CInscripcionAsignaturas(){}

std::list<std::string> CInscripcionAsignaturas::asignaturasNoInscriptos()
{
    ManejadorAsignatura * asignaturas = asignaturas -> getInstancia();

    //Creo la lista de asignaturas a devolver
    std::list<std::string> result;

    //Traigo todas las asignaturas existentes
    std::map<std::string,Asignatura*> listaAsignaturas = asignaturas -> listarMapAsignatura();

    ManejadorPerfil *  usuarios = usuarios -> getInstancia();
    Sesion * sesion = sesion -> getInstancia();

    //Obtengo estudiante con asignaturas de sesion
    Estudiante * estudiante = dynamic_cast<Estudiante*>(sesion -> getPerfil());

    if(estudiante == NULL)  throw std::invalid_argument("Usuario no encontrado\n");

    //Traigo las asignaturas en las cuales el estudiante esta inscripto
    std::list<Asignatura*> asignaturasEstudiante = estudiante -> getAsignaturas();

    //Creo el iterador para recorrer las listas de asignatura
    std::map<std::string,Asignatura*>::iterator iteradorAsig;

    std::list<Asignatura*>::iterator iteradorAsigestudiante;

    //Algoritmo de busqueda

    for (iteradorAsigestudiante = asignaturasEstudiante.begin(); iteradorAsigestudiante != asignaturasEstudiante.end(); iteradorAsigestudiante++)
    {
        iteradorAsig = listaAsignaturas.find((*iteradorAsigestudiante) -> getCodigo());

        if(iteradorAsig != listaAsignaturas.end())  listaAsignaturas.erase(iteradorAsig);
    }

    //Copiar lo que quedo del mapa a una lista de strings
    
    for(iteradorAsig = listaAsignaturas.begin(); iteradorAsig != listaAsignaturas.end(); iteradorAsig++)
    {
        result.push_back(iteradorAsig -> first);
    }
    
    return result;
}

void CInscripcionAsignaturas::selectAsignatura(std::string asignatura)
{
    this -> codigo = asignatura;
}

void CInscripcionAsignaturas::inscribir()
{
    ManejadorAsignatura * asignaturas = asignaturas -> getInstancia();
    Sesion * sesion = sesion -> getInstancia();

    Asignatura * asignaturaAIncribir = asignaturas -> buscarAsignatura(this -> codigo);

    //Busco si existe un estudiante con ese mail
    ManejadorPerfil *  usuarios = usuarios -> getInstancia();

    Estudiante * estudiante = dynamic_cast<Estudiante*>(sesion -> getPerfil());

    if(estudiante == NULL) throw std::invalid_argument("Usuario no encontrado\n");

    //Lo inscribo a esa asignatura
    estudiante -> addAsignaturas(asignaturaAIncribir);
}

//En cancelar no se borra nada, ya que no se creo ninguna instancia de ningun objeto porque no paso por la funcion inscribir()
void CInscripcionAsignaturas::cancelar(){}