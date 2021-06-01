#include "header/Estudiante.h"

Estudiante::Estudiante(){}

Estudiante::Estudiante(std::string nombre, std::string imagenURL, std::string password, std::string email, std::string documento) : Perfil(nombre, imagenURL, email, password)
{   
    this -> documento = documento;
}
Estudiante::~Estudiante(){}

void Estudiante::setDocumento(std::string)
{
    this -> documento = documento;
}

std::string Estudiante::getDocumento()
{
    return this -> documento;
}

DtPerfil* Estudiante::getDtPerfil()
{
    DtPerfil * newDtPerfil = new DtPerfil;
    return newDtPerfil;
}