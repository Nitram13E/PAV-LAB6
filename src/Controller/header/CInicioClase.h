#ifndef C_INICIOCLASE
#define C_INICIOCLASE

#include "../../Interfaces/IinicioClase.h"
#include "../../Class/header/Docente.h"
#include "../../Class/header/Estudiante.h"

#include <list>

class CInicioClase : public IinicioClase
{
    private:
        DtIniciarClase inicioClase;
        DtIniciarClaseFull * data;
        std::list<std::string> listaHabilitados;
        std::list<Estudiante*> listaEstudiantes;
        Docente* doc;
        tipoRol rol;

    public:
        CInicioClase();
        ~CInicioClase();

        std::list<std::string> asignaturasAsignadas();
        bool selectAsignatura(DtIniciarClase);
        std::list<std::string> inscriptosAsignatura();
        void habilitar(std::string);
        DtIniciarClaseFull* datosIngresados();

        void iniciarClase();
        void cancelar();

        void cargarDatos();
};

#endif