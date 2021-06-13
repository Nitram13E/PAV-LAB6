#include "Factory.h"
#include "Class/header/Sesion.h"
#include "Interfaces/IAltaAsignatura.h"
#include "Interfaces/IAltaUsuario.h"
#include "Interfaces/IAsignacionDocenteAsignatura.h"
#include "Interfaces/IAsistenciaClaseVivo.h"
#include "Interfaces/IEliminarAsignatura.h"
#include "Interfaces/IiniciarSesion.h"
#include "Interfaces/IinicioClase.h"
#include "Interfaces/IInscripcionAsignaturas.h"
#include "Interfaces/IListadoClase.h"
#include "Interfaces/IEnvioMensaje.h"

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
#include "Handlers/header/ManejadorPerfil.h"

#include <unistd.h>

bool CUIniciarSesion();
void menu();
void pressEnter();
void cargarDatos();
void CUAltaUsuario();
void CUAltaAsignatura();

void CUInscripcionAsignaturas();

void CUAsistenciaClaseVivo();

Factory* fabrica = Factory::getInstancia();
IiniciarSesion* IIS; 
IAltaUsuario* IAU;
IAsistenciaClaseVivo* IACV;
IAltaAsignatura * IAA;
IInscripcionesAsignaturas * IInscAsig;
IEnvioMensaje * IEM;


