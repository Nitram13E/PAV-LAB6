#ifndef C_ELIMINARASIGNATURA
#define C_ELIMINARASIGNATURA

#include <list>
#include <iostream>

class CEliminarAsignatura
{
    private:
        std::string codigo;
      
    public:
        CEliminarAsignatura();
        ~CEliminarAsignatura();

        std::list<std::string> listarAsignaturas();

        void selectAsignatura(std::string);

        void eliminarAsignatura();

        void cancelar();
};

#endif