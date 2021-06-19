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

std::ostream& operator << (std::ostream& out, DtInfoMonitoreo dtInfMonitoreo)
{
    std::cout << (DtInfoClase)dtInfMonitoreo << std::endl;

    std::list<std::string> estudiantes = dtInfMonitoreo.estudiantes;
    
    for(std::list<std::string>::iterator it = estudiantes.begin(); it != estudiantes.end(); it++)
    {
        std::cout << " - " << (*it) << std::endl;
    }

    return out;
}