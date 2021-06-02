#ifndef C_ALTAUSUARIO
#define C_ALTAUSUARIO

#include "../DataTypes/header/DtPerfil.h"
#include "../DataTypes/header/tipoPerfil.h"

class CAltaUsuario
{
    private: 
        DtPerfil datosUsuario;
        tipoPerfil tipo_perfil;
        std::string cedula;
        std::string instituto;
        
    public: 
        CAltaUsuario();
        ~CAltaUsuario();
        
        void ingresarDatosPerfil(DtPerfil);
        void ingresarEstudiante(std::string);
        void ingresarDocente(std::string);
        void altaUsuario();
        void cancelar();
};

#endif