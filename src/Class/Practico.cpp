#include "header/Practico.h"

Practico::Practico(){}

Practico::Practico(std::string nombre, DtTimeStamp inicio, DtTimeStamp* fin, std::string rutavideo) : Clase(nombre, inicio, fin, rutavideo){}

Practico::~Practico(){}

DtInfoClase Practico::getDtInfoClase()
{
    std::list<std::string> dtDocentes;
    std::list<Docente*>::iterator it;
    for(it = this->getDocentes().begin(); it != this->getDocentes().end(); ++it)
    {
        dtDocentes.push_back((*it)->getEmail());
    }
    DtInfoClase dtic = DtInfoClase(this->getID(),this->getNombre(),dtDocentes);
    return dtic;
}