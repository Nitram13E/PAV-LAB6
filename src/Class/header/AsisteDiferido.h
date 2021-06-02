#ifndef ASISTEDIFERIDO
#define ASISTEDIFERIDO

class Estudiante;

#include "../../DataTypes/header/DtLog.h"
#include "Estudiante.h"

#include <list>

class AsisteDiferido
{
    private:
        std::list<DtLog*> logs;
        Estudiante * estudiante;
        
    public:
        AsisteDiferido();
        AsisteDiferido(Estudiante*);
        ~AsisteDiferido();

        void addLog(DtLog*);
        std::list<DtLog*> getLogs();

        Estudiante* getEstudiante();
        void setEstudiante(Estudiante*);
};

#endif