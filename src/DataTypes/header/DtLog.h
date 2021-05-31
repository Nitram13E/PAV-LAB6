#ifndef DTLOG
#define DTLOG

#include "DtTimeStamp.h"

class DtLog
{
    private:

        DtTimeStamp inicio;
        DtTimeStamp fin;

    public:

        DtLog();
        DtLog(DtTimeStamp, DtTimeStamp);
        ~DtLog();
        
        DtTimeStamp getInicio();

        DtTimeStamp getFin();

        
};

#endif