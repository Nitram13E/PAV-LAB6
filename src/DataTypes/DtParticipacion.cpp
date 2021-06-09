#include "header/DtParticipacion.h"

DtParticipacion::DtParticipacion(){}

DtParticipacion::DtParticipacion(int id, DtTimeStamp fecha, std::string mensaje, DtParticipacion * responde)
{
    this -> id = id;
    this -> fecha = fecha;
    this -> mensaje = mensaje;
    this -> responde = responde;
}

DtParticipacion::~DtParticipacion(){}

int DtParticipacion::getId()
{
    return this -> id;
}

DtTimeStamp DtParticipacion::getFecha()
{
    return this -> fecha;
}

std::string DtParticipacion::getMensaje()
{
    return this -> mensaje;
}

DtParticipacion * DtParticipacion::getResponde()
{
    return this -> responde;
}