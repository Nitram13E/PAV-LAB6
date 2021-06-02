#ifndef ESTUDIANTE
#define ESTUDIANTE

#include "Perfil.h"
#include "Asignatura.h"

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