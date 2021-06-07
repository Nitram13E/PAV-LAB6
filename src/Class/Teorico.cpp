#include "header/Teorico.h"
#include "../DataTypes/header/DtInfoTeorico.h"

Teorico::Teorico(){}

Teorico::Teorico(std::string nombre, DtTimeStamp inicio, DtTimeStamp fin, std::string rutavideo) : Clase(nombre, inicio, fin, rutavideo){}

Teorico::~Teorico(){}

void Teorico::calcularAsistentes()
{
    this -> cantAsistentes = this -> getAsisteVivo().size();
}
DtInfoClase Teorico::getDtInfoClase()
{
    std::list<std::string> dtDocentes;
    std::list<Docente*>::iterator it;
    
    
    for(it = this->getDocentes().begin(); it != this->getDocentes().end(); ++it)
    {
        dtDocentes.push_back((*it)->getEmail());
    }
    DtInfoTeorico dtic = DtInfoTeorico(this->getID(),this->getNombre(),dtDocentes, this->cantAsistentes);

    return dtic;
}