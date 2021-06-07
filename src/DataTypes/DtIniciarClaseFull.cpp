#include "header/DtIniciarClaseFull.h"


DtIniciarClaseFull::DtIniciarClaseFull(){}

DtIniciarClaseFull::DtIniciarClaseFull(int id, std::string codigo, std::string nombre, DtTimeStamp fechahora) : DtIniciarClase(codigo, nombre, fechahora)
{
    this -> id = id;
}

DtIniciarClaseFull::~DtIniciarClaseFull()
{
    
}

int DtIniciarClaseFull::getId()
{
    return this -> id;
}