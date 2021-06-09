#include "header/CListadoClases.h"
#include "../Class/header/Sesion.h"
#include "../Handlers/header/ManejadorAsignatura.h"

CListadoClases::CListadoClases(){}
CListadoClases::~CListadoClases(){}

std::list<std::string> CListadoClases::asignaturasAsignadas()
{
    Sesion* session = Sesion::getInstancia();

    Perfil * p = session -> getPerfil();

    std::list<std::string> lista;

    if(session -> getTipoPerfil() == DOCENTE)
    {
        try
        {
            Docente * d = dynamic_cast<Docente*>(p);
            if(d != NULL)
            {
                 lista = d->listarAsignaturas();
                return lista;
            }
            else
            {
                throw std::invalid_argument("No se pudo listar las asignaturas asignadas");
            }
        }
        catch(std::invalid_argument& error)
        {
            std::cout << error.what() << std::endl;
        }
    }
    return lista;
}
std::list<DtInfoClase> CListadoClases::selectAsignatura(std::string codigoAsignatura)
{
    ManejadorAsignatura *ma = ManejadorAsignatura::getInstancia();

    std::list<DtInfoClase> list;
    
    Asignatura * a = ma -> buscarAsignatura(codigoAsignatura);

    list = a -> getDtInfoClase();

    return list;
}