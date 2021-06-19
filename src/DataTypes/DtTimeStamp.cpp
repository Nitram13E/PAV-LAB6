#include "header/DtTimeStamp.h"
#include <ctime>

DtTimeStamp::DtTimeStamp(){}

DtTimeStamp::DtTimeStamp(DtFecha fecha, int hora, int minuto, int segundo)
{
    this -> fecha = fecha;
    this -> hora = hora;
    this -> minuto = minuto;
    this -> segundo = segundo;
}

DtTimeStamp::DtTimeStamp(std::time_t tt)
{
    time(&tt); // Se usa para encontrar la hora actual
    struct tm * time = localtime(&tt);
    DtFecha fecha = DtFecha(time -> tm_mday, time -> tm_mon + 1, time -> tm_year + 1900);

    this -> fecha = fecha;
    this -> hora = time -> tm_hour;
    this -> minuto = time -> tm_min;
    this -> segundo = time ->tm_sec;
}

DtTimeStamp::~DtTimeStamp(){}

DtFecha DtTimeStamp::getFecha()
{
    return this -> fecha;
}

int DtTimeStamp::getHora()
{
    return this -> hora;
}

int DtTimeStamp::getMinuto()
{
    return this -> minuto;
}

int DtTimeStamp::getSegundo()
{
    return this -> segundo;
}

std::ostream& operator << (std::ostream& out, DtTimeStamp fechaHora)
{
    std::cout << fechaHora.getFecha() << " " << fechaHora.getHora() << ":" << fechaHora.getMinuto() << ":" << fechaHora.getSegundo();

    return out;
}