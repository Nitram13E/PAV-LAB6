#ifndef ASISTEENVIVO
#define ASISTEENVIVO

class Estudiante;

#include "../../DataTypes/header/DtTimeStamp.h"
#include "Estudiante.h"

class AsisteEnVivo
{
    private:
        DtTimeStamp inicio;
        DtTimeStamp fin;
        Estudiante * estudiante;
        
    public:
        AsisteEnVivo();
        AsisteEnVivo(DtTimeStamp, DtTimeStamp);
        ~AsisteEnVivo();

        void setInicio(DtTimeStamp);
        DtTimeStamp getInicio(); 

        void setFin(DtTimeStamp);
        DtTimeStamp getFin(); 

        void setEstudiante(Estudiante*);
        Estudiante* getEstudiante();
        
};

#endif
