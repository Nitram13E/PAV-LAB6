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
    switch (dtInstClase.getTeorico())
    {
    case 0:
        std::cout << "Teorico: No" << std::endl;
        break;
    case 1: 
        std::cout << "Teorico: Si" << std::endl;
        break;
    }
    switch (dtInstClase.getPractico())
    {
    case 0:
        std::cout << "Practico: No" << std::endl;
        break;
    case 1: 
        std::cout << "Practico: Si" << std::endl;
        break;
    }
    switch(dtInstClase.getMonitoreo())
    {
    case 0:
        std::cout << "Monitoreo: No" << std::endl;
        break;
    case 1: 
        std::cout << "Monitoreo: Si" << std::endl;
        break;
    }
    ///std::cout << "Teorico: " << dtInstClase.getTeorico() << std::endl;
    //std::cout << "Practico: " << dtInstClase.getPractico() << std::endl;
    //std::cout << "Monitoreo: " << dtInstClase.getMonitoreo();

    return out;
}