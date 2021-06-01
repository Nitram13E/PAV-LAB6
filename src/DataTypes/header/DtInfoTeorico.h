#ifndef DTINFOTEORICO
#define DTINFOTEORICO

#include "DtInfoClase.h"

class DtInfoTeorico : public DtInfoClase
{
    private:
        int cantAsistentes;
        
    public:

        DtInfoTeorico();
        DtInfoTeorico(int, std::string, std::list<std::string>, int);
        ~DtInfoTeorico();
        
        int getCantAsist();
};

#endif