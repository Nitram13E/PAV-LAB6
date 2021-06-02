#include "header/DtIniciarMonitoreo.h"

DtIniciarMonitoreo::DtIniciarMonitoreo(){}

DtIniciarMonitoreo::DtIniciarMonitoreo(int id, std::string codigo, std::string nombre, DtTimeStamp fechahora, std::list<std::string> habilitados) : DtIniciarClaseFull(id, codigo, nombre, fechahora)
{
    this -> habilitados = habilitados;
}

DtIniciarMonitoreo::~DtIniciarMonitoreo(){}

std::list<std::string> DtIniciarMonitoreo::getHabilitados()
{
    return this -> habilitados;
}