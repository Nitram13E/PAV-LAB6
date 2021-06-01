#include "header/Docente.h"

Docente::Docente(){}

Docente::Docente(std::string nombre, std::string imagenURL, std::string email, std::string password, std::string instituto) : Perfil(nombre, imagenURL, email, password)
{
    this -> instituto = instituto;
}

Docente::~Docente(){}

void Docente::setInstituto(std::string instituto)
{
    this -> instituto = instituto;
}

std::string Docente::getInstituto()
{
    return this -> instituto;
}

DtPerfil* Docente::getDtPerfil()
{
    DtPerfil * newDtPerfil = new DtPerfil;
    return newDtPerfil;
}
