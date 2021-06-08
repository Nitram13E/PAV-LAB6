#ifndef C_INICIOCLASE
#define C_INICIOCLASE

#include "../../Interfaces/IinicioClase.h"

#include <list>

class CInicioClase : public IinicioClase
{
    private:
        DtIniciarClase inicioClase;
        std::string email;
        
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
};

#endif