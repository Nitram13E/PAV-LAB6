#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

class Asignatura;

#include "Perfil.h"
#include "Asignatura.h"

#include <list>

class Estudiante: public Perfil
{
    private: 
        std::string documento;
        std::list<Asignatura*> asignaturas;
        
    public:
        Estudiante();
        Estudiante(std::string, std::string, std::string, std::string, std::string);
        ~Estudiante();

        void setDocumento(std::string);
        std::string getDocumento();

        void addAsignaturas(Asignatura*);
        std::list<Asignatura*> getAsignaturas();
};

#endif