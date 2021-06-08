#include "Fabrica.h"
#include "Controller/Header/CAltaAsignatura.h"
#include "Controller/Header/CAltaUsuario.h"
#include "Controller/Header/CAsignacionDocenteAsignatura.h"
#include "Controller/Header/CAsistenciaClaseVivo.h"
#include "Controller/Header/CELiminarAsignatura.h"
#include "Controller/Header/CEnvioMensaje.h"
#include "Controller/Header/CIniciarSesion.h"
#include "Controller/Header/CInicioClase.h"
#include "Controller/Header/CinscripcionAsignaturas.h"
#include "Controller/Header/CListadoClases.h"

Fabrica* Fabrica::instancia=NULL;

Fabrica::Fabrica(){}

Fabrica* Fabrica::getInstancia(){
    if (instancia==NULL)
        instancia= new Fabrica();
    return instancia;
}

IAltaAsignatura* Fabrica::getIAltaAsignatura(){
    return new CAltaAsignatura();
}

IAltaUsuario* Fabrica::getIAltaUsuario(){
    return new CAltaUsuario();
}

IAsignacionDocenteAsignatura* Fabrica::getIAsignacionDocenteAsignatura(){
    return new CAsignacionDocenteAsignatura();

}

IAsistenciaClaseVivo* Fabrica::getIAsistenciaClaseVivo(){
    return new CAsistenciaClaseVivo();
}

IEliminarAsignatura* Fabrica::getIEliminarAsignatura(){
    return new CEliminarAsignatura();
}

IiniciarSesion* Fabrica::getIiniciarSesion(){
    return new CIniciarSesion();
}

IinicioClase* Fabrica::getIinicioClase(){
    return new CInicioClase();
}

IInscripcionesAsignaturas* Fabrica::getIInscripcionesAsignaturas(){
    return new CInscripcionAsignaturas();
}


IListadoClases* Fabrica::getIListadoClases(){
    return new CListadoClases();
}
    
Fabrica::~Fabrica(){}