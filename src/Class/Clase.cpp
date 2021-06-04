#include "header/Clase.h"

int Clase::idActual = 0;//Inicializa la variable id generada por el sistema

Clase::Clase(){}

Clase::Clase(std::string nombre, DtTimeStamp inicio, DtTimeStamp fin, std::string rutavideo)
{
    this -> id = idActual;
    this -> nombre = nombre;
    this -> inicio = inicio;
    this -> fin = fin;
    this -> rutavideo = rutavideo;
    
    this -> incrementarIdActual();
}

Clase::~Clase(){}

void Clase::incrementarIdActual()
{
    this -> idActual++;
}

int Clase::getIdActual()
{
    return Clase::idActual;
}

int Clase::getID()
{
    return this -> id;
}

std::string Clase::getNombre()
{
    return this -> nombre;
}
void Clase::setNombre(std::string nombre)
{
    this -> nombre = nombre;
}

DtTimeStamp Clase::getInicio()
{
    return this -> inicio;
}

void Clase::setInicio(DtTimeStamp inicio)
{ 
    this -> inicio = inicio;
}

DtTimeStamp Clase::getFin()
{
    return this -> fin;
}

void Clase::setFin(DtTimeStamp fin)
{
    this -> fin = fin;
}

std::string Clase::getRutaVideo()
{
    return this -> rutavideo;
}
void Clase::setRutaVideo(std::string rutavideo)
{
    this -> rutavideo = rutavideo;
}


void Clase::addDocentes(Docente* docente)
{
    this -> docentes.push_back(docente);
}

std::list<Docente*> Clase::getDocentes()
{
    return this -> docentes;
}

void Clase::addParticipacion(Participacion* participacion)
{
    this -> participaciones.push_back(participacion);
}

std::list<Participacion*> Clase::getParticipaciones()
{
    return this -> participaciones;
}

void Clase::addAsisteEnVivo(AsisteVivo* asistencia)
{
    this -> asisteVivo.push_back(asistencia);
}

std::list<AsisteVivo*> Clase::getAsisteVivo()
{
    return this -> asisteVivo;
}

void Clase::addAsisteDiferido(AsisteDiferido* asistencia)
{
    this -> asisteDiferido.push_back(asistencia);
}
std::list<AsisteDiferido*> Clase::getAsisteDiferido()
{
    return this -> asisteDiferido;
}