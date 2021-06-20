#ifndef C_ALTAUSUARIO
#define C_ALTAUSUARIO

#include "../../Interfaces/IAltaUsuario.h"

class CAltaUsuario : public IAltaUsuario
{
    private: 
        DtPerfil datosUsuario;
        tipoPerfil tipo_perfil;
        std::string cedula;
        std::string instituto;
        
    public:
        CAltaUsuario();
        ~CAltaUsuario();
        
        void ingresarDatosPerfil(DtPerfil, tipoPerfil);
        void ingresarEstudiante(std::string);
        void ingresarDocente(std::string);
        void altaUsuario();
        void cancelar();

        void cargarDatos();
};

#endif