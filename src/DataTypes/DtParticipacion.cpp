#include "header/DtParticipacion.h"

DtParticipacion::DtParticipacion(){}

DtParticipacion::DtParticipacion(int id, DtTimeStamp fecha, std::string mensaje, DtParticipacion * responde)
{
    this -> id = id;
    this -> fecha = fecha;
    this -> mensaje = mensaje;
    this -> responde = responde;
}

DtParticipacion::~DtParticipacion(){}

int DtParticipacion::getId()
{
    return this -> id;
}

DtTimeStamp DtParticipacion::getFecha()
{
    return this -> fecha;
}

std::string DtParticipacion::getMensaje()
{
    return this -> mensaje;
}

DtParticipacion * DtParticipacion::getResponde()
{
    return this -> responde;
}

void DtParticipacion::bubbleMsg()
{
	for (int i = 0; i < this -> getMensaje().length() + 7; i++)
	{
		std::cout << "_";
	}
	std::cout << "\n";
	
	std::cout << "(" << this;
	std::cout << "  " << this -> getFecha().getHora() << ":" << this -> getFecha().getMinuto() << ")";
    std::cout << "\t[id: " << this -> getId() << "]" << std::endl;
	std::cout << "|/";
	
	for (int i = 0; i < this ->getMensaje().length() + 7; i++)
	{
		std::cout << "¯";
	}
	
	std::cout << "\n";
}