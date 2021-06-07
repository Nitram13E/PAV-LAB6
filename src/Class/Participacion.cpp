#include "header/Participacion.h"

Participacion::Participacion(){}

Participacion::Participacion(int id, DtTimeStamp fecha, std::string mensaje, Participacion * responde)
{
    this -> id = id;
    this -> fecha = fecha;
    this -> mensaje = mensaje;
    this -> responde = responde;
};


int Participacion::getId()
{
    return this -> id;
}

void Participacion::setId(int id)
{
    this -> id = id;
}

DtTimeStamp Participacion::getFecha()
{
    return this -> fecha;    
}

void Participacion::setFecha(DtTimeStamp fecha)
{
    this -> fecha = fecha;
}

std::string Participacion::getMensaje()
{
    return this -> mensaje;
}

void Participacion::setMensaje(std::string mensaje)
{
    this -> mensaje = mensaje;
}

Participacion* Participacion::getResponde()
{
    return this -> responde;
}

void Participacion::setResponde(Participacion* responde)
{
    this -> responde = responde;   
}

Perfil* Participacion::getPerfil()
{
    return this -> perfil;
}

void Participacion::setPerfil(Perfil* perfil)
{
    this -> perfil = perfil;
}