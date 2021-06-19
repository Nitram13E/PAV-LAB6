  
#include "header/ManejadorAsignatura.h"

ManejadorAsignatura* ManejadorAsignatura::instancia = NULL;

ManejadorAsignatura::ManejadorAsignatura(){}

ManejadorAsignatura::~ManejadorAsignatura(){}

ManejadorAsignatura* ManejadorAsignatura::getInstancia()
{
    if(instancia == NULL) instancia = new ManejadorAsignatura();

    return instancia;
}

Asignatura* ManejadorAsignatura::buscarAsignatura(std::string codigo)
{
    std::map<std::string,Asignatura*>::iterator iterador = this -> asignaturas.find(codigo);

    if(iterador != asignaturas.end())
    {
        return iterador -> second;
    }

    return NULL;
}

void ManejadorAsignatura::agregarAsignatura(Asignatura* asignatura)
{
    asignaturas.insert(std::pair<std::string, Asignatura*>(asignatura -> getCodigo(), asignatura));
}

bool ManejadorAsignatura::existeAsignatura(std::string codigo)
{
    std::map<std::string, Asignatura*>::iterator it = this -> asignaturas.find(codigo);
    return it != this -> asignaturas.end();
}

void ManejadorAsignatura::removeAsignatura(std::string codigo)
{
    std::map<std::string,Asignatura*>::iterator it = this -> asignaturas.find(codigo);
    Asignatura * asig = it -> second;
    this -> asignaturas.erase(it);
    delete asig;
}

std::list<std::string> ManejadorAsignatura::listarAsignatura()
{
    std::list<std::string> lista;
    
    for(std::map<std::string, Asignatura*>::iterator it = this -> asignaturas.begin(); it != asignaturas.end(); ++it)
    {
       lista.push_back(it -> first);
    }

    return lista;
}

std::map<std::string, Asignatura*> ManejadorAsignatura::listarMapAsignatura()
{
    return this -> asignaturas;
}