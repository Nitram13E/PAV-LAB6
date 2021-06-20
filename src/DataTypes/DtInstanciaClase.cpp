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
    if(dtInstClase.getTeorico()) std::cout << "   - Teorico" << std::endl;
    if(dtInstClase.getPractico()) std::cout << "   - Practico" << std::endl;
    if(dtInstClase.getMonitoreo()) std::cout << "   - Monitoreo" << std::endl;

    return out;
}