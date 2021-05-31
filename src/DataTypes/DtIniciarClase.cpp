#include "header/DtIniciarClase.h"

DtIniciarClase::DtIniciarClase(){}

DtIniciarClase::DtIniciarClase(std::string codigo, std::string nombre, DtTimeStamp fechaHora)
{
    this -> codigo = codigo;
    this -> nombre = nombre;
    this -> fechaHora = fechaHora;
}

DtIniciarClase::~DtIniciarClase(){}

std::string DtIniciarClase::getCodigo()
{
    return this -> codigo;
}

std::string DtIniciarClase::getNombre()
{
    return this -> nombre;
}

DtTimeStamp DtIniciarClase::getFechaHora()
{
    return this -> fechaHora;
}