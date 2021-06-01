#include "header/DtIniciarClaseFull.h"


DtIniciarClaseFull::DtIniciarClaseFull(){}

DtIniciarClaseFull::DtIniciarClaseFull(std::string codigo, std::string nombre, DtTimeStamp fechahora) : DtIniciarClase(codigo, nombre, fechahora)
{
    //Falta asignacion de id por el sistema
    //this -> id = randID();
}

DtIniciarClaseFull::~DtIniciarClaseFull()
{
    
}

int DtIniciarClaseFull::getId()
{
    return this -> id;
}