#include "header/AsisteVivo.h"

AsisteVivo::AsisteVivo(){}

AsisteVivo::AsisteVivo(DtTimeStamp inicio, DtTimeStamp fin)
{
    this -> inicio = inicio;
    this -> fin = fin;
}

AsisteVivo::~AsisteVivo(){}

void AsisteVivo::setInicio(DtTimeStamp inicio)
{
    this -> inicio = inicio;
}
DtTimeStamp AsisteVivo::getInicio()
{
    return this -> inicio;
} 

void AsisteVivo::setFin(DtTimeStamp fin)
{
    this -> fin = fin;
}
DtTimeStamp AsisteVivo::getFin()
{
    return this -> fin;
} 

void AsisteVivo::setEstudiante(Estudiante* estudiante)
{
    this -> estudiante = estudiante;
}
Estudiante* AsisteVivo::getEstudiante()
{
    return this -> estudiante;
}