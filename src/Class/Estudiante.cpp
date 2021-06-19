#include "header/Estudiante.h"

Estudiante::Estudiante(){}

Estudiante::Estudiante(std::string nombre, std::string imagenURL, std::string email, std::string password, std::string documento) : Perfil(nombre, imagenURL, email, password)
{   
    this -> documento = documento;
}
Estudiante::~Estudiante(){}

void Estudiante::setDocumento(std::string documento)
{
    this -> documento = documento;
}

std::string Estudiante::getDocumento()
{
    return this -> documento;
}

void Estudiante::addAsignaturas(Asignatura* asignatura)
{
    this -> asignaturas.push_back(asignatura);
}

std::list<Asignatura*> Estudiante::getAsignaturas()
{
    return this -> asignaturas;
}

void Estudiante::desvincularAsignatura(std::string codigo)
{
    std::list<Asignatura*>::iterator it = this -> asignaturas.begin();

    while(it != this -> asignaturas.end() && (*it) -> getCodigo() != codigo) it++;

    if(it != this -> asignaturas.end()) this -> asignaturas.remove(*it);

    //FORMA PARA CUANDO LAS LISTAS NO ESTAN PASADAS POR * (Forma YONA PLA)
    // if(it != this -> asignaturas.end())
    // {
    //     *it = this -> asignaturas.back();

    //     this -> asignaturas.back() = NULL;

    //     this -> asignaturas.remove(this -> asignaturas.back());
    // }
}

bool Estudiante::tieneAsignatura(std::string asignatura)
{
    std::list<Asignatura*>::iterator it = this -> asignaturas.begin();

    while(it != this -> asignaturas.end() && (*it) -> getCodigo() != asignatura) it++;

    if(it != this -> asignaturas.end()) return true;

    return false;
}