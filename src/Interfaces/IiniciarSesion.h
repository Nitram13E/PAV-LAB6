#ifndef I_INICIARSESION
#define I_INICIARSESION

#include <string>

class IiniciarSesion
{
    public:
        virtual void ingresarEmail(std::string email) = 0;
        virtual bool validarContrasenia(std::string password) = 0;
        virtual void iniciarSesion() = 0;
};

#endif