#include "header/Practico.h"

Practico::Practico(){}

Practico::Practico(std::string nombre, DtTimeStamp inicio, DtTimeStamp* fin, std::string rutavideo) : Clase(nombre, inicio, fin, rutavideo){}

Practico::~Practico(){}

DtInfoClase* Practico::getDtInfoClase()
{
    std::list<std::string> dtDocentes;
    std::list<Docente*>::iterator it;
    std::list<Docente*> listDoc = this -> getDocentes();

    for(it = listDoc.begin(); it != listDoc.end(); it++)
    {
        dtDocentes.push_back((*it) -> getEmail());
    }

    DtInfoClase* dtic = new DtInfoClase(this -> getID(), this->getNombre(), dtDocentes);
    return dtic;
}