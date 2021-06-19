#ifndef ASIGNATURA
#define ASIGNATURA

class Clase;

#include "Clase.h"
#include "../../DataTypes/header/DtInfoClase.h"
#include "../../Handlers/header/ManejadorClase.h"
#include "../../DataTypes/header/DtInstanciaClase.h"

#include <list>

class Asignatura
{
    private:
        std::string codigo;
        std::string nombre;
        DtInstanciaClase* tipoClases;
        std::list<Clase*> clases;
    public:
        Asignatura();
        Asignatura(std::string, std::string,DtInstanciaClase*);
        ~Asignatura();
        
        std::string getCodigo();
        void setCodigo(std::string);

        std::string getNombre();
        void setNombre(std::string);

        DtInstanciaClase* getTipoClases();
        void setTipoClases(DtInstanciaClase*);

        void addClases(Clase*);
        std::list<Clase*> getClases();

        std::list<DtInfoClase*> getDtInfoClase();

        std::list<int> listarIdAsisteVivo();
};

#endif