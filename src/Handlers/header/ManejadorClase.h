#ifndef MANEJADORCLASE
#define MANEJADORCLASE

#include "../../Class/header/Clase.h"

#include <map>
#include <list>

class ManejadorClase
{
    private:
        static ManejadorClase* instancia;
        std::map<int, Clase*> clases;
        ManejadorClase();
    
    public:
        static ManejadorClase* getInstancia();
        ~ManejadorClase();

        Clase* buscarClase(int);
        void addClase(Clase*);
        bool existeClase(int);
        void removeClase(int);
        std::list<Clase*> listarClases();
};

#endif