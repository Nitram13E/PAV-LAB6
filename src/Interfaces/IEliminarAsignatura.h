#ifndef IELIMINARASIGNATURA
#define IELIMINARASIGNATURA

#include <list>
#include <iostream>

class IEliminarAsignatura
{
    public:

        virtual std::list<std::string> listarAsignaturas() = 0;

        virtual void selectAsignatura(std::string) = 0;

        virtual void eliminarAsignatura() = 0;

        virtual void cancelar()= 0;
        
};

#endif