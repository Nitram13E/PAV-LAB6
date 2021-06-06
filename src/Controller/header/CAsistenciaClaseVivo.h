#ifndef C_ASISTENCIACLASEVIVO
#define C_ASISTENCIACLASEVIVO

#include "../../Interfaces/IAsistenciaClaseVivo.h"
#include "../../Class/header/Estudiante.h"

#include <list>

class CAsistenciaClaseVivo : public IAsistenciaClaseVivo
{
    private:
        std::string codAsig;
        int idClase;
        Estudiante* estudiante;

    public:
        CAsistenciaClaseVivo();
        ~CAsistenciaClaseVivo();

        std::list<std::string> asignaturasInscriptos();

        std::list<int> clasesOnlineDisponibles(std::string);

<<<<<<< HEAD:src/Controller/header/CAsistenciaClaseVivo.h
        DtAsistir* selectClase(int);
=======
        DtAsistir selectClase(int);
>>>>>>> ce5ce4dbba904188590ace7bc9d4d0d95e49a9f5:src/Controller/CAsistenciaClaseVivo.h

        void asistirClaseVivo();

        void cancelar();

<<<<<<< HEAD:src/Controller/header/CAsistenciaClaseVivo.h
        bool esEstudiante(std::string);

=======
>>>>>>> ce5ce4dbba904188590ace7bc9d4d0d95e49a9f5:src/Controller/CAsistenciaClaseVivo.h
};

#endif