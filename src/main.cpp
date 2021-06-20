#include "Factory.h"
#include "Class/header/Sesion.h"
#include "Interfaces/IAltaAsignatura.h"
#include "Interfaces/IAltaUsuario.h"
#include "Interfaces/IAsignacionDocenteAsignatura.h"
#include "Interfaces/IAsistenciaClaseVivo.h"
#include "Interfaces/IEnvioMensaje.h"
#include "Interfaces/IEliminarAsignatura.h"
#include "Interfaces/IiniciarSesion.h"
#include "Interfaces/IinicioClase.h"
#include "Interfaces/IInscripcionAsignaturas.h"
#include "Interfaces/IListadoClase.h"

#include "DataTypes/header/DtFecha.h"
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

void menu();
void pressEnter();
void cargarDatos();
void bubbleMsg(DtParticipacion);
bool CUIniciarSesion();
void CUAltaUsuario();
void CUAltaAsignatura();
void CUAsignacionDocenteAsignatura();
void CUInicioClase();
void CUAsistenciaClaseVivo();
void CUEnvioMensaje();
void CUInscripcionAsignaturas();
void CUListadoClase();
void CUEliminarAsignatura();

Factory* fabrica = Factory::getInstancia();
IiniciarSesion* IIS;
IAltaUsuario* IAU;
IAsignacionDocenteAsignatura * IADA;
IAsistenciaClaseVivo* IACV;
IAltaAsignatura * IAA;
IInscripcionesAsignaturas * IIA;
IEnvioMensaje * IEM;
IEliminarAsignatura * IEA;
IinicioClase * IIC;
IListadoClases * ILC;

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

    if(op == 1)
    {
        IAU = fabrica -> getIAltaUsuario();
        IAU -> cargarDatos();
        inicio = CUIniciarSesion();
    }
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
            std::cout << "5.Iniciar clase" << std::endl;
            std::cout << "---------------------------------------------------------" << std::endl;
            std::cout << "6.Asistencia clase en vivo" << std::endl;
            std::cout << "---------------------------------------------------------" << std::endl;
            std::cout << "7.Enviar mensaje" << std::endl;
            std::cout << "---------------------------------------------------------" << std::endl;
            std::cout << "8.Eliminar asignatura" << std::endl;
            std::cout << "---------------------------------------------------------" << std::endl;
            std::cout << "9.Listar clases" << std::endl;
            std::cout << "---------------------------------------------------------" << std::endl;
            std::cout << "10.Cargar datos de prueba" << std::endl;
            std::cout << "---------------------------------------------------------" << std::endl;
            std::cout << "11.Salir" << std::endl;
            std::cout << "---------------------------------------------------------" << std::endl;
            std::cout << "12.Cerrar Sesión" << std::endl;
            std::cout << "---------------------------------------------------------" << std::endl;
            std::cout << "Opción: ";
            std::cin >> op;

            switch(op)
            {
                case 1: // Alta de usuario  --Administrador
                    CUAltaUsuario();
                    break;

                case 2: // Alta de asignatura --Administrador
                    CUAltaAsignatura();
                    break;

                case 3: // Asignación de docentes a una asignatura  --Administrador
                    CUAsignacionDocenteAsignatura();
                    break;

                case 4: //Inscripción a las asignaturas  --Estudiante
                    CUInscripcionAsignaturas();
                    break;
                
                case 5: //Inicio de clase  --Docente
                    CUInicioClase();
                    break;

                case 6: // Asistencia a clase en vivo  --Estudiante
                    CUAsistenciaClaseVivo();
                    break;

                case 7: //Envío de mensaje  --Estudiante
                    CUEnvioMensaje();
                    break;

                case 8: //Eliminación de asignatura  --Administrador
                    CUEliminarAsignatura();
                    break;

                case 9: //Listado de Clases  --Docente
                    CUListadoClase();
                    break;

                case 10: //cargar datos
                    cargarDatos();
                    break;

                case 11: // Salir
                    std::cout << "\nSaliendo..." << std::endl;
                    sleep(2);
                    break;

                case 12: // Volver a iniciar sesion
                    CUIniciarSesion();
                    break;

                default:
                    std::cout << "\nPor favor, introduzca una opcion valida." << std::endl;
                    pressEnter();
                    system("clear");
            }
        }
        while (op != 11);
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
    std::cout << "\tCargar Datos:" << std::endl;
    std::cout << "1 - Agregar Usuarios" << std::endl;
    std::cout << "2 - Cargar todos los datos al sistema (si fueron cargados los usuarios)" << std::endl;
    std::cout << "Opción: ";
    int op;
    std::cin >> op;
    
    if(op == 1)
    {
        IAU = fabrica -> getIAltaUsuario();
        IAU -> cargarDatos();

        std::cout << "\nDatos cargados.\n" << std::endl;
    }
    else if(op == 2)
    {
        IAA = fabrica -> getIAltaAsignatura();
        IADA = fabrica -> getIAsignacionDocenteAsignatura();
        IIC = fabrica -> getIinicioClase();
        IIA = fabrica -> getInscripcionAsignaturas();
        IEM = fabrica -> getIEnvioMensaje();
        IAA -> cargarDatos();
        IADA -> cargarDatos();
        IIC -> cargarDatos();
        IIA -> cargarDatos();
        IEM -> cargarDatos();

        std::cout << "\nDatos cargados.\n" << std::endl;
    }
    else std::cout << "No se cargargá ningún dato. " << std::endl;
    pressEnter();
}

