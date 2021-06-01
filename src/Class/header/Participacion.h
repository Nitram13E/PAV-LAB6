#ifndef PARTICIPACION
#define PARTICIPACION

#include "../../DataTypes/header/DtTimeStamp.h"
#include "Perfil.h"

class Participacion
{
    private:
        int id; 
        DtTimeStamp fecha;
        std::string mensaje;
        Participacion * responde;
        Perfil * perfil;

    public:
        Participacion();
        Participacion(int, DtTimeStamp, std::string, Participacion*);
        ~Participacion();

        int getId();
        void setId(int);

        DtTimeStamp getFecha();
        void setFecha(DtTimeStamp);

        std::string getMensaje();
        void setMensaje(std::string);

        Participacion* getResponde();
        void setResponde(Participacion*);

        void setPerfil(Perfil*);
        Perfil* getPerfil();

};

#endif