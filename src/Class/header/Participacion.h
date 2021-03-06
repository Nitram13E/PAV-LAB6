#ifndef PARTICIPACION
#define PARTICIPACION

#include "../../DataTypes/header/DtTimeStamp.h"
#include "Perfil.h"

class Participacion
{
    private:
        static int idActual;

        int id; 
        Perfil * perfil;
        DtTimeStamp fecha;
        std::string mensaje;
        Participacion * responde;

        void incrementarIDActual();

    public:
        Participacion();
        Participacion(Perfil*, DtTimeStamp, std::string, Participacion*);
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