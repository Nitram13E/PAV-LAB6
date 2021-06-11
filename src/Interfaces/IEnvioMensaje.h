#ifndef ICENVIOMENSAJE 
#define ICENVIOMENSAJE

#include "../DataTypes/header/DtParticipacion.h"
#include <list>


class IEnvioMensaje 
{
      public:
            virtual std::list<int> clasesOnlineAsistiendo() = 0;
            virtual std::list<DtParticipacion*> selectClase(int) = 0;
            virtual void responder(int) = 0;
            virtual void ingresarTexto(std::string) = 0;
            virtual void enviarMensaje() = 0;
            virtual void cancelar() = 0;
};


#endif