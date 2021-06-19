#include "header/DtInstanciaClase.h"

DtInstanciaClase::DtInstanciaClase(){}

DtInstanciaClase::DtInstanciaClase(bool teorico, bool practico, bool monitoreo)
{
    this -> teorico = teorico;
    this -> practico = practico;
    this -> monitoreo = monitoreo;
}

DtInstanciaClase::~DtInstanciaClase(){}

bool DtInstanciaClase::getTeorico()
{  
    return this -> teorico;
}


bool DtInstanciaClase::getPractico()
{
    return this -> practico;
}

bool DtInstanciaClase::getMonitoreo()
{
    return this -> monitoreo;
}

std::ostream& operator << (std::ostream& out, DtInstanciaClase dtInstClase)
{
    std::cout << "Teorico: " << dtInstClase.getTeorico() << std::endl;
    std::cout << "Practico: " << dtInstClase.getPractico() << std::endl;
    std::cout << "Monitoreo: " << dtInstClase.getMonitoreo();

    return out;
}