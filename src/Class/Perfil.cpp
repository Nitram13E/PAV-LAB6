#include "header/Perfil.h"

Perfil::Perfil(){}

Perfil::Perfil(std::string nombre, std::string imagenURL, std::string email, std::string password)
{
    this -> nombre = nombre;
    this -> imagenURL = imagenURL;
    this -> email = email;
    this -> password = password;
}

Perfil::~Perfil(){}

void Perfil::setNombre(std::string nombre)
{
    this -> nombre = nombre;
}

std::string Perfil::getNombre()
{
    return this -> nombre;
}

void Perfil::setImagenURL(std::string imagenURL)
{
    this -> imagenURL = imagenURL;
}
std::string Perfil::getImagenURL()
{
    return this -> imagenURL;
}

void Perfil::setEmail(std::string email)
{
    this -> email = email;
}
std::string Perfil::getEmail()
{
    return this -> email;
}

void Perfil::setPassword(std::string password)
{
    this->password = password;
}

std::string Perfil::getPassword()
{
    return this -> password;
}
