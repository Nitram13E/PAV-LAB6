#include "header/DtIniciarClaseFull.h"

DtIniciarClaseFull::DtIniciarClaseFull(){}

DtIniciarClaseFull::DtIniciarClaseFull(int id, std::string codigo, std::string nombre, DtTimeStamp fechahora) : DtIniciarClase(codigo, nombre, fechahora)
{
    this -> id = id;
}

DtIniciarClaseFull::~DtIniciarClaseFull(){}

int DtIniciarClaseFull::getId()
{
    return this -> id;
}

std::ostream& operator << (std::ostream& out, DtIniciarClaseFull& dticf)
{
    std::cout << "Codigo asignatura: " << dticf.getCodigo() << std::endl;
    std::cout << "Nombre: " << dticf.getNombre() << std::endl;
    std::cout << "Fecha y hora: " << dticf.getFechaHora() << std::endl;
    std::cout << "ID: " << dticf.getId();

    return out;
}