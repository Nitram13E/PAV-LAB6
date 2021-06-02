#include "header/Teorico.h"

Teorico::Teorico(){}

Teorico::Teorico(std::string nombre, DtTimeStamp inicio, DtTimeStamp fin, std::string rutavideo) : Clase(nombre, inicio, fin, rutavideo){}

Teorico::~Teorico(){}

void Teorico::calcularAsistentes()
{
    this -> cantAsistentes = this -> getAsisteVivo().size();
}