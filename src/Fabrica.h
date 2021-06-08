#ifndef FABRICA
#define FABRICA

#include "Interfaces/IAltaAsignatura.h"
#include "Interfaces/IAltaUsuario.h"
#include "Interfaces/IAsignacionDocenteAsignatura.h"
#include "Interfaces/IAsistenciaClaseVivo.h"
#include "Interfaces/IEliminarAsignatura.h"
#include "Interfaces/IInscripcionAsignaturas.h"
#include "Interfaces/IListadoClase.h"

class Fabrica{
    private: 
        static Fabrica* instancia;
        Fabrica();
    public:
        static Fabrica* getInstancia();
        IAltaAsignatura* getIAltaAsignatura();
        IAltaUsuario* getIAltaUsuario();
        IAsignacionDocenteAsignatura* getIAsignacionDocenteAsignatura();
        IAsistenciaClaseVivo* getIAsistenciaClaseVivo();
        IEliminarAsignatura* getIEliminarAsignatura();
        IiniciarSesion* getIiniciarSesion();
        IinicioClase* getIinicioClase();
        IInscripcionesAsignaturas* getIInscripcionesAsignaturas();
        IListadoClases* getIListadoClases();        
        ~Fabrica();
    
};

#endif