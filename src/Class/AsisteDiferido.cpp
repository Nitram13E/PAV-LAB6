#include "header/AsisteDiferido.h"

AsisteDiferido::AsisteDiferido(){}

AsisteDiferido::AsisteDiferido(Estudiante * estudiante)
{
    this -> estudiante = estudiante;
}

AsisteDiferido::~AsisteDiferido(){}

void AsisteDiferido::addLog(DtLog * log)
{
    this -> logs.push_back(log);
}

std::list<DtLog*> AsisteDiferido::getLogs()
{
    return this -> logs;
}

void AsisteDiferido::setEstudiante(Estudiante* estudiante)
{
    this -> estudiante = estudiante;
}
Estudiante* AsisteDiferido::getEstudiante()
{
    return this -> estudiante;
}