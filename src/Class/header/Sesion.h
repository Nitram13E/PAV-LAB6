#ifndef SESION_H
#define SESION_H

#include "Perfil.h"
#include "../../DataTypes/header/tipoPerfil.h"

class Sesion
{
    private: 
        static Sesion* instancia;
        Perfil* p;
        tipoPerfil tipoDePerfil;
        Sesion();

    public:

        static Sesion* getInstancia();
        void setPerfil(Perfil*,tipoPerfil);
        Perfil* getPerfil();
        tipoPerfil getTipoPerfil();
        ~Sesion();
};
#endif