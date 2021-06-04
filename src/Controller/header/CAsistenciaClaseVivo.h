#ifndef C_ASISTENCIACLASEVIVO
#define C_ASISTENCIACLASEVIVO

#include "../../DataTypes/header/DtAsistir.h"
#include <list>

class CAsistenciaClaseVivo
{
    private:
        std::string cod;
        std::string id;

    public:
        CAsistenciaClaseVivo();
        ~CAsistenciaClaseVivo();

        std::list<std::string> asignaturasInscriptos();

        std::list<int> clasesOnlineDisponibles(std::string);

        DtAsistir selectClase(int);

        void asistirClaseVivo();

        void cancelar();

};

#endif