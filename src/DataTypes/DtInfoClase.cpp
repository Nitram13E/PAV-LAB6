#include "header/DtInfoClase.h"

DtInfoClase::DtInfoClase(){}

DtInfoClase::DtInfoClase(int id, std::string nombre, std::list<std::string> docentes)
{
    this -> id = id;
    this -> nombre = nombre;
    this -> docentes = docentes;
}

DtInfoClase::~DtInfoClase(){}

int DtInfoClase::getId()
{
    return this -> id;
}

std::string DtInfoClase::getNombre()
{
    return this -> nombre;
}

std::list<std::string> DtInfoClase::getDocentes()
{
    return this -> docentes;
}