void bubbleMsg(DtParticipacion * msg)//Crea burbuja para mensaje
{
	for (int i = 0; i < msg -> getMensaje().length() + 8; i++)
	{
		if(i == 0) std::cout << " ";
        
        else std::cout << "_";
	}
	std::cout << "\n";
	
	std::cout << "|";
	std::cout << msg -> getMensaje() << "  " << msg -> getFecha().getHora() << ":" << msg -> getFecha().getMinuto() << "|";
    std::cout << "\t[id: " << msg -> getId() << "]" << std::endl;
	std::cout << "|/";
	
	for (int i = 0; i < msg ->getMensaje().length() + 6; i++)
	{
		std::cout << "¯";
	}
	
	std::cout << "\n";
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
            IIS -> iniciarSesion();
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
        std::cout << "\t\tAlta Usuario" << std::endl << std::endl;
        std::cout << "Ingrese nombre: ";
        std::cin >> nom;
        system("clear");

        std::cout << "Ingrese imagen: ";
        std::cin >> imgURL;
        system("clear");

        std::cout << "Ingrese email: ";
        std::cin >> email;
        system("clear");

        std::cout << "Ingrese contraseña: ";
        std::cin >> pass;
        system("clear");
        
        DtPerfil perfil = DtPerfil(nom, imgURL, email, pass);

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

                IAU -> ingresarDatosPerfil(perfil, ESTUDIANTE);
                IAU -> ingresarEstudiante(ci);
                break;
            }
            case 1: // Es docente
            {
                // ingresarDocente
                std::string ins;
                std::cout << "Ingrese instituto: ";
                std::cin >> ins;

                IAU -> ingresarDatosPerfil(perfil, DOCENTE);
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
            try
            {
                IAU -> altaUsuario();
            }
            catch(std::invalid_argument& e)
            {
                std::cerr << e.what() << '\n';
                pressEnter();
            }
        }
        // [Quiere agregar usuario]
        system("clear");
        std::cout << "Desea crear un nuevo usuario? [S/N]: ";
        std::cin >> opAU;

    }while(opAU == "S" || opAU == "s");
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

    // AltaAsignatura
    DtAsignatura* datos = IAA -> ingresar(new DtAsignatura(codigo, nombre, tipo));
    
    system("clear");
    std::cout << *datos << std::endl;

    std::string confirmar;
    std::cout << "\nDesea agregar la asignatura? [S/N o Cualquier letra (menos la s)]: ";
    std::cin >> confirmar;
    if(confirmar == "S" || confirmar == "s")
    {
        try
        {
            IAA -> altaAsignatura();
        }
        catch(std::invalid_argument& e)
        {
            std::cerr << e.what() << '\n';
            pressEnter();
        }
    }
    else IAA -> cancelar();
}

