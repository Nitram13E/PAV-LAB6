#ifndef C_INICIOCLASE
#define C_INICIOCLASE

#include "../DataTypes/header/DtIniciarClase.h"
#include "../DataTypes/header/DtPerfil.h"

#include <list>

class CInicioClase
{
    private:
        DtIniciarClase inicioClase;
        std::list<std::string> habilitados;
        
    public:
        CInicioClase();
        ~CInicioClase();

        void ingresarDatosPerfil(DtPerfil);
        void ingresarEstudiante(std::string);
        void ingresarDocente(std::string);

        void altaUsuario();
        void cancelar();
};

#endif