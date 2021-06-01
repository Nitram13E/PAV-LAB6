#ifndef DTPARTICIPACION
#define DTPARTICIPACION

#include "DtTimeStamp.h"

class DtParticipacion
{
    private:

        int id;
        DtTimeStamp fecha;
        std::string mensaje;
        DtParticipacion * responde;
        
    public:

        DtParticipacion();
        DtParticipacion(int, DtTimeStamp, std::string, DtParticipacion*);
        ~DtParticipacion();
        
        int getId();

        DtTimeStamp getFecha();

        std::string getMensaje();

        DtParticipacion * getResponde();
};



#endif