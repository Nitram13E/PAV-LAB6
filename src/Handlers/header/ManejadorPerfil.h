#ifndef MANEJADORPERFIL
#define MANEJADORPERFIL

#include "../../Class/header/Perfil.h"

#include <map>
#include <list>
#include <iterator>

class ManejadorPerfil
{
    private:
        static ManejadorPerfil* instancia;
        std::map<std::string, Perfil*> perfiles;
        ManejadorPerfil();

    public:
        static ManejadorPerfil* getInstancia();
        ~ManejadorPerfil();
        
        Perfil* buscarPerfil(std::string);
        void addPerfil(Perfil*);
        bool existePerfil(std::string);
        void removePerfil(std::string);
        std::map<std::string, Perfil*> getPerfiles();
        std::list<Perfil*> listarPerfiles();
};

#endif