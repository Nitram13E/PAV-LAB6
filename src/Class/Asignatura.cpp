#include "header/Asignatura.h"

Asignatura::Asignatura(){}


Asignatura::Asignatura(std::string codigo, std::string nombre, DtInstanciaClase tipo)
{
    this -> codigo = codigo;
    this -> nombre = nombre;
    this -> tipoClases = tipo;
}

Asignatura::~Asignatura(){}

std::string Asignatura::getCodigo()
{
    return this -> codigo;
}

void Asignatura::setCodigo(std::string codigo)
{
    this -> codigo = codigo;
}

std::string Asignatura::getNombre()
{
    return this -> nombre;
}

void Asignatura::setNombre(std::string nombre)
{
    this -> nombre = nombre;
}

DtInstanciaClase Asignatura::getTipoClases()
{
    return this -> tipoClases;
}

void Asignatura::setTipoClases(DtInstanciaClase tipo)
{
    this -> tipoClases = tipo;
}

void Asignatura::addClases(Clase* clase)
{
    this -> clases.push_back(clase);
}
std::list<Clase*> Asignatura::getClases()
{
    return this -> clases;
}