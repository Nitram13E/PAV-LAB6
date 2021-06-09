#include "header/DtAsignatura.h"

DtAsignatura::DtAsignatura(){}

DtAsignatura::DtAsignatura(std::string codigo, std::string nombre, DtInstanciaClase* tipo)
{
    this -> codigo = codigo;
    this -> nombre = nombre;
    this -> tipoClases = tipo;
}

DtAsignatura::~DtAsignatura(){}

std::string DtAsignatura::getCodigo()
{
    return this -> codigo;
}

std::string DtAsignatura::getNombre()
{
    return this -> nombre;
}

DtInstanciaClase* DtAsignatura::getTipoClases()
{
    return this -> tipoClases;
}