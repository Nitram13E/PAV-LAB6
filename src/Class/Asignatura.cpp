#include "header/Asignatura.h"
#include "header/Sesion.h"

Asignatura::Asignatura(){}

Asignatura::Asignatura(std::string codigo, std::string nombre, DtInstanciaClase* tipo)
{
    this -> codigo = codigo;
    this -> nombre = nombre;
    this -> tipoClases = tipo;
}

Asignatura::~Asignatura()
{
    ManejadorClase * mc = ManejadorClase::getInstancia();
    
    std::list<Clase*>::iterator it;

    for(it = this -> clases.begin(); it != this -> clases.end(); it++) 
    {
        mc -> removeClase((*it) -> getID());
    }
}

std::string Asignatura::getCodigo()
{
    return this -> codigo;
}

void Asignatura::setCodigo(std::string codigo)
{
    this -> codigo = codigo;
}

std::string Asignatura::getNombre()
{
    return this -> nombre;
}

void Asignatura::setNombre(std::string nombre)
{
    this -> nombre = nombre;
}

DtInstanciaClase* Asignatura::getTipoClases()
{
    return this -> tipoClases;
}

void Asignatura::setTipoClases(DtInstanciaClase* tipo)
{
    this -> tipoClases = tipo;
}

void Asignatura::addClases(Clase* clase)
{
    this -> clases.push_back(clase);
}
std::list<Clase*> Asignatura::getClases()
{
    return this -> clases;
}
std::list<DtInfoClase> Asignatura::getDtInfoClase()
{
    std::list<DtInfoClase> lista;

    std::list<Clase*>::iterator it;

    for(it = this->clases.begin(); it != this->clases.end();++it)
    {
        DtInfoClase infoClase = (*it) -> getDtInfoClase();
        lista.push_back(infoClase);
    }
    return lista;
}

std::list<int> Asignatura::listarIdAsisteVivo()
{
    Sesion * sesion = Sesion::getInstancia();

    std::list<int> lista;

    // Si es estudiante se fija en si esta asistiendo(miramos en la coleccion AsisteVivo dentro de clase)
    if(sesion -> getTipoPerfil() == ESTUDIANTE)
    {
        std::list<Clase*>::iterator it;

        for(it = this -> clases.begin(); it != this -> clases.end(); it++)
        {
            if((*it) -> asisteEstudiante())
            {
                lista.push_back((*it) -> getID());
            }
        }
    }
    else if(sesion -> getTipoPerfil() == DOCENTE)// Si es un docente se fija si esta dictando una clase en vivo, para eso verificamos si la clase sigue estando en vivo(fin != NULL)
    {
        std::list<Clase*>::iterator it;

        for(it = this -> clases.begin(); it != this -> clases.end(); it++)
        {
            if((*it) -> enVivo())
            {
                lista.push_back((*it) -> getID());
            }
        }
    }
    
    return lista;
}