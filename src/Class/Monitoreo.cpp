#include "header/Monitoreo.h"
#include "../DataTypes/header/DtInfoMonitoreo.h"

Monitoreo::Monitoreo(){}

Monitoreo::Monitoreo(std::string nombre, DtTimeStamp inicio, DtTimeStamp* fin , std::string rutavideo, std::list<Estudiante*> habilitados) : Clase(nombre, inicio, fin, rutavideo)
{
    this -> habilitados = habilitados;
}

Monitoreo::~Monitoreo(){}

std::list<Estudiante*> Monitoreo::getHabilitados()
{
    return this -> habilitados;
}

DtInfoClase* Monitoreo::getDtInfoClase()
{
    std::list<std::string> dtDocentes;
    std::list<Docente*>::iterator it;

    std::list<Estudiante*>::iterator it2;
    std::list<std::string> dtEstudiantes;

    std::list<Docente*> listDocentes = this -> getDocentes();
    std::list<Estudiante*> listHabilitados = this -> habilitados;

    for(it = listDocentes.begin(); it != listDocentes.end(); it++)
    {
        dtDocentes.push_back((*it)->getEmail());
    }
    for(it2 = listHabilitados.begin(); it2 != listHabilitados.end(); it++)
    {
        dtEstudiantes.push_back((*it2) -> getEmail());
    }

    DtInfoMonitoreo* dtic = new DtInfoMonitoreo(this -> getID(), this -> getNombre(), dtDocentes, dtEstudiantes);
    return dtic;
}