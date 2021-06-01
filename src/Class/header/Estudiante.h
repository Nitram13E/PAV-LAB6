#ifndef ESTUDIANTE
#define ESTUDIANTE

#include "Perfil.h"
#include "Asignatura.h"

class Estudiante: Perfil
{
    private: 
        std::string documento;
        std::list<Asignatura> asignaturas;
        
    public:
        Estudiante();
        Estudiante(std::string, std::string, std::string, std::string, std::string);
        ~Estudiante();

        void setDocumento(std::string);
        std::string getDocumento();

        DtPerfil* getDtPerfil();
};

#endif 