#include "DtAsistir.h"

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
