#include "header/ManejadorPerfil.h"

ManejadorPerfil* ManejadorPerfil::instancia = NULL;

ManejadorPerfil::ManejadorPerfil(){}

ManejadorPerfil::~ManejadorPerfil(){}

ManejadorPerfil* ManejadorPerfil::getInstancia()
{
    if(instancia == NULL) instancia = new ManejadorPerfil();
    
    return instancia;
}

        
Perfil* ManejadorPerfil::buscarPerfil(std::string email)
{
    std::map<std::string,Perfil*>::iterator it = this -> perfiles.find(email);
    
    if(it == this->perfiles.end()) return NULL;
    
    return it -> second;
}

void ManejadorPerfil::addPerfil(Perfil* perfil)
{
    perfiles.insert(std::pair<std::string,Perfil*>(perfil -> getEmail(), perfil));
}

bool ManejadorPerfil::existePerfil(std::string mail)
{
    std::map<std::string,Perfil*>::iterator it = this -> perfiles.find(mail);

    return it != this -> perfiles.end();
}

void ManejadorPerfil::removePerfil(std::string mail)
{
    std::map<std::string,Perfil*>::iterator it = this -> perfiles.find(mail);
    this -> perfiles.erase(it);
}

std::list<Perfil*> ManejadorPerfil::listarPerfiles()
{
    std::list<Perfil*> lista;
    
    for(std::map<std::string, Perfil*>::iterator it = this -> perfiles.begin(); it != perfiles.end(); ++it)
    {
       lista.push_back(it -> second); 
    }

    return lista;
}
