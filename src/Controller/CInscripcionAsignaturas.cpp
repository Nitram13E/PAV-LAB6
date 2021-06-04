#include "header/CInscripcionAsignaturas.h"
#include "../Handlers/header/ManejadorAsignatura.h"
#include "../Handlers/header/ManejadorPerfil.h"


CInscripcionAsignaturas::CInscripcionAsignaturas(){}

CInscripcionAsignaturas::~CInscripcionAsignaturas(){}

std::list<std::string> CInscripcionAsignaturas::asignaturasNoInscriptos(std::string email)
{
    ManejadorAsignatura * asignaturas = asignaturas -> getInstancia();

    //Traigo todas las asignaturas existentes
    std::list<Asignatura*> listaAsignaturas = asignaturas -> listarAsignatura();

    ManejadorPerfil *  usuarios = usuarios -> getInstancia();

    //Busco si existe un estudiante con ese mail
    Perfil * usuario = usuarios -> buscarPerfil(email);
    Estudiante * estudiante = dynamic_cast<Estudiante*>(usuario);

    if(estudiante == NULL) return;

    //Traigo las asignaturas en las cuales el estudiante esta inscripto
    std::list<Asignatura*> asignaturasEstudiante = estudiante -> getAsignaturas();

    //Creo el iterador para recorrer las listas de asignatura
    std::list<Asignatura*>::iterator iteradorAsig = listaAsignaturas.begin();

    std::list<Asignatura*>::iterator iteradorAsigestudiante = asignaturasEstudiante.begin();

    //Creo la lista de asignaturas a devolver
    std::list<std::string> result;

    //Algoritmo para comparar asignaturas
    while (iteradorAsig != listaAsignaturas.end()) // Mientras no haya terminado de comprobar todas las asignaturas
    {
        //Si ambos iteradores son iguales quiere decir que ya esta inscripto por lo tanto paso a otra materia
        //SI NO son iguales entonces quiere decir que tengo que seguir comprobando por lo tanto avanzo el iterador de estudiante 
        if((*iteradorAsig) -> getCodigo() == (*iteradorAsigestudiante) -> getCodigo())
        {
            iteradorAsig++;
            iteradorAsigestudiante = asignaturasEstudiante.begin();
        }
        else
        {
            iteradorAsigestudiante++;
        }

        //Si llego al final de la lista de asignaturas de estudiante y todavia quedan asignaturas, lo ingresamos porque es una asignatura que no existe en estudiante
        if(iteradorAsigestudiante == asignaturasEstudiante.end() && iteradorAsig != listaAsignaturas.end())
        {
            result.push_back((*iteradorAsig) -> getCodigo());

            iteradorAsigestudiante = asignaturasEstudiante.begin();

            iteradorAsig++;
        }
    }
    
    return result;
}

void CInscripcionAsignaturas::selectAsignatura(std::string asignatura)
{
    this -> codigo = asignatura;
}

void CInscripcionAsignaturas::inscribir(std::string email)
{
    ManejadorAsignatura * asignaturas = asignaturas -> getInstancia();

    std::string codigoAsignatura = this -> codigo;

    Asignatura * asignaturaAIncribir = asignaturas -> buscarAsignatura(codigoAsignatura);


    //Busco si existe un estudiante con ese mail
    ManejadorPerfil *  usuarios = usuarios -> getInstancia();

    Perfil * usuario = usuarios -> buscarPerfil(email);

    Estudiante * estudiante = dynamic_cast<Estudiante*>(usuario);

    if(estudiante == NULL) return;

    //Lo inscribo a esa asignatura
    estudiante -> addAsignaturas(asignaturaAIncribir);
}

//En cancelar no se borra nada, ya que no se creo ninguna instancia de ningun objeto porque no paso por la funcion inscribir()
void CInscripcionAsignaturas::cancelar(){}












