#ifndef IASISTENCIACLASEVIVO
#define IASISTENCIACLASEVIVO

#include "../DataTypes/header/DtAsistir.h"
#include <list>

class IAsistenciaClaseVivo
{
    public:
        virtual std::list<std::string> asignaturasInscriptos() = 0;

        virtual std::list<int> clasesOnlineDisponibles(std::string) = 0;

        virtual DtAsistir selectClase(int) = 0;

        virtual void asistirClaseVivo() = 0;

        virtual void cancelar() = 0;
    };

#endif