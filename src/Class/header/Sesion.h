#ifndef SESION_H
#define SESION_H

#include "Perfil.h"
#include "../../DataTypes/header/tipoPerfil.h"

class Sesion{
    private: 
        static Sesion* instancia;
        Perfil* p;
        Sesion();
        tipoPerfil tipoDePerfil;
    public:
        static Sesion* getInstancia();
        ~Sesion();

        void setPerfil(Perfil*,tipoPerfil);
        Perfil* getPerfil();
        
        tipoPerfil getTipoPerfil();
        

};

#endif