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

std::ostream& operator << (std::ostream& out, const DtInfoClase& info)
{
    std::cout << "Codigo: " << info.id << std::endl;
    std::cout << "Nombre: " << info.nombre << std::endl;
    std::cout << "Codigos de los Docentes: " << std::endl;

    std::list<std::string> docentes = info.docentes;

    for(std::list<std::string>::iterator it = docentes.begin(); it != docentes.end(); it++)
    {
        std::cout << " - " << (*it) << std::endl;
    }

    return out;
}