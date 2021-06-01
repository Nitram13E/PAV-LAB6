#include "header/Clase.h"

Clase::Clase(){}

Clase::Clase(int id, std::string nombre, DtTimeStamp inicio, DtTimeStamp fin, std::string rutavideo)
{
    this -> id = id;
    this -> nombre = nombre;
    this -> inicio = inicio;
    this -> fin = fin;
    this -> rutavideo = rutavideo;
}

int Clase::getID()
{
    return this -> id;
}

void Clase::setID(int id)
{
    this -> id = id;
}

std::string Clase::getNombre()
{
    return this -> nombre;
}
void Clase::setNombre(std::string nombre)
{
    this -> nombre = nombre;
}

DtTimeStamp Clase::getInicio()
{
    return this -> inicio;
}

void Clase::setInicio(DtTimeStamp inicio)
{
    this -> inicio = inicio;
}

DtTimeStamp Clase::getFin()
{
    return this -> fin;
}

void Clase::setFin(DtTimeStamp fin)
{
    this -> fin = fin;
}

std::string Clase::getRutaVideo()
{
    return this -> rutavideo;
}
void Clase::setRutaVideo(std::string rutavideo)
{
    this -> rutavideo = rutavideo;
}