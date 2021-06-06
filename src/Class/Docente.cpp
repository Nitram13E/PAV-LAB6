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

void Docente::addRol(Rol* rol)
{
    this -> roles.push_back(rol);
}
std::list<Rol*> Docente::getRoles()
{
    return this -> roles;
}
std::list<std::string> Docente::listarAsignaturas(){
    std::list<Rol*>::iterator it;
    std::list<std::string> list;
    std::string cod;
    for(it = roles.begin(); it != roles.end(); ++it){
        cod = (*it)->getCodigoAsignatura();
        list.push_back(cod);
    }
return list;
}