#include "Factory.h"
#include "Interfaces/IAltaAsignatura.h"
#include "Interfaces/IAltaUsuario.h"
#include "Interfaces/IAsignacionDocenteAsignatura.h"
#include "Interfaces/IAsistenciaClaseVivo.h"
#include "Interfaces/IEliminarAsignatura.h"
#include "Interfaces/IiniciarSesion.h"
#include "Interfaces/IinicioClase.h"
#include "Interfaces/IInscripcionAsignaturas.h"
#include "Interfaces/IListadoClase.h"

#include "DataTypes/header/DtFecha.h"
#include "DataTypes/header/DtLog.h"
#include "DataTypes/header/DtAsistir.h"
#include "DataTypes/header/DtPerfil.h"
#include "DataTypes/header/DtTimeStamp.h"
#include "DataTypes/header/DtInstanciaClase.h"
#include "DataTypes/header/DtAsignatura.h"
#include "DataTypes/header/DtInfoClase.h"
#include "DataTypes/header/DtInfoTeorico.h"
#include "DataTypes/header/DtInfoMonitoreo.h"
#include "DataTypes/header/DtIniciarClase.h"
#include "DataTypes/header/DtIniciarClaseFull.h"
#include "DataTypes/header/DtIniciarMonitoreo.h"
#include "DataTypes/header/DtParticipacion.h"

#include <unistd.h>

void menu();
void pressEnter();
void cargarDatos();

void menu()
{
    setlocale(LC_ALL, "");

    int op;
    
    do
    {
        system("clear");

        std::cout << "------------------------------------------------------------" << std::endl;
        std::cout << "Bienvenido a TecnoinfClass\n" << std::endl;
        std::cout << "------------------------------------------------------------" << std::endl;
        std::cout << "1.Alta de usuario" << std::endl;
        std::cout << "------------------------------------------------------------" << std::endl;
        std::cout << "2.Alta de asignatura" << std::endl;
        std::cout << "------------------------------------------------------------" << std::endl;
        std::cout << "3.Asignación de docentes a una asignatura" << std::endl;
        std::cout << "------------------------------------------------------------" << std::endl;
        std::cout << "4.Inscripción a las asignaturas" << std::endl;
        std::cout << "------------------------------------------------------------" << std::endl;
        std::cout << "13.Cargar datos de prueba" << std::endl;
        std::cout << "------------------------------------------------------------" << std::endl;
        std::cout << "14.Salir" << std::endl;
        std::cout << "------------------------------------------------------------" << std::endl;
        std::cout << "Opción: ";
        std::cin >> op;

        switch (op)
        {
            case 1: // Alta de usuario

                break;
                
            case 2: // Alta de asignatura

                break;

            case 3: // Asignación de docentes a una asignatura

                break;

            case 4: // Inscripción a las asignaturas

                break;

            case 13: // Cargar datos de prueba

                break;

            case 14: // Salir
                std::cout << "\nSaliendo.." << std::endl;
                sleep(2);

                break;
            
            default:
                std::cout << "\nPor favor, introduzca una opcion valida." << std::endl;
                pressEnter();
                system("clear");
        }
    }
    while (op != 14);
}

void pressEnter()
{
    std::string enter;
    std::getline(std::cin, enter);
    std::cout << "Presiona enter para continuar...";
    std::getline(std::cin, enter);
}


void cargarDatos()
{
    
}

int main()
{
    menu();

    return 0;
}