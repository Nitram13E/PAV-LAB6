#include "header/CAltaAsignatura.h"
#include "../Handlers/header/ManejadorAsignatura.h"

CAltaAsignatura::CAltaAsignatura(){}

CAltaAsignatura::~CAltaAsignatura(){}

DtAsignatura* CAltaAsignatura::ingresar(DtAsignatura* datosAsignatura)
{
    this -> datosAsignatura = datosAsignatura;

    return this -> datosAsignatura;
}

void CAltaAsignatura::altaAsignatura()
{
    Asignatura* newAsignatura = new Asignatura(this -> datosAsignatura -> getCodigo(), this -> datosAsignatura -> getNombre());

    ManejadorAsignatura* handlerAsignatura = ManejadorAsignatura::getInstancia();

    handlerAsignatura -> agregarAsignatura(newAsignatura);
}

void CAltaAsignatura::cancelar()
{
    delete this -> datosAsignatura;
}