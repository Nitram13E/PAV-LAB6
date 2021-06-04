/*Tendria que ingresar como Estudiante para acceder al Controlador
*/
#include "header/CAsistenciaClaseVivo.h"

CAsistenciaClaseVivo::CAsistenciaClaseVivo(){}
CAsistenciaClaseVivo::~CAsistenciaClaseVivo(){}

std::list<std::string> CAsistenciaClaseVivo::asignaturasInscriptos()
{
    std::list<Asignatura *> lista = this -> estudiante->getAsignaturas();

    for(std::list<Asignatura *>::iterator it = lista.begin(); it != lista.end(); ++it)
    {
        std::cout << *it << std::endl; //TENGO QUE HACER LA SOBRECARGA PARA IMPRIMIR LAS ASIGNATURAS
    }
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
    this -> idClase =id;

    DtAsistir* datos = new DtAsistir(this -> codAsig, this -> idClase);

    return datos;
}

void CAsistenciaClaseVivo::asistirClaseVivo()
{

}

void CAsistenciaClaseVivo::cancelar()
{

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