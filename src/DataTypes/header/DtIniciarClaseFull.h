#ifndef DTINICIARCLASEFULL
#define DTINICIARCLASEFULL

#include "DtIniciarClase.h"

#include <iostream>

class DtIniciarClaseFull : public DtIniciarClase
{
    private:
        int id;

    public:
        DtIniciarClaseFull();
        DtIniciarClaseFull(int, std::string, std::string, DtTimeStamp);
        ~DtIniciarClaseFull();

        int getId();

        friend std::ostream& operator << (std::ostream&, DtIniciarClaseFull&);
};

#endif