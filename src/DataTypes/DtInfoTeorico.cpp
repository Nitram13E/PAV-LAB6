#include "header/DtInfoTeorico.h"

DtInfoTeorico::DtInfoTeorico(){}

DtInfoTeorico::DtInfoTeorico(int id, std::string nombre, std::list<std::string> docentes, int cantAsistentes) : DtInfoClase(id, nombre, docentes)
{
    this -> cantAsistentes = cantAsistentes;
}

DtInfoTeorico::~DtInfoTeorico(){}

int DtInfoTeorico::getCantAsist()
{
    return this -> cantAsistentes;   
}