#ifndef DTPERFIL
#define DTPERFIL

#include <iostream>

class DtPerfil
{
    private:
        std::string nombre;
        std::string imagenUrl;
        std::string email;
        std::string password;
        
    public:

        DtPerfil();
        DtPerfil(std::string, std::string, std::string, std::string);
        ~DtPerfil();

        std::string getNombre();

        std::string getImagenURL();
        
        std::string getEmail();
        
        std::string getPassword();
};

#endif