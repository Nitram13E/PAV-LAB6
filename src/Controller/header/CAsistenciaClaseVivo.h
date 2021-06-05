#ifndef C_ASISTENCIACLASEVIVO
#define C_ASISTENCIACLASEVIVO

#include "../../Interfaces/IAsistenciaClaseVivo.h"
#include "../../Class/header/Estudiante.h"

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

        DtAsistir* selectClase(int);

        void asistirClaseVivo();

        void cancelar();

        bool esEstudiante(std::string);  //La funcion aux la tengo que agregar a la interfaz Tambien?

};

#endif