#ifndef FACTORY_H
#define FACTORY_H

#include "Interfaces/IAltaAsignatura.h"
#include "Interfaces/IAltaUsuario.h"
#include "Interfaces/IAsignacionDocenteAsignatura.h"
#include "Interfaces/IAsistenciaClaseVivo.h"
#include "Interfaces/IEliminarAsignatura.h"
#include "Interfaces/IEnvioMensaje.h"
#include "Interfaces/IiniciarSesion.h"
#include "Interfaces/IinicioClase.h"
#include "Interfaces/IInscripcionAsignaturas.h"
#include "Interfaces/IListadoClase.h"

class Factory
{
    public: 
        static Factory * instancia;
        Factory();
    public:
        ~Factory();

        static Factory* getInstancia();

        IAltaAsignatura* getIAltaAsignatura();
        IAltaUsuario* getIAltaUsuario();
        IAsignacionDocenteAsignatura* getIAsignacionDocenteAsignatura();
        IAsistenciaClaseVivo* getIAsistenciaClaseVivo();
        IEliminarAsignatura* getIEliminarAsignatura();
        IiniciarSesion* getIiniciarSesion();
        IEnvioMensaje* getIEnvioMensaje();
        IinicioClase* getIinicioClase();
        IInscripcionesAsignaturas* getInscripcionAsignaturas();
        IListadoClases* getIListadoClase();
};

#endif