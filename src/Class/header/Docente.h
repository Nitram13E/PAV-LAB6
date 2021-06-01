#ifndef DOCENTE 
#define DOCENTE

class Rol;

#include "Perfil.h"
#include "Rol.h"

#include <list>
#include <iterator>

class Docente : public Perfil
{
    private:
        std::string instituto;

        std::list<Rol*> roles;

    public:
        Docente();
        Docente(std::string, std::string, std::string, std::string, std::string);
        ~Docente();

        void setInstituto(std::string);
        std::string getInstituto();

        DtPerfil* getDtPerfil();
};

#endif 