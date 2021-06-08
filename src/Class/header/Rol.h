#ifndef ROL
#define ROL

class Asignatura;

#include "../../DataTypes/header/tipoRol.h"
#include "Asignatura.h"

class Rol
{
    private:
        tipoRol tipo;
        Asignatura * asignatura;

    public:
        Rol();
        Rol(tipoRol, Asignatura*);
        ~Rol();

        void setTipoRol(tipoRol);
        tipoRol getTipoRol();

        void setAsignatura(Asignatura*);
        Asignatura* getAsignatura();
        std::string getCodigoAsignatura();
};

#endif