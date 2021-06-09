#ifndef DTINSTANCIACLASE
#define DTINSTANCIACLASE

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
};

#endif