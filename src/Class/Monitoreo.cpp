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

DtInfoClase Monitoreo::getDtInfoClase()
{
    std::list<std::string> dtDocentes;
    std::list<Docente*>::iterator it;
    std::list<Estudiante*>::iterator it2;
    std::list<std::string> dtEstudiantes;
    for(it = this->getDocentes().begin(); it != this->getDocentes().end(); ++it)
    {
        dtDocentes.push_back((*it)->getEmail());
    }
    for(it2 = this->habilitados.begin(); it2 != this->habilitados.end(); ++it)
    {
        dtEstudiantes.push_back((*it2) -> getEmail());
    }
    
    DtInfoMonitoreo dtic = DtInfoMonitoreo(this -> getID(),this -> getNombre(),dtDocentes,dtEstudiantes);
    return dtic;
}