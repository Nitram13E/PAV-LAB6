#include "header/DtIniciarMonitoreo.h"

DtIniciarMonitoreo::DtIniciarMonitoreo(){}

DtIniciarMonitoreo::DtIniciarMonitoreo(std::string codigo, std::string nombre, DtTimeStamp fechahora, std::string * habilitados) : DtIniciarClaseFull(codigo, nombre, fechahora)
{
    //this -> habilitados = habilitados;
}

DtIniciarMonitoreo::~DtIniciarMonitoreo(){}

std::string * DtIniciarMonitoreo::getHabilitados()
{
    return this -> habilitados;
}