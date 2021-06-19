#include "header/Teorico.h"
#include "../DataTypes/header/DtInfoTeorico.h"

Teorico::Teorico(){}

Teorico::Teorico(std::string nombre, DtTimeStamp inicio, DtTimeStamp* fin, std::string rutavideo) : Clase(nombre, inicio, fin, rutavideo){}

Teorico::~Teorico(){}

void Teorico::calcularAsistentes()
{
 
   this -> cantAsistentes = this -> getAsisteVivo().size();
}

DtInfoClase* Teorico::getDtInfoClase()
{
    std::list<std::string> dtDocentes;
    std::list<Docente*>::iterator it;
    std::list<Docente*> listDoc = this -> getDocentes();

    for(it = listDoc.begin(); it != listDoc.end(); it++)
    {
        dtDocentes.push_back((*it) -> getEmail());
    }

    calcularAsistentes();

    DtInfoTeorico* dtic = new DtInfoTeorico(this -> getID(), this -> getNombre(), dtDocentes, this -> cantAsistentes);

    return dtic;
}