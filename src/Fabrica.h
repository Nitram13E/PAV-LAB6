#ifndef FABRICA
#define FABRICA

#include "Interfaces/IAltaAsignatura.h"
#include "Interfaces/IAltaUsuario.h"
#include "Interfaces/IAsistenciaClaseVivo.h"
#include "Interfaces/IInscripcionAsignaturas.h"

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
    return new ControladorAltaMozo();
}

IAsignacionDocenteAsignatura* Fabrica::getIAsignacionDocenteAsignatura(){

    return new ControladorAltaMesa();

}

IAsistenciaClaseVivo* Fabrica::getIAsistenciaClaseVivo(){
    return new ControladorIniciarVenta();
}

IEliminarAsignatura* Fabrica::getIEliminarAsignatura(){
    return new ControladorAgregarProducto();
}

IiniciarSesion* Fabrica::getIiniciarSesion(){
    return new ControladorQuitarProducto();
}

IinicioClase* Fabrica::getIinicioClase(){
    return new ControladorFacturacion();
}

IInscripcionesAsignaturas* Fabrica::getIInscripcionesAsignaturas(){
    return new ControladorInformacionProducto();
}


IListadoClases* Fabrica::getIListadoClases(){
    return new ControladorBajaProducto();
}
    
Fabrica::~Fabrica(){}