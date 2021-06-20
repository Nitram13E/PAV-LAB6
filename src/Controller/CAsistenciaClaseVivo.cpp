#include "header/CAsistenciaClaseVivo.h"
#include "../Handlers/header/ManejadorPerfil.h"
#include "../Handlers/header/ManejadorClase.h"
#include "../Handlers/header/ManejadorAsignatura.h"
#include "../Class/header/Sesion.h"
#include <ctime>

CAsistenciaClaseVivo::CAsistenciaClaseVivo(){}
CAsistenciaClaseVivo::~CAsistenciaClaseVivo(){}

//Lista las asignaturas que esta inscripto el estudiante
std::list<std::string> CAsistenciaClaseVivo::asignaturasInscriptos()
{
    Sesion* session = Sesion::getInstancia();
    
    if(session -> getTipoPerfil() != ESTUDIANTE) throw std::invalid_argument("El usuario no es un estudiante.");

    Estudiante* est = dynamic_cast<Estudiante*>(session -> getPerfil());
    
    if(est != NULL)
    {
        this -> estudiante = est;
    }

    std::list<std::string> lista;

    std::list<Asignatura *> asig = this -> estudiante-> getAsignaturas();

    for(std::list<Asignatura *>::iterator it = asig.begin(); it != asig.end(); ++it)
    {
        lista.push_back((*it)->getCodigo());
    }

    return lista;
}

//Lista las clases que no terminaron de la asignatura anteriormente seleccionada
std::list<int> CAsistenciaClaseVivo::clasesOnlineDisponibles(std::string codigoAsig)
{
    this -> codAsig = codigoAsig;

    std::list<int> lista;
    ManejadorAsignatura* ma = ManejadorAsignatura::getInstancia();

    Asignatura* asig = ma -> buscarAsignatura(codigoAsig);
    std::list<Clase *> clases = asig -> getClases();

    for(std::list<Clase *>::iterator it = clases.begin(); it != clases.end(); ++it)
    {
        if((*it) -> enVivo())
        {
            lista.push_back((*it) -> getID());
        }
    }

    return lista;
}

//Devuelve los datos ingresados, codigo de Asignatura e idClase
DtAsistir* CAsistenciaClaseVivo::selectClase(int id)
{
    this -> idClase = id;

   DtAsistir* datos = new DtAsistir(this -> codAsig, this -> idClase);

    return datos;
}

//Se crea el objeto AsisteVivo y se guarda en la clase
void CAsistenciaClaseVivo::asistirClaseVivo()
{
    ManejadorClase* mc = ManejadorClase::getInstancia();
    Clase* clase = mc -> buscarClase(this -> idClase);

    std::time_t tt;
    DtTimeStamp iTime = DtTimeStamp(tt);

    AsisteVivo* av = new AsisteVivo(iTime, NULL);
    av -> setEstudiante(this -> estudiante);

    clase -> addAsisteEnVivo(av);
}

void CAsistenciaClaseVivo::cancelar()
{
    delete this -> estudiante;
}