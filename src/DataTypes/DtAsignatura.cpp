#include "header/DtAsignatura.h"

DtAsignatura::DtAsignatura(){}

DtAsignatura::DtAsignatura(std::string codigo, std::string nombre, DtInstanciaClase* tipo)
{
    this -> codigo = codigo;
    this -> nombre = nombre;
    this -> tipoClases = tipo;
}

DtAsignatura::~DtAsignatura(){}

std::string DtAsignatura::getCodigo()
{
    return this -> codigo;
}

std::string DtAsignatura::getNombre()
{
    return this -> nombre;
}

DtInstanciaClase* DtAsignatura::getTipoClases()
{
    return this -> tipoClases;
}

std::ostream& operator << (std::ostream& salida, DtAsignatura& dtAsig)
{
    std::cout << "Codigo: " << dtAsig.getCodigo() << std::endl;
    std::cout << "Nombre: " << dtAsig.getNombre() << std::endl;
    std::cout << "Tipo Clases:\n" << *dtAsig.getTipoClases();

    return salida;
}