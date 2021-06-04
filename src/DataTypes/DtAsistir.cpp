#include "header/DtAsistir.h"

DtAsistir::DtAsistir(){}

DtAsistir::DtAsistir(std::string codigo, int id)
{
    this -> codigo = codigo;
    this -> id = id;
}

DtAsistir::~DtAsistir(){}

std::string DtAsistir::getCodigo()
{
    return this -> codigo;
}

int DtAsistir::getId()
{
    return this -> id;
}

std::ostream& operator <<(std::ostream& salida, DtAsistir asistir)
{
    std::cout << "Codigo de la Asignatura: " << asistir.getCodigo() << std::endl;
    std::cout << "ID de la Clase: " << asistir.getId() << std::endl;

    return salida;
}