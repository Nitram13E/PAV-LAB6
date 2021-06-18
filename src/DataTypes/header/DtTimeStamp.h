#ifndef DTTIMESTAMP
#define DTTIMESTAMP

#include "DtFecha.h"

#include <iostream>

class DtTimeStamp
{
    private:
        DtFecha fecha;
        int hora;
        int minuto;
        int segundo;
        
    public: 
        DtTimeStamp();
        DtTimeStamp(DtFecha,int,int,int);
        DtTimeStamp(time_t);
        ~DtTimeStamp();

        DtFecha getFecha();

        int getHora();

        int getMinuto();

        int getSegundo();

        friend std::ostream& operator << (std::ostream&, DtTimeStamp);
};

#endif