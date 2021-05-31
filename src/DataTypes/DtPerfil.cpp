#include "header/DtPerfil.h"



DtPerfil::DtPerfil(){}

DtPerfil::DtPerfil(std::string nombre, std::string imagenURL, std::string email, std::string pass)
{
    this -> nombre = nombre;
    this -> imagenUrl = imagenURL;
    this -> email = email;
    this -> password = pass;
}


DtPerfil::~DtPerfil(){}

std::string DtPerfil::getNombre()
{
    return this -> nombre;
}

std::string DtPerfil::getImagenURL()
{
    return this -> imagenUrl;
}

std::string DtPerfil::getEmail()
{
    return this -> email;   
}

std::string DtPerfil::getPassword()
{
    return this -> password;
}