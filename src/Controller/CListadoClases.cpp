#include "header/CListadoClases.h"
CListadoClases::CListadoClases(){}
CListadoClases::~CListadoClases(){}

std::list<std::string> CListadoClases::asignaturasAsignadas(){
    Sesion* session = Sesion::getInstancia();
    Perfil * p = session->getPerfil();
    if(session->getTipoPerfil() == DOCENTE){
        try{
            Docente * d = dynamic_cast<Docente*>(p);
            if(d != NULL){
                std::list<std::string> lista = d->asignaturas();
                return lista;
            }else{
                throw std::invalid_argument("No se pudo listar las asignaturas asignadas");
            }
        }catch(std::invalid_argument& error){
            std::cout << error.what() << std::endl;
        }
    }
}
std::list<DtInfoClase> CListadoClases::selectAsignatura(std::string codigoAsignatura){
    


}