void CUAsignacionDocenteAsignatura()
{
    IADA = fabrica -> getIAsignacionDocenteAsignatura();

    std::string codigo;
    std::string email;
    int r;
    tipoRol rol;
    
    std::string op;
    std::string confirmar;
    
    do
    {
        std::cout << "\t\tAsignacion de un Docente a una Asignatura\n" << std::endl;

        std::list<std::string> asignaturas = IADA -> listarAsignaturas();
        
        std::cout << "Asignaturas: " << std::endl;
        for(std::list<std::string>::iterator it = asignaturas.begin(); it != asignaturas.end(); it++)
        {
            std::cout << *it << std::endl;
        }

        std::cout << "Seleccione una asignatura: ";
        std:: cin >> codigo;
        system("clear");

        std::list<std::string> docentes = IADA -> docentesSinLaAsignatura(codigo);

        std::cout << "Docentes no asignados: " << std::endl;
        for(std::list<std::string>::iterator i = docentes.begin(); i != docentes.end(); i++)
        {
            std::cout << *i << std::endl;
        }

        std::cout << "Seleccione un docente: ";
        std:: cin >> email;
        system("clear");
        
        std::cout << "Asigne un rol: " << std::endl;
        std::cout << "1: Teorico" << std::endl;
        std::cout << "2: Practico" << std::endl;
        std::cout << "3: Monitoreo" << std::endl;
        std::cout << "Opción: ";
        std:: cin >> r;

        switch (r)
        {
        case 1:
            rol = TEORICO;
            break;
        
        case 2:
            rol = PRACTICO;
            break;

        case 3:
            rol = MONITOREO;
            break;

        default:
            std::cout << "Opción incorrecta. " << std::endl;
            pressEnter();
            op = "e";
            break;
        }
        
        if(op != "e")
        {
            system("clear");

            IADA -> selectDocente(email, rol);
            
            std::cout << "Desea confirmar? [S/N]: ";
            std::cin >> confirmar;

            if(confirmar == "S" || confirmar == "s")
            {
                try
                {
                    IADA -> asignarDocente();
                }
                catch(const std::invalid_argument& e)
                {
                    std::cerr << e.what() << '\n';
                    pressEnter();
                }
            }
            else IADA -> cancelar();
            system("clear");

            std::cout << "Desea continuar agregando docentes? [S/N]: ";
            std::cin >> op;

            docentes.clear();
            system("clear");
        }
    }while(op == "S");
}

void CUInicioClase()
{
    IIC = fabrica -> getIinicioClase();
    std::string codAsig;
    std::string nombre;
    DtIniciarClase inicio;

    try
    {
        std::list<std::string> asignaturasAsignadas = IIC -> asignaturasAsignadas();

        std::list<std::string>::iterator it;

        std::cout << "\t\tInicio Clase\n" << std::endl;


        if(asignaturasAsignadas.empty())
        {
            std::cout << "El docente no contiene asignaturas. " << std::endl;
            pressEnter();
        }
        else
        {
            std::cout << "Asignaturas Asignadas: " << std::endl;
            for(it = asignaturasAsignadas.begin(); it != asignaturasAsignadas.end(); it++) std::cout << (*it) << std::endl;

            std::cout << "Seleccione una de las Asignaturas: ";
            std::cin >> codAsig;
            std::cout << "Ingrese nombre de la clase: ";
            std::cin >> nombre;

            time_t time;
            inicio = DtIniciarClase(codAsig, nombre, DtTimeStamp(time));
            std::string op;

            if(IIC -> selectAsignatura(inicio))
            {
                std::list<std::string> inscriptos = IIC -> inscriptosAsignatura();
                std::list<std::string>::iterator it;

                std::cout << "Estudiantes inscriptos a la asignatura " << codAsig << ":" << std::endl;

                for(it = inscriptos.begin(); it != inscriptos.end(); it++)
                {
                    std::cout << " - " << *it << std::endl;
                }

                do
                {
                    std::string email;
                    std::cout << "Ingrese mail de alumno a habilitar: " << std::endl;
                    std::cin >> email;

                    IIC -> habilitar(email);

                    std::cout << "Desea agregar otro alumno? [S/N o Cualquier letra (menos la s)]: ";
                    std::cin >> op;

                }while(op == "S" || op == "s");
            }
            std::cout << *(IIC -> datosIngresados()) << std::endl;

            std::cout << "Desea confirmar los datos ingresados? [S/N o Cualquier letra (menos la s)]: ";
            std::cin >> op;

            if(op == "S" || op == "s") IIC -> iniciarClase();
            else IIC -> cancelar();
        }
    }
    catch(std::invalid_argument& e)
    {
        std::cerr << e.what() << std::endl;
        pressEnter();
    }
}

