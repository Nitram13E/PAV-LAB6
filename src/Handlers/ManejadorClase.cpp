#include "header/ManejadorClase.h"

ManejadorClase* ManejadorClase::instancia = NULL;

ManejadorClase::ManejadorClase(){}

ManejadorClase::~ManejadorClase(){}

ManejadorClase* ManejadorClase::getInstancia()
{
    if(instancia == NULL) instancia = new ManejadorClase();

    return instancia;
}

Clase* ManejadorClase::buscarClase(int id)
{
    std::map<int, Clase*>::iterator it = this -> clases.find(id);
    return it -> second;
}

void ManejadorClase::addClase(Clase* clase)
{
    clases.insert(std::pair<int, Clase*>(clase -> getID(), clase));
}

bool ManejadorClase::existeClase(int id)
{
    std::map<int, Clase*>:: iterator it = this -> clases.find(id);

    return it != this -> clases.end();
}

void ManejadorClase::removeClase(int id)
{
    std::map<int, Clase*>::iterator it = this -> clases.find(id);
    this -> clases.erase(it);
}

std::list<Clase*> ManejadorClase::listarClases()
{
    std::list<Clase *> lista;
    
    for(std::map<int, Clase*>::iterator it = this -> clases.begin(); it != this -> clases.end(); ++it)
    {
        lista.push_back(it -> second);
    }

    return lista;
}