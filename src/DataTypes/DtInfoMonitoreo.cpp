#include "header/DtInfoMonitoreo.h"

DtInfoMonitoreo::DtInfoMonitoreo(){}

DtInfoMonitoreo::DtInfoMonitoreo(int id, std::string nombre, std::list<std::string> docentes, std::list<std::string> estudiantes) : DtInfoClase(id, nombre, docentes)
{
    this -> estudiantes = estudiantes;
}

DtInfoMonitoreo::~DtInfoMonitoreo(){}

std::list<std::string> DtInfoMonitoreo::getEstudiantes()
{
    return this -> estudiantes;
}