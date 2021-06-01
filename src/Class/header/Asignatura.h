#ifndef ASIGNATURA
#define ASIGNATURA

class Clase;

#include "Clase.h"
#include <list>

class Asignatura
{
    private:
        std::string codigo;
        std::string nombre;
        std::list<Clase*> clases;
    
    public:
        Asignatura();
        Asignatura(std::string, std::string);
        ~Asignatura();
        
        std::string getCodigo();
        void setCodigo(std::string);

        std::string getNombre();
        void setNombre(std::string);
};

#endif