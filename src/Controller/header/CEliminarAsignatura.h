#ifndef C_ELIMINARASIGNATURA
#define C_ELIMINARASIGNATURA

#include "../../Interfaces/IEliminarAsignatura.h"
class CEliminarAsignatura : public IEliminarAsignatura
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