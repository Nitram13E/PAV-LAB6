#ifndef C_ENVIOMENSAJE
#define C_ENVIOMENSAJE

#include "../DataTypes/header/DtParticipacion.h"

#include <list>

class CEnvioMensaje
{
    private:
        DtParticipacion * participacion;

    public:
        CEnvioMensaje();
        ~CEnvioMensaje();

        std::list<int> clasesOnlineAsistiendo();

        std::list<DtParticipacion*> selectClase(int id);

        void responder(int idP);

        void ingresarTexto(std::string txt);

        void enviarMensaje();

        void cancelar();
};

#endif