void menu()
{
    setlocale(LC_ALL, "");

    int op;
    bool inicio;

    system("clear");
    std::cout << "\n\tBienvenido!\n" << std::endl;
    std::cout << "1) Iniciar Sesion" << std::endl;
    std::cout << "2) Registrarse" << std::endl;
    std::cout << "\nElija una opción: ";
    std::cin >> op;

    if(op == 1) inicio = CUIniciarSesion();
    else if(op == 2) 
    {
        CUAltaUsuario();
        inicio = CUIniciarSesion();
    }
    if(op == 3 || inicio) // Si el usuario ingreso en modo administrador (op = 3) o si inicio sesion exitosamente
    {
        do
        {
            system("clear");
            std::cout << "---------------------------------------------------------" << std::endl;
            std::cout << "\n\t\tBienvenido a TecnoinfClass\n" << std::endl;
            std::cout << "---------------------------------------------------------" << std::endl;
            std::cout << "1.Alta de usuario" << std::endl;
            std::cout << "---------------------------------------------------------" << std::endl;
            std::cout << "2.Alta de asignatura" << std::endl;
            std::cout << "---------------------------------------------------------" << std::endl;
            std::cout << "3.Asignación de docentes a una asignatura" << std::endl;
            std::cout << "---------------------------------------------------------" << std::endl;
            std::cout << "4.Inscripción a las asignaturas" << std::endl;
            std::cout << "---------------------------------------------------------" << std::endl;
            std::cout << "6.Asistencia clase en vivo" << std::endl;
            std::cout << "---------------------------------------------------------" << std::endl;
            std::cout << "13.Cargar datos de prueba" << std::endl;
            std::cout << "---------------------------------------------------------" << std::endl;
            std::cout << "14.Salir" << std::endl;
            std::cout << "---------------------------------------------------------" << std::endl;
            std::cout << "Opción: ";
            std::cin >> op;

            switch (op)
            {
                case 1: // Alta de usuario
                    CUAltaUsuario();
                    break;
                    
                case 2: // Alta de asignatura
                    CUAltaAsignatura();
                    break;

                case 3: // Asignación de docentes a una asignatura

                    break;

                case 4:
                    CUInscripcionAsignaturas();
                    break;

                case 14: // Salir
                    std::cout << "\nSaliendo..." << std::endl;
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

bool CUIniciarSesion()
{
    IIS = fabrica -> getIiniciarSesion();
    std::string email;
    std::string password;

    bool inicio = false;
    int intentos = 5;
    
    do
    {
        system("clear");
        std::cout << "-----------------------------------------------" << std::endl;
        std::cout << "\t\tIniciar Sesion:" << std::endl;
        std::cout << "-----------------------------------------------" << std::endl;
        std::cout << "Email: ";
        std::cin >> email;
        std::cout << "-----------------------------------------------" << std::endl;
        std::cout << "Contraseña: ";
        std::cin >> password;

        IIS -> ingresarEmail(email);

        if(IIS -> validarContrasenia(password))
        {
            IIS -> inciarSesion();
            inicio = true;
        }
        else
        {
            intentos--;
            std::cout << "\nContraseña incorrecta. Intentos restantes: "<< intentos << std::endl;
            sleep(1);
        }
    }while(!inicio && intentos > 0);

    return inicio;
}

void CUAltaUsuario()
{
    IAU = fabrica -> getIAltaUsuario();

    std::string nom;
    std::string imgURL;
    std::string email;
    std::string pass;

    std::string opAU;

    do
    {
        // ingresarDatosPerfil
        system("clear");
        std::cout << "Alta Usuario" << std::endl << std::endl;
        std::cout << "Ingrese nombre: ";
        std::cin >> nom;
        system("clear");

        std::cout << "Ingrese imagen: ";
        std::cin >> imgURL;
        system("clear");

        std::cout << "Ingrese email: ";
        std::cin >> email;
        system("clear");

        std::cout << "Ingrese password: ";
        std::cin >> pass;
        system("clear");
        
        DtPerfil auxPerfil = DtPerfil(nom, imgURL, email, pass);

        int op;

        std::cout << "Elija el tipo de perfil:" << std::endl;
        std::cout << "- Estudiante '0'" << std::endl;
        std::cout << "- Docente '1'" << std::endl;
        std::cout << "Opción: ";
        std::cin >> op;

        switch (op)
        {
            case 0: // Es estudiante
            {
                // ingresarEstudiante
                std::string ci;
                std::cout << "Ingrese CI: ";
                std::cin >> ci;

                IAU -> ingresarDatosPerfil(auxPerfil, ESTUDIANTE);
                IAU -> ingresarEstudiante(ci);
                break;
            }
            case 1: // Es docente
            {
                // ingresarDocente
                std::string ins;
                std::cout << "Ingrese instituto: ";
                std::cin >> ins;

                IAU -> ingresarDatosPerfil(auxPerfil, DOCENTE);
                IAU -> ingresarDocente(ins);
                break;
            }
            default:
                std::cout << "Por favor, ingrese una de las opciones." << std::endl;
        }
        // AltaUsuario
        std::string confirmar;
        std::cout << "Desea agregar el perfil? [S/N o Cualquier letra (menos la s)]: ";
        std::cin >> confirmar;
        
        if(confirmar == "S" || confirmar == "s")
        {
            IAU -> altaUsuario();
        }
        // [Quiere agregar usuario]
        system("clear");
        std::cout << "Desea crear un nuevo usuario? [S/N]: ";
        std::cin >> opAU;
        
    }while(opAU != "N");
}

void CUAltaAsignatura()
{
    IAA = fabrica -> getIAltaAsignatura();
    
    std::string codigo;
    std::string nombre;
    DtInstanciaClase* tipo;

    bool teorico = false;
    bool practico = false;
    bool monitoreo = false;

    system("clear");
    std::cout << "\t\tAlta Asignatura\n" << std::endl;
    std::cout << "Ingrese código: ";
    std::cin >> codigo;
    system("clear");
    std::cout << "Ingrese nombre: ";
    std::cin >> nombre;
    system("clear");
    
    std::string op;

    std::cout << "La asignatura tendrá clases de teorico? [S/N o Cualquier letra (menos la s)]: ";
    std::cin >> op;
    if(op == "S" || op == "s") teorico = true;

    std::cout << "La asignatura tendrá clases de practico? [S/N o Cualquier letra (menos la s)]: ";
    std::cin >> op;
    if(op == "S" || op == "s") practico = true;

    std::cout << "La asignatura tendrá clases de monitoreo? [S/N o Cualquier letra (menos la s)]: ";
    std::cin >> op;
    if(op == "S" || op == "s") monitoreo = true;

    tipo = new DtInstanciaClase(teorico, practico, monitoreo);

    DtAsignatura* dtAsig = new DtAsignatura(codigo, nombre, tipo);
   
    // AltaAsignatura
    IAA -> ingresar(dtAsig);

    std::string confirmar;
    std::cout << "Desea agregar la asignatura? [S/N o Cualquier letra (menos la s)]: ";
    std::cin >> confirmar;
    if(confirmar == "S" || confirmar == "s") IAA -> altaAsignatura();
    else IAA -> cancelar();
}

void CUAsistenciaClaseVivo()
{
    IACV = fabrica -> getIAsistenciaClaseVivo();

    std::string codigo;
    int id;
    char resp;
    
    std::list<std::string> inscr = IACV -> asignaturasInscriptos();
    std::cout << "Asignaturas cursando: " << std::endl;
    
    for(std::list<std::string>::iterator it = inscr.begin(); it != inscr.end(); ++it)
    {
        std::cout << *it << std::endl;
    }

    std::cout << "Seleccione una asignatura: ";
    std::cin >> codigo;
    system("clear");
    
    std::list<int> cDisp = IACV -> clasesOnlineDisponibles(codigo);
    std::cout << "Clases disponibles: \n" << std::endl;
    for(std::list<int>::iterator it = cDisp.begin(); it != cDisp.end(); ++it)
    {
        std::cout << *it << std::endl;
    }
    
    std::cout << "Seleccione una clase: ";
    std::cin >> id;  
    system("clear");
    
    DtAsistir* asist = IACV -> selectClase(id);
    std::cout << "Datos Ingresados: " << std::endl;
    std::cout << *asist << std::endl;
    
    std::cout << "Desea confirmar? [S/N]" << std::endl;
    std::cin >> resp; 
    if(resp == 'S')
    {
        IACV -> asistirClaseVivo();
        std::cout << "\nSu clase comenzara pronto.... o algo parecido, no se\n";
    } 
    else
    {
        IACV -> cancelar();
        std::cout << "\nUsted ha cancelado\n";
    }
}

void CUEnvioMensaje()
{
    int id_selected, id_response;
    std::string txt;

    IEM = fabrica -> getIEnvioMensaje();

    std::list<int> clasesVivo = IEM -> clasesOnlineAsistiendo();
    std::list<int>::iterator it;

    std::list<DtParticipacion*> participaciones;
    std::list<DtParticipacion*>::iterator it_p;

    std::cout << "\nClases en vivo:\n\n";

    for (it = clasesVivo.begin(); it != clasesVivo.end(); it++)
    {
        std::cout << "- " << *it << "\n";
    }

    do
    {
        system("clear");
        std::cout << "\nSeleccionar clase: ";
        std::cin >> id_selected;

        it = clasesVivo.begin();

        while (*it != id_selected && it != clasesVivo.end())
        {
            it++;
        }

    } while (it == clasesVivo.end());
    
    participaciones = IEM -> selectClase(id_selected);

    std::cout << "\nParticipaciones:\n\n";

    for (it_p = participaciones.begin(); it_p != participaciones.end(); it_p++)
    {

        (*it_p) -> bubbleMsg();

        if ((*it_p) -> getResponde() != NULL)
        {
            std::cout << "Responde a:\n";
            (*it_p) -> getResponde() -> bubbleMsg();
        }

        std::cout << "------------------------------------------------------------" << std::endl;
    }

    std::string confirmar;
    std::cout << "Desea contestar alguna participacion? [S/N o Cualquier letra (menos la s)]: ";
    std::cin >> confirmar;

    if(confirmar == "S" || confirmar == "s")
    {
        do
        {
            //system("clear");
            std::cout << "\n id de la participacion a responder: ";
            std::cin >> id_response;

            it_p = participaciones.begin();

            while ((*it_p) -> getId() != id_response && it_p != participaciones.end())
            {
                it_p++;
            }
        } while (it_p == participaciones.end());
        
        IEM ->responder(id_response);
    }

        std::cout << "\n Ingrese texto: ";
        std::cin >> txt;
        IEM -> ingresarTexto(txt);

    std::cout << "Seguro que quiere enviar la participacion? (Verifique que no sea un insulto al docente)[S/N o Cualquier letra (menos la s)]: ";
    std::cin >> confirmar;
    
    if(confirmar == "S" || confirmar == "s")
    {
        IEM -> enviarMensaje();
    }
    else
    {
        IEM -> cancelar();
    }
}

void CUInscripcionAsignaturas()
{
    IInscAsig = fabrica -> getInscripcionAsignaturas();

    std::string codigoAsig;
    int op = 0;

    do
    {
        std::list<std::string> listaAsignaturas = IInscAsig -> asignaturasNoInscriptos();

        std::list<std::string>::iterator it;

    
        if(listaAsignaturas.empty())
        {
            std::cout << "\nNo hay asignaturas disponibles a las cuales inscribirse.\n" << std::endl;

            op = 3;

            pressEnter();
        }
        else
        {
            //Muestro las asignaturas en las cuales el estudiante no esta inscripto
            for (it = listaAsignaturas.begin(); it != listaAsignaturas.end(); it++)
            {
                std::cout << *it << std::endl;
            }
            
            std::cout << "Seleccione la asignatura a inscribirse: ";
            std::cin >> codigoAsig;

            IInscAsig -> selectAsignatura(codigoAsig);

            std::cout << "1: Inscribirse" << std::endl << "2: Cancelar "<< std::endl;
            std::cout << "Ingrese una opcion: ";
            std::cin >> op;

            if(op == 1)
            {
                IInscAsig -> inscribir();
            }

            std::string confirmar;
            std::cout << "Desea continuar inscribiendose a asignaturas? [S/N o Cualquier letra (menos la s)]: ";
            std::cin >> confirmar;
            if(confirmar == "N" || confirmar == "n") op = 3;
        }   

    }while(op != 3);

}
