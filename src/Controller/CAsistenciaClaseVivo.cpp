/*Tendria que ingresar como Estudiante para acceder al Controlador
*/
#include "header/CAsistenciaClaseVivo.h"
#include "../Handlers/header/ManejadorPerfil.h"
#include "../Handlers/header/ManejadorClase.h"
#include "../Handlers/header/ManejadorAsignatura.h"
#include<ctime> 

CAsistenciaClaseVivo::CAsistenciaClaseVivo(){}
CAsistenciaClaseVivo::~CAsistenciaClaseVivo(){}

std::list<std::string> CAsistenciaClaseVivo::asignaturasInscriptos()
{
    std::list<std::string> lista;

    std::list<Asignatura *> asig = this -> estudiante->getAsignaturas();

    for(std::list<Asignatura *>::iterator it = asig.begin(); it != asig.end(); ++it)
    {
        lista.push_back((*it)->getCodigo());
    }

    return lista;
}

std::list<int> CAsistenciaClaseVivo::clasesOnlineDisponibles(std::string codigoAsig)
{
    this -> codAsig = codigoAsig;

    std::list<int> lista;
    ManejadorAsignatura* ma = ManejadorAsignatura::getInstancia();

    Asignatura* asig = ma -> buscarAsignatura(codigoAsig);
    std::list<Clase *> clases = asig->getClases();

    for(std::list<Clase *>::iterator it = clases.begin(); it != clases.end(); ++it)
    {
        lista.push_back((*it)->getID());
    }

    return lista;
}

DtAsistir* CAsistenciaClaseVivo::selectClase(int id)
{
    this -> idClase = id;

   DtAsistir* datos = new DtAsistir(this -> codAsig, this -> idClase);

    return datos;
}

void CAsistenciaClaseVivo::asistirClaseVivo()
{
    ManejadorClase* mc = ManejadorClase::getInstancia();
    Clase* clase = mc -> buscarClase(this -> idClase);

    std::time_t tt;
    time(&tt); //Se usa para encontrar la hora actual
    struct tm * time = localtime(&tt);
    DtFecha fecha = DtFecha(time -> tm_mday, time -> tm_mon, time -> tm_year);
    DtTimeStamp iTime = DtTimeStamp(fecha, time -> tm_hour, time -> tm_min, time ->tm_sec); 

    AsisteVivo* av = new AsisteVivo(iTime, NULL);
    av -> setEstudiante(this -> estudiante);

    clase -> addAsisteEnVivo(av);  
}

void CAsistenciaClaseVivo::cancelar()
{
    delete this -> estudiante;
}

bool CAsistenciaClaseVivo::esEstudiante(std::string mail)
{
    ManejadorPerfil* mp = ManejadorPerfil::getInstancia();
    Perfil* perf = mp -> buscarPerfil(mail);

    Estudiante* est = dynamic_cast<Estudiante *>(perf);
    if(est != NULL){
        this -> estudiante = est;
        return true;
    } else {
        return false;
    }
}