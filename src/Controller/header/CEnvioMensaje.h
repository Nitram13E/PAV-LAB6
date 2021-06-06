#ifndef C_ENVIOMENSAJE
#define C_ENVIOMENSAJE

#include "../../DataTypes/header/DtParticipacion.h"
#include "../../Handlers/header/ManejadorPerfil.h"
#include "../../Handlers/header/ManejadorClase.h"
#include "../../Class/header/Estudiante.h"
#include "../../Class/header/Sesion.h"

#include <list>

class CEnvioMensaje
{
    private:
        //DtParticipacion * participacion;
        int id_clase;
        int id_response;
        std::string txt;

    public:
        CEnvioMensaje();
        ~CEnvioMensaje();

        std::list<int> clasesOnlineAsistiendo(std::string);

        std::list<DtParticipacion*> selectClase(int);

        void responder(int);

        void ingresarTexto(std::string);

        void enviarMensaje();

        void cancelar();
};

std::list<DtParticipacion*> ctodtParticipacion(std::list<Participacion>);

#endif