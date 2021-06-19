#ifndef C_ENVIOMENSAJE
#define C_ENVIOMENSAJE

#include "../../Interfaces/IEnvioMensaje.h"
#include "../../DataTypes/header/DtParticipacion.h"
#include "../../Handlers/header/ManejadorPerfil.h"
#include "../../Handlers/header/ManejadorClase.h"
#include "../../Class/header/Estudiante.h"
#include "../../Class/header/Sesion.h"

#include <list>

class CEnvioMensaje : public IEnvioMensaje
{
    private:
        int id_clase;
        int id_response;
        std::string txt;

        DtParticipacion *ctodtParticipacion(Participacion*);

    public:
        CEnvioMensaje();
        ~CEnvioMensaje();

        std::list<int> clasesOnlineAsistiendo();

        std::list<DtParticipacion*> selectClase(int);

        void responder(int);

        void ingresarTexto(std::string);

        void enviarMensaje();

        void cancelar();
};

#endif