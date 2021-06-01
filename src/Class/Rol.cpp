#include "header/Rol.h"

Rol::Rol(){}

Rol::Rol(tipoRol rol, Asignatura * asignatura)
{
    this -> tipo = rol;
    this -> asignatura = asignatura;
}

Rol::~Rol(){}

void Rol::setTipoRol(tipoRol tipo)
{
    this -> tipo = tipo;
}

tipoRol Rol::getTipoRol()
{
    return this -> tipo;
}

void Rol::setAsignatura(Asignatura* asignatura)
{
    this -> asignatura = asignatura;
}

Asignatura* Rol::getAsignatura()
{
    return this -> asignatura;
}