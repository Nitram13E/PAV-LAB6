#ifndef CLASE
#define CLASE

class Docente;
class AsisteVivo;
class AsisteDiferido;

#include "../../DataTypes/header/DtTimeStamp.h"
#include "AsisteVivo.h"
#include "Docente.h"
#include "Participacion.h"
#include "../../DataTypes/header/DtInfoClase.h"

#include <list>
#include <iterator>

class Clase
{
    private:
        static int idActual;

        int id;
        std::string nombre;
        DtTimeStamp inicio;
        DtTimeStamp* fin;
        std::string rutavideo;

        std::list<Docente*> docentes;
        std::list<Participacion*> participaciones;
        std::list<AsisteVivo*> asisteVivo;

        void incrementarIdActual();

    public:
        Clase();
        Clase(std::string, DtTimeStamp, DtTimeStamp*, std::string);
        virtual ~Clase();

        static int getIdActual();

        int getID();

        std::string getNombre();
        void setNombre(std::string);
        
        DtTimeStamp getInicio();
        void setInicio(DtTimeStamp);

        DtTimeStamp* getFin();
        void setFin(DtTimeStamp*);

        std::string getRutaVideo();
        void setRutaVideo(std::string);

        void addDocentes(Docente*);
        std::list<Docente*> getDocentes();

        void addParticipacion(Participacion*);
        std::list<Participacion*> getParticipaciones();

        void addAsisteEnVivo(AsisteVivo*);
        std::list<AsisteVivo*> getAsisteVivo();

        bool asisteEstudiante();

        bool enVivo();

        virtual DtInfoClase getDtInfoClase() = 0;
};

#endif
