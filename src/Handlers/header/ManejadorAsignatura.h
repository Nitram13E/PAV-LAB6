#ifndef MANEJADORASIGNATURA
#define MANEJADORASIGNATURA

#include "../../Class/header/Asignatura.h"

#include <map>
#include <list>

class ManejadorAsignatura
{
    private:
        static ManejadorAsignatura* instancia;
        std::map<std::string, Asignatura*> asignaturas;
        ManejadorAsignatura();

    public:
        static ManejadorAsignatura* getInstancia();
        ~ManejadorAsignatura();

        Asignatura* buscarAsignatura(std::string);
        void agregarAsignatura(Asignatura*);
        bool existeAsignatura(std::string);
        void removeAsignatura(std::string);
        std::list<std::string> listarAsignatura();
        std::map<std::string, Asignatura*> listarMapAsignatura();
};

#endif