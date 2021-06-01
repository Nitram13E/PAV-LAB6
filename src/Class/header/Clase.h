#ifndef CLASE
#define CLASE

class Docente;

#include "../../DataTypes/header/DtTimeStamp.h"
#include "Docente.h"
#include "Participacion.h"

#include <list>
#include <iterator>

class Clase
{
    private:
        int id;
        std::string nombre;
        DtTimeStamp inicio;
        DtTimeStamp fin;
        std::string rutavideo;

        std::list<Docente*> docentes;
        std::list<Participacion*> participaciones;

    public:
        Clase();
        Clase(int, std::string, DtTimeStamp, DtTimeStamp, std::string);
        virtual ~Clase() = 0;

        int getID();
        void setID(int);

        std::string getNombre();
        void setNombre(std::string);
        
        DtTimeStamp getInicio();
        void setInicio(DtTimeStamp);

        DtTimeStamp getFin();
        void setFin(DtTimeStamp);

        std::string getRutaVideo();
        void setRutaVideo(std::string);
};

#endif