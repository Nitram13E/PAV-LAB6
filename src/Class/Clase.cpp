#include "header/Clase.h"
#include "header/Sesion.h"

int Clase::idActual = 0;//Inicializa la variable id generada por el sistema

Clase::Clase(){}

Clase::Clase(std::string nombre, DtTimeStamp inicio, DtTimeStamp* fin, std::string rutavideo)
{
    this -> id = idActual;
    this -> nombre = nombre;
    this -> inicio = inicio;
    this -> fin = fin;
    this -> rutavideo = rutavideo;

    this -> incrementarIdActual();
}

Clase::~Clase()
{
    //Borrando participaciones de Clase
    std::list<Participacion*>::iterator itP;
    std::list<Participacion*> p = this -> participaciones;
    
    for(itP = p.begin(); itP != p.end(); itP++)
    {
        delete (*itP);
    }

    //Borrando AsisteVivo de Clase
    std::list<AsisteVivo*>::iterator itA;
    std::list<AsisteVivo*> a = this -> asisteVivo;
    for(itA = a.begin(); itA != a.end(); itA++)
    {
        delete (*itA);
    }
}

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

DtTimeStamp* Clase::getFin()
{
    return this -> fin;
}

void Clase::setFin(DtTimeStamp* fin)
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

bool Clase::asisteEstudiante()
{
    Sesion* sesion = Sesion::getInstancia();

    Estudiante * estudiante = dynamic_cast<Estudiante*>(sesion -> getPerfil());

    std::list<AsisteVivo*>::iterator it = this -> asisteVivo.begin();

    while ((it != this -> asisteVivo.end()) && ((*it) -> getEstudiante() -> getEmail() != estudiante -> getEmail())) it++;

    // Si encontro al estudiante siempre va a ser distinto de end ya que se corta el while
    if ((it != this -> asisteVivo.end()) && (*it) -> getFin() == NULL) return true;

    return false;
}

bool Clase::enVivo()
{
    if(this -> fin == NULL) return true;

    return false;
}