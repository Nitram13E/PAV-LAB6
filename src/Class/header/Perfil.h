#ifndef PERFIL
#define PERFIL 

#include "../../DataTypes/header/DtPerfil.h"

#include <iostream>
#include <string>

class Perfil
{
    private:
        std::string nombre; 
        std::string imagenURL;
        std::string email;
        std::string password;
        
    public:

        Perfil();
        Perfil(std::string, std::string, std::string, std::string);
        ~Perfil();

        void setNombre(std::string);
        std::string getNombre();
        
        void setImagenURL(std::string);
        std::string getImagenURL();
    
        void setEmail(std::string);
        std::string getEmail();
        
        void setPassword(std::string);
        std::string getPassword();

        virtual DtPerfil* getDtPerfil() = 0;
        
    };

#endif 