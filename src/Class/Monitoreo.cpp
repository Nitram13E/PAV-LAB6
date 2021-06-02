#include "header/Monitoreo.h"

Monitoreo::Monitoreo(){}

Monitoreo::Monitoreo(std::string nombre, DtTimeStamp inicio, DtTimeStamp fin , std::string rutavideo) : Clase(nombre, inicio, fin, rutavideo){}

Monitoreo::~Monitoreo(){}


std::list<Estudiante*> Monitoreo::getHabilitados()
{
    return this -> habilitados;
}