#ifndef DTINSTANCIACLASE
#define DTINSTANCIACLASE

#include <iostream>

class DtInstanciaClase
{
    private:
        bool teorico;
        bool practico;
        bool monitoreo;
    
    public:

        DtInstanciaClase();
        DtInstanciaClase(bool,bool,bool);
        ~DtInstanciaClase();

        bool getTeorico();
        bool getPractico();
        bool getMonitoreo();

        friend std::ostream& operator << (std::ostream&, DtInstanciaClase);
};

#endif