#ifndef ASISTEVIVO
#define ASISTEVIVO

class Estudiante;

#include "../../DataTypes/header/DtTimeStamp.h"
#include "Estudiante.h"

class AsisteVivo
{
    private:
        DtTimeStamp inicio;
        DtTimeStamp * fin;
        Estudiante * estudiante;
        
    public:
        AsisteVivo();
        AsisteVivo(DtTimeStamp, DtTimeStamp*);
        ~AsisteVivo();

        void setInicio(DtTimeStamp);
        DtTimeStamp getInicio(); 

        void setFin(DtTimeStamp*);
        DtTimeStamp* getFin(); 

        void setEstudiante(Estudiante*);
        Estudiante* getEstudiante();
        
};

#endif
