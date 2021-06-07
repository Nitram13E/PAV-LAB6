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

    if(iterador == this->asignaturas.end()) return NULL;

    return iterador -> second;
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
    this -> asignaturas.erase(it);
}

std::list<Asignatura*> ManejadorAsignatura::listarAsignatura()
{
    std::list<Asignatura*> lista;
    
    for(std::map<std::string, Asignatura*>::iterator it = this -> asignaturas.begin(); it != asignaturas.end(); ++it)
    {
       lista.push_back(it -> second); 
    }

    return lista;
}