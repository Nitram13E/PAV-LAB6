#include "Factory.h"
#include "Controller/header/CAltaAsignatura.h"
#include "Controller/header/CAltaUsuario.h"
#include "Controller/header/CAsignacionDocenteAsignatura.h"
#include "Controller/header/CAsistenciaClaseVivo.h"
#include "Controller/header/CEliminarAsignatura.h"
#include "Controller/header/CIniciarSesion.h"
#include "Controller/header/CInicioClase.h"
#include "Controller/header/CInscripcionAsignaturas.h"
#include "Controller/header/CListadoClases.h"
#include "Controller/header/CEnvioMensaje.h"

Factory * Factory::instancia = NULL;

Factory::Factory(){}

Factory* Factory::getInstancia()
{
    if(instancia == NULL)
    {
        instancia = new Factory();
    }
    return instancia;
}

IAltaAsignatura* Factory::getIAltaAsignatura(){return new CAltaAsignatura();}

IAltaUsuario* Factory::getIAltaUsuario(){return new CAltaUsuario();}

//IAsignacionDocenteAsignatura* Factory::getIAsignacionDocenteAsignatura(){return new CAsignacionDocenteAsignatura();}

IAsistenciaClaseVivo* Factory::getIAsistenciaClaseVivo(){return new CAsistenciaClaseVivo();}

//IEliminarAsignatura* Factory::getIEliminarAsignatura(){return new CEliminarAsignatura();}

IiniciarSesion* Factory::getIiniciarSesion(){return new CIniciarSesion();}

//IinicioClase* Factory::getIinicioClase(){return new CInicioClase();}

IInscripcionesAsignaturas* Factory::getInscripcionAsignaturas(){return new CInscripcionAsignaturas();}

IEnvioMensaje* getIEnvioMensaje(){return new CEnvioMensaje();}