void CUAsistenciaClaseVivo()
{
    IACV = fabrica -> getIAsistenciaClaseVivo();

    std::string codigo;
    int id;
    std::string resp;

    try
    {
        std::list<std::string> inscr = IACV -> asignaturasInscriptos();
        std::cout << "\t\tAsistencia Clase en Vivo\n" << std::endl;
        std::cout << "Asignaturas cursando: " << std::endl;

        if(inscr.empty())
        {
            std::cout << "\n No esta inscripto a ninguna asignatura " << std::endl;
            pressEnter();
        }
        else
        {
            for(std::list<std::string>::iterator it = inscr.begin(); it != inscr.end(); ++it)
            {
                std::cout << *it << std::endl;
            }

            std::cout << "Seleccione una asignatura: ";
            std::cin >> codigo;
            system("clear");

            std::list<int> cDisp = IACV -> clasesOnlineDisponibles(codigo);
            std::cout << "Clases disponibles: \n" << std::endl;
            if(cDisp.empty())
            {
                std::cout << "\n No hay ninguna clase abierta" << std::endl;
                pressEnter();
            }
            else
            {
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
                if(resp == "S" || resp == "s")
                {
                    IACV -> asistirClaseVivo();
                    std::cout << "\nSu clase comenzara pronto....\n";
                    pressEnter();
                } 
                else
                {
                    IACV -> cancelar();
                    std::cout << "\nUsted ha cancelado\n";
                }
            }
        }
    }
    catch(std::invalid_argument& e)
    {
        std::cerr << e.what() << std::endl;
        pressEnter();
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
    
    system("clear");
    std::cout << "\t\tEnviar Mensaje\n" << std::endl;
    std::cout << "\nClases en vivo:\n\n";

    if(clasesVivo.empty())
    {
        std::cout << "No hay clases ninguna clase abierta" << std::endl;
        pressEnter();
    }
    else
    {
        for (it = clasesVivo.begin(); it != clasesVivo.end(); it++)
        {
            std::cout << " - " << *it << "\n";
        }

        do
        {
            std::cout << "\nSeleccionar clase: ";
            std::cin >> id_selected;

            it = clasesVivo.begin();

            while (it != clasesVivo.end() && *it != id_selected)    it++;

        } while (it == clasesVivo.end());
        
        participaciones = IEM -> selectClase(id_selected);

        std::cout << "\nParticipaciones:\n\n";

        for (it_p = participaciones.begin(); it_p != participaciones.end(); it_p++)
        {
            if ((*it_p) -> getResponde() != NULL)
            {
                std::cout << "Responde a:\n" << (*it_p) -> getResponde() -> getMensaje() << "\t[id: " << (*it_p) -> getResponde() -> getId() << "]" << std::endl;
            }
            bubbleMsg((*it_p));

            std::cout << "------------------------------------------------------------" << std::endl;
        }

        std::string confirmar;
        std::cout << "Desea contestar alguna participacion? [S/N o Cualquier letra (menos la s)]: ";
        std::cin >> confirmar;

        if(confirmar == "S" || confirmar == "s")
        {
            do
            {
                std::cout << "\nId de la participacion a responder: ";
                std::cin >> id_response;

                it_p = participaciones.begin();

                while ((*it_p) -> getId() != id_response && it_p != participaciones.end())
                {
                    it_p++;
                }
            } while (it_p == participaciones.end());
            
            IEM ->responder(id_response);
        }

            std::cout << "\nIngrese texto: ";
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
}

void CUInscripcionAsignaturas()
{
    IIA = fabrica -> getInscripcionAsignaturas();

    std::string codigoAsig;
    int op = 0;

    try
    {
        system("clear");
        std::cout << "\t\tInscripcion Asignatura" << std::endl;
        do
        {
            std::list<std::string> listaAsignaturas = IIA -> asignaturasNoInscriptos();
            std::list<std::string>::iterator it;

            if(listaAsignaturas.empty())
            {
                std::cout << "\nNo hay asignaturas disponibles a las cuales inscribirse.\n" << std::endl;

                op = 3;

                pressEnter();
            }
            else
            {
                system("clear");
                std::cout << "Asignaturas disponibles:";
                //Muestro las asignaturas en las cuales el estudiante no esta inscripto
                for (it = listaAsignaturas.begin(); it != listaAsignaturas.end(); it++)
                {
                    std::cout << *it << std::endl;
                }

                std::cout << "Seleccione la asignatura a inscribirse: ";
                std::cin >> codigoAsig;

                IIA -> selectAsignatura(codigoAsig);

                std::cout << "1: Inscribirse" << std::endl << "2: Cancelar "<< std::endl;
                std::cout << "Ingrese una opcion: ";
                std::cin >> op;

                if(op == 1)
                {
                    IIA -> inscribir();
                }

                std::string confirmar;
                std::cout << "Desea continuar inscribiendose a asignaturas? [S/N o Cualquier letra (menos la s)]: ";
                std::cin >> confirmar;
                if(confirmar == "N" || confirmar == "n") op = 3;
            }
        }while(op != 3);
    }
    catch(const std::invalid_argument& e)
    {
        std::cerr << e.what() << '\n';
        pressEnter();
    }
}

void CUListadoClase()
{
    ILC = fabrica -> getIListadoClase();

    try
    {
        std::list<std::string> clasesDelDocente = ILC -> asignaturasAsignadas();
        std::list<std::string>::iterator it;

        std::list<DtInfoClase*> infoClases;
        std::list<DtInfoClase*>::iterator itClases;

        std::string opcion;
        
        std::cout << "\t\tListar Clases\n" << std::endl;

        if(!clasesDelDocente.empty()) //lista no vacia
        {
            std::cout << "Seleccione una de las siguientes asignaturas que esta asignado: " << std::endl;
            
            for(it = clasesDelDocente.begin(); it != clasesDelDocente.end(); it++)
            {
                std::cout << " - " << (*it) << std::endl;
            }

            std::cout << std::endl <<"Opción: ";
            std::cin >> opcion;

            infoClases = ILC -> selectAsignatura(opcion);

            system("clear");
            std::cout << "Informacion de la Clase:" << std::endl;

            for(itClases = infoClases.begin(); itClases != infoClases.end(); itClases++) //hacer un dynamic cast sis DtInfoClaseMonitoreo o Teorico o Practico
            {
                DtInfoTeorico* infoTeorico = dynamic_cast<DtInfoTeorico*>(*itClases);

                if(infoTeorico != NULL) std::cout << *infoTeorico << std::endl;
                else
                {
                    DtInfoMonitoreo* infoMonitoreo = dynamic_cast<DtInfoMonitoreo*>(*itClases);
                    if(infoMonitoreo != NULL) std::cout << *infoMonitoreo << std::endl;
                    else std::cout << *(*itClases) << std::endl;
                }
            }
            pressEnter();
        }
        else
        {
            std::cout << "El docente no tiene clases. " << std::endl;
            pressEnter();
        }
    }
    catch(const std::invalid_argument& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void CUEliminarAsignatura()
{
    IEA = fabrica -> getIEliminarAsignatura();

    std::cout << "\t\tEliminar Asignatura: " << std::endl;
    std::list<std::string> listarAsignaturas = IEA ->  listarAsignaturas();
    std::list<std::string>::iterator it;
    std::string opcion;

    if(listarAsignaturas.empty())
    {
        std::cout << "\n No hay asignaturas" << std::endl;
        pressEnter();
    }
    else
    {
        for(it = listarAsignaturas.begin(); it != listarAsignaturas.end(); it++)
        {
            std::cout << " - " << *it << std::endl;
        }

        std::cout << "Seleccione una Asignatura: ";
        std::cin >> opcion;
        system("clear");

        IEA -> selectAsignatura(opcion);

        std::cout << "Desea confirmar? [S/N o Cualquier letra (menos la s)]: ";
        std::cin >> opcion;

        if (opcion =="S" || opcion == "s")
        {
            IEA -> eliminarAsignatura();
            std::cout << "Se ha eliminado la asignatura exitosamente" << std::endl;
            pressEnter();
        }
        else
        {
            std::cout <<"Operación cancelada." << std::endl;
            pressEnter();
        }
    }
}