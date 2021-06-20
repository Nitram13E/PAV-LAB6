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
    Asignatura* newAsignatura = new Asignatura(this -> datosAsignatura -> getCodigo(), this -> datosAsignatura -> getNombre(), this -> datosAsignatura -> getTipoClases());

    ManejadorAsignatura* handlerAsignatura = ManejadorAsignatura::getInstancia();

    handlerAsignatura -> agregarAsignatura(newAsignatura);
}

void CAltaAsignatura::cancelar()
{
    delete this -> datosAsignatura;
}

void CAltaAsignatura::cargarDatos()
{
    ingresar(new DtAsignatura("1", "PAV", new DtInstanciaClase(true, true, true)));
    altaAsignatura();

    ingresar(new DtAsignatura("2", "COE", new DtInstanciaClase(true, true, false)));
    altaAsignatura();

    ingresar(new DtAsignatura("3", "CONT", new DtInstanciaClase(false, true, false)));
    altaAsignatura();

    ingresar(new DtAsignatura("4", "BD II", new DtInstanciaClase(true, true, false)));
    altaAsignatura();

    ingresar(new DtAsignatura("5", "RC", new DtInstanciaClase(true, false, true)));
    altaAsignatura();

    ingresar(new DtAsignatura("6", "BD I", new DtInstanciaClase(false, true, false)));
    altaAsignatura();
}